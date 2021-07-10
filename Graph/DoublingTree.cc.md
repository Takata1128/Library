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
  bundledCode: "#line 1 \"Graph/DoublingTree.cc\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class Graph> class DoublingTree {\n    using T =\
    \ decltype(Graph::Edge::cost);\n    vector<vector<int>> parent; // parent[k][v]:=\
    \ v\u306E2^k\u89AA\u306E\u9802\u70B9\n    vector<T> dis;              // root\u304B\
    \u3089\u306E\u8DDD\u96E2\n    void init(const Graph &G, int root = 0) {\n    \
    \    int N = G.size();\n        int K = 1;\n        while((1 << K) < N)\n    \
    \        K++;\n        parent.assign(K, vector<int>(N, -1));\n        dis.assign(N,\
    \ -1);\n        dfs(root, -1, 0, G);\n        //\u30C0\u30D6\u30EA\u30F3\u30B0\
    \n        for(int k = 0; k + 1 < K; k++) {\n            for(int v = 0; v < N;\
    \ v++) {\n                if(parent[k][v] < 0) {\n                    parent[k\
    \ + 1][v] = -1;\n                } else {\n                    parent[k + 1][v]\
    \ = parent[k][parent[k][v]];\n                }\n            }\n        }\n  \
    \  }\n\n    // \u6839\u304B\u3089\u306E\u8DDD\u96E2\u3068\u4E00\u3064\u89AA\u3092\
    \u6C42\u3081\u308B\n    void dfs(int v, int p, int d, const Graph &G) {\n    \
    \    parent[0][v] = p;\n        dis[v] = d;\n        for(auto e : G[v]) {\n  \
    \          if(e.to != p)\n                dfs(e.to, v, d + e.cost, G);\n     \
    \   }\n    }\n\n  public:\n    DoublingTree(const Graph &G, int root = 0) {\n\
    \        init(G, root);\n    }\n\n    // u\u3068v\u306ELCA\u3092\u6C42\u3081\u308B\
    \n    int query(int u, int v) {\n        if(dis[u] < dis[v])\n            swap(u,\
    \ v);\n        int K = parent.size();\n        for(int k = 0; k < K; k++) {\n\
    \            if((dis[u] - dis[v]) & (1 << k)) {\n                u = parent[k][u];\n\
    \            }\n        }\n\n        if(u == v)\n            return u;\n     \
    \   // \u4E8C\u5206\u63A2\u7D22\n        for(int k = K - 1; k >= 0; k--) {\n \
    \           if(parent[k][u] != parent[k][v]) {\n                u = parent[k][u];\n\
    \                v = parent[k][v];\n            }\n        }\n        return parent[0][u];\n\
    \    }\n\n    // u\u3068v\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B\n    T dist(int\
    \ u, int v) {\n        return dis[u] + dis[v] - dis[query(u, v)] * 2;\n    }\n\
    };\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class Graph>\
    \ class DoublingTree {\n    using T = decltype(Graph::Edge::cost);\n    vector<vector<int>>\
    \ parent; // parent[k][v]:= v\u306E2^k\u89AA\u306E\u9802\u70B9\n    vector<T>\
    \ dis;              // root\u304B\u3089\u306E\u8DDD\u96E2\n    void init(const\
    \ Graph &G, int root = 0) {\n        int N = G.size();\n        int K = 1;\n \
    \       while((1 << K) < N)\n            K++;\n        parent.assign(K, vector<int>(N,\
    \ -1));\n        dis.assign(N, -1);\n        dfs(root, -1, 0, G);\n        //\u30C0\
    \u30D6\u30EA\u30F3\u30B0\n        for(int k = 0; k + 1 < K; k++) {\n         \
    \   for(int v = 0; v < N; v++) {\n                if(parent[k][v] < 0) {\n   \
    \                 parent[k + 1][v] = -1;\n                } else {\n         \
    \           parent[k + 1][v] = parent[k][parent[k][v]];\n                }\n \
    \           }\n        }\n    }\n\n    // \u6839\u304B\u3089\u306E\u8DDD\u96E2\
    \u3068\u4E00\u3064\u89AA\u3092\u6C42\u3081\u308B\n    void dfs(int v, int p, int\
    \ d, const Graph &G) {\n        parent[0][v] = p;\n        dis[v] = d;\n     \
    \   for(auto e : G[v]) {\n            if(e.to != p)\n                dfs(e.to,\
    \ v, d + e.cost, G);\n        }\n    }\n\n  public:\n    DoublingTree(const Graph\
    \ &G, int root = 0) {\n        init(G, root);\n    }\n\n    // u\u3068v\u306E\
    LCA\u3092\u6C42\u3081\u308B\n    int query(int u, int v) {\n        if(dis[u]\
    \ < dis[v])\n            swap(u, v);\n        int K = parent.size();\n       \
    \ for(int k = 0; k < K; k++) {\n            if((dis[u] - dis[v]) & (1 << k)) {\n\
    \                u = parent[k][u];\n            }\n        }\n\n        if(u ==\
    \ v)\n            return u;\n        // \u4E8C\u5206\u63A2\u7D22\n        for(int\
    \ k = K - 1; k >= 0; k--) {\n            if(parent[k][u] != parent[k][v]) {\n\
    \                u = parent[k][u];\n                v = parent[k][v];\n      \
    \      }\n        }\n        return parent[0][u];\n    }\n\n    // u\u3068v\u306E\
    \u8DDD\u96E2\u3092\u6C42\u3081\u308B\n    T dist(int u, int v) {\n        return\
    \ dis[u] + dis[v] - dis[query(u, v)] * 2;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/DoublingTree.cc
  requiredBy: []
  timestamp: '2021-07-10 17:10:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/DoublingTree.cc
layout: document
redirect_from:
- /library/Graph/DoublingTree.cc
- /library/Graph/DoublingTree.cc.html
title: Graph/DoublingTree.cc
---
