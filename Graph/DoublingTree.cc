#include <bits/stdc++.h>
using namespace std;

template <class Graph> class DoublingTree {
    using T = decltype(Graph::Edge::cost);
    vector<vector<int>> parent; // parent[k][v]:= vの2^k親の頂点
    vector<T> dis;              // rootからの距離
    void init(const Graph &G, int root = 0) {
        int N = G.size();
        int K = 1;
        while((1 << K) < N)
            K++;
        parent.assign(K, vector<int>(N, -1));
        dis.assign(N, -1);
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
    void dfs(int v, int p, int d, const Graph &G) {
        parent[0][v] = p;
        dis[v] = d;
        for(auto e : G[v]) {
            if(e.to != p)
                dfs(e.to, v, d + e.cost, G);
        }
    }

  public:
    DoublingTree(const Graph &G, int root = 0) {
        init(G, root);
    }

    // uとvのLCAを求める
    int query(int u, int v) {
        if(dis[u] < dis[v])
            swap(u, v);
        int K = parent.size();
        for(int k = 0; k < K; k++) {
            if((dis[u] - dis[v]) & (1 << k)) {
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

    // uとvの距離を求める
    T dist(int u, int v) {
        return dis[u] + dis[v] - dis[query(u, v)] * 2;
    }
};
