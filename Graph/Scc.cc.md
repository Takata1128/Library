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
    \ std;\n\n// \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u3000O(|V|+|E|)\ntemplate\
    \ <class Graph> class Scc {\n  private:\n    int N;\n    Graph G, rG;\n    vector<int>\
    \ vs;\n    vector<bool> used;\n    vector<int> cmp; // \u65B0\u30B0\u30E9\u30D5\
    \u306Eindex\n    void dfs(int v) {\n        used[v] = true;\n        for(auto\
    \ e : G[v]) {\n            if(!used[e.to])\n                dfs(e.to);\n     \
    \   }\n        vs.push_back(v);\n    }\n    void rdfs(int v, int k) {\n      \
    \  used[v] = true;\n        cmp[v] = k;\n        for(auto e : rG[v]) {\n     \
    \       if(!used[e.to])\n                rdfs(e.to, k);\n        }\n    }\n  \
    \  int process() {\n        fill(used.begin(), used.end(), false);\n        for(int\
    \ v = 0; v < N; v++) {\n            if(!used[v])\n                dfs(v);\n  \
    \      }\n        fill(used.begin(), used.end(), false);\n        int k = 0;\n\
    \        for(int i = N - 1; i >= 0; i--) {\n            if(!used[vs[i]])\n   \
    \             rdfs(vs[i], k++);\n        }\n        return k;\n    }\n\n  public:\n\
    \    Scc(Graph _G) : G(_G) {\n        N = G.size();\n        rG.resize(N);\n \
    \       for(int i = 0; i < G.size(); i++) {\n            for(auto e : G[i]) {\n\
    \                rG.add_edge(e.to, i);\n            }\n        }\n        used.resize(N);\n\
    \        cmp.resize(N);\n        process();\n    }\n    vector<int> get_new_indice()\
    \ const {\n        return cmp;\n    }\n    vector<vector<int>> get_new_graph()\
    \ const {\n        vector<vector<int>> g(N, vector<int>());\n        for(int i\
    \ = 0; i < N; i++) {\n            for(auto e : G[i]) {\n                if(cmp[i]\
    \ == cmp[e.to])\n                    continue;\n                g[cmp[i]].push_back(cmp[e.to]);\n\
    \            }\n        }\n        return g;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// \u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\u3000O(|V|+|E|)\ntemplate <class Graph> class Scc {\n  private:\n\
    \    int N;\n    Graph G, rG;\n    vector<int> vs;\n    vector<bool> used;\n \
    \   vector<int> cmp; // \u65B0\u30B0\u30E9\u30D5\u306Eindex\n    void dfs(int\
    \ v) {\n        used[v] = true;\n        for(auto e : G[v]) {\n            if(!used[e.to])\n\
    \                dfs(e.to);\n        }\n        vs.push_back(v);\n    }\n    void\
    \ rdfs(int v, int k) {\n        used[v] = true;\n        cmp[v] = k;\n       \
    \ for(auto e : rG[v]) {\n            if(!used[e.to])\n                rdfs(e.to,\
    \ k);\n        }\n    }\n    int process() {\n        fill(used.begin(), used.end(),\
    \ false);\n        for(int v = 0; v < N; v++) {\n            if(!used[v])\n  \
    \              dfs(v);\n        }\n        fill(used.begin(), used.end(), false);\n\
    \        int k = 0;\n        for(int i = N - 1; i >= 0; i--) {\n            if(!used[vs[i]])\n\
    \                rdfs(vs[i], k++);\n        }\n        return k;\n    }\n\n  public:\n\
    \    Scc(Graph _G) : G(_G) {\n        N = G.size();\n        rG.resize(N);\n \
    \       for(int i = 0; i < G.size(); i++) {\n            for(auto e : G[i]) {\n\
    \                rG.add_edge(e.to, i);\n            }\n        }\n        used.resize(N);\n\
    \        cmp.resize(N);\n        process();\n    }\n    vector<int> get_new_indice()\
    \ const {\n        return cmp;\n    }\n    vector<vector<int>> get_new_graph()\
    \ const {\n        vector<vector<int>> g(N, vector<int>());\n        for(int i\
    \ = 0; i < N; i++) {\n            for(auto e : G[i]) {\n                if(cmp[i]\
    \ == cmp[e.to])\n                    continue;\n                g[cmp[i]].push_back(cmp[e.to]);\n\
    \            }\n        }\n        return g;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Scc.cc
  requiredBy: []
  timestamp: '2021-07-10 17:10:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Scc.cc
layout: document
redirect_from:
- /library/Graph/Scc.cc
- /library/Graph/Scc.cc.html
title: Graph/Scc.cc
---
