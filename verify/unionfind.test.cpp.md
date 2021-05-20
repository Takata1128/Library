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
    \ < (n); (i)++)\n#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)\n#define\
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
    \ name(height, vector<type>(width));                    \\\n    read(name)\nusing\
    \ namespace std;\nusing ll = long long;\nusing pii = pair<int, int>;\nusing pll\
    \ = pair<ll, ll>;\nusing Graph = vector<vector<int>>;\ntemplate <typename T> struct\
    \ edge {\n    int from, to;\n    T cost;\n    edge(int f, int t, T c) : from(f),\
    \ to(t), cost(c) {}\n};\ntemplate <typename T> using WGraph = vector<vector<edge<T>>>;\n\
    const int INF = 1 << 30;\nconst ll LINF = 1LL << 60;\nconst int MOD = 1e9 + 7;\n\
    const char newl = '\\n';\ntemplate <class T> inline vector<T> make_vec(size_t\
    \ a, T val) {\n    return vector<T>(a, val);\n}\ntemplate <class... Ts> inline\
    \ auto make_vec(size_t a, Ts... ts) {\n    return vector<decltype(make_vec(ts...))>(a,\
    \ make_vec(ts...));\n}\nvoid read() {}\ntemplate <class T> inline void read(T\
    \ &a) { cin >> a; }\ntemplate <class T, class S> inline void read(pair<T, S> &p)\
    \ {\n    read(p.first), read(p.second);\n}\ntemplate <class T> inline void read(vector<T>\
    \ &v) {\n    for(auto &&a : v)\n        read(a);\n}\ntemplate <class Head, class...\
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
    \ }\ntemplate <class T, class U> inline bool chmax(T &a, U b) {\n    if(a < b)\
    \ {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\ntemplate <class\
    \ T, class U> inline bool chmin(T &a, U b) {\n    if(a > b) {\n        a = b;\n\
    \        return 1;\n    }\n    return 0;\n}\nstruct IO {\n    IO() {\n       \
    \ ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout << fixed\
    \ << setprecision(10);\n    }\n} io;\n#pragma endregion\n#line 4 \"verify/unionfind.test.cpp\"\
    \n\nint main() {\n    INT(n, q);\n    UnionFind uf(n);\n    rep(i, q) {\n    \
    \    INT(t, u, v);\n        if(t == 1) {\n            write(uf.same(u, v) ? 1\
    \ : 0);\n        } else {\n            uf.unite(u, v);\n        }\n    }\n   \
    \ return 0;\n}\n"
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
  timestamp: '2021-05-17 20:13:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/unionfind.test.cpp
- /verify/verify/unionfind.test.cpp.html
title: verify/unionfind.test.cpp
---
