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
  bundledCode: "#line 1 \"DataStructure/LazySegmentTree.cc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class S, class F> class LazySegTree {\n  private:\n\
    \    using Op = function<S(S, S)>;\n    using Mapping = function<S(S, F)>;\n \
    \   using Composition = function<F(F, F)>;\n\n    int n;\n    int org_size;\n\
    \    const Op op;\n    const Mapping mapping;\n    const Composition composition;\n\
    \    const S e;\n    const F oe;\n    vector<S> node;\n    vector<F> lazy;\n\n\
    \    // \u30CE\u30FC\u30C9\u306E\u8A55\u4FA1\n    inline S eval(int k) const {\
    \ return mapping(node[k], lazy[k]); }\n\n    // \u5B50\u306B\u4F1D\u64AD\n   \
    \ inline void propagate(int k) {\n        lazy[2 * k] = composition(lazy[2 * k],\
    \ lazy[k]);\n        lazy[2 * k + 1] = composition(lazy[2 * k + 1], lazy[k]);\n\
    \        node[k] = eval(k);\n        lazy[k] = oe;\n    }\n\n    // \u4E0A\u304B\
    \u3089\u4F1D\u64AD\n    inline void thrust(int k) {\n        for(int i = 31 -\
    \ __builtin_clz(k); i > 0; i--) {\n            if((k >> i) >= 1)\n           \
    \     propagate(k >> i);\n        }\n    }\n\n    // \u4E0B\u304B\u3089\u518D\u8A08\
    \u7B97\n    inline void recalc(int k) {\n        while(k > 1) {\n            k\
    \ >>= 1;\n            node[k] = op(eval(2 * k), eval(2 * k + 1));\n        }\n\
    \    }\n\n  public:\n    void set(int k, const S &x) { node[k + n] = x; }\n\n\
    \    void build() {\n        for(int i = n - 1; i > 0; i--)\n            node[i]\
    \ = op(node[2 * i], node[2 * i + 1]);\n    }\n\n    // [L,R)\u533A\u9593\u4F5C\
    \u7528\n    void update(int L, int R, F x) {\n        L += n, R += n;\n      \
    \  int L0 = L / (L & -L), R0 = R / (R & -R) - 1;\n        thrust(L0);\n      \
    \  thrust(R0);\n        while(L < R) {\n            if(L & 1) {\n            \
    \    lazy[L] = composition(lazy[L], x);\n                L++;\n            }\n\
    \            if(R & 1) {\n                R--;\n                lazy[R] = composition(lazy[R],\
    \ x);\n            }\n            L >>= 1;\n            R >>= 1;\n        }\n\
    \        recalc(L0);\n        recalc(R0);\n    }\n\n    // [L,R)\u533A\u9593\u53D6\
    \u5F97\n    S query(int L, int R) {\n        L += n, R += n;\n        thrust(L\
    \ / (L & -L));\n        thrust(R / (R & -R) - 1);\n        S vl = e, vr = e;\n\
    \        while(L < R) {\n            if(L & 1) {\n                vl = op(vl,\
    \ eval(L));\n                L++;\n            }\n            if(R & 1) {\n  \
    \              R--;\n                vr = op(eval(R), vr);\n            }\n  \
    \          L >>= 1;\n            R >>= 1;\n        }\n        return op(vl, vr);\n\
    \    }\n\n    S at(int k) const { return query(k, k + 1); };\n\n    // !!\u672A\
    verify!!\n    int max_right(int l, function<bool(S)> f) const {\n        if(l\
    \ == org_size)\n            return org_size;\n        l += n;\n        thrust(l\
    \ / (l & -l));\n        S cum = e;\n        do {\n            while(l % 2 == 0)\n\
    \                l >>= 1;\n            if(!f(op(cum, dat[l]))) {\n           \
    \     while(l < n) {\n                    l = 2 * l;\n                    if(f(op(cum,\
    \ dat[l]))) {\n                        cum = op(cum, dat[l]);\n              \
    \          l++;\n                    }\n                }\n                return\
    \ l - n;\n            }\n            cum = op(cum, dat[l]);\n            l++;\n\
    \        } while((l & -l) != l);\n        return org_size;\n    }\n\n    // !!\u672A\
    verify!!\n    int min_left(int r, function<bool(S)> f) const {\n        if(r ==\
    \ 0)\n            return 0;\n        r += n;\n        thrust(r / (r & -r) - 1);\n\
    \        S cum = e;\n        do {\n            r--;\n            while(r > 1 &&\
    \ (r % 2))\n                r >>= 1;\n            if(!f(op(dat[r], cum))) {\n\
    \                while(r < n) {\n                    r = 2 * r + 1;\n        \
    \            if(f(op(dat[r], cum))) {\n                        cum = op(dat[r],\
    \ cum);\n                        r--;\n                    }\n               \
    \ }\n                return r + 1 - n;\n            }\n            cum = op(dat[r],\
    \ cum);\n        } while((r & (-r) != r));\n        return 0;\n    }\n\n    LazySegTree(int\
    \ sz, const Op op, const Mapping mapping,\n                const Composition composition,\
    \ const S &e, const F &oe)\n        : op(op), mapping(mapping), composition(composition),\
    \ e(e), oe(oe) {\n        org_size = sz;\n        n = 1;\n        while(n < org_size)\
    \ {\n            n <<= 1;\n        }\n        node.resize(2 * n, e);\n       \
    \ lazy.resize(2 * n, oe);\n    }\n    LazySegTree(const vector<S> &v, const Op\
    \ op, const Mapping mapping,\n                const Composition composition, const\
    \ S &e, const F &oe)\n        : op(op), mapping(mapping), composition(composition),\
    \ e(e), oe(oe) {\n        org_size = v.size();\n        n = 1;\n        while(n\
    \ < org_size) {\n            n <<= 1;\n        }\n        node.resize(2 * n, e);\n\
    \        lazy.resize(2 * n, oe);\n        for(int i = 0; i < org_size; i++)\n\
    \            set(i, v[i]);\n        build();\n    }\n};\n\nstruct S {};\nstruct\
    \ F {};\nS op(S a, S b){};\nS mapping(S a, F f){};\nF composition(F f, F g){};\n\
    S e() {}\nF id() {}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class S, class\
    \ F> class LazySegTree {\n  private:\n    using Op = function<S(S, S)>;\n    using\
    \ Mapping = function<S(S, F)>;\n    using Composition = function<F(F, F)>;\n\n\
    \    int n;\n    int org_size;\n    const Op op;\n    const Mapping mapping;\n\
    \    const Composition composition;\n    const S e;\n    const F oe;\n    vector<S>\
    \ node;\n    vector<F> lazy;\n\n    // \u30CE\u30FC\u30C9\u306E\u8A55\u4FA1\n\
    \    inline S eval(int k) const { return mapping(node[k], lazy[k]); }\n\n    //\
    \ \u5B50\u306B\u4F1D\u64AD\n    inline void propagate(int k) {\n        lazy[2\
    \ * k] = composition(lazy[2 * k], lazy[k]);\n        lazy[2 * k + 1] = composition(lazy[2\
    \ * k + 1], lazy[k]);\n        node[k] = eval(k);\n        lazy[k] = oe;\n   \
    \ }\n\n    // \u4E0A\u304B\u3089\u4F1D\u64AD\n    inline void thrust(int k) {\n\
    \        for(int i = 31 - __builtin_clz(k); i > 0; i--) {\n            if((k >>\
    \ i) >= 1)\n                propagate(k >> i);\n        }\n    }\n\n    // \u4E0B\
    \u304B\u3089\u518D\u8A08\u7B97\n    inline void recalc(int k) {\n        while(k\
    \ > 1) {\n            k >>= 1;\n            node[k] = op(eval(2 * k), eval(2 *\
    \ k + 1));\n        }\n    }\n\n  public:\n    void set(int k, const S &x) { node[k\
    \ + n] = x; }\n\n    void build() {\n        for(int i = n - 1; i > 0; i--)\n\
    \            node[i] = op(node[2 * i], node[2 * i + 1]);\n    }\n\n    // [L,R)\u533A\
    \u9593\u4F5C\u7528\n    void update(int L, int R, F x) {\n        L += n, R +=\
    \ n;\n        int L0 = L / (L & -L), R0 = R / (R & -R) - 1;\n        thrust(L0);\n\
    \        thrust(R0);\n        while(L < R) {\n            if(L & 1) {\n      \
    \          lazy[L] = composition(lazy[L], x);\n                L++;\n        \
    \    }\n            if(R & 1) {\n                R--;\n                lazy[R]\
    \ = composition(lazy[R], x);\n            }\n            L >>= 1;\n          \
    \  R >>= 1;\n        }\n        recalc(L0);\n        recalc(R0);\n    }\n\n  \
    \  // [L,R)\u533A\u9593\u53D6\u5F97\n    S query(int L, int R) {\n        L +=\
    \ n, R += n;\n        thrust(L / (L & -L));\n        thrust(R / (R & -R) - 1);\n\
    \        S vl = e, vr = e;\n        while(L < R) {\n            if(L & 1) {\n\
    \                vl = op(vl, eval(L));\n                L++;\n            }\n\
    \            if(R & 1) {\n                R--;\n                vr = op(eval(R),\
    \ vr);\n            }\n            L >>= 1;\n            R >>= 1;\n        }\n\
    \        return op(vl, vr);\n    }\n\n    S at(int k) const { return query(k,\
    \ k + 1); };\n\n    // !!\u672Averify!!\n    int max_right(int l, function<bool(S)>\
    \ f) const {\n        if(l == org_size)\n            return org_size;\n      \
    \  l += n;\n        thrust(l / (l & -l));\n        S cum = e;\n        do {\n\
    \            while(l % 2 == 0)\n                l >>= 1;\n            if(!f(op(cum,\
    \ dat[l]))) {\n                while(l < n) {\n                    l = 2 * l;\n\
    \                    if(f(op(cum, dat[l]))) {\n                        cum = op(cum,\
    \ dat[l]);\n                        l++;\n                    }\n            \
    \    }\n                return l - n;\n            }\n            cum = op(cum,\
    \ dat[l]);\n            l++;\n        } while((l & -l) != l);\n        return\
    \ org_size;\n    }\n\n    // !!\u672Averify!!\n    int min_left(int r, function<bool(S)>\
    \ f) const {\n        if(r == 0)\n            return 0;\n        r += n;\n   \
    \     thrust(r / (r & -r) - 1);\n        S cum = e;\n        do {\n          \
    \  r--;\n            while(r > 1 && (r % 2))\n                r >>= 1;\n     \
    \       if(!f(op(dat[r], cum))) {\n                while(r < n) {\n          \
    \          r = 2 * r + 1;\n                    if(f(op(dat[r], cum))) {\n    \
    \                    cum = op(dat[r], cum);\n                        r--;\n  \
    \                  }\n                }\n                return r + 1 - n;\n \
    \           }\n            cum = op(dat[r], cum);\n        } while((r & (-r) !=\
    \ r));\n        return 0;\n    }\n\n    LazySegTree(int sz, const Op op, const\
    \ Mapping mapping,\n                const Composition composition, const S &e,\
    \ const F &oe)\n        : op(op), mapping(mapping), composition(composition),\
    \ e(e), oe(oe) {\n        org_size = sz;\n        n = 1;\n        while(n < org_size)\
    \ {\n            n <<= 1;\n        }\n        node.resize(2 * n, e);\n       \
    \ lazy.resize(2 * n, oe);\n    }\n    LazySegTree(const vector<S> &v, const Op\
    \ op, const Mapping mapping,\n                const Composition composition, const\
    \ S &e, const F &oe)\n        : op(op), mapping(mapping), composition(composition),\
    \ e(e), oe(oe) {\n        org_size = v.size();\n        n = 1;\n        while(n\
    \ < org_size) {\n            n <<= 1;\n        }\n        node.resize(2 * n, e);\n\
    \        lazy.resize(2 * n, oe);\n        for(int i = 0; i < org_size; i++)\n\
    \            set(i, v[i]);\n        build();\n    }\n};\n\nstruct S {};\nstruct\
    \ F {};\nS op(S a, S b){};\nS mapping(S a, F f){};\nF composition(F f, F g){};\n\
    S e() {}\nF id() {}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/LazySegmentTree.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/LazySegmentTree.cc
layout: document
redirect_from:
- /library/DataStructure/LazySegmentTree.cc
- /library/DataStructure/LazySegmentTree.cc.html
title: DataStructure/LazySegmentTree.cc
---
