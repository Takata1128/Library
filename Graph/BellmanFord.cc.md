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
  bundledCode: "#line 1 \"Graph/BellmanFord.cc\"\n#include <vector>\r\nusing namespace\
    \ std;\r\n\r\n/***\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5***/\r\
    \nconst int INF = 1 << 30;\r\nbool bellman_ford(int s, vector<vector<pair<int,\
    \ long long>>> const &g,\r\n                  vector<long long> &dist) {\r\n \
    \   int n = g.size();\r\n    vector<long long> dist(n, INF);\r\n    bool negative_cycle\
    \ = false;\r\n    dist[s] = 0;\r\n    for(int i = 0; i < n; i++) {\r\n       \
    \ for(int v = 0; v < n; v++) {\r\n            for(auto e : g[v]) {\r\n       \
    \         if(dist[v] != INF && dist[e.first] > dist[v] + e.second) {\r\n     \
    \               dist[e.first] = dist[v] + e.second;\r\n                    if(i\
    \ == n - 1) {\r\n                        dist[e.first] = -INF;\r\n           \
    \             negative_cycle = true;\r\n                    }\r\n            \
    \    }\r\n            }\r\n        }\r\n    }\r\n    return negative_cycle;\r\n\
    }\n"
  code: "#include <vector>\r\nusing namespace std;\r\n\r\n/***\u30D9\u30EB\u30DE\u30F3\
    \u30D5\u30A9\u30FC\u30C9\u6CD5***/\r\nconst int INF = 1 << 30;\r\nbool bellman_ford(int\
    \ s, vector<vector<pair<int, long long>>> const &g,\r\n                  vector<long\
    \ long> &dist) {\r\n    int n = g.size();\r\n    vector<long long> dist(n, INF);\r\
    \n    bool negative_cycle = false;\r\n    dist[s] = 0;\r\n    for(int i = 0; i\
    \ < n; i++) {\r\n        for(int v = 0; v < n; v++) {\r\n            for(auto\
    \ e : g[v]) {\r\n                if(dist[v] != INF && dist[e.first] > dist[v]\
    \ + e.second) {\r\n                    dist[e.first] = dist[v] + e.second;\r\n\
    \                    if(i == n - 1) {\r\n                        dist[e.first]\
    \ = -INF;\r\n                        negative_cycle = true;\r\n              \
    \      }\r\n                }\r\n            }\r\n        }\r\n    }\r\n    return\
    \ negative_cycle;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BellmanFord.cc
  requiredBy: []
  timestamp: '2021-07-10 17:10:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/BellmanFord.cc
layout: document
redirect_from:
- /library/Graph/BellmanFord.cc
- /library/Graph/BellmanFord.cc.html
title: Graph/BellmanFord.cc
---
