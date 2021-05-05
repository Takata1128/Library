#include <bits/stdc++.h>

class HLDecomposition {
  private:
    std::vector<std::vector<int>> g; // グラフ（木）
    int t;
    std::vector<int> sz;  // もとの木の部分木のサイズ
    std::vector<int> par; // もとの木での親
    std::vector<int>
        idx; // vの新たなidx(行きがけ順) segtree等に乗せたときのidxに対応
    std::vector<int> head; // 連結成分のうち最もidxが若い(浅い)頂点
    std::vector<int> depth; // もとの木での深さ

  public:
    HLDecomposition(std::vector<std::vector<int>> &g, int root = 0)
        : g(g), sz(g.size()), par(g.size()), idx(g.size()), head(g.size()),
          depth(g.size()), t(0) {
        dfs_sz(root, 0, -1);
        dfs_hld(root, -1, 0);
    }

    int dfs_sz(int v, int d, int p) {
        par[v] = p;
        if(sz[v] != 0)
            return sz[v];
        sz[v] = 1;
        depth[v] = d;
        for(auto nv : g[v]) {
            if(p == nv)
                continue;
            sz[v] += dfs_sz(nv, d + 1, v);
        }
        return sz[v];
    }

    void dfs_hld(int v, int p, int h) {
        idx[v] = t++;
        head[v] = h;
        if(par[v] != -1 && g[v].size() == 1)
            return;
        int m = 0;
        int nxt = -1;
        for(auto nv : g[v]) {
            if(nv == p)
                continue;
            if(sz[nv] > m) {
                m = sz[nv];
                nxt = nv;
            }
        }
        dfs_hld(nxt, v, h);
        for(auto nv : g[v]) {
            if(p == nv)
                continue;
            if(nv != nxt)
                dfs_hld(nv, v, nv);
        }
    }

    std::vector<std::pair<int, int>> query(int u, int v, bool is_edge = false) {
        std::vector<std::pair<int, int>> ret;
        while(head[u] != head[v]) {
            if(depth[head[u]] <= depth[head[v]]) {
                ret.push_back({idx[head[v]], idx[v]});
                v = par[head[v]];
            } else {
                ret.push_back({idx[head[u]], idx[u]});
                u = par[head[u]];
            }
        }
        if(!(is_edge && idx[u] == idx[v]))
            ret.push_back(
                {std::min(idx[u], idx[v]) + is_edge, std::max(idx[u], idx[v])});
        return ret;
    }

    template <typename S, typename Query, typename Function>
    S query(int u, int v, const S &e, const Query &q, const Function &f,
            bool is_edge = false) {
        S l = e, r = e;
        for(;; v = par[head[v]]) {
            if(idx[u] > idx[v]) {
                std::swap(u, v), std::swap(l, r);
            }
            if(head[v] == head[u])
                break;
            l = f(q(idx[head[v]], idx[v] + 1), l);
        }
        return f(f(q(idx[u] + is_edge, idx[v] + 1), l), r);
    }

    int lca(int u, int v) {
        for(;; v = par[head[v]]) {
            if(idx[u] > idx[v])
                std::swap(u, v);
            if(head[u] == head[v])
                return u;
        }
    }

    int get_idx(int v) { return idx[v]; }
    int get_depth(int v) { return depth[v]; }
    int get_size(int v) { return sz[v]; }
};
