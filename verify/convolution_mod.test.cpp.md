---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/Convolution.cc
    title: Math/Convolution.cc
  - icon: ':question:'
    path: Math/ModInt.cc
    title: Math/ModInt.cc
  - icon: ':question:'
    path: Others/template.cc
    title: Others/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"verify/convolution_mod.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\
    \n#line 1 \"Math/Convolution.cc\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\n\ntemplate <typename Mint> class Convolution {\n  private:\n\
    \    constexpr int primroot(int p) {\n        if(p == 2)\n            return 1;\n\
    \        if(p == 167772161)\n            return 3;\n        if(p == 469762049)\n\
    \            return 3;\n        if(p == 754974721)\n            return 11;\n \
    \       if(p == 998244353)\n            return 3;\n        assert(false);\n  \
    \  }\n\n  public:\n    void _ntt(vector<Mint> &a, bool is_inverse) {\n       \
    \ const int n = a.size();\n        const int mod = Mint::get_mod();\n        const\
    \ int g = primroot(mod);\n        assert((n ^ (n & -n)) == 0);\n        Mint h\
    \ = Mint(g).pow((mod - 1) / n);\n        h = (is_inverse ? h.inv() : h);\n\n \
    \       int i = 0;\n        for(int j = 1; j < n - 1; j++) {\n            for(int\
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
    \            t *= 2;\n        a.resize(t);\n        b.resize(t);\n        ntt(a);\n\
    \        ntt(b);\n        for(int i = 0; i < t; i++) {\n            a[i] *= b[i];\n\
    \        }\n        intt(a);\n        return a;\n    }\n\n    template <typename\
    \ T>\n    vector<Mint> convolution(const vector<T> &_a, const vector<T> &_b) {\n\
    \        vector<Mint> a(_a.size()), b(_b.size());\n        for(int i = 0; i <\
    \ a.size(); i++)\n            a[i] = _a[i];\n        for(int i = 0; i < b.size();\
    \ i++)\n            b[i] = _b[i];\n        return convolution(a, b);\n    }\n\
    };\n#line 2 \"Math/ModInt.cc\"\nusing namespace std;\r\n/* ModInt */\r\ntemplate\
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
    \ 2 \"Others/template.cc\"\n#pragma region Macros\n#line 4 \"Others/template.cc\"\
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
    using namespace std;\nusing ll = long long;\nusing pii = pair<int, int>;\nusing\
    \ pll = pair<ll, ll>;\nusing Graph = vector<vector<int>>;\ntemplate <typename\
    \ T> struct edge {\n    int from, to;\n    T cost;\n    edge(int f, int t, T c)\
    \ : from(f), to(t), cost(c) {}\n};\ntemplate <typename T> using WGraph = vector<vector<edge<T>>>;\n\
    const int INF = 1 << 30;\nconst ll LINF = 1LL << 60;\nconst int MOD = 1e9 + 7;\n\
    const char newl = '\\n';\ntemplate <class T> inline vector<T> make_vec(size_t\
    \ a, T val) {\n    return vector<T>(a, val);\n}\ntemplate <class... Ts> inline\
    \ auto make_vec(size_t a, Ts... ts) {\n    return vector<decltype(make_vec(ts...))>(a,\
    \ make_vec(ts...));\n}\nvoid read() {}\ntemplate <class T> inline void read(T\
    \ &a) { cin >> a; }\ntemplate <class T, class S> inline void read(pair<T, S> &p)\
    \ {\n    read(p.first), read(p.second);\n}\ntemplate <class T> inline void read(vector<T>\
    \ &v) {\n    for(auto &a : v)\n        read(a);\n}\ntemplate <class Head, class...\
    \ Tail>\ninline void read(Head &head, Tail &...tail) {\n    read(head), read(tail...);\n\
    }\ntemplate <class T> void write(const T &a) { cout << a << '\\n'; }\ntemplate\
    \ <class T> void write(const vector<T> &a) {\n    for(int i = 0; i < a.size();\
    \ i++)\n        cout << a[i] << (i + 1 == a.size() ? '\\n' : ' ');\n}\ntemplate\
    \ <class Head, class... Tail>\nvoid write(const Head &head, const Tail &...tail)\
    \ {\n    cout << head << ' ';\n    write(tail...);\n}\ntemplate <class T> void\
    \ writel(const T &a) { cout << a << '\\n'; }\ntemplate <class T> void writel(const\
    \ vector<T> &a) {\n    for(int i = 0; i < a.size(); i++)\n        cout << a[i]\
    \ << '\\n';\n}\ntemplate <class Head, class... Tail>\nvoid writel(const Head &head,\
    \ const Tail &...tail) {\n    cout << head << '\\n';\n    write(tail...);\n}\n\
    template <class T> auto sum(const T &a) { return accumulate(ALL(a), T(0)); }\n\
    template <class T> auto min(const T &a) { return *min_element(ALL(a)); }\ntemplate\
    \ <class T> auto max(const T &a) { return *max_element(ALL(a)); }\ntemplate <class\
    \ T> inline void chmax(T &a, T b) { (a < b ? a = b : a); }\ntemplate <class T>\
    \ inline void chmin(T &a, T b) { (a > b ? a = b : a); }\nstruct IO {\n    IO()\
    \ {\n        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n       \
    \ cout << fixed << setprecision(10);\n    }\n} io;\n#pragma endregion\n#line 5\
    \ \"verify/convolution_mod.test.cpp\"\n\nint main() {\n    INT(n, m);\n    VEC(int,\
    \ a, n);\n    VEC(int, b, m);\n    using mint = ModInt<998244353>;\n    Convolution<mint>\
    \ ntt;\n    auto ans = ntt.convolution(a, b);\n    for(int i = 0; i < n + m -\
    \ 1; i++)\n        cout << ans[i] << \" \\n\"[i == ans.size() - 1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ \"../Math/Convolution.cc\"\n#include \"../Math/ModInt.cc\"\n#include \"../Others/template.cc\"\
    \n\nint main() {\n    INT(n, m);\n    VEC(int, a, n);\n    VEC(int, b, m);\n \
    \   using mint = ModInt<998244353>;\n    Convolution<mint> ntt;\n    auto ans\
    \ = ntt.convolution(a, b);\n    for(int i = 0; i < n + m - 1; i++)\n        cout\
    \ << ans[i] << \" \\n\"[i == ans.size() - 1];\n}\n"
  dependsOn:
  - Math/Convolution.cc
  - Math/ModInt.cc
  - Others/template.cc
  isVerificationFile: true
  path: verify/convolution_mod.test.cpp
  requiredBy: []
  timestamp: '2021-05-09 19:12:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/convolution_mod.test.cpp
- /verify/verify/convolution_mod.test.cpp.html
title: verify/convolution_mod.test.cpp
---
