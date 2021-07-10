---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/convolution_mod.test.cpp
    title: verify/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/inv_of_formal_power_series.test.cpp
    title: verify/inv_of_formal_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/ModInt.cc\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n/* ModInt */\r\ntemplate <uint_fast64_t MOD> class ModInt {\r\n    using\
    \ u64 = uint_fast64_t;\r\n\r\n  public:\r\n    u64 val;\r\n\r\n    ModInt(const\
    \ u64 x = 0) : val((x + MOD) % MOD) {}\r\n    constexpr u64 &value() { return\
    \ val; }\r\n    static const u64 get_mod() { return MOD; }\r\n    constexpr ModInt\
    \ operator-() { return val ? MOD - val : 0; }\r\n    constexpr ModInt operator+(const\
    \ ModInt &rhs) const {\r\n        return ModInt(*this) += rhs;\r\n    }\r\n  \
    \  constexpr ModInt operator-(const ModInt &rhs) const {\r\n        return ModInt(*this)\
    \ -= rhs;\r\n    }\r\n    constexpr ModInt operator*(const ModInt &rhs) const\
    \ {\r\n        return ModInt(*this) *= rhs;\r\n    }\r\n    constexpr ModInt operator/(const\
    \ ModInt &rhs) const {\r\n        return ModInt(*this) /= rhs;\r\n    }\r\n  \
    \  constexpr ModInt &operator+=(const ModInt &rhs) {\r\n        val += rhs.val;\r\
    \n        if(val >= MOD) {\r\n            val -= MOD;\r\n        }\r\n       \
    \ return *this;\r\n    }\r\n    constexpr ModInt &operator-=(const ModInt &rhs)\
    \ {\r\n        if(val < rhs.val) {\r\n            val += MOD;\r\n        }\r\n\
    \        val -= rhs.val;\r\n        return *this;\r\n    }\r\n    constexpr ModInt\
    \ &operator*=(const ModInt &rhs) {\r\n        val = val * rhs.val % MOD;\r\n \
    \       return *this;\r\n    }\r\n\r\n    constexpr ModInt &operator/=(const ModInt\
    \ &rhs) {\r\n        *this *= rhs.inv();\r\n        return *this;\r\n    }\r\n\
    \r\n    constexpr bool operator==(const ModInt &rhs) const {\r\n        return\
    \ this->val == rhs.val;\r\n    }\r\n    constexpr bool operator!=(const ModInt\
    \ &rhs) const {\r\n        return this->val != rhs.val;\r\n    }\r\n    friend\
    \ constexpr ostream &operator<<(ostream &os, const ModInt<MOD> &x) {\r\n     \
    \   return os << x.val;\r\n    }\r\n    friend constexpr istream &operator>>(istream\
    \ &is, ModInt<MOD> &x) {\r\n        return is >> x.val;\r\n    }\r\n\r\n    constexpr\
    \ ModInt inv() const { return ModInt(*this).pow(MOD - 2); }\r\n\r\n    constexpr\
    \ ModInt pow(long long e) const {\r\n        u64 x = 1, p = val;\r\n        while(e\
    \ > 0) {\r\n            if(e % 2 == 0) {\r\n                p = (p * p) % MOD;\r\
    \n                e /= 2;\r\n            } else {\r\n                x = (x *\
    \ p) % MOD;\r\n                e--;\r\n            }\r\n        }\r\n        return\
    \ ModInt(x);\r\n    }\r\n};\r\n\r\nusing mint = ModInt<1000000007UL>;\r\n// using\
    \ mint = ModInt<998244353UL>;\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n/* ModInt */\r\ntemplate\
    \ <uint_fast64_t MOD> class ModInt {\r\n    using u64 = uint_fast64_t;\r\n\r\n\
    \  public:\r\n    u64 val;\r\n\r\n    ModInt(const u64 x = 0) : val((x + MOD)\
    \ % MOD) {}\r\n    constexpr u64 &value() { return val; }\r\n    static const\
    \ u64 get_mod() { return MOD; }\r\n    constexpr ModInt operator-() { return val\
    \ ? MOD - val : 0; }\r\n    constexpr ModInt operator+(const ModInt &rhs) const\
    \ {\r\n        return ModInt(*this) += rhs;\r\n    }\r\n    constexpr ModInt operator-(const\
    \ ModInt &rhs) const {\r\n        return ModInt(*this) -= rhs;\r\n    }\r\n  \
    \  constexpr ModInt operator*(const ModInt &rhs) const {\r\n        return ModInt(*this)\
    \ *= rhs;\r\n    }\r\n    constexpr ModInt operator/(const ModInt &rhs) const\
    \ {\r\n        return ModInt(*this) /= rhs;\r\n    }\r\n    constexpr ModInt &operator+=(const\
    \ ModInt &rhs) {\r\n        val += rhs.val;\r\n        if(val >= MOD) {\r\n  \
    \          val -= MOD;\r\n        }\r\n        return *this;\r\n    }\r\n    constexpr\
    \ ModInt &operator-=(const ModInt &rhs) {\r\n        if(val < rhs.val) {\r\n \
    \           val += MOD;\r\n        }\r\n        val -= rhs.val;\r\n        return\
    \ *this;\r\n    }\r\n    constexpr ModInt &operator*=(const ModInt &rhs) {\r\n\
    \        val = val * rhs.val % MOD;\r\n        return *this;\r\n    }\r\n\r\n\
    \    constexpr ModInt &operator/=(const ModInt &rhs) {\r\n        *this *= rhs.inv();\r\
    \n        return *this;\r\n    }\r\n\r\n    constexpr bool operator==(const ModInt\
    \ &rhs) const {\r\n        return this->val == rhs.val;\r\n    }\r\n    constexpr\
    \ bool operator!=(const ModInt &rhs) const {\r\n        return this->val != rhs.val;\r\
    \n    }\r\n    friend constexpr ostream &operator<<(ostream &os, const ModInt<MOD>\
    \ &x) {\r\n        return os << x.val;\r\n    }\r\n    friend constexpr istream\
    \ &operator>>(istream &is, ModInt<MOD> &x) {\r\n        return is >> x.val;\r\n\
    \    }\r\n\r\n    constexpr ModInt inv() const { return ModInt(*this).pow(MOD\
    \ - 2); }\r\n\r\n    constexpr ModInt pow(long long e) const {\r\n        u64\
    \ x = 1, p = val;\r\n        while(e > 0) {\r\n            if(e % 2 == 0) {\r\n\
    \                p = (p * p) % MOD;\r\n                e /= 2;\r\n           \
    \ } else {\r\n                x = (x * p) % MOD;\r\n                e--;\r\n \
    \           }\r\n        }\r\n        return ModInt(x);\r\n    }\r\n};\r\n\r\n\
    using mint = ModInt<1000000007UL>;\r\n// using mint = ModInt<998244353UL>;\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/ModInt.cc
  requiredBy: []
  timestamp: '2021-07-10 17:13:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/inv_of_formal_power_series.test.cpp
  - verify/convolution_mod.test.cpp
documentation_of: Math/ModInt.cc
layout: document
redirect_from:
- /library/Math/ModInt.cc
- /library/Math/ModInt.cc.html
title: Math/ModInt.cc
---
