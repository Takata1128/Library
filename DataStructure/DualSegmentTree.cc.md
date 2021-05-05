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
  bundledCode: "#line 1 \"DataStructure/DualSegmentTree.cc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n/*** DualSegmentTree ***/\ntemplate <class F> class DualSegTree\
    \ {\n  private:\n    using Composition = function<F(F, F)>;\n\n    size_t n;\n\
    \    const Composition composition;\n    const F oe;\n    vector<F> lazy;\n\n\
    \    // \u5B50\u306B\u4F1D\u64AD\n    inline void propagate(int k) {\n       \
    \ if(lazy[k] != oe) {\n            lazy[2 * k] = composition(lazy[2 * k], lazy[k]);\n\
    \            lazy[2 * k + 1] = composition(lazy[2 * k + 1], lazy[k]);\n      \
    \      lazy[k] = oe;\n        }\n    }\n\n    // \u4E0A\u304B\u3089\u4F1D\u64AD\
    \n    inline void thrust(int k) {\n        for(int i = 31 - __builtin_clz(k);\
    \ i > 0; i--) {\n            if((k >> i) >= 1)\n                propagate(k >>\
    \ i);\n        }\n    }\n\n  public:\n    DualSegTree(int sz, const Composition\
    \ _h, const F &_oe)\n        : composition(_h), oe(_oe) {\n        n = 1;\n  \
    \      while(n < sz) {\n            n <<= 1;\n        }\n        lazy.resize(2\
    \ * n, oe);\n    }\n\n    DualSegTree(const vector<F> &v, const Composition _h,\
    \ const F &_oe)\n        : composition(_h), oe(_oe) {\n        int sz = v.size();\n\
    \        n = 1;\n        while(n < sz) {\n            n <<= 1;\n        }\n  \
    \      lazy.resize(2 * n, oe);\n        for(int i = 0; i < sz; i++)\n        \
    \    set(i, v[i]);\n    }\n\n    void set(int k, const F &x) {\n        k += n;\n\
    \        thrust(k);\n        lazy[k] = x;\n    }\n\n    // [L,R)\u533A\u9593\u4F5C\
    \u7528\n    void update(int L, int R, const F &x) {\n        L += n, R += n;\n\
    \        int L0 = L / (L & -L), R0 = R / (R & -R) - 1;\n        thrust(L0);\n\
    \        thrust(R0);\n        while(L < R) {\n            if(L & 1) {\n      \
    \          lazy[L] = composition(x, lazy[L]);\n                L++;\n        \
    \    }\n            if(R & 1) {\n                R--;\n                lazy[R]\
    \ = composition(lazy[R], x);\n            }\n            L >>= 1;\n          \
    \  R >>= 1;\n        }\n    }\n\n    // \u4E00\u70B9\u53D6\u5F97\n    F at(int\
    \ k) {\n        k += n;\n        thrust(k);\n        return lazy[k];\n    }\n\n\
    \    F operator[](int k) { return at(k); }\n};\n\nstruct F {};\nF composition(F\
    \ f, F g){};\nF id() {}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n/*** DualSegmentTree ***/\n\
    template <class F> class DualSegTree {\n  private:\n    using Composition = function<F(F,\
    \ F)>;\n\n    size_t n;\n    const Composition composition;\n    const F oe;\n\
    \    vector<F> lazy;\n\n    // \u5B50\u306B\u4F1D\u64AD\n    inline void propagate(int\
    \ k) {\n        if(lazy[k] != oe) {\n            lazy[2 * k] = composition(lazy[2\
    \ * k], lazy[k]);\n            lazy[2 * k + 1] = composition(lazy[2 * k + 1],\
    \ lazy[k]);\n            lazy[k] = oe;\n        }\n    }\n\n    // \u4E0A\u304B\
    \u3089\u4F1D\u64AD\n    inline void thrust(int k) {\n        for(int i = 31 -\
    \ __builtin_clz(k); i > 0; i--) {\n            if((k >> i) >= 1)\n           \
    \     propagate(k >> i);\n        }\n    }\n\n  public:\n    DualSegTree(int sz,\
    \ const Composition _h, const F &_oe)\n        : composition(_h), oe(_oe) {\n\
    \        n = 1;\n        while(n < sz) {\n            n <<= 1;\n        }\n  \
    \      lazy.resize(2 * n, oe);\n    }\n\n    DualSegTree(const vector<F> &v, const\
    \ Composition _h, const F &_oe)\n        : composition(_h), oe(_oe) {\n      \
    \  int sz = v.size();\n        n = 1;\n        while(n < sz) {\n            n\
    \ <<= 1;\n        }\n        lazy.resize(2 * n, oe);\n        for(int i = 0; i\
    \ < sz; i++)\n            set(i, v[i]);\n    }\n\n    void set(int k, const F\
    \ &x) {\n        k += n;\n        thrust(k);\n        lazy[k] = x;\n    }\n\n\
    \    // [L,R)\u533A\u9593\u4F5C\u7528\n    void update(int L, int R, const F &x)\
    \ {\n        L += n, R += n;\n        int L0 = L / (L & -L), R0 = R / (R & -R)\
    \ - 1;\n        thrust(L0);\n        thrust(R0);\n        while(L < R) {\n   \
    \         if(L & 1) {\n                lazy[L] = composition(x, lazy[L]);\n  \
    \              L++;\n            }\n            if(R & 1) {\n                R--;\n\
    \                lazy[R] = composition(lazy[R], x);\n            }\n         \
    \   L >>= 1;\n            R >>= 1;\n        }\n    }\n\n    // \u4E00\u70B9\u53D6\
    \u5F97\n    F at(int k) {\n        k += n;\n        thrust(k);\n        return\
    \ lazy[k];\n    }\n\n    F operator[](int k) { return at(k); }\n};\n\nstruct F\
    \ {};\nF composition(F f, F g){};\nF id() {}"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DualSegmentTree.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/DualSegmentTree.cc
layout: document
redirect_from:
- /library/DataStructure/DualSegmentTree.cc
- /library/DataStructure/DualSegmentTree.cc.html
title: DataStructure/DualSegmentTree.cc
---
