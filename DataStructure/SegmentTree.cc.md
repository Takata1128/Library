---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/staticrmq.test.cpp
    title: verify/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SegmentTree.cc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\ntemplate <class S> struct SegmentTree {\n  private:\n  \
    \  using Op = function<S(S, S)>;\n    const Op op;\n    const S e;\n    int n;\n\
    \    int org_size;\n    vector<S> dat;\n\n  public:\n    void set(int k, S a)\
    \ { dat[k + n] = a; }\n\n    void build() {\n        for(int i = n - 1; i > 0;\
    \ i--) {\n            dat[i] = op(dat[2 * i], dat[2 * i + 1]);\n        }\n  \
    \  }\n\n    void update(int k, const S &a) {\n        k += n;\n        dat[k]\
    \ = a;\n        while(k >>= 1) {\n            dat[k] = op(dat[k * 2], dat[k *\
    \ 2 + 1]);\n        }\n    }\n\n    S at(int a) const { return query(a, a + 1);\
    \ }\n\n    // query for [a,b)\n    S query(int a, int b) const {\n        S vl\
    \ = e, vr = e;\n        a += n, b += n;\n        for(; a < b; a >>= 1, b >>= 1)\
    \ {\n            if(a & 1)\n                vl = op(vl, dat[a++]);\n         \
    \   if(b & 1)\n                vr = op(dat[--b], vr);\n        }\n        return\
    \ op(vl, vr);\n    }\n\n    int max_right(int l, function<bool(S)> f) const {\n\
    \        if(l == org_size)\n            return org_size;\n        l += n;\n  \
    \      S cum = e;\n        do {\n            while(l % 2 == 0)\n             \
    \   l >>= 1;\n            if(!f(op(cum, dat[l]))) {\n                while(l <\
    \ n) {\n                    l = 2 * l;\n                    if(f(op(cum, dat[l])))\
    \ {\n                        cum = op(cum, dat[l]);\n                        l++;\n\
    \                    }\n                }\n                return l - n;\n   \
    \         }\n            cum = op(cum, dat[l]);\n            l++;\n        } while((l\
    \ & -l) != l);\n        return org_size;\n    }\n\n    // !!\u672Averify!!\n \
    \   int min_left(int r, function<bool(S)> f) const {\n        if(r == 0)\n   \
    \         return 0;\n        r += n;\n        S cum = e;\n        do {\n     \
    \       r--;\n            while(r > 1 && (r % 2))\n                r >>= 1;\n\
    \            if(!f(op(dat[r], cum))) {\n                while(r < n) {\n     \
    \               r = 2 * r + 1;\n                    if(f(op(dat[r], cum))) {\n\
    \                        cum = op(dat[r], cum);\n                        r--;\n\
    \                    }\n                }\n                return r + 1 - n;\n\
    \            }\n            cum = op(dat[r], cum);\n        } while((r & (-r)\
    \ != r));\n        return 0;\n    }\n\n    SegmentTree(int _n, const Op op, const\
    \ S &e) : op(op), e(e) {\n        org_size = _n;\n        n = 1;\n        while(n\
    \ < org_size)\n            n *= 2;\n        dat.assign(2 * n, e);\n    }\n\n \
    \   SegmentTree(const vector<S> &v, const Op op, const S &e) : op(op), e(e) {\n\
    \        org_size = v.size();\n        n = 1;\n        while(n < org_size)\n \
    \           n *= 2;\n        dat.assign(2 * n, e);\n        for(int i = 0; i <\
    \ org_size; i++)\n            set(i, v[i]);\n        build();\n    }\n};\n\n//\
    \ struct S {};\n// S op(const S &a, const S &b){};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\ntemplate <class S> struct\
    \ SegmentTree {\n  private:\n    using Op = function<S(S, S)>;\n    const Op op;\n\
    \    const S e;\n    int n;\n    int org_size;\n    vector<S> dat;\n\n  public:\n\
    \    void set(int k, S a) { dat[k + n] = a; }\n\n    void build() {\n        for(int\
    \ i = n - 1; i > 0; i--) {\n            dat[i] = op(dat[2 * i], dat[2 * i + 1]);\n\
    \        }\n    }\n\n    void update(int k, const S &a) {\n        k += n;\n \
    \       dat[k] = a;\n        while(k >>= 1) {\n            dat[k] = op(dat[k *\
    \ 2], dat[k * 2 + 1]);\n        }\n    }\n\n    S at(int a) const { return query(a,\
    \ a + 1); }\n\n    // query for [a,b)\n    S query(int a, int b) const {\n   \
    \     S vl = e, vr = e;\n        a += n, b += n;\n        for(; a < b; a >>= 1,\
    \ b >>= 1) {\n            if(a & 1)\n                vl = op(vl, dat[a++]);\n\
    \            if(b & 1)\n                vr = op(dat[--b], vr);\n        }\n  \
    \      return op(vl, vr);\n    }\n\n    int max_right(int l, function<bool(S)>\
    \ f) const {\n        if(l == org_size)\n            return org_size;\n      \
    \  l += n;\n        S cum = e;\n        do {\n            while(l % 2 == 0)\n\
    \                l >>= 1;\n            if(!f(op(cum, dat[l]))) {\n           \
    \     while(l < n) {\n                    l = 2 * l;\n                    if(f(op(cum,\
    \ dat[l]))) {\n                        cum = op(cum, dat[l]);\n              \
    \          l++;\n                    }\n                }\n                return\
    \ l - n;\n            }\n            cum = op(cum, dat[l]);\n            l++;\n\
    \        } while((l & -l) != l);\n        return org_size;\n    }\n\n    // !!\u672A\
    verify!!\n    int min_left(int r, function<bool(S)> f) const {\n        if(r ==\
    \ 0)\n            return 0;\n        r += n;\n        S cum = e;\n        do {\n\
    \            r--;\n            while(r > 1 && (r % 2))\n                r >>=\
    \ 1;\n            if(!f(op(dat[r], cum))) {\n                while(r < n) {\n\
    \                    r = 2 * r + 1;\n                    if(f(op(dat[r], cum)))\
    \ {\n                        cum = op(dat[r], cum);\n                        r--;\n\
    \                    }\n                }\n                return r + 1 - n;\n\
    \            }\n            cum = op(dat[r], cum);\n        } while((r & (-r)\
    \ != r));\n        return 0;\n    }\n\n    SegmentTree(int _n, const Op op, const\
    \ S &e) : op(op), e(e) {\n        org_size = _n;\n        n = 1;\n        while(n\
    \ < org_size)\n            n *= 2;\n        dat.assign(2 * n, e);\n    }\n\n \
    \   SegmentTree(const vector<S> &v, const Op op, const S &e) : op(op), e(e) {\n\
    \        org_size = v.size();\n        n = 1;\n        while(n < org_size)\n \
    \           n *= 2;\n        dat.assign(2 * n, e);\n        for(int i = 0; i <\
    \ org_size; i++)\n            set(i, v[i]);\n        build();\n    }\n};\n\n//\
    \ struct S {};\n// S op(const S &a, const S &b){};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.cc
  requiredBy: []
  timestamp: '2021-07-10 17:10:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/staticrmq.test.cpp
documentation_of: DataStructure/SegmentTree.cc
layout: document
redirect_from:
- /library/DataStructure/SegmentTree.cc
- /library/DataStructure/SegmentTree.cc.html
title: DataStructure/SegmentTree.cc
---
