---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/staticrmq.test.cpp
    title: verify/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unionfind.test.cpp
    title: verify/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Others/template.cc\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
    #define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)\n#define FOR(i, m, n) for(int(i)\
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
    \ cout << fixed << setprecision(10);\n    }\n} io;\n#pragma endregion\n"
  code: "#pragma once\n#pragma region Macros\n#include <bits/stdc++.h>\n#define rep(i,\
    \ n) for(int(i) = 0; (i) < (n); (i)++)\n#define FOR(i, m, n) for(int(i) = (m);\
    \ (i) < (n); (i)++)\n#define ALL(v) (v).begin(), (v).end()\n#define LLA(v) (v).rbegin(),\
    \ (v).rend()\n#define SZ(v) (int)(v).size()\n#define INT(...)                \
    \                                               \\\n    int __VA_ARGS__;     \
    \                                                      \\\n    read(__VA_ARGS__)\n\
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
    \ cout << fixed << setprecision(10);\n    }\n} io;\n#pragma endregion\n"
  dependsOn: []
  isVerificationFile: false
  path: Others/template.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/staticrmq.test.cpp
  - verify/unionfind.test.cpp
documentation_of: Others/template.cc
layout: document
redirect_from:
- /library/Others/template.cc
- /library/Others/template.cc.html
title: Others/template.cc
---
