#include <bits/stdc++.h>
using namespace std;

// Ford-fulkerson maxFlow(O(F|E|),F:最大流量)
// だいたい↑の計算量より割と早くなるらしい
struct Ford_fulkerson {
    const int INF = 1 << 30;
    struct edge {
        int to, cap, rev;
    };
    int n;
    vector<vector<edge>> graph;
    vector<int> vis;

    Ford_fulkerson(int _n) : n(_n), graph(n), vis(n) {}

    void addEdge(int from, int to, int cap) {
        graph[from].push_back((edge){to, cap, (int)graph[to].size()});
        graph[to].push_back((edge){from, 0, (int)graph[from].size() - 1});
    }
    int dfs(int v, int t, int f) {
        if(v == t)
            return f;
        vis[v] = true;
        for(int i = 0; i < (int)graph[v].size(); i++) {
            edge &e = graph[v][i];
            if(!vis[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if(d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        int flow = 0;
        for(;;) {
            for(int i = 0; i < n; i++)
                vis[i] = false;
            int f = dfs(s, t, INF);
            if(f == 0)
                return flow;
            flow += f;
        }
    }
};