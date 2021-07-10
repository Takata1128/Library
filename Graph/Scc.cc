#include <bits/stdc++.h>
using namespace std;

// 強連結成分分解　O(|V|+|E|)
template <class Graph> class Scc {
  private:
    int N;
    Graph G, rG;
    vector<int> vs;
    vector<bool> used;
    vector<int> cmp; // 新グラフのindex
    void dfs(int v) {
        used[v] = true;
        for(auto e : G[v]) {
            if(!used[e.to])
                dfs(e.to);
        }
        vs.push_back(v);
    }
    void rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for(auto e : rG[v]) {
            if(!used[e.to])
                rdfs(e.to, k);
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

  public:
    Scc(Graph _G) : G(_G) {
        N = G.size();
        rG.resize(N);
        for(int i = 0; i < G.size(); i++) {
            for(auto e : G[i]) {
                rG.add_edge(e.to, i);
            }
        }
        used.resize(N);
        cmp.resize(N);
        process();
    }
    vector<int> get_new_indice() const {
        return cmp;
    }
    vector<vector<int>> get_new_graph() const {
        vector<vector<int>> g(N, vector<int>());
        for(int i = 0; i < N; i++) {
            for(auto e : G[i]) {
                if(cmp[i] == cmp[e.to])
                    continue;
                g[cmp[i]].push_back(cmp[e.to]);
            }
        }
        return g;
    }
};