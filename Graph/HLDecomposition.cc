#include <bits/stdc++.h>
using namespace std;

template <typename Tree>
class HeavyLightDecomposition {
  private:
    Tree g;           // グラフ（木）
    int n;            // 木の頂点数
    int t;            // 探索順序
    vector<int> sz;   // もとの木の部分木のサイズ
    vector<int> par;  // もとの木での親
    vector<int> idx;  // vの新たなidx(行きがけ順) segtree等に乗せたときのidxに対応
    vector<int> out;  // vの帰りがけ順 部分木クエリに使用
    vector<int> head; // 連結成分のうち最もidxが若い(浅い)頂点
    vector<int> dpth; // もとの木での深さ

    // 各部分木のサイズ計算
    int dfs_sz(int v, int p, int d) {
        par[v] = p;
        dpth[v] = d;
        sz[v] = 1;
        if(g[v].size() >= 2 && g[v][0].to == p) swap(g[v][0], g[v].back()); // g[v][0]が親への辺だとまずい
        for(auto &e : g[v]) {
            if(p == e.to) continue;
            sz[v] += dfs_sz(e.to, v, d + 1);
            if(sz[e.to] > sz[g[v][0].to]) swap(g[v][0], e); // heavyな辺を先頭へ
        }
        return sz[v];
    }

    // HL分解
    void dfs_hld(int v, int p) {
        idx[v] = t++;
        for(auto e : g[v]) {
            if(e.to == p) continue;
            head[e.to] = (e.to == g[v][0].to ? head[v] : e.to); // heavyな辺か？
            dfs_hld(e.to, v);
        }
        out[v] = t;
    }

  public:
    HeavyLightDecomposition(Tree &g, int root = 0)
        : g(g), n(g.size()), sz(n), par(n), idx(n), out(n), head(n),
          dpth(n), t(0) {
        assert(g.edges.size() == n - 1);
        dfs_sz(root, -1, 0);
        dfs_hld(root, -1);
    }

    // [u,v]パスのHL分解後の区間の集合を取得
    vector<pair<int, int>> get_path_sequences(int u, int v, bool is_edge = false) {
        vector<pair<int, int>> ret;
        while(head[u] != head[v]) {
            if(dpth[head[u]] <= dpth[head[v]]) {
                ret.push_back({idx[head[v]], idx[v]});
                v = par[head[v]];
            } else {
                ret.push_back({idx[head[u]], idx[u]});
                u = par[head[u]];
            }
        }
        if(!(is_edge && idx[u] == idx[v]))
            ret.push_back(
                {min(idx[u], idx[v]) + is_edge, max(idx[u], idx[v])});
        return ret;
    }

    // 頂点u以下の部分木のHL分解後の区間の集合を取得
    vector<pair<int, int>> get_subtree_sequences(int v, bool is_edge = false) {
        return get_path_sequences(idx[v] + is_edge, out[v] - 1, is_edge);
    }

    // [u,v]パスに対する更新 O((log n)^2)
    template <class Function>
    void apply_path(int u, int v, const Function &update, bool is_edge = false) {
        for(;; v = par[head[v]]) {
            if(idx[u] > idx[v]) { // uが根側
                swap(u, v);
            }
            if(head[v] == head[u]) break;
            update(idx[head[v]], idx[v]);
        }
        update(idx[u] + is_edge, idx[v]);
    }

    // [u,v]パスに対する取得 O((log n)^2)
    template <typename S, typename Op, typename Function>
    S prod_path(int u, int v, const S &e, const Op &op, const Function &prod,
                bool is_edge = false) const {
        S l = e, r = e;
        for(;; v = par[head[v]]) { // uが根側
            if(idx[u] > idx[v]) {
                swap(u, v), swap(l, r);
            }
            if(head[v] == head[u]) break;
            l = op(prod(idx[head[v]], idx[v]), l);
        }
        return op(op(prod(idx[u] + is_edge, idx[v]), l), r);
    }

    // vを根とする部分木に対する更新 O(log n)
    void apply_subtree(int v, function<void(int, int)> func, bool is_edge = false) {
        func(idx[v] + is_edge, out[v] - 1);
    }

    // vを根とする部分木に対する取得 O(log n)
    template <typename S>
    S prod_subtree(int v, function<S(int, int)> func, bool is_edge = false) const {
        return func(idx[v] + is_edge, out[v] - 1);
    }

    // u,vのLCA : O(log n)
    int lca(int u, int v) const {
        for(;; v = par[head[v]]) {
            if(idx[u] > idx[v])
                swap(u, v);
            if(head[u] == head[v])
                return u;
        }
    }
    int dist(int u, int v) const {
        return dpth[u] + dpth[v] - 2 * dpth[lca(u, v)];
    }
    int index(int v) const { return idx[v]; }
    int depth(int v) const { return dpth[v]; }
    int subtree_size(int v) const { return sz[v]; }
};