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
  bundledCode: "#line 1 \"Graph/TreeDiamiter.cc\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll = long long;\n\ntemplate <typename T> struct edge {\n\
    \    int to;\n    T cost;\n};\n\nusing Graph = vector<vector<edge<ll>>>;\n\ntemplate\
    \ <typename T> pair<T, int> dfs(int v, int p, const Graph &G) {\n    auto ret\
    \ = MP((T)0, v);\n    for(auto e : G[v]) {\n        if(e.to == p)\n          \
    \  continue;\n        auto next = dfs<T>(e.to, v, G);\n        next.first += e.cost;\n\
    \        ret = max(ret, next);\n    }\n    return ret;\n}\n\ntemplate <typename\
    \ T> T tree_diameter(const vector<vector<edge<T>>> &G) {\n    auto s = dfs<T>(0,\
    \ -1, G);\n    auto t = dfs<T>(s.second, -1, G);\n    return t.first;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    template <typename T> struct edge {\n    int to;\n    T cost;\n};\n\nusing Graph\
    \ = vector<vector<edge<ll>>>;\n\ntemplate <typename T> pair<T, int> dfs(int v,\
    \ int p, const Graph &G) {\n    auto ret = MP((T)0, v);\n    for(auto e : G[v])\
    \ {\n        if(e.to == p)\n            continue;\n        auto next = dfs<T>(e.to,\
    \ v, G);\n        next.first += e.cost;\n        ret = max(ret, next);\n    }\n\
    \    return ret;\n}\n\ntemplate <typename T> T tree_diameter(const vector<vector<edge<T>>>\
    \ &G) {\n    auto s = dfs<T>(0, -1, G);\n    auto t = dfs<T>(s.second, -1, G);\n\
    \    return t.first;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/TreeDiamiter.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/TreeDiamiter.cc
layout: document
redirect_from:
- /library/Graph/TreeDiamiter.cc
- /library/Graph/TreeDiamiter.cc.html
title: Graph/TreeDiamiter.cc
---
