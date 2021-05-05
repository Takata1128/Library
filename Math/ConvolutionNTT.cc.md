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
  bundledCode: "#line 1 \"Math/ConvolutionNTT.cc\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll = long long;\n\ntemplate <int MOD = 998244353, int\
    \ primroot = 3> class ConvolutionNTT {\n  private:\n    vector<ll> a, b;\n   \
    \ ll modpow(ll v, ll n) {\n        ll x = 1, p = v;\n        while(n > 0) {\n\
    \            if(n % 2 == 0) {\n                p = (p * p) % MOD;\n          \
    \      n /= 2;\n            } else {\n                x = (x * p) % MOD;\n   \
    \             n--;\n            }\n        }\n        return x;\n    }\n    ll\
    \ modinv(ll v) { return modpow(v, MOD - 2); }\n\n  public:\n    ConvolutionNTT(vector<ll>\
    \ &_a, vector<ll> &_b) {\n        a = _a;\n        b = _b;\n    }\n\n    vector<ll>\
    \ ntt_rec(vector<ll> a, bool is_inverse = false) {\n        int n = a.size();\n\
    \        if(n == 1)\n            return a;\n        vector<ll> f0(n / 2), f1(n\
    \ / 2);\n        for(int i = 0; i < (n / 2); i++) {\n            f0[i] = (a[i\
    \ * 2]);\n            f1[i] = (a[i * 2 + 1]);\n        }\n        f0 = ntt_rec(f0,\
    \ is_inverse), f1 = ntt_rec(f1, is_inverse);\n        ll zeta = modpow(is_inverse\
    \ ? modinv(primroot) : primroot, MOD / n);\n        ll pow_zeta = 1;\n       \
    \ for(int i = 0; i < n; i++) {\n            a[i] = (f0[i % (n / 2)] + pow_zeta\
    \ * f1[i % (n / 2)]) % MOD;\n            pow_zeta *= zeta;\n            pow_zeta\
    \ %= MOD;\n        }\n        return a;\n    }\n\n    vector<ll> ntt(vector<ll>\
    \ a, bool is_inverse) {\n        vector<ll> ret = ntt_rec(a, is_inverse);\n  \
    \      int n = ret.size();\n        if(is_inverse) {\n            for(int i =\
    \ 0; i < n; i++) {\n                ret[i] *= modinv(n);\n                ret[i]\
    \ %= MOD;\n            }\n        }\n        return ret;\n    }\n\n    vector<ll>\
    \ convolve() {\n        int s = a.size() + b.size() - 1;\n        int t = 1;\n\
    \        while(t < s)\n            t *= 2;\n        a.resize(t);\n        b.resize(t);\n\
    \n        vector<ll> A = ntt(a, false);\n        vector<ll> B = ntt(b, false);\n\
    \        vector<ll> C(t);\n        for(int i = 0; i < t; i++) {\n            C[i]\
    \ = (A[i] * B[i]) % MOD;\n        }\n        C = ntt(C, true);\n        return\
    \ C;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    template <int MOD = 998244353, int primroot = 3> class ConvolutionNTT {\n  private:\n\
    \    vector<ll> a, b;\n    ll modpow(ll v, ll n) {\n        ll x = 1, p = v;\n\
    \        while(n > 0) {\n            if(n % 2 == 0) {\n                p = (p\
    \ * p) % MOD;\n                n /= 2;\n            } else {\n               \
    \ x = (x * p) % MOD;\n                n--;\n            }\n        }\n       \
    \ return x;\n    }\n    ll modinv(ll v) { return modpow(v, MOD - 2); }\n\n  public:\n\
    \    ConvolutionNTT(vector<ll> &_a, vector<ll> &_b) {\n        a = _a;\n     \
    \   b = _b;\n    }\n\n    vector<ll> ntt_rec(vector<ll> a, bool is_inverse = false)\
    \ {\n        int n = a.size();\n        if(n == 1)\n            return a;\n  \
    \      vector<ll> f0(n / 2), f1(n / 2);\n        for(int i = 0; i < (n / 2); i++)\
    \ {\n            f0[i] = (a[i * 2]);\n            f1[i] = (a[i * 2 + 1]);\n  \
    \      }\n        f0 = ntt_rec(f0, is_inverse), f1 = ntt_rec(f1, is_inverse);\n\
    \        ll zeta = modpow(is_inverse ? modinv(primroot) : primroot, MOD / n);\n\
    \        ll pow_zeta = 1;\n        for(int i = 0; i < n; i++) {\n            a[i]\
    \ = (f0[i % (n / 2)] + pow_zeta * f1[i % (n / 2)]) % MOD;\n            pow_zeta\
    \ *= zeta;\n            pow_zeta %= MOD;\n        }\n        return a;\n    }\n\
    \n    vector<ll> ntt(vector<ll> a, bool is_inverse) {\n        vector<ll> ret\
    \ = ntt_rec(a, is_inverse);\n        int n = ret.size();\n        if(is_inverse)\
    \ {\n            for(int i = 0; i < n; i++) {\n                ret[i] *= modinv(n);\n\
    \                ret[i] %= MOD;\n            }\n        }\n        return ret;\n\
    \    }\n\n    vector<ll> convolve() {\n        int s = a.size() + b.size() - 1;\n\
    \        int t = 1;\n        while(t < s)\n            t *= 2;\n        a.resize(t);\n\
    \        b.resize(t);\n\n        vector<ll> A = ntt(a, false);\n        vector<ll>\
    \ B = ntt(b, false);\n        vector<ll> C(t);\n        for(int i = 0; i < t;\
    \ i++) {\n            C[i] = (A[i] * B[i]) % MOD;\n        }\n        C = ntt(C,\
    \ true);\n        return C;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/ConvolutionNTT.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/ConvolutionNTT.cc
layout: document
redirect_from:
- /library/Math/ConvolutionNTT.cc
- /library/Math/ConvolutionNTT.cc.html
title: Math/ConvolutionNTT.cc
---
