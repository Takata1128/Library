---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/Graph.cc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <typename T = int> class Graph {\n  public:\n    class Edge\
    \ {\n      public:\n        int from, to;\n        T cost;\n        Edge() = default;\n\
    \        Edge(int f, int t, T c) : from(f), to(t), cost(c) {}\n        bool operator<(const\
    \ Edge &rhs) const {\n            return cost < rhs.cost;\n        }\n    };\n\
    \    vector<vector<Edge>> g;\n    vector<Edge> edges;\n    int n;\n    const T\
    \ INF = numeric_limits<T>::max();\n    Graph() = default;\n    Graph(int n) :\
    \ n(n), g(n) {}\n    vector<Edge> &operator[](int k) { return g[k]; }\n    const\
    \ vector<Edge> &operator[](int k) const { return g[k]; }\n\n    int size() const\
    \ { return g.size(); }\n    void resize(size_t sz) { g.resize(sz, vector<Edge>());\
    \ }\n\n    void add_edge(int u, int v) {\n        g[u].push_back(Edge(u, v, 1));\n\
    \        edges.push_back(Edge(u, v, 1));\n    }\n    void add_edge(int u, int\
    \ v, T c) {\n        g[u].push_back(Edge(u, v, c));\n        edges.push_back(Edge(u,\
    \ v, c));\n    }\n    void unite(int u, int v) {\n        g[u].push_back(Edge(u,\
    \ v, 1));\n        g[v].push_back(Edge(v, u, 1));\n        edges.push_back(Edge(u,\
    \ v, 1));\n    }\n    void unite(int u, int v, T c) {\n        g[u].push_back(Edge(u,\
    \ v, c));\n        g[v].push_back(Edge(v, u, c));\n        edges.push_back(Edge(u,\
    \ v, c));\n    }\n\n    vector<T> dijkstra(int s) {\n        priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>,\n                       greater<pair<T, int>>>\n\
    \            que;\n        vector<T> dist(n, INF);\n        dist[s] = 0;\n   \
    \     que.push(make_pair(0, s));\n        while(!que.empty()) {\n            pair<T,\
    \ int> p = que.top();\n            que.pop();\n            int v = p.second;\n\
    \            if(dist[v] < p.first)\n                continue;\n            for(auto\
    \ e : g[v]) {\n                if(dist[e.to] > dist[v] + e.cost) {\n         \
    \           dist[e.to] = dist[v] + e.cost;\n                    que.push(make_pair(dist[e.to],\
    \ e.to));\n                }\n            }\n        }\n        for(int i = 0;\
    \ i < n; i++)\n            if(dist[i] == INF)\n                dist[i] = -1;\n\
    \        return dist;\n    }\n\n    pair<bool, vector<T>> bellman_ford(int s)\
    \ {\n        int n = g.size();\n        vector<ll> dist(n, INF);\n        bool\
    \ negative_cycle = false;\n        dist[s] = 0;\n        for(int i = 0; i < n;\
    \ i++) {\n            for(int v = 0; v < n; v++) {\n                for(auto e\
    \ : g[v]) {\n                    if(dist[v] != INF && dist[e.to] > dist[v] + e.cost)\
    \ {\n                        dist[e.to] = dist[v] + e.cost;\n                \
    \        if(i == n - 1) {\n                            dist[e.to] = -INF;\n  \
    \                          negative_cycle = true;\n                        }\n\
    \                    }\n                }\n            }\n        }\n        return\
    \ {negative_cycle, dist};\n    }\n\n    // 0 or 1\n    vector<int> bipartite_split()\
    \ {\n        vector<int> ret(n, -1);\n        auto dfs = [&](auto &&dfs, int v,\
    \ int p, bool pcolor) -> bool {\n            ret[v] = !pcolor;\n            for(auto\
    \ e : g[v]) {\n                if(v == p) continue;\n                if(ret[v]\
    \ == ret[e.to]) return false;\n                if(ret[e.to] == -1 && !dfs(dfs,\
    \ e.to, v, ret[v])) return false;\n            }\n            return true;\n \
    \       };\n        for(int i = 0; i < n; i++) {\n            if(ret[i] == -1\
    \ && !dfs(dfs, i, -1, 0)) return vector<int>();\n        }\n        return ret;\n\
    \    }\n\n    template <class UnionFind> pair<ll, vector<Edge>> kruskal() {\n\
    \        T sum = 0;\n        sort(edges.begin(), edges.end());\n        vector<Edge>\
    \ ret;\n        UnionFind uf(n);\n        for(auto e : edges) {\n            if(!uf.same(e.from,\
    \ e.to)) {\n                uf.unite(e.from, e.to);\n                ret.push_back(e);\n\
    \                sum += e.cost;\n            }\n        }\n        return make_pair(sum,\
    \ ret);\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename T =\
    \ int> class Graph {\n  public:\n    class Edge {\n      public:\n        int\
    \ from, to;\n        T cost;\n        Edge() = default;\n        Edge(int f, int\
    \ t, T c) : from(f), to(t), cost(c) {}\n        bool operator<(const Edge &rhs)\
    \ const {\n            return cost < rhs.cost;\n        }\n    };\n    vector<vector<Edge>>\
    \ g;\n    vector<Edge> edges;\n    int n;\n    const T INF = numeric_limits<T>::max();\n\
    \    Graph() = default;\n    Graph(int n) : n(n), g(n) {}\n    vector<Edge> &operator[](int\
    \ k) { return g[k]; }\n    const vector<Edge> &operator[](int k) const { return\
    \ g[k]; }\n\n    int size() const { return g.size(); }\n    void resize(size_t\
    \ sz) { g.resize(sz, vector<Edge>()); }\n\n    void add_edge(int u, int v) {\n\
    \        g[u].push_back(Edge(u, v, 1));\n        edges.push_back(Edge(u, v, 1));\n\
    \    }\n    void add_edge(int u, int v, T c) {\n        g[u].push_back(Edge(u,\
    \ v, c));\n        edges.push_back(Edge(u, v, c));\n    }\n    void unite(int\
    \ u, int v) {\n        g[u].push_back(Edge(u, v, 1));\n        g[v].push_back(Edge(v,\
    \ u, 1));\n        edges.push_back(Edge(u, v, 1));\n    }\n    void unite(int\
    \ u, int v, T c) {\n        g[u].push_back(Edge(u, v, c));\n        g[v].push_back(Edge(v,\
    \ u, c));\n        edges.push_back(Edge(u, v, c));\n    }\n\n    vector<T> dijkstra(int\
    \ s) {\n        priority_queue<pair<T, int>, vector<pair<T, int>>,\n         \
    \              greater<pair<T, int>>>\n            que;\n        vector<T> dist(n,\
    \ INF);\n        dist[s] = 0;\n        que.push(make_pair(0, s));\n        while(!que.empty())\
    \ {\n            pair<T, int> p = que.top();\n            que.pop();\n       \
    \     int v = p.second;\n            if(dist[v] < p.first)\n                continue;\n\
    \            for(auto e : g[v]) {\n                if(dist[e.to] > dist[v] + e.cost)\
    \ {\n                    dist[e.to] = dist[v] + e.cost;\n                    que.push(make_pair(dist[e.to],\
    \ e.to));\n                }\n            }\n        }\n        for(int i = 0;\
    \ i < n; i++)\n            if(dist[i] == INF)\n                dist[i] = -1;\n\
    \        return dist;\n    }\n\n    pair<bool, vector<T>> bellman_ford(int s)\
    \ {\n        int n = g.size();\n        vector<ll> dist(n, INF);\n        bool\
    \ negative_cycle = false;\n        dist[s] = 0;\n        for(int i = 0; i < n;\
    \ i++) {\n            for(int v = 0; v < n; v++) {\n                for(auto e\
    \ : g[v]) {\n                    if(dist[v] != INF && dist[e.to] > dist[v] + e.cost)\
    \ {\n                        dist[e.to] = dist[v] + e.cost;\n                \
    \        if(i == n - 1) {\n                            dist[e.to] = -INF;\n  \
    \                          negative_cycle = true;\n                        }\n\
    \                    }\n                }\n            }\n        }\n        return\
    \ {negative_cycle, dist};\n    }\n\n    // 0 or 1\n    vector<int> bipartite_split()\
    \ {\n        vector<int> ret(n, -1);\n        auto dfs = [&](auto &&dfs, int v,\
    \ int p, bool pcolor) -> bool {\n            ret[v] = !pcolor;\n            for(auto\
    \ e : g[v]) {\n                if(v == p) continue;\n                if(ret[v]\
    \ == ret[e.to]) return false;\n                if(ret[e.to] == -1 && !dfs(dfs,\
    \ e.to, v, ret[v])) return false;\n            }\n            return true;\n \
    \       };\n        for(int i = 0; i < n; i++) {\n            if(ret[i] == -1\
    \ && !dfs(dfs, i, -1, 0)) return vector<int>();\n        }\n        return ret;\n\
    \    }\n\n    template <class UnionFind> pair<ll, vector<Edge>> kruskal() {\n\
    \        T sum = 0;\n        sort(edges.begin(), edges.end());\n        vector<Edge>\
    \ ret;\n        UnionFind uf(n);\n        for(auto e : edges) {\n            if(!uf.same(e.from,\
    \ e.to)) {\n                uf.unite(e.from, e.to);\n                ret.push_back(e);\n\
    \                sum += e.cost;\n            }\n        }\n        return make_pair(sum,\
    \ ret);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Graph.cc
  requiredBy: []
  timestamp: '2021-07-10 17:10:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Graph.cc
layout: document
redirect_from:
- /library/Graph/Graph.cc
- /library/Graph/Graph.cc.html
title: Graph/Graph.cc
---
