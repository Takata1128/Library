---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.cc
    title: DataStructure/SegmentTree.cc
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/staticrmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n#line 1 \"DataStructure/SegmentTree.cc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class S>\nstruct SegmentTree\n{\nprivate:\n    using Op =\
    \ function<S(S, S)>;\n    const Op op;\n    const S e;\n    int n;\n    int org_size;\n\
    \    vector<S> dat;\n\npublic:\n    void set(int k, S a) { dat[k + n] = a; }\n\
    \n    void build()\n    {\n        for (int i = n - 1; i > 0; i--)\n        {\n\
    \            dat[i] = op(dat[2 * i], dat[2 * i + 1]);\n        }\n    }\n\n  \
    \  void update(int k, const S &a)\n    {\n        k += n;\n        dat[k] = a;\n\
    \        while (k >>= 1)\n        {\n            dat[k] = op(dat[k * 2], dat[k\
    \ * 2 + 1]);\n        }\n    }\n\n    S at(int a) const { return query(a, a +\
    \ 1); }\n\n    // query for [a,b)\n    S query(int a, int b) const\n    {\n  \
    \      S vl = e, vr = e;\n        a += n, b += n;\n        for (; a < b; a >>=\
    \ 1, b >>= 1)\n        {\n            if (a & 1)\n                vl = op(vl,\
    \ dat[a++]);\n            if (b & 1)\n                vr = op(dat[--b], vr);\n\
    \        }\n        return op(vl, vr);\n    }\n\n    int max_right(int l, function<bool(S)>\
    \ f) const\n    {\n        if (l == org_size)\n            return org_size;\n\
    \        l += n;\n        S cum = e;\n        do\n        {\n            while\
    \ (l % 2 == 0)\n                l >>= 1;\n            if (!f(op(cum, dat[l])))\n\
    \            {\n                while (l < n)\n                {\n           \
    \         l = 2 * l;\n                    if (f(op(cum, dat[l])))\n          \
    \          {\n                        cum = op(cum, dat[l]);\n               \
    \         l++;\n                    }\n                }\n                return\
    \ l - n;\n            }\n            cum = op(cum, dat[l]);\n            l++;\n\
    \        } while ((l & -l) != l);\n        return org_size;\n    }\n\n    // !!\u672A\
    verify!!\n    int min_left(int r, function<bool(S)> f) const\n    {\n        if\
    \ (r == 0)\n            return 0;\n        r += n;\n        S cum = e;\n     \
    \   do\n        {\n            r--;\n            while (r > 1 && (r % 2))\n  \
    \              r >>= 1;\n            if (!f(op(dat[r], cum)))\n            {\n\
    \                while (r < n)\n                {\n                    r = 2 *\
    \ r + 1;\n                    if (f(op(dat[r], cum)))\n                    {\n\
    \                        cum = op(dat[r], cum);\n                        r--;\n\
    \                    }\n                }\n                return r + 1 - n;\n\
    \            }\n            cum = op(dat[r], cum);\n        } while ((r & (-r)\
    \ != r));\n        return 0;\n    }\n\n    SegmentTree(int _n, const Op op, const\
    \ S &e) : op(op), e(e)\n    {\n        org_size = _n;\n        n = 1;\n      \
    \  while (n < org_size)\n            n *= 2;\n        dat.assign(2 * n, e);\n\
    \    }\n\n    SegmentTree(const vector<S> &v, const Op op, const S &e) : op(op),\
    \ e(e)\n    {\n        org_size = v.size();\n        n = 1;\n        while (n\
    \ < org_size)\n            n *= 2;\n        dat.resize(2 * n);\n        for (int\
    \ i = 0; i < org_size; i++)\n            set(i, v[i]);\n        build();\n   \
    \ }\n};\n#line 1 \"Others/template.cc\"\n#pragma region Macros\n#line 3 \"Others/template.cc\"\
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
    } io;\n#pragma endregion\n#line 4 \"verify/staticrmq.test.cpp\"\n\nusing S = int;\n\
    S op(S a, S b) { return min(a, b); };\nS e() { return INF; }\n\nint main() {\n\
    \    INT(n, q);\n    VEC(int, a, n);\n    SegmentTree<S> st(a, op, e());\n   \
    \ rep(i, q) {\n        INT(l, r);\n        write(st.query(l, r));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    ../DataStructure/SegmentTree.cc\"\n#include \"../Others/template.cc\"\n\nusing\
    \ S = int;\nS op(S a, S b) { return min(a, b); };\nS e() { return INF; }\n\nint\
    \ main() {\n    INT(n, q);\n    VEC(int, a, n);\n    SegmentTree<S> st(a, op,\
    \ e());\n    rep(i, q) {\n        INT(l, r);\n        write(st.query(l, r));\n\
    \    }\n}"
  dependsOn:
  - DataStructure/SegmentTree.cc
  - Others/template.cc
  isVerificationFile: true
  path: verify/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2021-05-17 20:13:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/verify/staticrmq.test.cpp
- /verify/verify/staticrmq.test.cpp.html
title: verify/staticrmq.test.cpp
---
