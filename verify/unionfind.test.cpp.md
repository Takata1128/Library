---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.cc
    title: DataStructure/UnionFind.cc
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#line 1 \"DataStructure/UnionFind.cc\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n// UnionFind\r\nstruct UnionFind {\r\n    vector<int> par;\r\n \
    \   vector<int> siz;\r\n\r\n    UnionFind(int N) : par(N), siz(N, 1) {\r\n   \
    \     for(int i = 0; i < N; i++)\r\n            par[i] = i;\r\n    }\r\n    int\
    \ root(int x) {\r\n        if(par[x] == x)\r\n            return x;\r\n      \
    \  return par[x] = root(par[x]);\r\n    }\r\n    void unite(int x, int y) {\r\n\
    \        int rx = root(x);\r\n        int ry = root(y);\r\n        if(rx == ry)\r\
    \n            return;\r\n        if(siz[rx] < siz[ry])\r\n            swap(rx,\
    \ ry);\r\n        siz[rx] += siz[ry];\r\n        par[ry] = rx;\r\n    }\r\n  \
    \  bool same(int x, int y) {\r\n        int rx = root(x);\r\n        int ry =\
    \ root(y);\r\n        return rx == ry;\r\n    }\r\n    int size(int x) { return\
    \ siz[root(x)]; }\r\n};\r\n\r\n//\u3000\u91CD\u307F\u4ED8\u304DUnionFind\r\ntemplate\
    \ <typename T> struct WeightedUnionFind {\r\n    vector<int> par;\r\n    vector<int>\
    \ siz;\r\n    vector<T> diff_weight;\r\n\r\n    WeightedUnionFind(int N) : par(N),\
    \ siz(N, 1), diff_weight(N, T(0)) {\r\n        for(int i = 0; i < N; i++) {\r\n\
    \            par[i] = i;\r\n        }\r\n    }\r\n\r\n    T weight(int x) {\r\n\
    \        root(x);\r\n        return diff_weight[x];\r\n    }\r\n\r\n    T diff(int\
    \ x, int y) { return weight(y) - weight(x); }\r\n\r\n    int root(int x) {\r\n\
    \        if(par[x] == x)\r\n            return x;\r\n        else {\r\n      \
    \      int r = root(par[x]);\r\n            diff_weight[x] += diff_weight[par[x]];\r\
    \n            return par[x] = r;\r\n        }\r\n    }\r\n    void unite(int x,\
    \ int y, T w) {\r\n        w += weight(x), w -= weight(y);\r\n        int rx =\
    \ root(x);\r\n        int ry = root(y);\r\n        if(rx == ry)\r\n          \
    \  return;\r\n        if(siz[rx] < siz[ry])\r\n            swap(rx, ry), w = -w;\r\
    \n        siz[rx] += siz[ry];\r\n        par[ry] = rx;\r\n        diff_weight[ry]\
    \ = w;\r\n    }\r\n    bool same(int x, int y) {\r\n        int rx = root(x);\r\
    \n        int ry = root(y);\r\n        return rx == ry;\r\n    }\r\n    int size(int\
    \ x) { return siz[root(x)]; }\r\n};\n#line 1 \"Others/template.cc\"\n#pragma region\
    \ Macros\n#line 3 \"Others/template.cc\"\n#define rep(i, n) for(int(i) = 0; (i)\
    \ < (n); (i)++)\n#define rrep(i, n) for(int(i) = (n)-1; (i) >= 0; (i)--)\n#define\
    \ FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)\n#define ROF(i, m, n) for(int(i)\
    \ = (n)-1; (i) >= (m); (i)--)\n#define ALL(v) (v).begin(), (v).end()\n#define\
    \ LLA(v) (v).rbegin(), (v).rend()\n#define SZ(v) (int)(v).size()\n#define INT(...)\
    \                                                               \\\n    int __VA_ARGS__;\
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
    \         \\\n    read(name)\n#define DVEC(type, name1, name2, size)         \
    \                                \\\n    vector<type> name1(size), name2(size);\
    \                                     \\\n    read(name1, name2);\n#define TVEC(type,\
    \ name1, name2, name3, size)                                  \\\n    vector<type>\
    \ name1(size), name2(size), name3(size);                        \\\n    read(name1,\
    \ name2, name3);\nusing namespace std;\nusing ll = long long;\nusing pii = pair<int,\
    \ int>;\nusing pll = pair<ll, ll>;\nconst int INF = 1 << 30;\nconst ll LINF =\
    \ 1LL << 60;\nconst int MOD = 1e9 + 7;\nconst char newl = '\\n';\nconst int dx[]\
    \ = {1, 0, -1, 0};\nconst int dy[] = {0, 1, 0, -1};\ntemplate <class T> inline\
    \ bool between(T x, T l, T r) {\n    return l <= x && x < r;\n}\ntemplate <class\
    \ T> inline vector<T> make_vec(size_t a, T val) {\n    return vector<T>(a, val);\n\
    }\ntemplate <class... Ts> inline auto make_vec(size_t a, Ts... ts) {\n    return\
    \ vector<decltype(make_vec(ts...))>(a, make_vec(ts...));\n}\nvoid read() {}\n\
    template <class T> inline void read(T &a) { cin >> a; }\ntemplate <class T, class\
    \ S> inline void read(pair<T, S> &p) {\n    read(p.first), read(p.second);\n}\n\
    template <class T> inline void read(vector<T> &v) {\n    for(auto &&a : v)\n \
    \       read(a);\n}\ntemplate <class T, class U> inline void read(vector<T> &a,\
    \ vector<U> &b) {\n    for(int i = 0; i < a.size(); i++) {\n        read(a[i]);\n\
    \        read(b[i]);\n    }\n}\ntemplate <class T, class U, class V>\ninline void\
    \ read(vector<T> &a, vector<U> &b, vector<V> &c) {\n    for(int i = 0; i < a.size();\
    \ i++) {\n        read(a[i]);\n        read(b[i]);\n        read(c[i]);\n    }\n\
    }\ntemplate <class Head, class... Tail>\ninline void read(Head &head, Tail &...tail)\
    \ {\n    read(head), read(tail...);\n}\ntemplate <class T> void write(const T\
    \ &a) { cout << a << '\\n'; }\ntemplate <class T> void write(const vector<T> &a)\
    \ {\n    for(int i = 0; i < a.size(); i++)\n        cout << a[i] << (i + 1 ==\
    \ a.size() ? '\\n' : ' ');\n}\ntemplate <class Head, class... Tail>\nvoid write(const\
    \ Head &head, const Tail &...tail) {\n    cout << head << ' ';\n    write(tail...);\n\
    }\ntemplate <class T> void writel(const T &a) { cout << a << '\\n'; }\ntemplate\
    \ <class T> void writel(const vector<T> &a) {\n    for(int i = 0; i < a.size();\
    \ i++)\n        cout << a[i] << '\\n';\n}\ntemplate <class Head, class... Tail>\n\
    void writel(const Head &head, const Tail &...tail) {\n    cout << head << '\\\
    n';\n    write(tail...);\n}\ntemplate <class T> auto sum(const vector<T> &a) {\n\
    \    return accumulate(ALL(a), T(0));\n}\ntemplate <class T> auto min(const vector<T>\
    \ &a) { return *min_element(ALL(a)); }\ntemplate <class T> auto max(const vector<T>\
    \ &a) { return *max_element(ALL(a)); }\ntemplate <class T, class U> void msort(vector<T>\
    \ &a, vector<U> &b) {\n    assert(a.size() == b.size());\n    vector<pair<T, U>>\
    \ ab(a.size());\n    for(int i = 0; i < a.size(); i++)\n        ab[i] = {a[i],\
    \ b[i]};\n    sort(ALL(ab));\n    for(int i = 0; i < a.size(); i++) {\n      \
    \  a[i] = ab[i].first;\n        b[i] = ab[i].second;\n    }\n}\ntemplate <class\
    \ T, class U, class V>\nvoid msort(vector<T> &a, vector<U> &b, vector<V> &c) {\n\
    \    assert(a.size() == b.size() && b.size() == c.size());\n    vector<tuple<T,\
    \ U, V>> abc(a.size());\n    for(int i = 0; i < a.size(); i++)\n        abc[i]\
    \ = {a[i], b[i], c[i]};\n    sort(ALL(abc));\n    for(int i = 0; i < a.size();\
    \ i++) {\n        a[i] = get<0>(abc[i]);\n        b[i] = get<1>(abc[i]);\n   \
    \     c[i] = get<2>(abc[i]);\n    }\n}\ntemplate <class T, class U> inline bool\
    \ chmax(T &a, U b) {\n    if(a < b) {\n        a = b;\n        return 1;\n   \
    \ }\n    return 0;\n}\ntemplate <class T, class U> inline bool chmin(T &a, U b)\
    \ {\n    if(a > b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n\
    }\nint digit(ll a) {\n    ll ret = 0;\n    while(a && ++ret)\n        a /= 10;\n\
    \    return ret;\n}\nint digit_sum(ll a) {\n    ll ret = 0;\n    while(a) {\n\
    \        ret += a % 10;\n        a /= 10;\n    }\n    return ret;\n}\nll llpow(ll\
    \ a, ll n) {\n    ll ret = 1;\n    rep(i, n) ret *= a;\n    return ret;\n}\ninline\
    \ int bsf(int v) { return __builtin_ctz(v); } // \u6700\u4E0B\u4F4D\u306E1\u304C\
    \u4E0B\u304B\u3089\u4F55\u756A\u76EE\u304B\ninline int bsf(ll v) { return __builtin_ctzll(v);\
    \ }\ninline int bsr(int v) {\n    return 31 - __builtin_clz(v);\n} // \u6700\u4E0A\
    \u4F4D\u306E1\u304C\u4E0B\u304B\u3089\u4F55\u756A\u76EE\u304B\ninline int bsr(ll\
    \ v) { return 63 - __builtin_clzll(v); }\ninline int lsb(int v) { return v & -v;\
    \ } // \u6700\u4E0A\u4F4D\u306E1\u3060\u3051\u6B8B\u3059\ninline ll lsb(ll v)\
    \ { return v & -v; }\ninline int msb(int v) { return 1 << bsr(v); } // \u6700\u4E0A\
    \u4F4D\u306E1\u3060\u3051\u6B8B\u3059\ninline ll msb(ll v) { return 1LL << bsr(v);\
    \ }\nstruct IO {\n    IO() {\n        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(10);\n    }\n} io;\n#pragma endregion\n\
    #line 4 \"verify/unionfind.test.cpp\"\n\nint main() {\n    INT(n, q);\n    UnionFind\
    \ uf(n);\n    rep(i, q) {\n        INT(t, u, v);\n        if(t == 1) {\n     \
    \       write(uf.same(u, v) ? 1 : 0);\n        } else {\n            uf.unite(u,\
    \ v);\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    ../DataStructure/UnionFind.cc\"\n#include \"../Others/template.cc\"\n\nint main()\
    \ {\n    INT(n, q);\n    UnionFind uf(n);\n    rep(i, q) {\n        INT(t, u,\
    \ v);\n        if(t == 1) {\n            write(uf.same(u, v) ? 1 : 0);\n     \
    \   } else {\n            uf.unite(u, v);\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/UnionFind.cc
  - Others/template.cc
  isVerificationFile: true
  path: verify/unionfind.test.cpp
  requiredBy: []
  timestamp: '2021-07-10 17:10:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/unionfind.test.cpp
- /verify/verify/unionfind.test.cpp.html
title: verify/unionfind.test.cpp
---
