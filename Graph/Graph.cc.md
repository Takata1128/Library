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
    \ std;\n\ntemplate <typename T> class Graph {\n    class Edge {\n        int from,\
    \ to;\n        T cost;\n        Edge() = default();\n        Edge(int f, int t,\
    \ T c) : from(f), to(t), cost(c) {}\n    };\n    vector<vector<Edge>> g;\n   \
    \ int n;\n    const T INF;\n    Graph() = default;\n    Graph(int n) : n(n), g(n)\
    \ { INF = numeric_limits<T>::max(); }\n    vector<Edge> &operator[](int k) { return\
    \ g[k]; }\n    const vector<Edge> &operator[](int k) const { return g[k]; }\n\n\
    \    int size() const { return g.size(); }\n\n    void add_edge(int u, int v)\
    \ { g[u].push_back(Edge(u, v, 1)); }\n    void add_edge(int u, int v, int cost)\
    \ { g[u].push_back(Edge(u, v, c)); }\n    void unite(int u, int v) {\n       \
    \ g[u].push_back(Edge(u, v, 1));\n        g[v].push_back(Edge(v, u, 1));\n   \
    \ }\n    void unite(int u, int v, int cost) {\n        g[u].push_back(Edge(u,\
    \ v, c));\n        g[v].push_back(Edge(v, u, c));\n    }\n\n    vector<T> dijkstra(int\
    \ s) {\n        priority_queue<pair<int, T>, vector<pair<int, T>>,\n         \
    \              greater<pair<int, T>>>\n            que;\n        vector<T> dist(n,\
    \ INF);\n        dist[s] = 0;\n        que.push(make_pair(0, s));\n        while(!que.empty())\
    \ {\n            pair<int, T> p = que.top();\n            que.pop();\n       \
    \     int v = p.second;\n            if(dist[v] < p.first)\n                continue;\n\
    \            for(auto e : g[v]) {\n                if(d[e.to] > dist[v] + e.cost)\
    \ {\n                    d[e.to] = dist[v] + e.cost;\n                    que.push(make_pair(dist[e.to],\
    \ e.to));\n                }\n            }\n        }\n        for(int i = 0;\
    \ i < n; i++)\n            if(dist[i] == INF)\n                dist[i] = -1;\n\
    \    }\n\n    pair<bool, vector<T>> bellman_ford(int s) {\n        int n = g.size();\n\
    \        vector<ll> dist(n, INF);\n        bool negative_cycle = false;\n    \
    \    dist[s] = 0;\n        for(int i = 0; i < n; i++) {\n            for(int v\
    \ = 0; v < n; v++) {\n                for(auto e : g[v]) {\n                 \
    \   if(dist[v] != INF && dist[e.to] > dist[v] + e.cost) {\n                  \
    \      dist[e.to] = dist[v] + e.cost;\n                        if(i == n - 1)\
    \ {\n                            dist[e.to] = -INF;\n                        \
    \    negative_cycle = true;\n                        }\n                    }\n\
    \                }\n            }\n        }\n        return {negative_cycle,\
    \ dist};\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename T> class\
    \ Graph {\n    class Edge {\n        int from, to;\n        T cost;\n        Edge()\
    \ = default();\n        Edge(int f, int t, T c) : from(f), to(t), cost(c) {}\n\
    \    };\n    vector<vector<Edge>> g;\n    int n;\n    const T INF;\n    Graph()\
    \ = default;\n    Graph(int n) : n(n), g(n) { INF = numeric_limits<T>::max();\
    \ }\n    vector<Edge> &operator[](int k) { return g[k]; }\n    const vector<Edge>\
    \ &operator[](int k) const { return g[k]; }\n\n    int size() const { return g.size();\
    \ }\n\n    void add_edge(int u, int v) { g[u].push_back(Edge(u, v, 1)); }\n  \
    \  void add_edge(int u, int v, int cost) { g[u].push_back(Edge(u, v, c)); }\n\
    \    void unite(int u, int v) {\n        g[u].push_back(Edge(u, v, 1));\n    \
    \    g[v].push_back(Edge(v, u, 1));\n    }\n    void unite(int u, int v, int cost)\
    \ {\n        g[u].push_back(Edge(u, v, c));\n        g[v].push_back(Edge(v, u,\
    \ c));\n    }\n\n    vector<T> dijkstra(int s) {\n        priority_queue<pair<int,\
    \ T>, vector<pair<int, T>>,\n                       greater<pair<int, T>>>\n \
    \           que;\n        vector<T> dist(n, INF);\n        dist[s] = 0;\n    \
    \    que.push(make_pair(0, s));\n        while(!que.empty()) {\n            pair<int,\
    \ T> p = que.top();\n            que.pop();\n            int v = p.second;\n \
    \           if(dist[v] < p.first)\n                continue;\n            for(auto\
    \ e : g[v]) {\n                if(d[e.to] > dist[v] + e.cost) {\n            \
    \        d[e.to] = dist[v] + e.cost;\n                    que.push(make_pair(dist[e.to],\
    \ e.to));\n                }\n            }\n        }\n        for(int i = 0;\
    \ i < n; i++)\n            if(dist[i] == INF)\n                dist[i] = -1;\n\
    \    }\n\n    pair<bool, vector<T>> bellman_ford(int s) {\n        int n = g.size();\n\
    \        vector<ll> dist(n, INF);\n        bool negative_cycle = false;\n    \
    \    dist[s] = 0;\n        for(int i = 0; i < n; i++) {\n            for(int v\
    \ = 0; v < n; v++) {\n                for(auto e : g[v]) {\n                 \
    \   if(dist[v] != INF && dist[e.to] > dist[v] + e.cost) {\n                  \
    \      dist[e.to] = dist[v] + e.cost;\n                        if(i == n - 1)\
    \ {\n                            dist[e.to] = -INF;\n                        \
    \    negative_cycle = true;\n                        }\n                    }\n\
    \                }\n            }\n        }\n        return {negative_cycle,\
    \ dist};\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Graph.cc
  requiredBy: []
  timestamp: '2021-05-22 20:11:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Graph.cc
layout: document
redirect_from:
- /library/Graph/Graph.cc
- /library/Graph/Graph.cc.html
title: Graph/Graph.cc
---
