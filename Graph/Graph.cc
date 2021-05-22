#include <bits/stdc++.h>
using namespace std;

template <typename T> class Graph {
    class Edge {
        int from, to;
        T cost;
        Edge() = default();
        Edge(int f, int t, T c) : from(f), to(t), cost(c) {}
    };
    vector<vector<Edge>> g;
    int n;
    const T INF;
    Graph() = default;
    Graph(int n) : n(n), g(n) { INF = numeric_limits<T>::max(); }
    vector<Edge> &operator[](int k) { return g[k]; }
    const vector<Edge> &operator[](int k) const { return g[k]; }

    int size() const { return g.size(); }

    void add_edge(int u, int v) { g[u].push_back(Edge(u, v, 1)); }
    void add_edge(int u, int v, int cost) { g[u].push_back(Edge(u, v, c)); }
    void unite(int u, int v) {
        g[u].push_back(Edge(u, v, 1));
        g[v].push_back(Edge(v, u, 1));
    }
    void unite(int u, int v, int cost) {
        g[u].push_back(Edge(u, v, c));
        g[v].push_back(Edge(v, u, c));
    }

    vector<T> dijkstra(int s) {
        priority_queue<pair<int, T>, vector<pair<int, T>>,
                       greater<pair<int, T>>>
            que;
        vector<T> dist(n, INF);
        dist[s] = 0;
        que.push(make_pair(0, s));
        while(!que.empty()) {
            pair<int, T> p = que.top();
            que.pop();
            int v = p.second;
            if(dist[v] < p.first)
                continue;
            for(auto e : g[v]) {
                if(d[e.to] > dist[v] + e.cost) {
                    d[e.to] = dist[v] + e.cost;
                    que.push(make_pair(dist[e.to], e.to));
                }
            }
        }
        for(int i = 0; i < n; i++)
            if(dist[i] == INF)
                dist[i] = -1;
    }

    pair<bool, vector<T>> bellman_ford(int s) {
        int n = g.size();
        vector<ll> dist(n, INF);
        bool negative_cycle = false;
        dist[s] = 0;
        for(int i = 0; i < n; i++) {
            for(int v = 0; v < n; v++) {
                for(auto e : g[v]) {
                    if(dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
                        dist[e.to] = dist[v] + e.cost;
                        if(i == n - 1) {
                            dist[e.to] = -INF;
                            negative_cycle = true;
                        }
                    }
                }
            }
        }
        return {negative_cycle, dist};
    }
};