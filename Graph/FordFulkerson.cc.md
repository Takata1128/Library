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
  bundledCode: "#line 1 \"Graph/FordFulkerson.cc\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\n// Ford-fulkerson maxFlow(O(F|E|),F:\u6700\u5927\u6D41\
    \u91CF)\r\n// \u3060\u3044\u305F\u3044\u2191\u306E\u8A08\u7B97\u91CF\u3088\u308A\
    \u5272\u3068\u65E9\u304F\u306A\u308B\u3089\u3057\u3044\r\nstruct Ford_fulkerson\
    \ {\r\n    const int INF = 1 << 30;\r\n    struct edge {\r\n        int to, cap,\
    \ rev;\r\n    };\r\n    int n;\r\n    vector<vector<edge>> graph;\r\n    vector<int>\
    \ vis;\r\n\r\n    Ford_fulkerson(int _n) : n(_n), graph(n), vis(n) {}\r\n\r\n\
    \    void addEdge(int from, int to, int cap) {\r\n        graph[from].push_back((edge){to,\
    \ cap, (int)graph[to].size()});\r\n        graph[to].push_back((edge){from, 0,\
    \ (int)graph[from].size() - 1});\r\n    }\r\n    int dfs(int v, int t, int f)\
    \ {\r\n        if(v == t)\r\n            return f;\r\n        vis[v] = true;\r\
    \n        for(int i = 0; i < (int)graph[v].size(); i++) {\r\n            edge\
    \ &e = graph[v][i];\r\n            if(!vis[e.to] && e.cap > 0) {\r\n         \
    \       int d = dfs(e.to, t, min(f, e.cap));\r\n                if(d > 0) {\r\n\
    \                    e.cap -= d;\r\n                    graph[e.to][e.rev].cap\
    \ += d;\r\n                    return d;\r\n                }\r\n            }\r\
    \n        }\r\n        return 0;\r\n    }\r\n\r\n    int maxFlow(int s, int t)\
    \ {\r\n        int flow = 0;\r\n        for(;;) {\r\n            for(int i = 0;\
    \ i < n; i++)\r\n                vis[i] = false;\r\n            int f = dfs(s,\
    \ t, INF);\r\n            if(f == 0)\r\n                return flow;\r\n     \
    \       flow += f;\r\n        }\r\n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n// Ford-fulkerson\
    \ maxFlow(O(F|E|),F:\u6700\u5927\u6D41\u91CF)\r\n// \u3060\u3044\u305F\u3044\u2191\
    \u306E\u8A08\u7B97\u91CF\u3088\u308A\u5272\u3068\u65E9\u304F\u306A\u308B\u3089\
    \u3057\u3044\r\nstruct Ford_fulkerson {\r\n    const int INF = 1 << 30;\r\n  \
    \  struct edge {\r\n        int to, cap, rev;\r\n    };\r\n    int n;\r\n    vector<vector<edge>>\
    \ graph;\r\n    vector<int> vis;\r\n\r\n    Ford_fulkerson(int _n) : n(_n), graph(n),\
    \ vis(n) {}\r\n\r\n    void addEdge(int from, int to, int cap) {\r\n        graph[from].push_back((edge){to,\
    \ cap, (int)graph[to].size()});\r\n        graph[to].push_back((edge){from, 0,\
    \ (int)graph[from].size() - 1});\r\n    }\r\n    int dfs(int v, int t, int f)\
    \ {\r\n        if(v == t)\r\n            return f;\r\n        vis[v] = true;\r\
    \n        for(int i = 0; i < (int)graph[v].size(); i++) {\r\n            edge\
    \ &e = graph[v][i];\r\n            if(!vis[e.to] && e.cap > 0) {\r\n         \
    \       int d = dfs(e.to, t, min(f, e.cap));\r\n                if(d > 0) {\r\n\
    \                    e.cap -= d;\r\n                    graph[e.to][e.rev].cap\
    \ += d;\r\n                    return d;\r\n                }\r\n            }\r\
    \n        }\r\n        return 0;\r\n    }\r\n\r\n    int maxFlow(int s, int t)\
    \ {\r\n        int flow = 0;\r\n        for(;;) {\r\n            for(int i = 0;\
    \ i < n; i++)\r\n                vis[i] = false;\r\n            int f = dfs(s,\
    \ t, INF);\r\n            if(f == 0)\r\n                return flow;\r\n     \
    \       flow += f;\r\n        }\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/FordFulkerson.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/FordFulkerson.cc
layout: document
redirect_from:
- /library/Graph/FordFulkerson.cc
- /library/Graph/FordFulkerson.cc.html
title: Graph/FordFulkerson.cc
---
