---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unionfind.test.cpp
    title: verify/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/UnionFind.cc\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\n// UnionFind\r\nstruct UnionFind {\r\n    vector<int>\
    \ par;\r\n    vector<int> siz;\r\n\r\n    UnionFind(int N) : par(N), siz(N, 1)\
    \ {\r\n        for(int i = 0; i < N; i++)\r\n            par[i] = i;\r\n    }\r\
    \n    int root(int x) {\r\n        if(par[x] == x)\r\n            return x;\r\n\
    \        return par[x] = root(par[x]);\r\n    }\r\n    void unite(int x, int y)\
    \ {\r\n        int rx = root(x);\r\n        int ry = root(y);\r\n        if(rx\
    \ == ry)\r\n            return;\r\n        if(siz[rx] < siz[ry])\r\n         \
    \   swap(rx, ry);\r\n        siz[rx] += siz[ry];\r\n        par[ry] = rx;\r\n\
    \    }\r\n    bool same(int x, int y) {\r\n        int rx = root(x);\r\n     \
    \   int ry = root(y);\r\n        return rx == ry;\r\n    }\r\n    int size(int\
    \ x) { return siz[root(x)]; }\r\n};\r\n\r\n//\u3000\u91CD\u307F\u4ED8\u304DUnionFind\r\
    \ntemplate <typename T> struct WeightedUnionFind {\r\n    vector<int> par;\r\n\
    \    vector<int> siz;\r\n    vector<T> diff_weight;\r\n\r\n    WeightedUnionFind(int\
    \ N) : par(N), siz(N, 1), diff_weight(N, T(0)) {\r\n        for(int i = 0; i <\
    \ N; i++) {\r\n            par[i] = i;\r\n        }\r\n    }\r\n\r\n    T weight(int\
    \ x) {\r\n        root(x);\r\n        return diff_weight[x];\r\n    }\r\n\r\n\
    \    T diff(int x, int y) { return weight(y) - weight(x); }\r\n\r\n    int root(int\
    \ x) {\r\n        if(par[x] == x)\r\n            return x;\r\n        else {\r\
    \n            int r = root(par[x]);\r\n            diff_weight[x] += diff_weight[par[x]];\r\
    \n            return par[x] = r;\r\n        }\r\n    }\r\n    void unite(int x,\
    \ int y, T w) {\r\n        w += weight(x), w -= weight(y);\r\n        int rx =\
    \ root(x);\r\n        int ry = root(y);\r\n        if(rx == ry)\r\n          \
    \  return;\r\n        if(siz[rx] < siz[ry])\r\n            swap(rx, ry), w = -w;\r\
    \n        siz[rx] += siz[ry];\r\n        par[ry] = rx;\r\n        diff_weight[ry]\
    \ = w;\r\n    }\r\n    bool same(int x, int y) {\r\n        int rx = root(x);\r\
    \n        int ry = root(y);\r\n        return rx == ry;\r\n    }\r\n    int size(int\
    \ x) { return siz[root(x)]; }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n// UnionFind\r\n\
    struct UnionFind {\r\n    vector<int> par;\r\n    vector<int> siz;\r\n\r\n   \
    \ UnionFind(int N) : par(N), siz(N, 1) {\r\n        for(int i = 0; i < N; i++)\r\
    \n            par[i] = i;\r\n    }\r\n    int root(int x) {\r\n        if(par[x]\
    \ == x)\r\n            return x;\r\n        return par[x] = root(par[x]);\r\n\
    \    }\r\n    void unite(int x, int y) {\r\n        int rx = root(x);\r\n    \
    \    int ry = root(y);\r\n        if(rx == ry)\r\n            return;\r\n    \
    \    if(siz[rx] < siz[ry])\r\n            swap(rx, ry);\r\n        siz[rx] +=\
    \ siz[ry];\r\n        par[ry] = rx;\r\n    }\r\n    bool same(int x, int y) {\r\
    \n        int rx = root(x);\r\n        int ry = root(y);\r\n        return rx\
    \ == ry;\r\n    }\r\n    int size(int x) { return siz[root(x)]; }\r\n};\r\n\r\n\
    //\u3000\u91CD\u307F\u4ED8\u304DUnionFind\r\ntemplate <typename T> struct WeightedUnionFind\
    \ {\r\n    vector<int> par;\r\n    vector<int> siz;\r\n    vector<T> diff_weight;\r\
    \n\r\n    WeightedUnionFind(int N) : par(N), siz(N, 1), diff_weight(N, T(0)) {\r\
    \n        for(int i = 0; i < N; i++) {\r\n            par[i] = i;\r\n        }\r\
    \n    }\r\n\r\n    T weight(int x) {\r\n        root(x);\r\n        return diff_weight[x];\r\
    \n    }\r\n\r\n    T diff(int x, int y) { return weight(y) - weight(x); }\r\n\r\
    \n    int root(int x) {\r\n        if(par[x] == x)\r\n            return x;\r\n\
    \        else {\r\n            int r = root(par[x]);\r\n            diff_weight[x]\
    \ += diff_weight[par[x]];\r\n            return par[x] = r;\r\n        }\r\n \
    \   }\r\n    void unite(int x, int y, T w) {\r\n        w += weight(x), w -= weight(y);\r\
    \n        int rx = root(x);\r\n        int ry = root(y);\r\n        if(rx == ry)\r\
    \n            return;\r\n        if(siz[rx] < siz[ry])\r\n            swap(rx,\
    \ ry), w = -w;\r\n        siz[rx] += siz[ry];\r\n        par[ry] = rx;\r\n   \
    \     diff_weight[ry] = w;\r\n    }\r\n    bool same(int x, int y) {\r\n     \
    \   int rx = root(x);\r\n        int ry = root(y);\r\n        return rx == ry;\r\
    \n    }\r\n    int size(int x) { return siz[root(x)]; }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unionfind.test.cpp
documentation_of: DataStructure/UnionFind.cc
layout: document
redirect_from:
- /library/DataStructure/UnionFind.cc
- /library/DataStructure/UnionFind.cc.html
title: DataStructure/UnionFind.cc
---
