#include <bits/stdc++.h>
using namespace std;

template <typename T = int> class Graph {
  public:
    class Edge {
      public:
        int from, to;
        T cost;
        Edge() = default;
        Edge(int f, int t, T c) : from(f), to(t), cost(c) {}
        bool operator<(const Edge &rhs) const {
            return cost < rhs.cost;
        }
    };
    vector<vector<Edge>> g;
    vector<Edge> edges;
    int n;
    const T INF = numeric_limits<T>::max();
    Graph() = default;
    Graph(int n) : n(n), g(n) {}
    vector<Edge> &operator[](int k) { return g[k]; }
    const vector<Edge> &operator[](int k) const { return g[k]; }

    int size() const { return g.size(); }
    void resize(size_t sz) { g.resize(sz, vector<Edge>()); }

    void add_edge(int u, int v) {
        g[u].push_back(Edge(u, v, 1));
        edges.push_back(Edge(u, v, 1));
    }
    void add_edge(int u, int v, T c) {
        g[u].push_back(Edge(u, v, c));
        edges.push_back(Edge(u, v, c));
    }
    void unite(int u, int v) {
        g[u].push_back(Edge(u, v, 1));
        g[v].push_back(Edge(v, u, 1));
        edges.push_back(Edge(u, v, 1));
    }
    void unite(int u, int v, T c) {
        g[u].push_back(Edge(u, v, c));
        g[v].push_back(Edge(v, u, c));
        edges.push_back(Edge(u, v, c));
    }

    vector<T> dijkstra(int s) {
        priority_queue<pair<T, int>, vector<pair<T, int>>,
                       greater<pair<T, int>>>
            que;
        vector<T> dist(n, INF);
        dist[s] = 0;
        que.push(make_pair(0, s));
        while(!que.empty()) {
            pair<T, int> p = que.top();
            que.pop();
            int v = p.second;
            if(dist[v] < p.first)
                continue;
            for(auto e : g[v]) {
                if(dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    que.push(make_pair(dist[e.to], e.to));
                }
            }
        }
        for(int i = 0; i < n; i++)
            if(dist[i] == INF)
                dist[i] = -1;
        return dist;
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

    // 0 or 1
    vector<int> bipartite_split() {
        vector<int> ret(n, -1);
        auto dfs = [&](auto &&dfs, int v, int p, bool pcolor) -> bool {
            ret[v] = !pcolor;
            for(auto e : g[v]) {
                if(v == p) continue;
                if(ret[v] == ret[e.to]) return false;
                if(ret[e.to] == -1 && !dfs(dfs, e.to, v, ret[v])) return false;
            }
            return true;
        };
        for(int i = 0; i < n; i++) {
            if(ret[i] == -1 && !dfs(dfs, i, -1, 0)) return vector<int>();
        }
        return ret;
    }

    template <class UnionFind> pair<ll, vector<Edge>> kruskal() {
        T sum = 0;
        sort(edges.begin(), edges.end());
        vector<Edge> ret;
        UnionFind uf(n);
        for(auto e : edges) {
            if(!uf.same(e.from, e.to)) {
                uf.unite(e.from, e.to);
                ret.push_back(e);
                sum += e.cost;
            }
        }
        return make_pair(sum, ret);
    }
};