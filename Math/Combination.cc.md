---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://perogram.hateblo.jp/entry/2020/07/08/120017
    - https://yukicoder.me/submissions/520882
  bundledCode: "#line 1 \"Math/Combination.cc\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\n//\u4E8C\u9805\u4FC2\u6570\uFF08nCk mod.p;1<=k<=n<=1e7,p\u306F\
    \u7D20\u6570\uFF09for ModInt\r\ntemplate <class T> struct BiCoefficient {\r\n\
    \    vector<T> fac, finv, inv;\r\n    BiCoefficient(const int MAX) : fac(MAX),\
    \ finv(MAX), inv(MAX) {\r\n        fac[0] = fac[1] = 1;\r\n        finv[0] = finv[1]\
    \ = 1;\r\n        inv[1] = 1;\r\n        for(int i = 2; i < MAX; i++) {\r\n  \
    \          fac[i] = fac[i - 1] * i;\r\n            inv[i] = -inv[MOD % i] * (MOD\
    \ / i);\r\n            finv[i] = finv[i - 1] * inv[i];\r\n        }\r\n    }\r\
    \n    T comb(int n, int k) {\r\n        if(n < k)\r\n            return 0;\r\n\
    \        if(n < 0 || k < 0)\r\n            return 0;\r\n        return fac[n]\
    \ * finv[k] * finv[n - k];\r\n    }\r\n};\r\n\r\n// // \u9577\u3055n,1<=a[i]<=m\u3067\
    \u5358\u8ABF\u5897\u52A0\u306E\u6570\u5217\r\n// T inc_seq(int n, int m) { return\
    \ comb(m, n); }\r\n// // \u9577\u3055n,1<=a[i]<=m\u3067\u5E83\u7FA9\u5358\u8ABF\
    \u5897\u52A0\u306E\u6570\u5217(b[i]:=a[i]+i\u3068\u304A\u3044\u3066\u2191\u306B\
    \u5E30\u7740)\r\n// // \u7247\u65B9\u3082\u3057\u304F\u306F\u4E21\u7AEF\u3092\u56FA\
    \u5B9A\u3059\u308B\u3068\u304D:comb(m+n-1,(n-1 or n-2));\r\n// T non_dec_seq(int\
    \ n, int m) { return comb(m + n - 1, n); }\r\n// // \u8DB3\u3057\u3066S\u306B\u306A\
    \u308B\u9577\u3055n\u306E\u6574\u6570\u5217\r\n// T sum_seq(int n,int S){ return\
    \ comb(S+n-1,n); }\r\n// // \u8DB3\u3057\u3066S\u4EE5\u4E0B\u306B\u306A\u308B\u9577\
    \u3055n\u306E\u6574\u6570\u5217\r\n// T sum_no_more_seq(int n,int S){return comb(S+n,n);}\r\
    \n\r\n//\u4E8C\u9805\u4FC2\u6570\uFF08nCk mod.p;1<=k<=n<=1e7,p\u306F\u7D20\u6570\
    \uFF09for long long\r\nstruct Combination {\r\n    const int MOD = 1000000007;\r\
    \n    vector<long long> fac, finv, inv;\r\n    Combination(const int MAX) : fac(MAX),\
    \ finv(MAX), inv(MAX) {\r\n        fac[0] = fac[1] = 1;\r\n        finv[0] = finv[1]\
    \ = 1;\r\n        inv[1] = 1;\r\n        for(int i = 2; i < MAX; i++) {\r\n  \
    \          fac[i] = fac[i - 1] * i % MOD;\r\n            inv[i] = MOD - inv[MOD\
    \ % i] * (MOD / i) % MOD;\r\n            finv[i] = finv[i - 1] * inv[i] % MOD;\r\
    \n        }\r\n    }\r\n    long long comb(int n, int k) {\r\n        if(n < k)\r\
    \n            return 0;\r\n        if(n < 0 || k < 0)\r\n            return 0;\r\
    \n        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;\r\n    }\r\n};\r\
    \n\r\n//\u4E8C\u9805\u4FC2\u6570\uFF08nCk mod.p;1<=k<=n<=2000,p\u306F\u7D20\u6570\
    \u3067\u306A\u304F\u3068\u3082\u3088\u3044\uFF09\r\nconst int MAX_C = 1000;\r\n\
    long long Com[MAX_C][MAX_C];\r\nvoid calc_com(int MOD) {\r\n    memset(Com, 0,\
    \ sizeof(Com));\r\n    Com[0][0] = 1;\r\n    for(int i = 1; i < MAX_C; ++i) {\r\
    \n        Com[i][0] = 1;\r\n        for(int j = 1; j < MAX_C; ++j) {\r\n     \
    \       Com[i][j] = (Com[i - 1][j - 1] + Com[i - 1][j]) % MOD;\r\n        }\r\n\
    \    }\r\n}\r\n\r\n//\u4E8C\u9805\u4FC2\u6570 (nCk mod.p; p is prime, Lucas\u306E\
    \u5B9A\u7406)\r\nstruct Lucas {\r\n    vector<vector<long long>> com;\r\n    long\
    \ long p;\r\n    Lucas(long long p) : p(p) { init(p); }\r\n\r\n    void init(long\
    \ long p) {\r\n        com.assign(p, vector<long long>(p));\r\n        com[0][0]\
    \ = 1;\r\n        for(int i = 1; i < p; i++) {\r\n            com[i][0] = 1;\r\
    \n            for(int j = i; j > 0; j--) {\r\n                com[i][j] = (com[i\
    \ - 1][j - 1] + com[i - 1][j]) % p;\r\n            }\r\n        }\r\n    }\r\n\
    \r\n    long long comb(long long n, long long k) {\r\n        long long ret =\
    \ 1;\r\n        while(n > 0) {\r\n            int ni = n % p;\r\n            int\
    \ ki = k % p;\r\n            ret *= com[ni][ki];\r\n            ret %= p;\r\n\
    \            n /= p;\r\n            k /= p;\r\n        }\r\n        return ret;\r\
    \n    }\r\n};\r\n\r\n//\u4E8C\u9805\u4FC2\u6570 O(k)\r\n// n\u3068k\u306E\u3069\
    \u3061\u3089\u304B\u304C\u5909\u5316\u3057\u3066\u3044\u304F\u3068\u304D\u3001\
    O(\u5909\u5316\u91CF)\u3067\u3059\u3079\u3066\u6C42\u3081\u3089\u308C\u308B\u3000\
    \u591A\u5206\r\n// \u53C2\u8003\uFF1Ahttps://perogram.hateblo.jp/entry/2020/07/08/120017\r\
    \n// https://yukicoder.me/submissions/520882\r\ntemplate <class T> T nCk(long\
    \ long n, long long k, map<pair<long long, long long>, T> &mp) {\r\n    auto key\
    \ = {n, k};\r\n    if(mp.count(key))\r\n        return mp[key];\r\n    if(k ==\
    \ 0 || k == n) {\r\n        T ret = 1;\r\n        return ret;\r\n    }\r\n   \
    \ if(k == 1 || k == n - 1) {\r\n        T ret = n;\r\n        return ret;\r\n\
    \    }\r\n    // return mp[key] = nCk(n, k - 1, mp) * (n - k + 1) / k;\r\n   \
    \ return mp[key] = nCk(n - 1, k, mp) * n / (n - k);\r\n}\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n//\u4E8C\u9805\u4FC2\
    \u6570\uFF08nCk mod.p;1<=k<=n<=1e7,p\u306F\u7D20\u6570\uFF09for ModInt\r\ntemplate\
    \ <class T> struct BiCoefficient {\r\n    vector<T> fac, finv, inv;\r\n    BiCoefficient(const\
    \ int MAX) : fac(MAX), finv(MAX), inv(MAX) {\r\n        fac[0] = fac[1] = 1;\r\
    \n        finv[0] = finv[1] = 1;\r\n        inv[1] = 1;\r\n        for(int i =\
    \ 2; i < MAX; i++) {\r\n            fac[i] = fac[i - 1] * i;\r\n            inv[i]\
    \ = -inv[MOD % i] * (MOD / i);\r\n            finv[i] = finv[i - 1] * inv[i];\r\
    \n        }\r\n    }\r\n    T comb(int n, int k) {\r\n        if(n < k)\r\n  \
    \          return 0;\r\n        if(n < 0 || k < 0)\r\n            return 0;\r\n\
    \        return fac[n] * finv[k] * finv[n - k];\r\n    }\r\n};\r\n\r\n// // \u9577\
    \u3055n,1<=a[i]<=m\u3067\u5358\u8ABF\u5897\u52A0\u306E\u6570\u5217\r\n// T inc_seq(int\
    \ n, int m) { return comb(m, n); }\r\n// // \u9577\u3055n,1<=a[i]<=m\u3067\u5E83\
    \u7FA9\u5358\u8ABF\u5897\u52A0\u306E\u6570\u5217(b[i]:=a[i]+i\u3068\u304A\u3044\
    \u3066\u2191\u306B\u5E30\u7740)\r\n// // \u7247\u65B9\u3082\u3057\u304F\u306F\u4E21\
    \u7AEF\u3092\u56FA\u5B9A\u3059\u308B\u3068\u304D:comb(m+n-1,(n-1 or n-2));\r\n\
    // T non_dec_seq(int n, int m) { return comb(m + n - 1, n); }\r\n// // \u8DB3\u3057\
    \u3066S\u306B\u306A\u308B\u9577\u3055n\u306E\u6574\u6570\u5217\r\n// T sum_seq(int\
    \ n,int S){ return comb(S+n-1,n); }\r\n// // \u8DB3\u3057\u3066S\u4EE5\u4E0B\u306B\
    \u306A\u308B\u9577\u3055n\u306E\u6574\u6570\u5217\r\n// T sum_no_more_seq(int\
    \ n,int S){return comb(S+n,n);}\r\n\r\n//\u4E8C\u9805\u4FC2\u6570\uFF08nCk mod.p;1<=k<=n<=1e7,p\u306F\
    \u7D20\u6570\uFF09for long long\r\nstruct Combination {\r\n    const int MOD =\
    \ 1000000007;\r\n    vector<long long> fac, finv, inv;\r\n    Combination(const\
    \ int MAX) : fac(MAX), finv(MAX), inv(MAX) {\r\n        fac[0] = fac[1] = 1;\r\
    \n        finv[0] = finv[1] = 1;\r\n        inv[1] = 1;\r\n        for(int i =\
    \ 2; i < MAX; i++) {\r\n            fac[i] = fac[i - 1] * i % MOD;\r\n       \
    \     inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;\r\n            finv[i] =\
    \ finv[i - 1] * inv[i] % MOD;\r\n        }\r\n    }\r\n    long long comb(int\
    \ n, int k) {\r\n        if(n < k)\r\n            return 0;\r\n        if(n <\
    \ 0 || k < 0)\r\n            return 0;\r\n        return fac[n] * (finv[k] * finv[n\
    \ - k] % MOD) % MOD;\r\n    }\r\n};\r\n\r\n//\u4E8C\u9805\u4FC2\u6570\uFF08nCk\
    \ mod.p;1<=k<=n<=2000,p\u306F\u7D20\u6570\u3067\u306A\u304F\u3068\u3082\u3088\u3044\
    \uFF09\r\nconst int MAX_C = 1000;\r\nlong long Com[MAX_C][MAX_C];\r\nvoid calc_com(int\
    \ MOD) {\r\n    memset(Com, 0, sizeof(Com));\r\n    Com[0][0] = 1;\r\n    for(int\
    \ i = 1; i < MAX_C; ++i) {\r\n        Com[i][0] = 1;\r\n        for(int j = 1;\
    \ j < MAX_C; ++j) {\r\n            Com[i][j] = (Com[i - 1][j - 1] + Com[i - 1][j])\
    \ % MOD;\r\n        }\r\n    }\r\n}\r\n\r\n//\u4E8C\u9805\u4FC2\u6570 (nCk mod.p;\
    \ p is prime, Lucas\u306E\u5B9A\u7406)\r\nstruct Lucas {\r\n    vector<vector<long\
    \ long>> com;\r\n    long long p;\r\n    Lucas(long long p) : p(p) { init(p);\
    \ }\r\n\r\n    void init(long long p) {\r\n        com.assign(p, vector<long long>(p));\r\
    \n        com[0][0] = 1;\r\n        for(int i = 1; i < p; i++) {\r\n         \
    \   com[i][0] = 1;\r\n            for(int j = i; j > 0; j--) {\r\n           \
    \     com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % p;\r\n            }\r\n\
    \        }\r\n    }\r\n\r\n    long long comb(long long n, long long k) {\r\n\
    \        long long ret = 1;\r\n        while(n > 0) {\r\n            int ni =\
    \ n % p;\r\n            int ki = k % p;\r\n            ret *= com[ni][ki];\r\n\
    \            ret %= p;\r\n            n /= p;\r\n            k /= p;\r\n     \
    \   }\r\n        return ret;\r\n    }\r\n};\r\n\r\n//\u4E8C\u9805\u4FC2\u6570\
    \ O(k)\r\n// n\u3068k\u306E\u3069\u3061\u3089\u304B\u304C\u5909\u5316\u3057\u3066\
    \u3044\u304F\u3068\u304D\u3001O(\u5909\u5316\u91CF)\u3067\u3059\u3079\u3066\u6C42\
    \u3081\u3089\u308C\u308B\u3000\u591A\u5206\r\n// \u53C2\u8003\uFF1Ahttps://perogram.hateblo.jp/entry/2020/07/08/120017\r\
    \n// https://yukicoder.me/submissions/520882\r\ntemplate <class T> T nCk(long\
    \ long n, long long k, map<pair<long long, long long>, T> &mp) {\r\n    auto key\
    \ = {n, k};\r\n    if(mp.count(key))\r\n        return mp[key];\r\n    if(k ==\
    \ 0 || k == n) {\r\n        T ret = 1;\r\n        return ret;\r\n    }\r\n   \
    \ if(k == 1 || k == n - 1) {\r\n        T ret = n;\r\n        return ret;\r\n\
    \    }\r\n    // return mp[key] = nCk(n, k - 1, mp) * (n - k + 1) / k;\r\n   \
    \ return mp[key] = nCk(n - 1, k, mp) * n / (n - k);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Combination.cc
  requiredBy: []
  timestamp: '2021-07-10 17:10:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Combination.cc
layout: document
redirect_from:
- /library/Math/Combination.cc
- /library/Math/Combination.cc.html
title: Math/Combination.cc
---
