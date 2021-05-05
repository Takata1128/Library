#include <bits/stdc++.h>
using namespace std;
/*
    LCAを求める構造体
    参考:https://algo-logic.info/lca/
    初期化:O(NlogN)
    クエリ:O(logN)
*/
struct LowestCommonAncestor {
    vector<vector<int>> parent; // parent[k][v]:= vの2^k親の頂点
    vector<int> dist;           // rootからの距離
    LowestCommonAncestor(const vector<vector<int>> &G, int root = 0) {
        init(G, root);
    }

    void init(const vector<vector<int>> &G, int root = 0) {
        int N = G.size();
        int K = 1;
        while((1 << K) < N)
            K++;
        parent.assign(K, vector<int>(N, -1));
        dist.assign(N, -1);
        dfs(root, -1, 0, G);
        //ダブリング
        for(int k = 0; k + 1 < K; k++) {
            for(int v = 0; v < N; v++) {
                if(parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    // 根からの距離と一つ親を求める
    void dfs(int v, int p, int d, const vector<vector<int>> &G) {
        parent[0][v] = p;
        dist[v] = d;
        for(auto nv : G[v]) {
            if(nv != p)
                dfs(nv, v, d + 1, G);
        }
    }

    // uとvのLCAを求める
    int query(int u, int v) {
        if(dist[u] < dist[v])
            swap(u, v);
        int K = parent.size();
        for(int k = 0; k < K; k++) {
            if((dist[u] - dist[v]) & (1 << k)) {
                u = parent[k][u];
            }
        }

        if(u == v)
            return u;
        // 二分探索
        for(int k = K - 1; k >= 0; k--) {
            if(parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};
