---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://algo-logic.info/lca/
  bundledCode: "#line 1 \"Graph/LowestCommonAncestor.cc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n/*\n    LCA\u3092\u6C42\u3081\u308B\u69CB\u9020\u4F53\n\
    \    \u53C2\u8003:https://algo-logic.info/lca/\n    \u521D\u671F\u5316:O(NlogN)\n\
    \    \u30AF\u30A8\u30EA:O(logN)\n*/\nstruct LowestCommonAncestor {\n    vector<vector<int>>\
    \ parent; // parent[k][v]:= v\u306E2^k\u89AA\u306E\u9802\u70B9\n    vector<int>\
    \ dist;           // root\u304B\u3089\u306E\u8DDD\u96E2\n    LowestCommonAncestor(const\
    \ vector<vector<int>> &G, int root = 0) {\n        init(G, root);\n    }\n\n \
    \   void init(const vector<vector<int>> &G, int root = 0) {\n        int N = G.size();\n\
    \        int K = 1;\n        while((1 << K) < N)\n            K++;\n        parent.assign(K,\
    \ vector<int>(N, -1));\n        dist.assign(N, -1);\n        dfs(root, -1, 0,\
    \ G);\n        //\u30C0\u30D6\u30EA\u30F3\u30B0\n        for(int k = 0; k + 1\
    \ < K; k++) {\n            for(int v = 0; v < N; v++) {\n                if(parent[k][v]\
    \ < 0) {\n                    parent[k + 1][v] = -1;\n                } else {\n\
    \                    parent[k + 1][v] = parent[k][parent[k][v]];\n           \
    \     }\n            }\n        }\n    }\n\n    // \u6839\u304B\u3089\u306E\u8DDD\
    \u96E2\u3068\u4E00\u3064\u89AA\u3092\u6C42\u3081\u308B\n    void dfs(int v, int\
    \ p, int d, const vector<vector<int>> &G) {\n        parent[0][v] = p;\n     \
    \   dist[v] = d;\n        for(auto nv : G[v]) {\n            if(nv != p)\n   \
    \             dfs(nv, v, d + 1, G);\n        }\n    }\n\n    // u\u3068v\u306E\
    LCA\u3092\u6C42\u3081\u308B\n    int query(int u, int v) {\n        if(dist[u]\
    \ < dist[v])\n            swap(u, v);\n        int K = parent.size();\n      \
    \  for(int k = 0; k < K; k++) {\n            if((dist[u] - dist[v]) & (1 << k))\
    \ {\n                u = parent[k][u];\n            }\n        }\n\n        if(u\
    \ == v)\n            return u;\n        // \u4E8C\u5206\u63A2\u7D22\n        for(int\
    \ k = K - 1; k >= 0; k--) {\n            if(parent[k][u] != parent[k][v]) {\n\
    \                u = parent[k][u];\n                v = parent[k][v];\n      \
    \      }\n        }\n        return parent[0][u];\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n/*\n    LCA\u3092\u6C42\u3081\
    \u308B\u69CB\u9020\u4F53\n    \u53C2\u8003:https://algo-logic.info/lca/\n    \u521D\
    \u671F\u5316:O(NlogN)\n    \u30AF\u30A8\u30EA:O(logN)\n*/\nstruct LowestCommonAncestor\
    \ {\n    vector<vector<int>> parent; // parent[k][v]:= v\u306E2^k\u89AA\u306E\u9802\
    \u70B9\n    vector<int> dist;           // root\u304B\u3089\u306E\u8DDD\u96E2\n\
    \    LowestCommonAncestor(const vector<vector<int>> &G, int root = 0) {\n    \
    \    init(G, root);\n    }\n\n    void init(const vector<vector<int>> &G, int\
    \ root = 0) {\n        int N = G.size();\n        int K = 1;\n        while((1\
    \ << K) < N)\n            K++;\n        parent.assign(K, vector<int>(N, -1));\n\
    \        dist.assign(N, -1);\n        dfs(root, -1, 0, G);\n        //\u30C0\u30D6\
    \u30EA\u30F3\u30B0\n        for(int k = 0; k + 1 < K; k++) {\n            for(int\
    \ v = 0; v < N; v++) {\n                if(parent[k][v] < 0) {\n             \
    \       parent[k + 1][v] = -1;\n                } else {\n                   \
    \ parent[k + 1][v] = parent[k][parent[k][v]];\n                }\n           \
    \ }\n        }\n    }\n\n    // \u6839\u304B\u3089\u306E\u8DDD\u96E2\u3068\u4E00\
    \u3064\u89AA\u3092\u6C42\u3081\u308B\n    void dfs(int v, int p, int d, const\
    \ vector<vector<int>> &G) {\n        parent[0][v] = p;\n        dist[v] = d;\n\
    \        for(auto nv : G[v]) {\n            if(nv != p)\n                dfs(nv,\
    \ v, d + 1, G);\n        }\n    }\n\n    // u\u3068v\u306ELCA\u3092\u6C42\u3081\
    \u308B\n    int query(int u, int v) {\n        if(dist[u] < dist[v])\n       \
    \     swap(u, v);\n        int K = parent.size();\n        for(int k = 0; k <\
    \ K; k++) {\n            if((dist[u] - dist[v]) & (1 << k)) {\n              \
    \  u = parent[k][u];\n            }\n        }\n\n        if(u == v)\n       \
    \     return u;\n        // \u4E8C\u5206\u63A2\u7D22\n        for(int k = K -\
    \ 1; k >= 0; k--) {\n            if(parent[k][u] != parent[k][v]) {\n        \
    \        u = parent[k][u];\n                v = parent[k][v];\n            }\n\
    \        }\n        return parent[0][u];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/LowestCommonAncestor.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/LowestCommonAncestor.cc
layout: document
redirect_from:
- /library/Graph/LowestCommonAncestor.cc
- /library/Graph/LowestCommonAncestor.cc.html
title: Graph/LowestCommonAncestor.cc
---
