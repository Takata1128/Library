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
  bundledCode: "#line 1 \"Others/cp-template.cc\"\n#pragma region Macros\n#include\
    \ <bits/stdc++.h>\n#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)\n#define\
    \ FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)\n#define ALL(v) (v).begin(),\
    \ (v).end()\n#define LLA(v) (v).rbegin(), (v).rend()\n#define SZ(v) (int)(v).size()\n\
    #define INT(...)     \\\n    int __VA_ARGS__; \\\n    read(__VA_ARGS__)\n#define\
    \ LL(...)     \\\n    ll __VA_ARGS__; \\\n    read(__VA_ARGS__)\n#define DOUBLE(...)\
    \     \\\n    double __VA_ARGS__; \\\n    read(__VA_ARGS__)\n#define CHAR(...)\
    \     \\\n    char __VA_ARGS__; \\\n    read(__VA_ARGS__)\n#define STRING(...)\
    \     \\\n    string __VA_ARGS__; \\\n    read(__VA_ARGS__)\n#define VEC(type,\
    \ name, size) \\\n    vector<type> name(size);  \\\n    read(name)\n#define VEC2(type,\
    \ name, height, width)                     \\\n    vector<vector<type>> name(height,\
    \ vector<type>(width)); \\\n    read(name)\nusing namespace std;\nusing ll = long\
    \ long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\nusing Graph =\
    \ vector<vector<int>>;\ntemplate <typename T> struct edge {\n    int from, to;\n\
    \    T cost;\n    edge(int f, int t, T c) : from(f), to(t), cost(c) {}\n};\ntemplate\
    \ <typename T> using WGraph = vector<vector<edge<T>>>;\nconst int INF = 1 << 30;\n\
    const ll LINF = 1LL << 60;\nconst int MOD = 1e9 + 7;\nconst char newl = '\\n';\n\
    template <class T> inline vector<T> make_vec(size_t a, T val) {\n    return vector<T>(a,\
    \ val);\n}\ntemplate <class... Ts> inline auto make_vec(size_t a, Ts... ts) {\n\
    \    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));\n}\nvoid read()\
    \ {}\ntemplate <class T> inline void read(T &a) { cin >> a; }\ntemplate <class\
    \ T, class S> inline void read(pair<T, S> &p) {\n    read(p.first), read(p.second);\n\
    }\ntemplate <class T> inline void read(vector<T> &v) {\n    for(auto &&a : v)\n\
    \        read(a);\n}\ntemplate <class Head, class... Tail>\ninline void read(Head\
    \ &head, Tail &...tail) {\n    read(head), read(tail...);\n}\ntemplate <class\
    \ T> void write(const T &a) { cout << a << '\\n'; }\ntemplate <class T, class\
    \ S> void write(const pair<T, S> &a) {\n    cout << a.first << ' ' << a.second\
    \ << '\\n';\n}\ntemplate <class T> void write(const vector<T> &a) {\n    for(int\
    \ i = 0; i < a.size(); i++)\n        cout << a[i] << (i + 1 == a.size() ? '\\\
    n' : ' ');\n}\ntemplate <class Head, class... Tail>\nvoid write(const Head &head,\
    \ const Tail &...tail) {\n    cout << head << ' ';\n    write(tail...);\n}\ntemplate\
    \ <class T> void debug(const T &a) { cerr << a << '\\n'; }\ntemplate <class T,\
    \ class S> void debug(const pair<T, S> &a) {\n    cerr << a.first << ' ' << a.second\
    \ << '\\n';\n}\ntemplate <class T> void debug(const vector<T> &a) {\n    for(int\
    \ i = 0; i < a.size(); i++)\n        cerr << a[i] << (i + 1 == a.size() ? '\\\
    n' : ' ');\n}\ntemplate <class Head, class... Tail>\nvoid debug(const Head &head,\
    \ const Tail &...tail) {\n    cerr << head << ' ';\n    debug(tail...);\n}\ntemplate\
    \ <class T> void writel(const vector<T> &a) {\n    for(int i = 0; i < a.size();\
    \ i++)\n        write(a[i]);\n}\ntemplate <class Head, class... Tail>\nvoid writel(const\
    \ Head &head, const Tail &...tail) {\n    cout << head << '\\n';\n    write(tail...);\n\
    }\ntemplate <class T> auto sum(const vector<T> &a) {\n    return accumulate(ALL(a),\
    \ T(0));\n}\ntemplate <class T> auto min(const vector<T> &a) { return *min_element(ALL(a));\
    \ }\ntemplate <class T> auto max(const vector<T> &a) { return *max_element(ALL(a));\
    \ }\ntemplate <class T, class U> inline bool chmax(T &a, U b) {\n    if(a < b)\
    \ {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\ntemplate <class\
    \ T, class U> inline bool chmin(T &a, U b) {\n    if(a > b) {\n        a = b;\n\
    \        return 1;\n    }\n    return 0;\n}\nstruct IO {\n    IO() {\n       \
    \ ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n        cout << fixed\
    \ << setprecision(10);\n    }\n} io;\n#pragma endregion\n\nvoid solve() {\n  \
    \  $1\n}\n\nint main() {\n    // INT(t);\n    int t = 1;\n    while(t--) {\n \
    \       solve();\n    }\n}\n"
  code: "#pragma region Macros\n#include <bits/stdc++.h>\n#define rep(i, n) for(int(i)\
    \ = 0; (i) < (n); (i)++)\n#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)\n\
    #define ALL(v) (v).begin(), (v).end()\n#define LLA(v) (v).rbegin(), (v).rend()\n\
    #define SZ(v) (int)(v).size()\n#define INT(...)     \\\n    int __VA_ARGS__; \\\
    \n    read(__VA_ARGS__)\n#define LL(...)     \\\n    ll __VA_ARGS__; \\\n    read(__VA_ARGS__)\n\
    #define DOUBLE(...)     \\\n    double __VA_ARGS__; \\\n    read(__VA_ARGS__)\n\
    #define CHAR(...)     \\\n    char __VA_ARGS__; \\\n    read(__VA_ARGS__)\n#define\
    \ STRING(...)     \\\n    string __VA_ARGS__; \\\n    read(__VA_ARGS__)\n#define\
    \ VEC(type, name, size) \\\n    vector<type> name(size);  \\\n    read(name)\n\
    #define VEC2(type, name, height, width)                     \\\n    vector<vector<type>>\
    \ name(height, vector<type>(width)); \\\n    read(name)\nusing namespace std;\n\
    using ll = long long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    using Graph = vector<vector<int>>;\ntemplate <typename T> struct edge {\n    int\
    \ from, to;\n    T cost;\n    edge(int f, int t, T c) : from(f), to(t), cost(c)\
    \ {}\n};\ntemplate <typename T> using WGraph = vector<vector<edge<T>>>;\nconst\
    \ int INF = 1 << 30;\nconst ll LINF = 1LL << 60;\nconst int MOD = 1e9 + 7;\nconst\
    \ char newl = '\\n';\ntemplate <class T> inline vector<T> make_vec(size_t a, T\
    \ val) {\n    return vector<T>(a, val);\n}\ntemplate <class... Ts> inline auto\
    \ make_vec(size_t a, Ts... ts) {\n    return vector<decltype(make_vec(ts...))>(a,\
    \ make_vec(ts...));\n}\nvoid read() {}\ntemplate <class T> inline void read(T\
    \ &a) { cin >> a; }\ntemplate <class T, class S> inline void read(pair<T, S> &p)\
    \ {\n    read(p.first), read(p.second);\n}\ntemplate <class T> inline void read(vector<T>\
    \ &v) {\n    for(auto &&a : v)\n        read(a);\n}\ntemplate <class Head, class...\
    \ Tail>\ninline void read(Head &head, Tail &...tail) {\n    read(head), read(tail...);\n\
    }\ntemplate <class T> void write(const T &a) { cout << a << '\\n'; }\ntemplate\
    \ <class T, class S> void write(const pair<T, S> &a) {\n    cout << a.first <<\
    \ ' ' << a.second << '\\n';\n}\ntemplate <class T> void write(const vector<T>\
    \ &a) {\n    for(int i = 0; i < a.size(); i++)\n        cout << a[i] << (i + 1\
    \ == a.size() ? '\\n' : ' ');\n}\ntemplate <class Head, class... Tail>\nvoid write(const\
    \ Head &head, const Tail &...tail) {\n    cout << head << ' ';\n    write(tail...);\n\
    }\ntemplate <class T> void debug(const T &a) { cerr << a << '\\n'; }\ntemplate\
    \ <class T, class S> void debug(const pair<T, S> &a) {\n    cerr << a.first <<\
    \ ' ' << a.second << '\\n';\n}\ntemplate <class T> void debug(const vector<T>\
    \ &a) {\n    for(int i = 0; i < a.size(); i++)\n        cerr << a[i] << (i + 1\
    \ == a.size() ? '\\n' : ' ');\n}\ntemplate <class Head, class... Tail>\nvoid debug(const\
    \ Head &head, const Tail &...tail) {\n    cerr << head << ' ';\n    debug(tail...);\n\
    }\ntemplate <class T> void writel(const vector<T> &a) {\n    for(int i = 0; i\
    \ < a.size(); i++)\n        write(a[i]);\n}\ntemplate <class Head, class... Tail>\n\
    void writel(const Head &head, const Tail &...tail) {\n    cout << head << '\\\
    n';\n    write(tail...);\n}\ntemplate <class T> auto sum(const vector<T> &a) {\n\
    \    return accumulate(ALL(a), T(0));\n}\ntemplate <class T> auto min(const vector<T>\
    \ &a) { return *min_element(ALL(a)); }\ntemplate <class T> auto max(const vector<T>\
    \ &a) { return *max_element(ALL(a)); }\ntemplate <class T, class U> inline bool\
    \ chmax(T &a, U b) {\n    if(a < b) {\n        a = b;\n        return 1;\n   \
    \ }\n    return 0;\n}\ntemplate <class T, class U> inline bool chmin(T &a, U b)\
    \ {\n    if(a > b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n\
    }\nstruct IO {\n    IO() {\n        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(10);\n    }\n} io;\n#pragma endregion\n\
    \nvoid solve() {\n    $1\n}\n\nint main() {\n    // INT(t);\n    int t = 1;\n\
    \    while(t--) {\n        solve();\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: Others/cp-template.cc
  requiredBy: []
  timestamp: '2021-06-08 21:09:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/cp-template.cc
layout: document
redirect_from:
- /library/Others/cp-template.cc
- /library/Others/cp-template.cc.html
title: Others/cp-template.cc
---
