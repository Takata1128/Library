---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/convolution_mod.test.cpp
    title: verify/convolution_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: cc
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Convolution.cc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\ntemplate <typename Mint> class Convolution {\n\
    \  private:\n    constexpr int primroot(int p) {\n        if(p == 2)\n       \
    \     return 1;\n        if(p == 167772161)\n            return 3;\n        if(p\
    \ == 469762049)\n            return 3;\n        if(p == 754974721)\n         \
    \   return 11;\n        if(p == 998244353)\n            return 3;\n        assert(false);\n\
    \    }\n\n  public:\n    void _ntt(vector<Mint> &a, bool is_inverse) {\n     \
    \   const int n = a.size();\n        const int mod = Mint::get_mod();\n      \
    \  const int g = primroot(mod);\n        assert((n ^ (n & -n)) == 0);\n      \
    \  Mint h = Mint(g).pow((mod - 1) / n);\n        h = (is_inverse ? h.inv() : h);\n\
    \n        int i = 0;\n        for(int j = 1; j < n - 1; j++) {\n            for(int\
    \ k = n >> 1; k > (i ^= k); k >>= 1)\n                ;\n            if(j < i)\n\
    \                swap(a[i], a[j]);\n        }\n\n        for(int m = 1; m < n;\
    \ m *= 2) {\n            const int m2 = 2 * m;\n            const Mint base =\
    \ h.pow(n / m2);\n            Mint w = 1;\n            for(int x = 0; x < m; x++)\
    \ {\n                for(int s = x; s < n; s += m2) {\n                    Mint\
    \ u = a[s];\n                    Mint d = a[s + m] * w;\n                    a[s]\
    \ = u + d;\n                    a[s + m] = u - d;\n                }\n       \
    \         w *= base;\n            }\n        }\n    }\n\n    void ntt(vector<Mint>\
    \ &a) { _ntt(a, false); }\n    void intt(vector<Mint> &a) {\n        _ntt(a, true);\n\
    \        int n = a.size();\n        Mint n_inv = Mint(n).inv();\n        for(auto\
    \ &x : a)\n            x *= n_inv;\n    }\n\n    vector<Mint> convolution(const\
    \ vector<Mint> &_a, const vector<Mint> &_b) {\n        vector<Mint> a(_a), b(_b);\n\
    \        int s = a.size() + b.size();\n        int t = 1;\n        while(t < s)\n\
    \            t *= 2;\n        a.resize(t);\n        b.resize(t);\n\n        ntt(a);\n\
    \        ntt(b);\n        for(int i = 0; i < t; i++) {\n            a[i] *= b[i];\n\
    \        }\n        intt(a);\n        return a;\n    }\n\n    template <typename\
    \ T>\n    vector<Mint> convolution(const vector<T> &_a, const vector<T> &_b) {\n\
    \        vector<Mint> a(_a.size()), b(_b.size());\n        for(int i = 0; i <\
    \ a.size(); i++)\n            a[i] = _a[i];\n        for(int i = 0; i < b.size();\
    \ i++)\n            b[i] = _b[i];\n        return convolution(a, b);\n    }\n\
    };\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    template <typename Mint> class Convolution {\n  private:\n    constexpr int primroot(int\
    \ p) {\n        if(p == 2)\n            return 1;\n        if(p == 167772161)\n\
    \            return 3;\n        if(p == 469762049)\n            return 3;\n  \
    \      if(p == 754974721)\n            return 11;\n        if(p == 998244353)\n\
    \            return 3;\n        assert(false);\n    }\n\n  public:\n    void _ntt(vector<Mint>\
    \ &a, bool is_inverse) {\n        const int n = a.size();\n        const int mod\
    \ = Mint::get_mod();\n        const int g = primroot(mod);\n        assert((n\
    \ ^ (n & -n)) == 0);\n        Mint h = Mint(g).pow((mod - 1) / n);\n        h\
    \ = (is_inverse ? h.inv() : h);\n\n        int i = 0;\n        for(int j = 1;\
    \ j < n - 1; j++) {\n            for(int k = n >> 1; k > (i ^= k); k >>= 1)\n\
    \                ;\n            if(j < i)\n                swap(a[i], a[j]);\n\
    \        }\n\n        for(int m = 1; m < n; m *= 2) {\n            const int m2\
    \ = 2 * m;\n            const Mint base = h.pow(n / m2);\n            Mint w =\
    \ 1;\n            for(int x = 0; x < m; x++) {\n                for(int s = x;\
    \ s < n; s += m2) {\n                    Mint u = a[s];\n                    Mint\
    \ d = a[s + m] * w;\n                    a[s] = u + d;\n                    a[s\
    \ + m] = u - d;\n                }\n                w *= base;\n            }\n\
    \        }\n    }\n\n    void ntt(vector<Mint> &a) { _ntt(a, false); }\n    void\
    \ intt(vector<Mint> &a) {\n        _ntt(a, true);\n        int n = a.size();\n\
    \        Mint n_inv = Mint(n).inv();\n        for(auto &x : a)\n            x\
    \ *= n_inv;\n    }\n\n    vector<Mint> convolution(const vector<Mint> &_a, const\
    \ vector<Mint> &_b) {\n        vector<Mint> a(_a), b(_b);\n        int s = a.size()\
    \ + b.size();\n        int t = 1;\n        while(t < s)\n            t *= 2;\n\
    \        a.resize(t);\n        b.resize(t);\n\n        ntt(a);\n        ntt(b);\n\
    \        for(int i = 0; i < t; i++) {\n            a[i] *= b[i];\n        }\n\
    \        intt(a);\n        return a;\n    }\n\n    template <typename T>\n   \
    \ vector<Mint> convolution(const vector<T> &_a, const vector<T> &_b) {\n     \
    \   vector<Mint> a(_a.size()), b(_b.size());\n        for(int i = 0; i < a.size();\
    \ i++)\n            a[i] = _a[i];\n        for(int i = 0; i < b.size(); i++)\n\
    \            b[i] = _b[i];\n        return convolution(a, b);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Convolution.cc
  requiredBy: []
  timestamp: '2021-05-05 19:28:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/convolution_mod.test.cpp
documentation_of: Math/Convolution.cc
layout: document
redirect_from:
- /library/Math/Convolution.cc
- /library/Math/Convolution.cc.html
title: Math/Convolution.cc
---
