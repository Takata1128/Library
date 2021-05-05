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
  bundledCode: "#line 1 \"Graph/Scc.cc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u3000O(|V|+|E|)\nclass\
    \ Scc {\n  public:\n    int N;\n    vector<vector<int>> G, rG;\n    vector<int>\
    \ vs;\n    vector<bool> used;\n    vector<int> cmp; // \u65B0\u30B0\u30E9\u30D5\
    \u306Eindex\n\n    Scc(vector<vector<int>> _G) : G(_G) {\n        N = G.size();\n\
    \        rG.resize(N, vector<int>());\n        for(int i = 0; i < G.size(); i++)\
    \ {\n            for(auto nv : G[i]) {\n                rG[nv].push_back(i);\n\
    \            }\n        }\n        used.resize(N);\n        cmp.resize(N);\n \
    \   }\n\n    void dfs(int v) {\n        used[v] = true;\n        for(auto nv :\
    \ G[v]) {\n            if(!used[nv])\n                dfs(nv);\n        }\n  \
    \      vs.push_back(v);\n    }\n\n    void rdfs(int v, int k) {\n        used[v]\
    \ = true;\n        cmp[v] = k;\n        for(auto nv : rG[v]) {\n            if(!used[nv])\n\
    \                rdfs(nv, k);\n        }\n    }\n\n    int process() {\n     \
    \   fill(used.begin(), used.end(), false);\n        for(int v = 0; v < N; v++)\
    \ {\n            if(!used[v])\n                dfs(v);\n        }\n        fill(used.begin(),\
    \ used.end(), false);\n        int k = 0;\n        for(int i = N - 1; i >= 0;\
    \ i--) {\n            if(!used[vs[i]])\n                rdfs(vs[i], k++);\n  \
    \      }\n        return k;\n    }\n\n    vector<vector<int>> get() {\n      \
    \  vector<vector<int>> g(N, vector<int>());\n        for(int i = 0; i < N; i++)\
    \ {\n            for(auto nv : G[i]) {\n                if(cmp[i] == cmp[nv])\n\
    \                    continue;\n                g[cmp[i]].push_back(cmp[nv]);\n\
    \            }\n        }\n        return g;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// \u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\u3000O(|V|+|E|)\nclass Scc {\n  public:\n    int N;\n    vector<vector<int>>\
    \ G, rG;\n    vector<int> vs;\n    vector<bool> used;\n    vector<int> cmp; //\
    \ \u65B0\u30B0\u30E9\u30D5\u306Eindex\n\n    Scc(vector<vector<int>> _G) : G(_G)\
    \ {\n        N = G.size();\n        rG.resize(N, vector<int>());\n        for(int\
    \ i = 0; i < G.size(); i++) {\n            for(auto nv : G[i]) {\n           \
    \     rG[nv].push_back(i);\n            }\n        }\n        used.resize(N);\n\
    \        cmp.resize(N);\n    }\n\n    void dfs(int v) {\n        used[v] = true;\n\
    \        for(auto nv : G[v]) {\n            if(!used[nv])\n                dfs(nv);\n\
    \        }\n        vs.push_back(v);\n    }\n\n    void rdfs(int v, int k) {\n\
    \        used[v] = true;\n        cmp[v] = k;\n        for(auto nv : rG[v]) {\n\
    \            if(!used[nv])\n                rdfs(nv, k);\n        }\n    }\n\n\
    \    int process() {\n        fill(used.begin(), used.end(), false);\n       \
    \ for(int v = 0; v < N; v++) {\n            if(!used[v])\n                dfs(v);\n\
    \        }\n        fill(used.begin(), used.end(), false);\n        int k = 0;\n\
    \        for(int i = N - 1; i >= 0; i--) {\n            if(!used[vs[i]])\n   \
    \             rdfs(vs[i], k++);\n        }\n        return k;\n    }\n\n    vector<vector<int>>\
    \ get() {\n        vector<vector<int>> g(N, vector<int>());\n        for(int i\
    \ = 0; i < N; i++) {\n            for(auto nv : G[i]) {\n                if(cmp[i]\
    \ == cmp[nv])\n                    continue;\n                g[cmp[i]].push_back(cmp[nv]);\n\
    \            }\n        }\n        return g;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Scc.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Scc.cc
layout: document
redirect_from:
- /library/Graph/Scc.cc
- /library/Graph/Scc.cc.html
title: Graph/Scc.cc
---
