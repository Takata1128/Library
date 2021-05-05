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
  bundledCode: "#line 1 \"Graph/TopologicalSort.cc\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n/*\n    \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
    \u3000O(V+E)\n    G: \u6709\u5411\u30B0\u30E9\u30D5\n    in: \u9802\u70B9\u306E\
    \u5165\u6B21\u6570\u3000\n*/\nvector<int> topological_sort(const vector<vector<int>>\
    \ &G, vector<int> in) {\n    vector<int> ret;\n    stack<int> st;\n    for(int\
    \ i = 0; i < in.size(); i++)\n        if(in[i] == 0)\n            st.push(i);\n\
    \    while(st.size()) {\n        int v = st.top();\n        st.pop();\n      \
    \  ret.push_back(v);\n        for(auto &nv : G[v]) {\n            in[nv]--;\n\
    \            if(in[nv] == 0)\n                st.push(nv);\n        }\n    }\n\
    \    return ret;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n/*\n    \u30C8\u30DD\u30ED\
    \u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3000O(V+E)\n    G: \u6709\u5411\u30B0\u30E9\
    \u30D5\n    in: \u9802\u70B9\u306E\u5165\u6B21\u6570\u3000\n*/\nvector<int> topological_sort(const\
    \ vector<vector<int>> &G, vector<int> in) {\n    vector<int> ret;\n    stack<int>\
    \ st;\n    for(int i = 0; i < in.size(); i++)\n        if(in[i] == 0)\n      \
    \      st.push(i);\n    while(st.size()) {\n        int v = st.top();\n      \
    \  st.pop();\n        ret.push_back(v);\n        for(auto &nv : G[v]) {\n    \
    \        in[nv]--;\n            if(in[nv] == 0)\n                st.push(nv);\n\
    \        }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/TopologicalSort.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/TopologicalSort.cc
layout: document
redirect_from:
- /library/Graph/TopologicalSort.cc
- /library/Graph/TopologicalSort.cc.html
title: Graph/TopologicalSort.cc
---
