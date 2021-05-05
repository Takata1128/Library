#include <bits/stdc++.h>
using namespace std;

// 強連結成分分解　O(|V|+|E|)
class Scc {
  public:
    int N;
    vector<vector<int>> G, rG;
    vector<int> vs;
    vector<bool> used;
    vector<int> cmp; // 新グラフのindex

    Scc(vector<vector<int>> _G) : G(_G) {
        N = G.size();
        rG.resize(N, vector<int>());
        for(int i = 0; i < G.size(); i++) {
            for(auto nv : G[i]) {
                rG[nv].push_back(i);
            }
        }
        used.resize(N);
        cmp.resize(N);
    }

    void dfs(int v) {
        used[v] = true;
        for(auto nv : G[v]) {
            if(!used[nv])
                dfs(nv);
        }
        vs.push_back(v);
    }

    void rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for(auto nv : rG[v]) {
            if(!used[nv])
                rdfs(nv, k);
        }
    }

    int process() {
        fill(used.begin(), used.end(), false);
        for(int v = 0; v < N; v++) {
            if(!used[v])
                dfs(v);
        }
        fill(used.begin(), used.end(), false);
        int k = 0;
        for(int i = N - 1; i >= 0; i--) {
            if(!used[vs[i]])
                rdfs(vs[i], k++);
        }
        return k;
    }

    vector<vector<int>> get() {
        vector<vector<int>> g(N, vector<int>());
        for(int i = 0; i < N; i++) {
            for(auto nv : G[i]) {
                if(cmp[i] == cmp[nv])
                    continue;
                g[cmp[i]].push_back(cmp[nv]);
            }
        }
        return g;
    }
};