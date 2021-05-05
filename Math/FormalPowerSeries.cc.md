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
  bundledCode: "#line 1 \"Math/FormalPowerSeries.cc\"\n#pragma region Macros\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\ntemplate <class\
    \ T> void write(const T &a) { cout << a << '\\n'; }\ntemplate <class T> void write(const\
    \ vector<T> &a) {\n    for(int i = 0; i < a.size(); i++)\n        cout << a[i]\
    \ << (i + 1 == a.size() ? '\\n' : ' ');\n}\nstruct IO {\n    IO() {\n        ios::sync_with_stdio(false);\n\
    \        cin.tie(nullptr);\n        cout << fixed << setprecision(10);\n    }\n\
    } io;\n\n#pragma endregion\n\ntemplate <uint_fast64_t MOD> class ModInt {\n  \
    \  using u64 = uint_fast64_t;\n\n  public:\n    u64 val;\n\n    ModInt(const u64\
    \ x = 0) : val((x + MOD) % MOD) {}\n    constexpr u64 &value() { return val; }\n\
    \    constexpr ModInt operator-() { return val ? MOD - val : 0; }\n    constexpr\
    \ ModInt operator+(const ModInt &rhs) const {\n        return ModInt(*this) +=\
    \ rhs;\n    }\n    constexpr ModInt operator-(const ModInt &rhs) const {\n   \
    \     return ModInt(*this) -= rhs;\n    }\n    constexpr ModInt operator*(const\
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
    \ ModInt &rhs) {\n        return this->val == rhs.val;\n    }\n    constexpr bool\
    \ operator!=(const ModInt &rhs) {\n        return this->val != rhs.val;\n    }\n\
    \    friend constexpr ostream &operator<<(ostream &os, const ModInt<MOD> &x) {\n\
    \        return os << x.val;\n    }\n    friend constexpr istream &operator>>(istream\
    \ &is, ModInt<MOD> &x) {\n        return is >> x.val;\n    }\n\n    constexpr\
    \ ModInt inv() const { return ModInt(*this).pow(MOD - 2); }\n\n    constexpr ModInt\
    \ pow(ll e) const {\n        u64 x = 1, p = val;\n        while(e > 0) {\n   \
    \         if(e % 2 == 0) {\n                p = (p * p) % MOD;\n             \
    \   e /= 2;\n            } else {\n                x = (x * p) % MOD;\n      \
    \          e--;\n            }\n        }\n        return ModInt(x);\n    }\n\
    };\n\nconstexpr int primroot(int p) {\n    if(p == 2)\n        return 1;\n   \
    \ if(p == 167772161)\n        return 3;\n    if(p == 469762049)\n        return\
    \ 3;\n    if(p == 754974721)\n        return 11;\n    if(p == 998244353)\n   \
    \     return 3;\n    assert(false);\n}\n\ntemplate <typename T> struct FormalPowerSeries\
    \ : public vector<T> {\n    using vector<T>::vector;\n    using Mint = T;\n  \
    \  using F = FormalPowerSeries<T>;\n    template <int prime>\n    inline vector<ModInt<prime>>\
    \ ntt(vector<ModInt<prime>> a, bool is_inverse) {\n        auto f = [&](auto &&f,\
    \ vector<ModInt<prime>> a,\n                     bool is_inverse) -> vector<ModInt<prime>>\
    \ {\n            int n = a.size();\n            if(n == 1)\n                return\
    \ a;\n            vector<ModInt<prime>> f0(n / 2), f1(n / 2);\n            for(int\
    \ i = 0; i < (n / 2); i++) {\n                f0[i] = (a[i * 2]);\n          \
    \      f1[i] = (a[i * 2 + 1]);\n            }\n            f0 = f(f, f0, is_inverse),\
    \ f1 = f(f, f1, is_inverse);\n            ModInt<prime> zeta =\n             \
    \   (is_inverse\n                     ? ModInt<prime>(primroot(prime)).inv().pow(prime\
    \ / n)\n                     : ModInt<prime>(primroot(prime)).pow(prime / n));\n\
    \            ModInt<prime> pow_zeta = 1;\n            for(int i = 0; i < n; i++)\
    \ {\n                a[i] = (f0[i % (n / 2)] + pow_zeta * f1[i % (n / 2)]);\n\
    \                pow_zeta *= zeta;\n            }\n            return a;\n   \
    \     };\n        vector<ModInt<prime>> ret = f(f, a, is_inverse);\n        int\
    \ n = ret.size();\n        if(is_inverse) {\n            for(int i = 0; i < n;\
    \ i++) {\n                ret[i] *= ModInt<prime>(n).inv();\n            }\n \
    \       }\n        return ret;\n    }\n    template <int prime>\n    inline vector<ModInt<prime>>\
    \ convolve(const vector<Mint> &_a,\n                                         \
    \ const vector<Mint> &_b) {\n        vector<Mint> a(_a), b(_b);\n        int s\
    \ = a.size() + b.size() - 1;\n        int t = 1;\n        while(t < s)\n     \
    \       t *= 2;\n        a.resize(t);\n        b.resize(t);\n        vector<ModInt<prime>>\
    \ A = ntt<prime>(a, false);\n        vector<ModInt<prime>> B = ntt<prime>(b, false);\n\
    \        vector<ModInt<prime>> C(t);\n        for(int i = 0; i < t; i++) {\n \
    \           C[i] = (A[i] * B[i]);\n        }\n        C = ntt<prime>(C, true);\n\
    \        return C;\n    }\n\n    inline vector<ModInt<998244353>>\n    convolution(const\
    \ vector<ModInt<998244353>> &g,\n                const vector<ModInt<998244353>>\
    \ &h) {\n        return convolve<998244353>(g, h);\n    }\n\n    void shrink()\
    \ {\n        while(this->size() && this->back() == T(0))\n            this->pop_back();\n\
    \    }\n\n  public:\n    FormalPowerSeries(vector<Mint> v) {\n        *this =\
    \ FormalPowerSeries(v.size());\n        for(int i = 0; i < v.size(); i++)\n  \
    \          (*this)[i] = v[i];\n    }\n    F operator*(const Mint &g) const { return\
    \ F(*this) *= g; }\n    F &operator*=(const Mint &g) {\n        for(auto &e :\
    \ *this)\n            e *= g;\n        return *this;\n    }\n    F operator*(const\
    \ F &g) const { return F(*this) *= g; }\n    F &operator*=(const F &g) {\n   \
    \     if((*this).empty() || g.empty()) {\n            this->clear();\n       \
    \     return *this;\n        }\n        return *this = convolution(*this, g);\n\
    \    }\n    F operator/(const Mint &g) const { return F(*this) /= g; }\n    F\
    \ &operator/=(const Mint &g) {\n        assert(g != Mint(0));\n        return\
    \ (*this) *= g.inv();\n    }\n    F operator+(const F &g) const { return F(*this)\
    \ += g; }\n    F &operator+=(const F &g) {\n        if(g.size() > this->size())\
    \ {\n            this->resize(g.size());\n        }\n        for(int i = 0; i\
    \ < this->size(); i++)\n            (*this)[i] += g[i];\n        return *this;\n\
    \    }\n    F operator-(const F &g) const { return F(*this) -= g; }\n    F &operator-=(const\
    \ F &g) {\n        if(g.size() > this->size()) {\n            this->resize(g.size());\n\
    \        }\n        for(int i = 0; i < this->size(); i++)\n            (*this)[i]\
    \ -= g[i];\n        return *this;\n    }\n    F operator-() const {\n        F\
    \ res(*this);\n        for(auto &e : *this)\n            e = -e;\n        return\
    \ res;\n    }\n    F &operator<<=(const int d) {\n        int n = (*this).size();\n\
    \        (*this).insert((*this).begin(), d, 0);\n        (*this).resize(n);\n\
    \        return *this;\n    }\n    F &operator>>=(const int d) {\n        int\
    \ n = (*this).size();\n        (*this).erase((*this).begin(), (*this).begin()\
    \ + min(n, d));\n        (*this).resize(n);\n        return *this;\n    }\n  \
    \  F &operator=(const F &g) {\n        (*this).clear();\n        (*this).resize(g.size());\n\
    \        for(int i = 0; i < g.size(); i++)\n            (*this)[i] = g[i];\n \
    \       return *this;\n    }\n\n    F pre(int sz) const {\n        return F((*this).begin(),\n\
    \                 (*this).begin() + min(sz, (int)(*this).size()));\n    }\n\n\
    \    F inv(int d = -1) {\n        int n = (*this).size();\n        assert(n !=\
    \ 0 && (*this)[0] != Mint(0));\n        if(d == -1)\n            d = n;\n    \
    \    assert(d >= 0);\n        F ret({Mint(1) / (*this)[0]});\n        for(int\
    \ i = 1; i < d; i <<= 1) {\n            ret = (ret * 2 - ret * ret * pre(i <<\
    \ 1)).pre(i << 1);\n        }\n        return ret.pre(d);\n    }\n};\n\nint main()\
    \ {\n    int n;\n    cin >> n;\n    using mint = ModInt<998244353>;\n    FormalPowerSeries<mint>\
    \ a(n);\n    for(int i = 0; i < n; i++)\n        cin >> a[i];\n    auto b = a.inv();\n\
    \    for(int i = 0; i < n; i++) {\n        cout << b[i] << (i == n - 1 ? '\\n'\
    \ : ' ');\n    }\n}\n"
  code: "#pragma region Macros\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\ntemplate <class T> void write(const T &a) { cout << a << '\\\
    n'; }\ntemplate <class T> void write(const vector<T> &a) {\n    for(int i = 0;\
    \ i < a.size(); i++)\n        cout << a[i] << (i + 1 == a.size() ? '\\n' : ' ');\n\
    }\nstruct IO {\n    IO() {\n        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(10);\n    }\n} io;\n\n#pragma endregion\n\
    \ntemplate <uint_fast64_t MOD> class ModInt {\n    using u64 = uint_fast64_t;\n\
    \n  public:\n    u64 val;\n\n    ModInt(const u64 x = 0) : val((x + MOD) % MOD)\
    \ {}\n    constexpr u64 &value() { return val; }\n    constexpr ModInt operator-()\
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
    \    constexpr bool operator==(const ModInt &rhs) {\n        return this->val\
    \ == rhs.val;\n    }\n    constexpr bool operator!=(const ModInt &rhs) {\n   \
    \     return this->val != rhs.val;\n    }\n    friend constexpr ostream &operator<<(ostream\
    \ &os, const ModInt<MOD> &x) {\n        return os << x.val;\n    }\n    friend\
    \ constexpr istream &operator>>(istream &is, ModInt<MOD> &x) {\n        return\
    \ is >> x.val;\n    }\n\n    constexpr ModInt inv() const { return ModInt(*this).pow(MOD\
    \ - 2); }\n\n    constexpr ModInt pow(ll e) const {\n        u64 x = 1, p = val;\n\
    \        while(e > 0) {\n            if(e % 2 == 0) {\n                p = (p\
    \ * p) % MOD;\n                e /= 2;\n            } else {\n               \
    \ x = (x * p) % MOD;\n                e--;\n            }\n        }\n       \
    \ return ModInt(x);\n    }\n};\n\nconstexpr int primroot(int p) {\n    if(p ==\
    \ 2)\n        return 1;\n    if(p == 167772161)\n        return 3;\n    if(p ==\
    \ 469762049)\n        return 3;\n    if(p == 754974721)\n        return 11;\n\
    \    if(p == 998244353)\n        return 3;\n    assert(false);\n}\n\ntemplate\
    \ <typename T> struct FormalPowerSeries : public vector<T> {\n    using vector<T>::vector;\n\
    \    using Mint = T;\n    using F = FormalPowerSeries<T>;\n    template <int prime>\n\
    \    inline vector<ModInt<prime>> ntt(vector<ModInt<prime>> a, bool is_inverse)\
    \ {\n        auto f = [&](auto &&f, vector<ModInt<prime>> a,\n               \
    \      bool is_inverse) -> vector<ModInt<prime>> {\n            int n = a.size();\n\
    \            if(n == 1)\n                return a;\n            vector<ModInt<prime>>\
    \ f0(n / 2), f1(n / 2);\n            for(int i = 0; i < (n / 2); i++) {\n    \
    \            f0[i] = (a[i * 2]);\n                f1[i] = (a[i * 2 + 1]);\n  \
    \          }\n            f0 = f(f, f0, is_inverse), f1 = f(f, f1, is_inverse);\n\
    \            ModInt<prime> zeta =\n                (is_inverse\n             \
    \        ? ModInt<prime>(primroot(prime)).inv().pow(prime / n)\n             \
    \        : ModInt<prime>(primroot(prime)).pow(prime / n));\n            ModInt<prime>\
    \ pow_zeta = 1;\n            for(int i = 0; i < n; i++) {\n                a[i]\
    \ = (f0[i % (n / 2)] + pow_zeta * f1[i % (n / 2)]);\n                pow_zeta\
    \ *= zeta;\n            }\n            return a;\n        };\n        vector<ModInt<prime>>\
    \ ret = f(f, a, is_inverse);\n        int n = ret.size();\n        if(is_inverse)\
    \ {\n            for(int i = 0; i < n; i++) {\n                ret[i] *= ModInt<prime>(n).inv();\n\
    \            }\n        }\n        return ret;\n    }\n    template <int prime>\n\
    \    inline vector<ModInt<prime>> convolve(const vector<Mint> &_a,\n         \
    \                                 const vector<Mint> &_b) {\n        vector<Mint>\
    \ a(_a), b(_b);\n        int s = a.size() + b.size() - 1;\n        int t = 1;\n\
    \        while(t < s)\n            t *= 2;\n        a.resize(t);\n        b.resize(t);\n\
    \        vector<ModInt<prime>> A = ntt<prime>(a, false);\n        vector<ModInt<prime>>\
    \ B = ntt<prime>(b, false);\n        vector<ModInt<prime>> C(t);\n        for(int\
    \ i = 0; i < t; i++) {\n            C[i] = (A[i] * B[i]);\n        }\n       \
    \ C = ntt<prime>(C, true);\n        return C;\n    }\n\n    inline vector<ModInt<998244353>>\n\
    \    convolution(const vector<ModInt<998244353>> &g,\n                const vector<ModInt<998244353>>\
    \ &h) {\n        return convolve<998244353>(g, h);\n    }\n\n    void shrink()\
    \ {\n        while(this->size() && this->back() == T(0))\n            this->pop_back();\n\
    \    }\n\n  public:\n    FormalPowerSeries(vector<Mint> v) {\n        *this =\
    \ FormalPowerSeries(v.size());\n        for(int i = 0; i < v.size(); i++)\n  \
    \          (*this)[i] = v[i];\n    }\n    F operator*(const Mint &g) const { return\
    \ F(*this) *= g; }\n    F &operator*=(const Mint &g) {\n        for(auto &e :\
    \ *this)\n            e *= g;\n        return *this;\n    }\n    F operator*(const\
    \ F &g) const { return F(*this) *= g; }\n    F &operator*=(const F &g) {\n   \
    \     if((*this).empty() || g.empty()) {\n            this->clear();\n       \
    \     return *this;\n        }\n        return *this = convolution(*this, g);\n\
    \    }\n    F operator/(const Mint &g) const { return F(*this) /= g; }\n    F\
    \ &operator/=(const Mint &g) {\n        assert(g != Mint(0));\n        return\
    \ (*this) *= g.inv();\n    }\n    F operator+(const F &g) const { return F(*this)\
    \ += g; }\n    F &operator+=(const F &g) {\n        if(g.size() > this->size())\
    \ {\n            this->resize(g.size());\n        }\n        for(int i = 0; i\
    \ < this->size(); i++)\n            (*this)[i] += g[i];\n        return *this;\n\
    \    }\n    F operator-(const F &g) const { return F(*this) -= g; }\n    F &operator-=(const\
    \ F &g) {\n        if(g.size() > this->size()) {\n            this->resize(g.size());\n\
    \        }\n        for(int i = 0; i < this->size(); i++)\n            (*this)[i]\
    \ -= g[i];\n        return *this;\n    }\n    F operator-() const {\n        F\
    \ res(*this);\n        for(auto &e : *this)\n            e = -e;\n        return\
    \ res;\n    }\n    F &operator<<=(const int d) {\n        int n = (*this).size();\n\
    \        (*this).insert((*this).begin(), d, 0);\n        (*this).resize(n);\n\
    \        return *this;\n    }\n    F &operator>>=(const int d) {\n        int\
    \ n = (*this).size();\n        (*this).erase((*this).begin(), (*this).begin()\
    \ + min(n, d));\n        (*this).resize(n);\n        return *this;\n    }\n  \
    \  F &operator=(const F &g) {\n        (*this).clear();\n        (*this).resize(g.size());\n\
    \        for(int i = 0; i < g.size(); i++)\n            (*this)[i] = g[i];\n \
    \       return *this;\n    }\n\n    F pre(int sz) const {\n        return F((*this).begin(),\n\
    \                 (*this).begin() + min(sz, (int)(*this).size()));\n    }\n\n\
    \    F inv(int d = -1) {\n        int n = (*this).size();\n        assert(n !=\
    \ 0 && (*this)[0] != Mint(0));\n        if(d == -1)\n            d = n;\n    \
    \    assert(d >= 0);\n        F ret({Mint(1) / (*this)[0]});\n        for(int\
    \ i = 1; i < d; i <<= 1) {\n            ret = (ret * 2 - ret * ret * pre(i <<\
    \ 1)).pre(i << 1);\n        }\n        return ret.pre(d);\n    }\n};\n\nint main()\
    \ {\n    int n;\n    cin >> n;\n    using mint = ModInt<998244353>;\n    FormalPowerSeries<mint>\
    \ a(n);\n    for(int i = 0; i < n; i++)\n        cin >> a[i];\n    auto b = a.inv();\n\
    \    for(int i = 0; i < n; i++) {\n        cout << b[i] << (i == n - 1 ? '\\n'\
    \ : ' ');\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/FormalPowerSeries.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/FormalPowerSeries.cc
layout: document
redirect_from:
- /library/Math/FormalPowerSeries.cc
- /library/Math/FormalPowerSeries.cc.html
title: Math/FormalPowerSeries.cc
---
