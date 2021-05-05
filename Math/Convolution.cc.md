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
  bundledCode: "#line 1 \"Math/Convolution.cc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n/* ModInt */\ntemplate <uint_fast64_t MOD> class\
    \ ModInt {\n    using u64 = uint_fast64_t;\n\n  public:\n    u64 val;\n\n    ModInt(const\
    \ u64 x = 0) : val((x + MOD) % MOD) {}\n    constexpr u64 &value() { return val;\
    \ }\n    static const u64 get_mod() { return MOD; }\n    constexpr ModInt operator-()\
    \ { return val ? MOD - val : 0; }\n    constexpr ModInt operator+(const ModInt\
    \ &rhs) const {\n        return ModInt(*this) += rhs;\n    }\n    constexpr ModInt\
    \ operator-(const ModInt &rhs) const {\n        return ModInt(*this) -= rhs;\n\
    \    }\n    constexpr ModInt operator*(const ModInt &rhs) const {\n        return\
    \ ModInt(*this) *= rhs;\n    }\n    constexpr ModInt operator/(const ModInt &rhs)\
    \ const {\n        return ModInt(*this) /= rhs;\n    }\n    constexpr ModInt &operator+=(const\
    \ ModInt &rhs) {\n        val += rhs.val;\n        if(val >= MOD) {\n        \
    \    val -= MOD;\n        }\n        return *this;\n    }\n    constexpr ModInt\
    \ &operator-=(const ModInt &rhs) {\n        if(val < rhs.val) {\n            val\
    \ += MOD;\n        }\n        val -= rhs.val;\n        return *this;\n    }\n\
    \    constexpr ModInt &operator*=(const ModInt &rhs) {\n        val = val * rhs.val\
    \ % MOD;\n        return *this;\n    }\n\n    constexpr ModInt &operator/=(const\
    \ ModInt &rhs) {\n        *this *= rhs.inv();\n        return *this;\n    }\n\n\
    \    constexpr bool operator==(const ModInt &rhs) { return this->a == rhs.a; }\n\
    \    constexpr bool operator!=(const ModInt &rhs) { return this->a != rhs.a; }\n\
    \    friend constexpr ostream &operator<<(ostream &os, const ModInt<MOD> &x) {\n\
    \        return os << x.val;\n    }\n    friend constexpr istream &operator>>(istream\
    \ &is, ModInt<MOD> &x) {\n        return is >> x.val;\n    }\n\n    constexpr\
    \ ModInt inv() const { return ModInt(*this).pow(MOD - 2); }\n\n    constexpr ModInt\
    \ pow(long long e) const {\n        u64 x = 1, p = val;\n        while(e > 0)\
    \ {\n            if(e % 2 == 0) {\n                p = (p * p) % MOD;\n      \
    \          e /= 2;\n            } else {\n                x = (x * p) % MOD;\n\
    \                e--;\n            }\n        }\n        return ModInt(x);\n \
    \   }\n};\n\ntemplate <typename Mint> class Convolution {\n  private:\n    constexpr\
    \ int primroot(int p) {\n        if(p == 2)\n            return 1;\n        if(p\
    \ == 167772161)\n            return 3;\n        if(p == 469762049)\n         \
    \   return 3;\n        if(p == 754974721)\n            return 11;\n        if(p\
    \ == 998244353)\n            return 3;\n        assert(false);\n    }\n\n  public:\n\
    \    void _ntt(vector<Mint> &a, bool is_inverse) {\n        const int n = a.size();\n\
    \        const int mod = Mint::get_mod();\n        const int g = primroot(mod);\n\
    \        assert((n ^ (n & -n)) == 0);\n        Mint h = Mint(g).pow((mod - 1)\
    \ / n);\n        h = (is_inverse ? h.inv() : h);\n\n        int i = 0;\n     \
    \   for(int j = 1; j < n - 1; j++) {\n            for(int k = n >> 1; k > (i ^=\
    \ k); k >>= 1)\n                ;\n            if(j < i)\n                swap(a[i],\
    \ a[j]);\n        }\n\n        for(int m = 1; m < n; m *= 2) {\n            const\
    \ int m2 = 2 * m;\n            const Mint base = h.pow(n / m2);\n            Mint\
    \ w = 1;\n            for(int x = 0; x < m; x++) {\n                for(int s\
    \ = x; s < n; s += m2) {\n                    Mint u = a[s];\n               \
    \     Mint d = a[s + m] * w;\n                    a[s] = u + d;\n            \
    \        a[s + m] = u - d;\n                }\n                w *= base;\n  \
    \          }\n        }\n    }\n\n    void ntt(vector<Mint> &a) { _ntt(a, false);\
    \ }\n    void intt(vector<Mint> &a) {\n        _ntt(a, true);\n        int n =\
    \ a.size();\n        Mint n_inv = Mint(n).inv();\n        for(auto &x : a)\n \
    \           x *= n_inv;\n    }\n\n    vector<Mint> convolution(const vector<Mint>\
    \ &_a, const vector<Mint> &_b) {\n        vector<Mint> a(_a), b(_b);\n       \
    \ int s = a.size() + b.size() - 1;\n        int t = 1;\n        while(t < s)\n\
    \            t *= 2;\n        a.resize(t);\n        b.resize(t);\n\n        ntt(a);\n\
    \        ntt(b);\n        for(int i = 0; i < t; i++) {\n            a[i] *= b[i];\n\
    \        }\n        intt(a);\n        return a;\n    }\n\n    template <typename\
    \ T>\n    vector<Mint> convolution(const vector<T> &_a, const vector<T> &_b) {\n\
    \        vector<Mint> a(_a.size()), b(_b.size());\n        for(int i = 0; i <\
    \ a.size(); i++)\n            a[i] = _a[i];\n        for(int i = 0; i < b.size();\
    \ i++)\n            b[i] = _b[i];\n        return convolution(a, b);\n    }\n\
    };\n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    vector<int> a(n), b(m);\n\
    \    for(int i = 0; i < n; i++)\n        cin >> a[i];\n    for(int i = 0; i <\
    \ m; i++)\n        cin >> b[i];\n    using mint = ModInt<998244353>;\n    Convolution<mint>\
    \ ntt;\n    auto ans = ntt.convolution(a, b);\n    for(int i = 0; i < ans.size();\
    \ i++)\n        cout << ans[i] << \" \\n\"[i == ans.size() - 1];\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n/*\
    \ ModInt */\ntemplate <uint_fast64_t MOD> class ModInt {\n    using u64 = uint_fast64_t;\n\
    \n  public:\n    u64 val;\n\n    ModInt(const u64 x = 0) : val((x + MOD) % MOD)\
    \ {}\n    constexpr u64 &value() { return val; }\n    static const u64 get_mod()\
    \ { return MOD; }\n    constexpr ModInt operator-() { return val ? MOD - val :\
    \ 0; }\n    constexpr ModInt operator+(const ModInt &rhs) const {\n        return\
    \ ModInt(*this) += rhs;\n    }\n    constexpr ModInt operator-(const ModInt &rhs)\
    \ const {\n        return ModInt(*this) -= rhs;\n    }\n    constexpr ModInt operator*(const\
    \ ModInt &rhs) const {\n        return ModInt(*this) *= rhs;\n    }\n    constexpr\
    \ ModInt operator/(const ModInt &rhs) const {\n        return ModInt(*this) /=\
    \ rhs;\n    }\n    constexpr ModInt &operator+=(const ModInt &rhs) {\n       \
    \ val += rhs.val;\n        if(val >= MOD) {\n            val -= MOD;\n       \
    \ }\n        return *this;\n    }\n    constexpr ModInt &operator-=(const ModInt\
    \ &rhs) {\n        if(val < rhs.val) {\n            val += MOD;\n        }\n \
    \       val -= rhs.val;\n        return *this;\n    }\n    constexpr ModInt &operator*=(const\
    \ ModInt &rhs) {\n        val = val * rhs.val % MOD;\n        return *this;\n\
    \    }\n\n    constexpr ModInt &operator/=(const ModInt &rhs) {\n        *this\
    \ *= rhs.inv();\n        return *this;\n    }\n\n    constexpr bool operator==(const\
    \ ModInt &rhs) { return this->a == rhs.a; }\n    constexpr bool operator!=(const\
    \ ModInt &rhs) { return this->a != rhs.a; }\n    friend constexpr ostream &operator<<(ostream\
    \ &os, const ModInt<MOD> &x) {\n        return os << x.val;\n    }\n    friend\
    \ constexpr istream &operator>>(istream &is, ModInt<MOD> &x) {\n        return\
    \ is >> x.val;\n    }\n\n    constexpr ModInt inv() const { return ModInt(*this).pow(MOD\
    \ - 2); }\n\n    constexpr ModInt pow(long long e) const {\n        u64 x = 1,\
    \ p = val;\n        while(e > 0) {\n            if(e % 2 == 0) {\n           \
    \     p = (p * p) % MOD;\n                e /= 2;\n            } else {\n    \
    \            x = (x * p) % MOD;\n                e--;\n            }\n       \
    \ }\n        return ModInt(x);\n    }\n};\n\ntemplate <typename Mint> class Convolution\
    \ {\n  private:\n    constexpr int primroot(int p) {\n        if(p == 2)\n   \
    \         return 1;\n        if(p == 167772161)\n            return 3;\n     \
    \   if(p == 469762049)\n            return 3;\n        if(p == 754974721)\n  \
    \          return 11;\n        if(p == 998244353)\n            return 3;\n   \
    \     assert(false);\n    }\n\n  public:\n    void _ntt(vector<Mint> &a, bool\
    \ is_inverse) {\n        const int n = a.size();\n        const int mod = Mint::get_mod();\n\
    \        const int g = primroot(mod);\n        assert((n ^ (n & -n)) == 0);\n\
    \        Mint h = Mint(g).pow((mod - 1) / n);\n        h = (is_inverse ? h.inv()\
    \ : h);\n\n        int i = 0;\n        for(int j = 1; j < n - 1; j++) {\n    \
    \        for(int k = n >> 1; k > (i ^= k); k >>= 1)\n                ;\n     \
    \       if(j < i)\n                swap(a[i], a[j]);\n        }\n\n        for(int\
    \ m = 1; m < n; m *= 2) {\n            const int m2 = 2 * m;\n            const\
    \ Mint base = h.pow(n / m2);\n            Mint w = 1;\n            for(int x =\
    \ 0; x < m; x++) {\n                for(int s = x; s < n; s += m2) {\n       \
    \             Mint u = a[s];\n                    Mint d = a[s + m] * w;\n   \
    \                 a[s] = u + d;\n                    a[s + m] = u - d;\n     \
    \           }\n                w *= base;\n            }\n        }\n    }\n\n\
    \    void ntt(vector<Mint> &a) { _ntt(a, false); }\n    void intt(vector<Mint>\
    \ &a) {\n        _ntt(a, true);\n        int n = a.size();\n        Mint n_inv\
    \ = Mint(n).inv();\n        for(auto &x : a)\n            x *= n_inv;\n    }\n\
    \n    vector<Mint> convolution(const vector<Mint> &_a, const vector<Mint> &_b)\
    \ {\n        vector<Mint> a(_a), b(_b);\n        int s = a.size() + b.size() -\
    \ 1;\n        int t = 1;\n        while(t < s)\n            t *= 2;\n        a.resize(t);\n\
    \        b.resize(t);\n\n        ntt(a);\n        ntt(b);\n        for(int i =\
    \ 0; i < t; i++) {\n            a[i] *= b[i];\n        }\n        intt(a);\n \
    \       return a;\n    }\n\n    template <typename T>\n    vector<Mint> convolution(const\
    \ vector<T> &_a, const vector<T> &_b) {\n        vector<Mint> a(_a.size()), b(_b.size());\n\
    \        for(int i = 0; i < a.size(); i++)\n            a[i] = _a[i];\n      \
    \  for(int i = 0; i < b.size(); i++)\n            b[i] = _b[i];\n        return\
    \ convolution(a, b);\n    }\n};\n\nint main() {\n    int n, m;\n    cin >> n >>\
    \ m;\n    vector<int> a(n), b(m);\n    for(int i = 0; i < n; i++)\n        cin\
    \ >> a[i];\n    for(int i = 0; i < m; i++)\n        cin >> b[i];\n    using mint\
    \ = ModInt<998244353>;\n    Convolution<mint> ntt;\n    auto ans = ntt.convolution(a,\
    \ b);\n    for(int i = 0; i < ans.size(); i++)\n        cout << ans[i] << \" \\\
    n\"[i == ans.size() - 1];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Convolution.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Convolution.cc
layout: document
redirect_from:
- /library/Math/Convolution.cc
- /library/Math/Convolution.cc.html
title: Math/Convolution.cc
---
