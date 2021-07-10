---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Garner\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0. x % m[i] ==\
      \ b[i] % m[i]\u3092\u6E80\u305F\u3059\u6700\u5C0F\u306Ex\u3092\u6C42\u3081\u308B\
      ."
    links: []
  bundledCode: "#line 1 \"Math/Math.cc\"\n#include <bits/stdc++.h>\r\n\r\nnamespace\
    \ math {\r\n\r\nstd::set<long long> divisor(long long n) {\r\n    std::set<long\
    \ long> ret;\r\n    for(long long i = 1; i * i <= n; i++) {\r\n        if(n %\
    \ i == 0) {\r\n            ret.insert(i);\r\n            if(i * i != n)\r\n  \
    \              ret.insert(n / i);\r\n        }\r\n    }\r\n    return ret;\r\n\
    }\r\n\r\n// \u7D20\u6570\u7BE9\uFF0B\u7D20\u56E0\u6570\u5206\u89E3\r\n// \u521D\
    \u671F\u5316O(N),\u7D20\u56E0\u6570\u5206\u89E3O(logN)\r\n// \u305F\u304F\u3055\
    \u3093\u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\u3068\u304D\u306F\u3053\u3063\
    \u3061\r\nstruct Sieve {\r\n    int N;\r\n    std::vector<int> sieve;\r\n    Sieve(int\
    \ n) : N(n + 1), sieve(n + 1) { init(); }\r\n    void init() {\r\n        std::iota(sieve.begin(),\
    \ sieve.end(), 0);\r\n        for(int i = 2; i * i <= N; i++) {\r\n          \
    \  if(sieve[i] < i)\r\n                continue;\r\n            for(int j = i\
    \ * i; j <= N; j += i) {\r\n                if(sieve[j] == j)\r\n            \
    \        sieve[j] = i;\r\n            }\r\n        }\r\n    }\r\n\r\n    bool\
    \ is_prime(int x) {\r\n        assert(x <= N);\r\n        if(x == 1)\r\n     \
    \       return false;\r\n        return sieve[x] == x;\r\n    }\r\n\r\n    std::map<long\
    \ long, int> prime_factorize(long long n) {\r\n        assert(n <= N);\r\n   \
    \     std::map<long long, int> ret;\r\n        while(n > 1) {\r\n            ret[sieve[n]]++;\r\
    \n            n = n / sieve[n];\r\n        }\r\n        return ret;\r\n    }\r\
    \n};\r\n\r\n// \u7D20\u56E0\u6570\u5206\u89E3\r\n// O(sqrt(N))\r\nstd::map<long\
    \ long, int> prime_factor(long long n) {\r\n    std::map<long long, int> ret;\r\
    \n    for(long long i = 2; i * i <= n; i++) {\r\n        while(n % i == 0) {\r\
    \n            ret[i]++;\r\n            n /= i;\r\n        }\r\n    }\r\n    if(n\
    \ != 1)\r\n        ret[n] = 1;\r\n    return ret;\r\n}\r\n\r\nlong long mod_pow(long\
    \ long x, long long n, long long mod) {\r\n    if(n == 0)\r\n        return 1;\r\
    \n    long long res = mod_pow(x * x % mod, n / 2, mod);\r\n    if(n & 1)\r\n \
    \       res = res * x % mod;\r\n    return res;\r\n}\r\n\r\nlong long euler_phi(long\
    \ long n) {\r\n    long long ret = n;\r\n    for(long long i = 2; i * i <= n;\
    \ i++) {\r\n        if(n % i == 0) {\r\n            ret -= ret / i;\r\n      \
    \      while(n % i == 0)\r\n                n /= i;\r\n        }\r\n    }\r\n\
    \    if(n > 1)\r\n        ret -= ret / n;\r\n    return ret;\r\n}\r\n\r\nlong\
    \ long extgcd(long long a, long long b, long long &x, long long &y) {\r\n    if(b\
    \ == 0) {\r\n        x = 1;\r\n        y = 0;\r\n        return a;\r\n    }\r\n\
    \    long long d = extgcd(b, a % b, y, x);\r\n    y -= a / b * x;\r\n    return\
    \ d;\r\n}\r\n\r\nlong long mod_inv(long long a, long long mod) {\r\n    long long\
    \ b = mod, u = 1, v = 0;\r\n    while(b) {\r\n        long long t = a / b;\r\n\
    \        std::swap(a -= t * b, b);\r\n        std::swap(u -= t * b, v);\r\n  \
    \  }\r\n    u %= mod;\r\n    if(u < 0)\r\n        u += mod;\r\n    return u;\r\
    \n}\r\n\r\nstd::pair<long long, long long>\r\ncrt2(const std::pair<long long,\
    \ long long> &rm1,\r\n     const std::pair<long long, long long> &rm2) {\r\n \
    \   long long p, q;\r\n    auto [r1, m1] = rm1;\r\n    auto [r2, m2] = rm2;\r\n\
    \    long long d = extgcd(r1, m2, p, q);\r\n    if((r2 - r1) % d != 0)\r\n   \
    \     return {0, -1};\r\n    long long m = m1 * (m2 / d);\r\n    long long tmp\
    \ = (r2 - r1) / d * p % (m2 / d);\r\n    long long c = (r1 + m1 * tmp);\r\n  \
    \  long long r = (c % m + m) % m;\r\n    return {r, m};\r\n}\r\n\r\n/**\r\n *\
    \ @brief  Garner\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0. x % m[i] == b[i] %\
    \ m[i]\u3092\u6E80\u305F\u3059\u6700\u5C0F\u306Ex\u3092\u6C42\u3081\u308B.\r\n\
    \ *\r\n * @param rm {\u3042\u307E\u308A,\u6CD5}\u306E\u914D\u5217. !!\u6CD5\u306F\
    \u3059\u3079\u3066\u4E92\u3044\u306B\u7D20!!\r\n * @return long long x % m[i]\
    \ == b[i] % m[i]\u3092\u6E80\u305F\u3059\u6700\u5C0F\u306Ex.\r\n */\r\nlong long\
    \ garner(const std::vector<std::pair<long long, long long>> &rm) {\r\n    int\
    \ n = rm.size();\r\n    long long m_prod = 1;\r\n    long long res = rm[0].first\
    \ % rm[0].second;\r\n    for(int i = 1; i < n; i++) {\r\n        auto [r, m] =\
    \ rm[i];\r\n        m_prod *= rm[i - 1].second;\r\n        long long t = (((r\
    \ - res) * mod_inv(m_prod, m)) % m + m) % m;\r\n        res += t * m_prod;\r\n\
    \    }\r\n    return res;\r\n}\r\n\r\n/**\r\n * @brief  Garner\u306E\u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0. x % m[i] == b[i] % m[i]\u3092\u6E80\u305F\u3059\u6700\
    \u5C0F\u306Ex\u3092\u6C42\u3081\u308B.\r\n *\r\n * @param rm {\u3042\u307E\u308A\
    ,\u6CD5}\u306E\u914D\u5217. !!\u6CD5\u306F\u3059\u3079\u3066\u4E92\u3044\u306B\
    \u7D20!!\r\n * @param mod \u7B54\u3048\u306E\u6CD5.\r\n * @return long long x\
    \ % m[i] == b[i] % m[i]\u3092\u6E80\u305F\u3059\u6700\u5C0F\u306Ex (mod M).\r\n\
    \ */\r\nlong long garner_mod(std::vector<std::pair<long long, long long>> rm,\r\
    \n                     long long mod) {\r\n    rm.emplace_back(0, mod);\r\n  \
    \  int n = rm.size();\r\n    std::vector<long long> coffs(n, 1), constants(n,\
    \ 0);\r\n    for(int i = 0; i < n - 1; i++) {\r\n        auto [r, m] = rm[i];\r\
    \n        long long t = ((r - constants[i]) * mod_inv(coffs[i], m) % m + m) &\
    \ m;\r\n        for(int j = i + 1; j < n; j++) {\r\n            (constants[j]\
    \ += coffs[j] * t) %= rm[j].second;\r\n            (coffs[j] *= m) %= rm[j].second;\r\
    \n        }\r\n    }\r\n    return constants.back();\r\n}\r\n\r\nlong long floor_div(long\
    \ long a, long long b) {\r\n    assert(b != 0);\r\n    if(b < 0)\r\n        a\
    \ = -a, b = -b;\r\n    return a >= 0 ? a / b : (a - (b - 1)) / b;\r\n}\r\n\r\n\
    long long ceil_div(long long a, long long b) {\r\n    assert(b != 0);\r\n    if(b\
    \ < 0)\r\n        a = -a, b = -b;\r\n    return a >= 0 ? (a + b - 1) / b : a /\
    \ b;\r\n}\r\n\r\nint bit_length(long long x) {\r\n    assert(x >= 0);\r\n    int\
    \ ret = 0;\r\n    while(x > 0) {\r\n        ret++;\r\n        x /= 2;\r\n    }\r\
    \n    return ret;\r\n}\r\n\r\nlong long ll_sqrt(long long x) {\r\n    long long\
    \ ret = sqrt(x) - 1;\r\n    while((ret + 1) * (ret + 1) <= x)\r\n        ret++;\r\
    \n    return ret;\r\n}\r\n\r\n// multiple of d in [left,right],left>0\r\nlong\
    \ long cmul(long long left, long long right, long long d) {\r\n    if(left ==\
    \ 0)\r\n        return right / d;\r\n    return right / d - (left - 1) / d;\r\n\
    }\r\n\r\n// multiple of d in [left,right]\r\nlong long count_multiple(long long\
    \ left, long long right, long long d) {\r\n    if(right < 0)\r\n        return\
    \ cmul(-right, -left, d);\r\n    if(left > 0)\r\n        return cmul(left, right,\
    \ d);\r\n    return cmul(0, right, d) + cmul(0, -left, d) - 1;\r\n}\r\n\r\n};\
    \ // namespace math\r\n\r\nusing namespace math;\n"
  code: "#include <bits/stdc++.h>\r\n\r\nnamespace math {\r\n\r\nstd::set<long long>\
    \ divisor(long long n) {\r\n    std::set<long long> ret;\r\n    for(long long\
    \ i = 1; i * i <= n; i++) {\r\n        if(n % i == 0) {\r\n            ret.insert(i);\r\
    \n            if(i * i != n)\r\n                ret.insert(n / i);\r\n       \
    \ }\r\n    }\r\n    return ret;\r\n}\r\n\r\n// \u7D20\u6570\u7BE9\uFF0B\u7D20\u56E0\
    \u6570\u5206\u89E3\r\n// \u521D\u671F\u5316O(N),\u7D20\u56E0\u6570\u5206\u89E3\
    O(logN)\r\n// \u305F\u304F\u3055\u3093\u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\
    \u3068\u304D\u306F\u3053\u3063\u3061\r\nstruct Sieve {\r\n    int N;\r\n    std::vector<int>\
    \ sieve;\r\n    Sieve(int n) : N(n + 1), sieve(n + 1) { init(); }\r\n    void\
    \ init() {\r\n        std::iota(sieve.begin(), sieve.end(), 0);\r\n        for(int\
    \ i = 2; i * i <= N; i++) {\r\n            if(sieve[i] < i)\r\n              \
    \  continue;\r\n            for(int j = i * i; j <= N; j += i) {\r\n         \
    \       if(sieve[j] == j)\r\n                    sieve[j] = i;\r\n           \
    \ }\r\n        }\r\n    }\r\n\r\n    bool is_prime(int x) {\r\n        assert(x\
    \ <= N);\r\n        if(x == 1)\r\n            return false;\r\n        return\
    \ sieve[x] == x;\r\n    }\r\n\r\n    std::map<long long, int> prime_factorize(long\
    \ long n) {\r\n        assert(n <= N);\r\n        std::map<long long, int> ret;\r\
    \n        while(n > 1) {\r\n            ret[sieve[n]]++;\r\n            n = n\
    \ / sieve[n];\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n// \u7D20\
    \u56E0\u6570\u5206\u89E3\r\n// O(sqrt(N))\r\nstd::map<long long, int> prime_factor(long\
    \ long n) {\r\n    std::map<long long, int> ret;\r\n    for(long long i = 2; i\
    \ * i <= n; i++) {\r\n        while(n % i == 0) {\r\n            ret[i]++;\r\n\
    \            n /= i;\r\n        }\r\n    }\r\n    if(n != 1)\r\n        ret[n]\
    \ = 1;\r\n    return ret;\r\n}\r\n\r\nlong long mod_pow(long long x, long long\
    \ n, long long mod) {\r\n    if(n == 0)\r\n        return 1;\r\n    long long\
    \ res = mod_pow(x * x % mod, n / 2, mod);\r\n    if(n & 1)\r\n        res = res\
    \ * x % mod;\r\n    return res;\r\n}\r\n\r\nlong long euler_phi(long long n) {\r\
    \n    long long ret = n;\r\n    for(long long i = 2; i * i <= n; i++) {\r\n  \
    \      if(n % i == 0) {\r\n            ret -= ret / i;\r\n            while(n\
    \ % i == 0)\r\n                n /= i;\r\n        }\r\n    }\r\n    if(n > 1)\r\
    \n        ret -= ret / n;\r\n    return ret;\r\n}\r\n\r\nlong long extgcd(long\
    \ long a, long long b, long long &x, long long &y) {\r\n    if(b == 0) {\r\n \
    \       x = 1;\r\n        y = 0;\r\n        return a;\r\n    }\r\n    long long\
    \ d = extgcd(b, a % b, y, x);\r\n    y -= a / b * x;\r\n    return d;\r\n}\r\n\
    \r\nlong long mod_inv(long long a, long long mod) {\r\n    long long b = mod,\
    \ u = 1, v = 0;\r\n    while(b) {\r\n        long long t = a / b;\r\n        std::swap(a\
    \ -= t * b, b);\r\n        std::swap(u -= t * b, v);\r\n    }\r\n    u %= mod;\r\
    \n    if(u < 0)\r\n        u += mod;\r\n    return u;\r\n}\r\n\r\nstd::pair<long\
    \ long, long long>\r\ncrt2(const std::pair<long long, long long> &rm1,\r\n   \
    \  const std::pair<long long, long long> &rm2) {\r\n    long long p, q;\r\n  \
    \  auto [r1, m1] = rm1;\r\n    auto [r2, m2] = rm2;\r\n    long long d = extgcd(r1,\
    \ m2, p, q);\r\n    if((r2 - r1) % d != 0)\r\n        return {0, -1};\r\n    long\
    \ long m = m1 * (m2 / d);\r\n    long long tmp = (r2 - r1) / d * p % (m2 / d);\r\
    \n    long long c = (r1 + m1 * tmp);\r\n    long long r = (c % m + m) % m;\r\n\
    \    return {r, m};\r\n}\r\n\r\n/**\r\n * @brief  Garner\u306E\u30A2\u30EB\u30B4\
    \u30EA\u30BA\u30E0. x % m[i] == b[i] % m[i]\u3092\u6E80\u305F\u3059\u6700\u5C0F\
    \u306Ex\u3092\u6C42\u3081\u308B.\r\n *\r\n * @param rm {\u3042\u307E\u308A,\u6CD5\
    }\u306E\u914D\u5217. !!\u6CD5\u306F\u3059\u3079\u3066\u4E92\u3044\u306B\u7D20\
    !!\r\n * @return long long x % m[i] == b[i] % m[i]\u3092\u6E80\u305F\u3059\u6700\
    \u5C0F\u306Ex.\r\n */\r\nlong long garner(const std::vector<std::pair<long long,\
    \ long long>> &rm) {\r\n    int n = rm.size();\r\n    long long m_prod = 1;\r\n\
    \    long long res = rm[0].first % rm[0].second;\r\n    for(int i = 1; i < n;\
    \ i++) {\r\n        auto [r, m] = rm[i];\r\n        m_prod *= rm[i - 1].second;\r\
    \n        long long t = (((r - res) * mod_inv(m_prod, m)) % m + m) % m;\r\n  \
    \      res += t * m_prod;\r\n    }\r\n    return res;\r\n}\r\n\r\n/**\r\n * @brief\
    \  Garner\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0. x % m[i] == b[i] % m[i]\u3092\
    \u6E80\u305F\u3059\u6700\u5C0F\u306Ex\u3092\u6C42\u3081\u308B.\r\n *\r\n * @param\
    \ rm {\u3042\u307E\u308A,\u6CD5}\u306E\u914D\u5217. !!\u6CD5\u306F\u3059\u3079\
    \u3066\u4E92\u3044\u306B\u7D20!!\r\n * @param mod \u7B54\u3048\u306E\u6CD5.\r\n\
    \ * @return long long x % m[i] == b[i] % m[i]\u3092\u6E80\u305F\u3059\u6700\u5C0F\
    \u306Ex (mod M).\r\n */\r\nlong long garner_mod(std::vector<std::pair<long long,\
    \ long long>> rm,\r\n                     long long mod) {\r\n    rm.emplace_back(0,\
    \ mod);\r\n    int n = rm.size();\r\n    std::vector<long long> coffs(n, 1), constants(n,\
    \ 0);\r\n    for(int i = 0; i < n - 1; i++) {\r\n        auto [r, m] = rm[i];\r\
    \n        long long t = ((r - constants[i]) * mod_inv(coffs[i], m) % m + m) &\
    \ m;\r\n        for(int j = i + 1; j < n; j++) {\r\n            (constants[j]\
    \ += coffs[j] * t) %= rm[j].second;\r\n            (coffs[j] *= m) %= rm[j].second;\r\
    \n        }\r\n    }\r\n    return constants.back();\r\n}\r\n\r\nlong long floor_div(long\
    \ long a, long long b) {\r\n    assert(b != 0);\r\n    if(b < 0)\r\n        a\
    \ = -a, b = -b;\r\n    return a >= 0 ? a / b : (a - (b - 1)) / b;\r\n}\r\n\r\n\
    long long ceil_div(long long a, long long b) {\r\n    assert(b != 0);\r\n    if(b\
    \ < 0)\r\n        a = -a, b = -b;\r\n    return a >= 0 ? (a + b - 1) / b : a /\
    \ b;\r\n}\r\n\r\nint bit_length(long long x) {\r\n    assert(x >= 0);\r\n    int\
    \ ret = 0;\r\n    while(x > 0) {\r\n        ret++;\r\n        x /= 2;\r\n    }\r\
    \n    return ret;\r\n}\r\n\r\nlong long ll_sqrt(long long x) {\r\n    long long\
    \ ret = sqrt(x) - 1;\r\n    while((ret + 1) * (ret + 1) <= x)\r\n        ret++;\r\
    \n    return ret;\r\n}\r\n\r\n// multiple of d in [left,right],left>0\r\nlong\
    \ long cmul(long long left, long long right, long long d) {\r\n    if(left ==\
    \ 0)\r\n        return right / d;\r\n    return right / d - (left - 1) / d;\r\n\
    }\r\n\r\n// multiple of d in [left,right]\r\nlong long count_multiple(long long\
    \ left, long long right, long long d) {\r\n    if(right < 0)\r\n        return\
    \ cmul(-right, -left, d);\r\n    if(left > 0)\r\n        return cmul(left, right,\
    \ d);\r\n    return cmul(0, right, d) + cmul(0, -left, d) - 1;\r\n}\r\n\r\n};\
    \ // namespace math\r\n\r\nusing namespace math;"
  dependsOn: []
  isVerificationFile: false
  path: Math/Math.cc
  requiredBy: []
  timestamp: '2021-07-10 17:13:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Math.cc
layout: document
redirect_from:
- /library/Math/Math.cc
- /library/Math/Math.cc.html
title: "Garner\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0. x % m[i] == b[i] % m[i]\u3092\
  \u6E80\u305F\u3059\u6700\u5C0F\u306Ex\u3092\u6C42\u3081\u308B."
---
