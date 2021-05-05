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
  bundledCode: "#line 1 \"Graph/HLDecomposition.cc\"\n#include <bits/stdc++.h>\n\n\
    class HLDecomposition {\n  private:\n    std::vector<std::vector<int>> g; // \u30B0\
    \u30E9\u30D5\uFF08\u6728\uFF09\n    int t;\n    std::vector<int> sz;  // \u3082\
    \u3068\u306E\u6728\u306E\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\n    std::vector<int>\
    \ par; // \u3082\u3068\u306E\u6728\u3067\u306E\u89AA\n    std::vector<int>\n \
    \       idx; // v\u306E\u65B0\u305F\u306Aidx(\u884C\u304D\u304C\u3051\u9806) segtree\u7B49\
    \u306B\u4E57\u305B\u305F\u3068\u304D\u306Eidx\u306B\u5BFE\u5FDC\n    std::vector<int>\
    \ head; // \u9023\u7D50\u6210\u5206\u306E\u3046\u3061\u6700\u3082idx\u304C\u82E5\
    \u3044(\u6D45\u3044)\u9802\u70B9\n    std::vector<int> depth; // \u3082\u3068\u306E\
    \u6728\u3067\u306E\u6DF1\u3055\n\n  public:\n    HLDecomposition(std::vector<std::vector<int>>\
    \ &g, int root = 0)\n        : g(g), sz(g.size()), par(g.size()), idx(g.size()),\
    \ head(g.size()),\n          depth(g.size()), t(0) {\n        dfs_sz(root, 0,\
    \ -1);\n        dfs_hld(root, -1, 0);\n    }\n\n    int dfs_sz(int v, int d, int\
    \ p) {\n        par[v] = p;\n        if(sz[v] != 0)\n            return sz[v];\n\
    \        sz[v] = 1;\n        depth[v] = d;\n        for(auto nv : g[v]) {\n  \
    \          if(p == nv)\n                continue;\n            sz[v] += dfs_sz(nv,\
    \ d + 1, v);\n        }\n        return sz[v];\n    }\n\n    void dfs_hld(int\
    \ v, int p, int h) {\n        idx[v] = t++;\n        head[v] = h;\n        if(par[v]\
    \ != -1 && g[v].size() == 1)\n            return;\n        int m = 0;\n      \
    \  int nxt = -1;\n        for(auto nv : g[v]) {\n            if(nv == p)\n   \
    \             continue;\n            if(sz[nv] > m) {\n                m = sz[nv];\n\
    \                nxt = nv;\n            }\n        }\n        dfs_hld(nxt, v,\
    \ h);\n        for(auto nv : g[v]) {\n            if(p == nv)\n              \
    \  continue;\n            if(nv != nxt)\n                dfs_hld(nv, v, nv);\n\
    \        }\n    }\n\n    std::vector<std::pair<int, int>> query(int u, int v,\
    \ bool is_edge = false) {\n        std::vector<std::pair<int, int>> ret;\n   \
    \     while(head[u] != head[v]) {\n            if(depth[head[u]] <= depth[head[v]])\
    \ {\n                ret.push_back({idx[head[v]], idx[v]});\n                v\
    \ = par[head[v]];\n            } else {\n                ret.push_back({idx[head[u]],\
    \ idx[u]});\n                u = par[head[u]];\n            }\n        }\n   \
    \     if(!(is_edge && idx[u] == idx[v]))\n            ret.push_back(\n       \
    \         {std::min(idx[u], idx[v]) + is_edge, std::max(idx[u], idx[v])});\n \
    \       return ret;\n    }\n\n    template <typename S, typename Query, typename\
    \ Function>\n    S query(int u, int v, const S &e, const Query &q, const Function\
    \ &f,\n            bool is_edge = false) {\n        S l = e, r = e;\n        for(;;\
    \ v = par[head[v]]) {\n            if(idx[u] > idx[v]) {\n                std::swap(u,\
    \ v), std::swap(l, r);\n            }\n            if(head[v] == head[u])\n  \
    \              break;\n            l = f(q(idx[head[v]], idx[v] + 1), l);\n  \
    \      }\n        return f(f(q(idx[u] + is_edge, idx[v] + 1), l), r);\n    }\n\
    \n    int lca(int u, int v) {\n        for(;; v = par[head[v]]) {\n          \
    \  if(idx[u] > idx[v])\n                std::swap(u, v);\n            if(head[u]\
    \ == head[v])\n                return u;\n        }\n    }\n\n    int get_idx(int\
    \ v) { return idx[v]; }\n    int get_depth(int v) { return depth[v]; }\n    int\
    \ get_size(int v) { return sz[v]; }\n};\n"
  code: "#include <bits/stdc++.h>\n\nclass HLDecomposition {\n  private:\n    std::vector<std::vector<int>>\
    \ g; // \u30B0\u30E9\u30D5\uFF08\u6728\uFF09\n    int t;\n    std::vector<int>\
    \ sz;  // \u3082\u3068\u306E\u6728\u306E\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\
    \n    std::vector<int> par; // \u3082\u3068\u306E\u6728\u3067\u306E\u89AA\n  \
    \  std::vector<int>\n        idx; // v\u306E\u65B0\u305F\u306Aidx(\u884C\u304D\
    \u304C\u3051\u9806) segtree\u7B49\u306B\u4E57\u305B\u305F\u3068\u304D\u306Eidx\u306B\
    \u5BFE\u5FDC\n    std::vector<int> head; // \u9023\u7D50\u6210\u5206\u306E\u3046\
    \u3061\u6700\u3082idx\u304C\u82E5\u3044(\u6D45\u3044)\u9802\u70B9\n    std::vector<int>\
    \ depth; // \u3082\u3068\u306E\u6728\u3067\u306E\u6DF1\u3055\n\n  public:\n  \
    \  HLDecomposition(std::vector<std::vector<int>> &g, int root = 0)\n        :\
    \ g(g), sz(g.size()), par(g.size()), idx(g.size()), head(g.size()),\n        \
    \  depth(g.size()), t(0) {\n        dfs_sz(root, 0, -1);\n        dfs_hld(root,\
    \ -1, 0);\n    }\n\n    int dfs_sz(int v, int d, int p) {\n        par[v] = p;\n\
    \        if(sz[v] != 0)\n            return sz[v];\n        sz[v] = 1;\n     \
    \   depth[v] = d;\n        for(auto nv : g[v]) {\n            if(p == nv)\n  \
    \              continue;\n            sz[v] += dfs_sz(nv, d + 1, v);\n       \
    \ }\n        return sz[v];\n    }\n\n    void dfs_hld(int v, int p, int h) {\n\
    \        idx[v] = t++;\n        head[v] = h;\n        if(par[v] != -1 && g[v].size()\
    \ == 1)\n            return;\n        int m = 0;\n        int nxt = -1;\n    \
    \    for(auto nv : g[v]) {\n            if(nv == p)\n                continue;\n\
    \            if(sz[nv] > m) {\n                m = sz[nv];\n                nxt\
    \ = nv;\n            }\n        }\n        dfs_hld(nxt, v, h);\n        for(auto\
    \ nv : g[v]) {\n            if(p == nv)\n                continue;\n         \
    \   if(nv != nxt)\n                dfs_hld(nv, v, nv);\n        }\n    }\n\n \
    \   std::vector<std::pair<int, int>> query(int u, int v, bool is_edge = false)\
    \ {\n        std::vector<std::pair<int, int>> ret;\n        while(head[u] != head[v])\
    \ {\n            if(depth[head[u]] <= depth[head[v]]) {\n                ret.push_back({idx[head[v]],\
    \ idx[v]});\n                v = par[head[v]];\n            } else {\n       \
    \         ret.push_back({idx[head[u]], idx[u]});\n                u = par[head[u]];\n\
    \            }\n        }\n        if(!(is_edge && idx[u] == idx[v]))\n      \
    \      ret.push_back(\n                {std::min(idx[u], idx[v]) + is_edge, std::max(idx[u],\
    \ idx[v])});\n        return ret;\n    }\n\n    template <typename S, typename\
    \ Query, typename Function>\n    S query(int u, int v, const S &e, const Query\
    \ &q, const Function &f,\n            bool is_edge = false) {\n        S l = e,\
    \ r = e;\n        for(;; v = par[head[v]]) {\n            if(idx[u] > idx[v])\
    \ {\n                std::swap(u, v), std::swap(l, r);\n            }\n      \
    \      if(head[v] == head[u])\n                break;\n            l = f(q(idx[head[v]],\
    \ idx[v] + 1), l);\n        }\n        return f(f(q(idx[u] + is_edge, idx[v] +\
    \ 1), l), r);\n    }\n\n    int lca(int u, int v) {\n        for(;; v = par[head[v]])\
    \ {\n            if(idx[u] > idx[v])\n                std::swap(u, v);\n     \
    \       if(head[u] == head[v])\n                return u;\n        }\n    }\n\n\
    \    int get_idx(int v) { return idx[v]; }\n    int get_depth(int v) { return\
    \ depth[v]; }\n    int get_size(int v) { return sz[v]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/HLDecomposition.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/HLDecomposition.cc
layout: document
redirect_from:
- /library/Graph/HLDecomposition.cc
- /library/Graph/HLDecomposition.cc.html
title: Graph/HLDecomposition.cc
---
