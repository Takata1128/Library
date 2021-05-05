---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: 0-indexed (Internally 1-indexed) Fenwick Tree
    links: []
  bundledCode: "#line 1 \"DataStructure/FenwickTree.cc\"\n#include <bits/stdc++.h>\n\
    \n/**\n * @brief 0-indexed (Internally 1-indexed) Fenwick Tree\n *\n * @tparam\
    \ T Universal set.\n */\ntemplate <typename T> struct FenwickTree {\n    int n;\n\
    \    std::vector<T> dat;\n\n    FenwickTree(int n) : n(++n), dat(n, 0) {}\n\n\
    \    void add(int i, T x) {\n        for(++i; i < n; i += i & -i)\n          \
    \  dat[i] = dat[i] + x;\n    }\n\n    /**\n     * @brief Sum values in [0,i]\n\
    \     *\n     * @param i Right end of interval. Note that closed-interval [0,i].\n\
    \     * @return T Summation values in [0,i].\n     */\n    T sum(int i) {\n  \
    \      T res = 0;\n        for(++i; i > 0; i -= i & -i) {\n            res = res\
    \ + dat[i];\n        }\n        return res;\n    }\n\n    /**\n     * @brief Sum\
    \ values in [l,r]\n     *\n     * @param l Left end of interval.\n     * @param\
    \ r Right end of interval.\n     * @return T Summation values in [l,r]\n     */\n\
    \    T sum(int l, int r) { return sum(r) - sum(l - 1); }\n\n    /**\n     * @brief\
    \ Sum all values.\n     *\n     * @return T Summation values.\n     */\n    T\
    \ sumAll() { return sum(n - 1); }\n\n    /**\n     * @brief If regard as histogram\
    \ of elements, get k-th element.\n     *\n     * @param k Get k-th element.\n\
    \     * @return int Index to which k-th element belongs.\n     */\n    int get(T\
    \ k) {\n        ++k;\n        int res = 0;\n        int N = 1;\n        while(N\
    \ < n)\n            N *= 2;\n        for(int i = N / 2; i > 0; i /= 2) {\n   \
    \         if(res + i < n && dat[res + i] < k) {\n                k = k - dat[res\
    \ + i];\n                res = res + i;\n            }\n        }\n        return\
    \ res + 1;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * @brief 0-indexed (Internally 1-indexed)\
    \ Fenwick Tree\n *\n * @tparam T Universal set.\n */\ntemplate <typename T> struct\
    \ FenwickTree {\n    int n;\n    std::vector<T> dat;\n\n    FenwickTree(int n)\
    \ : n(++n), dat(n, 0) {}\n\n    void add(int i, T x) {\n        for(++i; i < n;\
    \ i += i & -i)\n            dat[i] = dat[i] + x;\n    }\n\n    /**\n     * @brief\
    \ Sum values in [0,i]\n     *\n     * @param i Right end of interval. Note that\
    \ closed-interval [0,i].\n     * @return T Summation values in [0,i].\n     */\n\
    \    T sum(int i) {\n        T res = 0;\n        for(++i; i > 0; i -= i & -i)\
    \ {\n            res = res + dat[i];\n        }\n        return res;\n    }\n\n\
    \    /**\n     * @brief Sum values in [l,r]\n     *\n     * @param l Left end\
    \ of interval.\n     * @param r Right end of interval.\n     * @return T Summation\
    \ values in [l,r]\n     */\n    T sum(int l, int r) { return sum(r) - sum(l -\
    \ 1); }\n\n    /**\n     * @brief Sum all values.\n     *\n     * @return T Summation\
    \ values.\n     */\n    T sumAll() { return sum(n - 1); }\n\n    /**\n     * @brief\
    \ If regard as histogram of elements, get k-th element.\n     *\n     * @param\
    \ k Get k-th element.\n     * @return int Index to which k-th element belongs.\n\
    \     */\n    int get(T k) {\n        ++k;\n        int res = 0;\n        int\
    \ N = 1;\n        while(N < n)\n            N *= 2;\n        for(int i = N / 2;\
    \ i > 0; i /= 2) {\n            if(res + i < n && dat[res + i] < k) {\n      \
    \          k = k - dat[res + i];\n                res = res + i;\n           \
    \ }\n        }\n        return res + 1;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/FenwickTree.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/FenwickTree.cc
layout: document
redirect_from:
- /library/DataStructure/FenwickTree.cc
- /library/DataStructure/FenwickTree.cc.html
title: 0-indexed (Internally 1-indexed) Fenwick Tree
---
