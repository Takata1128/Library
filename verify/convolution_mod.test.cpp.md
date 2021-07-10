---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/ConvolutionNTT.cc
    title: Math/ConvolutionNTT.cc
  - icon: ':heavy_check_mark:'
    path: Math/ModInt.cc
    title: Math/ModInt.cc
  - icon: ':heavy_check_mark:'
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
    \n#line 1 \"Math/ConvolutionNTT.cc\"\n#include <bits/stdc++.h>\nusing namespace\
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
    using mint = ModInt<1000000007UL>;\r\n// using mint = ModInt<998244353UL>;\r\n\
    #line 1 \"Others/template.cc\"\n#pragma region Macros\n#line 3 \"Others/template.cc\"\
    \n#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)\n#define rrep(i, n) for(int(i)\
    \ = (n)-1; (i) >= 0; (i)--)\n#define FOR(i, m, n) for(int(i) = (m); (i) < (n);\
    \ (i)++)\n#define ROF(i, m, n) for(int(i) = (n)-1; (i) >= (m); (i)--)\n#define\
    \ ALL(v) (v).begin(), (v).end()\n#define LLA(v) (v).rbegin(), (v).rend()\n#define\
    \ SZ(v) (int)(v).size()\n#define INT(...)                                    \
    \                           \\\n    int __VA_ARGS__;                         \
    \                                  \\\n    read(__VA_ARGS__)\n#define LL(...)\
    \                                                                \\\n    ll __VA_ARGS__;\
    \                                                            \\\n    read(__VA_ARGS__)\n\
    #define DOUBLE(...)                                                          \
    \  \\\n    double __VA_ARGS__;                                               \
    \         \\\n    read(__VA_ARGS__)\n#define CHAR(...)                       \
    \                                       \\\n    char __VA_ARGS__;            \
    \                                              \\\n    read(__VA_ARGS__)\n#define\
    \ STRING(...)                                                            \\\n\
    \    string __VA_ARGS__;                                                     \
    \   \\\n    read(__VA_ARGS__)\n#define VEC(type, name, size)                 \
    \                                 \\\n    vector<type> name(size);           \
    \                                        \\\n    read(name)\n#define VEC2(type,\
    \ name, height, width)                                        \\\n    vector<vector<type>>\
    \ name(height, vector<type>(width));                    \\\n    read(name)\n#define\
    \ DVEC(type, name1, name2, size)                                         \\\n\
    \    vector<type> name1(size), name2(size);                                  \
    \   \\\n    read(name1, name2);\n#define TVEC(type, name1, name2, name3, size)\
    \                                  \\\n    vector<type> name1(size), name2(size),\
    \ name3(size);                        \\\n    read(name1, name2, name3);\nusing\
    \ namespace std;\nusing ll = long long;\nusing pii = pair<int, int>;\nusing pll\
    \ = pair<ll, ll>;\nconst int INF = 1 << 30;\nconst ll LINF = 1LL << 60;\nconst\
    \ int MOD = 1e9 + 7;\nconst char newl = '\\n';\nconst int dx[] = {1, 0, -1, 0};\n\
    const int dy[] = {0, 1, 0, -1};\ntemplate <class T> inline bool between(T x, T\
    \ l, T r) {\n    return l <= x && x < r;\n}\ntemplate <class T> inline vector<T>\
    \ make_vec(size_t a, T val) {\n    return vector<T>(a, val);\n}\ntemplate <class...\
    \ Ts> inline auto make_vec(size_t a, Ts... ts) {\n    return vector<decltype(make_vec(ts...))>(a,\
    \ make_vec(ts...));\n}\nvoid read() {}\ntemplate <class T> inline void read(T\
    \ &a) { cin >> a; }\ntemplate <class T, class S> inline void read(pair<T, S> &p)\
    \ {\n    read(p.first), read(p.second);\n}\ntemplate <class T> inline void read(vector<T>\
    \ &v) {\n    for(auto &&a : v)\n        read(a);\n}\ntemplate <class T, class\
    \ U> inline void read(vector<T> &a, vector<U> &b) {\n    for(int i = 0; i < a.size();\
    \ i++) {\n        read(a[i]);\n        read(b[i]);\n    }\n}\ntemplate <class\
    \ T, class U, class V>\ninline void read(vector<T> &a, vector<U> &b, vector<V>\
    \ &c) {\n    for(int i = 0; i < a.size(); i++) {\n        read(a[i]);\n      \
    \  read(b[i]);\n        read(c[i]);\n    }\n}\ntemplate <class Head, class...\
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
    template <class T> auto sum(const vector<T> &a) {\n    return accumulate(ALL(a),\
    \ T(0));\n}\ntemplate <class T> auto min(const vector<T> &a) { return *min_element(ALL(a));\
    \ }\ntemplate <class T> auto max(const vector<T> &a) { return *max_element(ALL(a));\
    \ }\ntemplate <class T, class U> void msort(vector<T> &a, vector<U> &b) {\n  \
    \  assert(a.size() == b.size());\n    vector<pair<T, U>> ab(a.size());\n    for(int\
    \ i = 0; i < a.size(); i++)\n        ab[i] = {a[i], b[i]};\n    sort(ALL(ab));\n\
    \    for(int i = 0; i < a.size(); i++) {\n        a[i] = ab[i].first;\n      \
    \  b[i] = ab[i].second;\n    }\n}\ntemplate <class T, class U, class V>\nvoid\
    \ msort(vector<T> &a, vector<U> &b, vector<V> &c) {\n    assert(a.size() == b.size()\
    \ && b.size() == c.size());\n    vector<tuple<T, U, V>> abc(a.size());\n    for(int\
    \ i = 0; i < a.size(); i++)\n        abc[i] = {a[i], b[i], c[i]};\n    sort(ALL(abc));\n\
    \    for(int i = 0; i < a.size(); i++) {\n        a[i] = get<0>(abc[i]);\n   \
    \     b[i] = get<1>(abc[i]);\n        c[i] = get<2>(abc[i]);\n    }\n}\ntemplate\
    \ <class T, class U> inline bool chmax(T &a, U b) {\n    if(a < b) {\n       \
    \ a = b;\n        return 1;\n    }\n    return 0;\n}\ntemplate <class T, class\
    \ U> inline bool chmin(T &a, U b) {\n    if(a > b) {\n        a = b;\n       \
    \ return 1;\n    }\n    return 0;\n}\nint digit(ll a) {\n    ll ret = 0;\n   \
    \ while(a && ++ret)\n        a /= 10;\n    return ret;\n}\nint digit_sum(ll a)\
    \ {\n    ll ret = 0;\n    while(a) {\n        ret += a % 10;\n        a /= 10;\n\
    \    }\n    return ret;\n}\nll llpow(ll a, ll n) {\n    ll ret = 1;\n    rep(i,\
    \ n) ret *= a;\n    return ret;\n}\ninline int bsf(int v) { return __builtin_ctz(v);\
    \ } // \u6700\u4E0B\u4F4D\u306E1\u304C\u4E0B\u304B\u3089\u4F55\u756A\u76EE\u304B\
    \ninline int bsf(ll v) { return __builtin_ctzll(v); }\ninline int bsr(int v) {\n\
    \    return 31 - __builtin_clz(v);\n} // \u6700\u4E0A\u4F4D\u306E1\u304C\u4E0B\
    \u304B\u3089\u4F55\u756A\u76EE\u304B\ninline int bsr(ll v) { return 63 - __builtin_clzll(v);\
    \ }\ninline int lsb(int v) { return v & -v; } // \u6700\u4E0A\u4F4D\u306E1\u3060\
    \u3051\u6B8B\u3059\ninline ll lsb(ll v) { return v & -v; }\ninline int msb(int\
    \ v) { return 1 << bsr(v); } // \u6700\u4E0A\u4F4D\u306E1\u3060\u3051\u6B8B\u3059\
    \ninline ll msb(ll v) { return 1LL << bsr(v); }\nstruct IO {\n    IO() {\n   \
    \     ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout <<\
    \ fixed << setprecision(10);\n    }\n} io;\n#pragma endregion\n#line 5 \"verify/convolution_mod.test.cpp\"\
    \n\nint main() {\n    INT(n, m);\n    VEC(int, a, n);\n    VEC(int, b, m);\n \
    \   using mint = ModInt<998244353>;\n    Convolution<mint> ntt;\n    auto ans\
    \ = ntt.convolution(a, b);\n    for(int i = 0; i < n + m - 1; i++)\n        cout\
    \ << ans[i] << \" \\n\"[i == ans.size() - 1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ \"../Math/ConvolutionNTT.cc\"\n#include \"../Math/ModInt.cc\"\n#include \"../Others/template.cc\"\
    \n\nint main() {\n    INT(n, m);\n    VEC(int, a, n);\n    VEC(int, b, m);\n \
    \   using mint = ModInt<998244353>;\n    Convolution<mint> ntt;\n    auto ans\
    \ = ntt.convolution(a, b);\n    for(int i = 0; i < n + m - 1; i++)\n        cout\
    \ << ans[i] << \" \\n\"[i == ans.size() - 1];\n}\n"
  dependsOn:
  - Math/ConvolutionNTT.cc
  - Math/ModInt.cc
  - Others/template.cc
  isVerificationFile: true
  path: verify/convolution_mod.test.cpp
  requiredBy: []
  timestamp: '2021-07-10 17:13:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/convolution_mod.test.cpp
- /verify/verify/convolution_mod.test.cpp.html
title: verify/convolution_mod.test.cpp
---
