---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/Convolution.cc
    title: Math/Convolution.cc
  - icon: ':x:'
    path: Math/FormalPowerSeries.cc
    title: Math/FormalPowerSeries.cc
  - icon: ':question:'
    path: Math/ModInt.cc
    title: Math/ModInt.cc
  - icon: ':question:'
    path: Others/template.cc
    title: Others/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/inv_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/inv_of_formal_power_series
  bundledCode: "#line 1 \"verify/inv_of_formal_power_series.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\n#line 1 \"Math/Convolution.cc\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\ntemplate\
    \ <typename Mint> class Convolution {\n  private:\n    constexpr int primroot(int\
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
    \        a.resize(t);\n        b.resize(t);\n        ntt(a);\n        ntt(b);\n\
    \        for(int i = 0; i < t; i++) {\n            a[i] *= b[i];\n        }\n\
    \        intt(a);\n        return a;\n    }\n\n    template <typename T>\n   \
    \ vector<Mint> convolution(const vector<T> &_a, const vector<T> &_b) {\n     \
    \   vector<Mint> a(_a.size()), b(_b.size());\n        for(int i = 0; i < a.size();\
    \ i++)\n            a[i] = _a[i];\n        for(int i = 0; i < b.size(); i++)\n\
    \            b[i] = _b[i];\n        return convolution(a, b);\n    }\n};\n#line\
    \ 2 \"Math/FormalPowerSeries.cc\"\nusing namespace std;\n\ntemplate <typename\
    \ Mint> struct FormalPowerSeries : public vector<Mint> {\n    using vector<Mint>::vector;\n\
    \    using F = FormalPowerSeries<Mint>;\n    using CONV = function<vector<Mint>(vector<Mint>,\
    \ vector<Mint>)>;\n\n    static CONV &get_conv() {\n        static CONV conv =\
    \ nullptr;\n        return conv;\n    }\n\n    static void set_conv(CONV f) {\
    \ get_conv() = f; }\n\n    void shrink() {\n        while(this->size() && this->back()\
    \ == Mint(0))\n            this->pop_back();\n    }\n\n  public:\n    template\
    \ <typename T> FormalPowerSeries(vector<T> v) {\n        *this = FormalPowerSeries(v.size());\n\
    \        for(int i = 0; i < v.size(); i++)\n            (*this)[i] = Mint(v[i]);\n\
    \    }\n\n    F operator*(const Mint &g) const { return F(*this) *= g; }\n   \
    \ F &operator*=(const Mint &g) {\n        for(auto &e : *this)\n            e\
    \ *= g;\n        return *this;\n    }\n    F operator*(const F &g) const { return\
    \ F(*this) *= g; }\n    F &operator*=(const F &g) {\n        if((*this).empty()\
    \ || g.empty()) {\n            this->clear();\n            return *this;\n   \
    \     }\n        if(get_conv() == nullptr) {\n            assert(false);\n   \
    \     } else {\n            return *this = get_conv()(*this, g);\n        }\n\
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
    \       return *this;\n    }\n    template <typename T> F &operator=(const vector<T>\
    \ &g) {\n        (*this).clear();\n        (*this).resize(g.size());\n       \
    \ for(int i = 0; i < g.size(); i++)\n            (*this)[i] = Mint(g[i]);\n  \
    \      return *this;\n    }\n\n    F pre(int sz) const {\n        return F((*this).begin(),\n\
    \                 (*this).begin() + min(sz, (int)(*this).size()));\n    }\n\n\
    \    F inv(int d = -1) {\n        int n = (*this).size();\n        assert(n !=\
    \ 0 && (*this)[0] != Mint(0));\n        if(d == -1)\n            d = n;\n    \
    \    assert(d >= 0);\n        F ret({Mint(1) / (*this)[0]});\n        for(int\
    \ i = 1; i < d; i <<= 1) {\n            ret = (ret * 2 - ret * ret * pre(i <<\
    \ 1)).pre(i << 1);\n        }\n        return ret.pre(d);\n    }\n\n    // multiply\
    \ and divide (1+cz^d)\n    void multiply(const int d, const T c) {\n        int\
    \ n = this->size();\n        if(c == T(1))\n            for(int i = n - d; i >=\
    \ 0; i--)\n                (*this)[i + d] += (*this)[i];\n        else if(c ==\
    \ T(-1))\n            for(int i = n - d; i >= 0; i--)\n                (*this)[i\
    \ + d] -= (*this)[i];\n        else\n            for(int i = n - d; i >= 0; i--)\n\
    \                (*this)[i + d] += (*this)[i] * c;\n    }\n    void divide(const\
    \ int d, const T c) {\n        int n = this->size();\n        if(c == T(1))\n\
    \            for(int i = 0; i < n - d; i++)\n                (*this)[i + d] -=\
    \ (*this)[i];\n        else if(c == T(-1))\n            for(int i = 0; i < n -\
    \ d; i++)\n                (*this)[i + d] += (*this)[i];\n        else\n     \
    \       for(int i = 0; i < n - d; i++)\n                (*this)[i + d] -= (*this)[i]\
    \ * c;\n    }\n};\n#line 2 \"Math/ModInt.cc\"\nusing namespace std;\r\n/* ModInt\
    \ */\r\ntemplate <uint_fast64_t MOD> class ModInt {\r\n    using u64 = uint_fast64_t;\r\
    \n\r\n  public:\r\n    u64 val;\r\n\r\n    ModInt(const u64 x = 0) : val((x +\
    \ MOD) % MOD) {}\r\n    constexpr u64 &value() { return val; }\r\n    static const\
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
    \ &rhs) {\r\n        return this->val == rhs.val;\r\n    }\r\n    constexpr bool\
    \ operator!=(const ModInt &rhs) {\r\n        return this->val != rhs.val;\r\n\
    \    }\r\n    friend constexpr ostream &operator<<(ostream &os, const ModInt<MOD>\
    \ &x) {\r\n        return os << x.val;\r\n    }\r\n    friend constexpr istream\
    \ &operator>>(istream &is, ModInt<MOD> &x) {\r\n        return is >> x.val;\r\n\
    \    }\r\n\r\n    constexpr ModInt inv() const { return ModInt(*this).pow(MOD\
    \ - 2); }\r\n\r\n    constexpr ModInt pow(long long e) const {\r\n        u64\
    \ x = 1, p = val;\r\n        while(e > 0) {\r\n            if(e % 2 == 0) {\r\n\
    \                p = (p * p) % MOD;\r\n                e /= 2;\r\n           \
    \ } else {\r\n                x = (x * p) % MOD;\r\n                e--;\r\n \
    \           }\r\n        }\r\n        return ModInt(x);\r\n    }\r\n};\n#line\
    \ 1 \"Others/template.cc\"\n#pragma region Macros\n#line 3 \"Others/template.cc\"\
    \n#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)\n#define FOR(i, m, n) for(int(i)\
    \ = (m); (i) < (n); (i)++)\n#define ALL(v) (v).begin(), (v).end()\n#define LLA(v)\
    \ (v).rbegin(), (v).rend()\n#define SZ(v) (int)(v).size()\n#define INT(...)  \
    \                                                             \\\n    int __VA_ARGS__;\
    \                                                           \\\n    read(__VA_ARGS__)\n\
    #define LL(...)                                                              \
    \  \\\n    ll __VA_ARGS__;                                                   \
    \         \\\n    read(__VA_ARGS__)\n#define DOUBLE(...)                     \
    \                                       \\\n    double __VA_ARGS__;          \
    \                                              \\\n    read(__VA_ARGS__)\n#define\
    \ CHAR(...)                                                              \\\n\
    \    char __VA_ARGS__;                                                       \
    \   \\\n    read(__VA_ARGS__)\n#define STRING(...)                           \
    \                                 \\\n    string __VA_ARGS__;                \
    \                                        \\\n    read(__VA_ARGS__)\n#define VEC(type,\
    \ name, size)                                                  \\\n    vector<type>\
    \ name(size);                                                   \\\n    read(name)\n\
    #define VEC2(type, name, height, width)                                      \
    \  \\\n    vector<vector<type>> name(height, vector<type>(width));           \
    \         \\\n    read(name)\nusing namespace std;\nusing ll = long long;\nusing\
    \ pii = pair<int, int>;\nusing pll = pair<ll, ll>;\nusing Graph = vector<vector<int>>;\n\
    template <typename T> struct edge {\n    int from, to;\n    T cost;\n    edge(int\
    \ f, int t, T c) : from(f), to(t), cost(c) {}\n};\ntemplate <typename T> using\
    \ WGraph = vector<vector<edge<T>>>;\nconst int INF = 1 << 30;\nconst ll LINF =\
    \ 1LL << 60;\nconst int MOD = 1e9 + 7;\nconst char newl = '\\n';\ntemplate <class\
    \ T> inline vector<T> make_vec(size_t a, T val) {\n    return vector<T>(a, val);\n\
    }\ntemplate <class... Ts> inline auto make_vec(size_t a, Ts... ts) {\n    return\
    \ vector<decltype(make_vec(ts...))>(a, make_vec(ts...));\n}\nvoid read() {}\n\
    template <class T> inline void read(T &a) { cin >> a; }\ntemplate <class T, class\
    \ S> inline void read(pair<T, S> &p) {\n    read(p.first), read(p.second);\n}\n\
    template <class T> inline void read(vector<T> &v) {\n    for(auto &&a : v)\n \
    \       read(a);\n}\ntemplate <class Head, class... Tail>\ninline void read(Head\
    \ &head, Tail &...tail) {\n    read(head), read(tail...);\n}\ntemplate <class\
    \ T> void write(const T &a) { cout << a << '\\n'; }\ntemplate <class T> void write(const\
    \ vector<T> &a) {\n    for(int i = 0; i < a.size(); i++)\n        cout << a[i]\
    \ << (i + 1 == a.size() ? '\\n' : ' ');\n}\ntemplate <class Head, class... Tail>\n\
    void write(const Head &head, const Tail &...tail) {\n    cout << head << ' ';\n\
    \    write(tail...);\n}\ntemplate <class T> void writel(const T &a) { cout <<\
    \ a << '\\n'; }\ntemplate <class T> void writel(const vector<T> &a) {\n    for(int\
    \ i = 0; i < a.size(); i++)\n        cout << a[i] << '\\n';\n}\ntemplate <class\
    \ Head, class... Tail>\nvoid writel(const Head &head, const Tail &...tail) {\n\
    \    cout << head << '\\n';\n    write(tail...);\n}\ntemplate <class T> auto sum(const\
    \ vector<T> &a) {\n    return accumulate(ALL(a), T(0));\n}\ntemplate <class T>\
    \ auto min(const vector<T> &a) { return *min_element(ALL(a)); }\ntemplate <class\
    \ T> auto max(const vector<T> &a) { return *max_element(ALL(a)); }\ntemplate <class\
    \ T, class U> inline bool chmax(T &a, U b) {\n    if(a < b) {\n        a = b;\n\
    \        return 1;\n    }\n    return 0;\n}\ntemplate <class T, class U> inline\
    \ bool chmin(T &a, U b) {\n    if(a > b) {\n        a = b;\n        return 1;\n\
    \    }\n    return 0;\n}\nstruct IO {\n    IO() {\n        ios::sync_with_stdio(false);\n\
    \        cin.tie(nullptr);\n        cout << fixed << setprecision(10);\n    }\n\
    } io;\n#pragma endregion\n#line 6 \"verify/inv_of_formal_power_series.test.cpp\"\
    \n\nint main() {\n    INT(n);\n    VEC(int, a, n);\n    using mint = ModInt<998244353>;\n\
    \    auto f = [&](vector<mint> a, vector<mint> b) {\n        Convolution<mint>\
    \ ntt;\n        return ntt.convolution(a, b);\n    };\n    FormalPowerSeries<mint>\
    \ fps(a);\n    FormalPowerSeries<mint>::set_conv(f);\n    auto v = fps.inv();\n\
    \    write(vector<mint>(v));\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n#include \"../Math/Convolution.cc\"\n#include \"../Math/FormalPowerSeries.cc\"\
    \n#include \"../Math/ModInt.cc\"\n#include \"../Others/template.cc\"\n\nint main()\
    \ {\n    INT(n);\n    VEC(int, a, n);\n    using mint = ModInt<998244353>;\n \
    \   auto f = [&](vector<mint> a, vector<mint> b) {\n        Convolution<mint>\
    \ ntt;\n        return ntt.convolution(a, b);\n    };\n    FormalPowerSeries<mint>\
    \ fps(a);\n    FormalPowerSeries<mint>::set_conv(f);\n    auto v = fps.inv();\n\
    \    write(vector<mint>(v));\n}"
  dependsOn:
  - Math/Convolution.cc
  - Math/FormalPowerSeries.cc
  - Math/ModInt.cc
  - Others/template.cc
  isVerificationFile: true
  path: verify/inv_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2021-05-20 17:31:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/inv_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/verify/inv_of_formal_power_series.test.cpp
- /verify/verify/inv_of_formal_power_series.test.cpp.html
title: verify/inv_of_formal_power_series.test.cpp
---
