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
  bundledCode: "#line 1 \"DataStructure/SegmentTree.cc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class S>\nstruct SegmentTree\n{\nprivate:\n\
    \    using Op = function<S(S, S)>;\n    const Op op;\n    const S e;\n    int\
    \ n;\n    int org_size;\n    vector<S> dat;\n\npublic:\n    void set(int k, S\
    \ a) { dat[k + n] = a; }\n\n    void build()\n    {\n        for (int i = n -\
    \ 1; i > 0; i--)\n        {\n            dat[i] = op(dat[2 * i], dat[2 * i + 1]);\n\
    \        }\n    }\n\n    void update(int k, const S &a)\n    {\n        k += n;\n\
    \        dat[k] = a;\n        while (k >>= 1)\n        {\n            dat[k] =\
    \ op(dat[k * 2], dat[k * 2 + 1]);\n        }\n    }\n\n    S at(int a) const {\
    \ return query(a, a + 1); }\n\n    // query for [a,b)\n    S query(int a, int\
    \ b) const\n    {\n        S vl = e, vr = e;\n        a += n, b += n;\n      \
    \  for (; a < b; a >>= 1, b >>= 1)\n        {\n            if (a & 1)\n      \
    \          vl = op(vl, dat[a++]);\n            if (b & 1)\n                vr\
    \ = op(dat[--b], vr);\n        }\n        return op(vl, vr);\n    }\n\n    int\
    \ max_right(int l, function<bool(S)> f) const\n    {\n        if (l == org_size)\n\
    \            return org_size;\n        l += n;\n        S cum = e;\n        do\n\
    \        {\n            while (l % 2 == 0)\n                l >>= 1;\n       \
    \     if (!f(op(cum, dat[l])))\n            {\n                while (l < n)\n\
    \                {\n                    l = 2 * l;\n                    if (f(op(cum,\
    \ dat[l])))\n                    {\n                        cum = op(cum, dat[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - n;\n            }\n            cum = op(cum, dat[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return org_size;\n\
    \    }\n\n    // !!\u672Averify!!\n    int min_left(int r, function<bool(S)> f)\
    \ const\n    {\n        if (r == 0)\n            return 0;\n        r += n;\n\
    \        S cum = e;\n        do\n        {\n            r--;\n            while\
    \ (r > 1 && (r % 2))\n                r >>= 1;\n            if (!f(op(dat[r],\
    \ cum)))\n            {\n                while (r < n)\n                {\n  \
    \                  r = 2 * r + 1;\n                    if (f(op(dat[r], cum)))\n\
    \                    {\n                        cum = op(dat[r], cum);\n     \
    \                   r--;\n                    }\n                }\n         \
    \       return r + 1 - n;\n            }\n            cum = op(dat[r], cum);\n\
    \        } while ((r & (-r) != r));\n        return 0;\n    }\n\n    SegmentTree(int\
    \ _n, const Op op, const S &e) : op(op), e(e)\n    {\n        org_size = _n;\n\
    \        n = 1;\n        while (n < org_size)\n            n *= 2;\n        dat.assign(2\
    \ * n, e);\n    }\n\n    SegmentTree(const vector<S> &v, const Op op, const S\
    \ &e) : op(op), e(e)\n    {\n        org_size = v.size();\n        n = 1;\n  \
    \      while (n < org_size)\n            n *= 2;\n        dat.resize(2 * n);\n\
    \        for (int i = 0; i < org_size; i++)\n            set(i, v[i]);\n     \
    \   build();\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class S>\nstruct\
    \ SegmentTree\n{\nprivate:\n    using Op = function<S(S, S)>;\n    const Op op;\n\
    \    const S e;\n    int n;\n    int org_size;\n    vector<S> dat;\n\npublic:\n\
    \    void set(int k, S a) { dat[k + n] = a; }\n\n    void build()\n    {\n   \
    \     for (int i = n - 1; i > 0; i--)\n        {\n            dat[i] = op(dat[2\
    \ * i], dat[2 * i + 1]);\n        }\n    }\n\n    void update(int k, const S &a)\n\
    \    {\n        k += n;\n        dat[k] = a;\n        while (k >>= 1)\n      \
    \  {\n            dat[k] = op(dat[k * 2], dat[k * 2 + 1]);\n        }\n    }\n\
    \n    S at(int a) const { return query(a, a + 1); }\n\n    // query for [a,b)\n\
    \    S query(int a, int b) const\n    {\n        S vl = e, vr = e;\n        a\
    \ += n, b += n;\n        for (; a < b; a >>= 1, b >>= 1)\n        {\n        \
    \    if (a & 1)\n                vl = op(vl, dat[a++]);\n            if (b & 1)\n\
    \                vr = op(dat[--b], vr);\n        }\n        return op(vl, vr);\n\
    \    }\n\n    int max_right(int l, function<bool(S)> f) const\n    {\n       \
    \ if (l == org_size)\n            return org_size;\n        l += n;\n        S\
    \ cum = e;\n        do\n        {\n            while (l % 2 == 0)\n          \
    \      l >>= 1;\n            if (!f(op(cum, dat[l])))\n            {\n       \
    \         while (l < n)\n                {\n                    l = 2 * l;\n \
    \                   if (f(op(cum, dat[l])))\n                    {\n         \
    \               cum = op(cum, dat[l]);\n                        l++;\n       \
    \             }\n                }\n                return l - n;\n          \
    \  }\n            cum = op(cum, dat[l]);\n            l++;\n        } while ((l\
    \ & -l) != l);\n        return org_size;\n    }\n\n    // !!\u672Averify!!\n \
    \   int min_left(int r, function<bool(S)> f) const\n    {\n        if (r == 0)\n\
    \            return 0;\n        r += n;\n        S cum = e;\n        do\n    \
    \    {\n            r--;\n            while (r > 1 && (r % 2))\n             \
    \   r >>= 1;\n            if (!f(op(dat[r], cum)))\n            {\n          \
    \      while (r < n)\n                {\n                    r = 2 * r + 1;\n\
    \                    if (f(op(dat[r], cum)))\n                    {\n        \
    \                cum = op(dat[r], cum);\n                        r--;\n      \
    \              }\n                }\n                return r + 1 - n;\n     \
    \       }\n            cum = op(dat[r], cum);\n        } while ((r & (-r) != r));\n\
    \        return 0;\n    }\n\n    SegmentTree(int _n, const Op op, const S &e)\
    \ : op(op), e(e)\n    {\n        org_size = _n;\n        n = 1;\n        while\
    \ (n < org_size)\n            n *= 2;\n        dat.assign(2 * n, e);\n    }\n\n\
    \    SegmentTree(const vector<S> &v, const Op op, const S &e) : op(op), e(e)\n\
    \    {\n        org_size = v.size();\n        n = 1;\n        while (n < org_size)\n\
    \            n *= 2;\n        dat.resize(2 * n);\n        for (int i = 0; i <\
    \ org_size; i++)\n            set(i, v[i]);\n        build();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.cc
  requiredBy: []
  timestamp: '2021-05-05 18:59:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegmentTree.cc
layout: document
redirect_from:
- /library/DataStructure/SegmentTree.cc
- /library/DataStructure/SegmentTree.cc.html
title: DataStructure/SegmentTree.cc
---
