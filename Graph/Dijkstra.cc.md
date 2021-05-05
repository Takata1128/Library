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
  bundledCode: "#line 1 \"Graph/Dijkstra.cc\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\ntemplate <typename T> struct edge {\r\n    int to;\r\n    T cost;\r\
    \n    edge(int t, T c) : to(t), cost(c) {}\r\n};\r\n\r\ntemplate <typename T>\
    \ using Graph = vector<vector<edge<T>>>;\r\n\r\ntemplate <typename T, T INF> void\
    \ dijkstra(int s, vector<T> &d, Graph<T> &G) {\r\n    priority_queue<pair<int,\
    \ T>, vector<pair<int, T>>, greater<pair<int, T>>>\r\n        que;\r\n    fill(All(d),\
    \ INF);\r\n    d[s] = 0;\r\n    que.push(make_pair(0, s));\r\n    while(!que.empty())\
    \ {\r\n        pair<int, T> p = que.top();\r\n        que.pop();\r\n        int\
    \ v = p.second;\r\n        if(d[v] < p.first)\r\n            continue;\r\n   \
    \     for(auto e : G[v]) {\r\n            if(d[e.to] > d[v] + e.cost) {\r\n  \
    \              d[e.to] = d[v] + e.cost;\r\n                que.push(make_pair(d[e.to],\
    \ e.to));\r\n            }\r\n        }\r\n    }\r\n}\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\ntemplate <typename\
    \ T> struct edge {\r\n    int to;\r\n    T cost;\r\n    edge(int t, T c) : to(t),\
    \ cost(c) {}\r\n};\r\n\r\ntemplate <typename T> using Graph = vector<vector<edge<T>>>;\r\
    \n\r\ntemplate <typename T, T INF> void dijkstra(int s, vector<T> &d, Graph<T>\
    \ &G) {\r\n    priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int,\
    \ T>>>\r\n        que;\r\n    fill(All(d), INF);\r\n    d[s] = 0;\r\n    que.push(make_pair(0,\
    \ s));\r\n    while(!que.empty()) {\r\n        pair<int, T> p = que.top();\r\n\
    \        que.pop();\r\n        int v = p.second;\r\n        if(d[v] < p.first)\r\
    \n            continue;\r\n        for(auto e : G[v]) {\r\n            if(d[e.to]\
    \ > d[v] + e.cost) {\r\n                d[e.to] = d[v] + e.cost;\r\n         \
    \       que.push(make_pair(d[e.to], e.to));\r\n            }\r\n        }\r\n\
    \    }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Dijkstra.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Dijkstra.cc
layout: document
redirect_from:
- /library/Graph/Dijkstra.cc
- /library/Graph/Dijkstra.cc.html
title: Graph/Dijkstra.cc
---
