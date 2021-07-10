---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.cc
    title: DataStructure/SegmentTree.cc
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/staticrmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n#line 1 \"DataStructure/SegmentTree.cc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <class S> struct SegmentTree {\n  private:\n    using Op = function<S(S,\
    \ S)>;\n    const Op op;\n    const S e;\n    int n;\n    int org_size;\n    vector<S>\
    \ dat;\n\n  public:\n    void set(int k, S a) { dat[k + n] = a; }\n\n    void\
    \ build() {\n        for(int i = n - 1; i > 0; i--) {\n            dat[i] = op(dat[2\
    \ * i], dat[2 * i + 1]);\n        }\n    }\n\n    void update(int k, const S &a)\
    \ {\n        k += n;\n        dat[k] = a;\n        while(k >>= 1) {\n        \
    \    dat[k] = op(dat[k * 2], dat[k * 2 + 1]);\n        }\n    }\n\n    S at(int\
    \ a) const { return query(a, a + 1); }\n\n    // query for [a,b)\n    S query(int\
    \ a, int b) const {\n        S vl = e, vr = e;\n        a += n, b += n;\n    \
    \    for(; a < b; a >>= 1, b >>= 1) {\n            if(a & 1)\n               \
    \ vl = op(vl, dat[a++]);\n            if(b & 1)\n                vr = op(dat[--b],\
    \ vr);\n        }\n        return op(vl, vr);\n    }\n\n    int max_right(int\
    \ l, function<bool(S)> f) const {\n        if(l == org_size)\n            return\
    \ org_size;\n        l += n;\n        S cum = e;\n        do {\n            while(l\
    \ % 2 == 0)\n                l >>= 1;\n            if(!f(op(cum, dat[l]))) {\n\
    \                while(l < n) {\n                    l = 2 * l;\n            \
    \        if(f(op(cum, dat[l]))) {\n                        cum = op(cum, dat[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - n;\n            }\n            cum = op(cum, dat[l]);\n\
    \            l++;\n        } while((l & -l) != l);\n        return org_size;\n\
    \    }\n\n    // !!\u672Averify!!\n    int min_left(int r, function<bool(S)> f)\
    \ const {\n        if(r == 0)\n            return 0;\n        r += n;\n      \
    \  S cum = e;\n        do {\n            r--;\n            while(r > 1 && (r %\
    \ 2))\n                r >>= 1;\n            if(!f(op(dat[r], cum))) {\n     \
    \           while(r < n) {\n                    r = 2 * r + 1;\n             \
    \       if(f(op(dat[r], cum))) {\n                        cum = op(dat[r], cum);\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - n;\n            }\n            cum = op(dat[r], cum);\n\
    \        } while((r & (-r) != r));\n        return 0;\n    }\n\n    SegmentTree(int\
    \ _n, const Op op, const S &e) : op(op), e(e) {\n        org_size = _n;\n    \
    \    n = 1;\n        while(n < org_size)\n            n *= 2;\n        dat.assign(2\
    \ * n, e);\n    }\n\n    SegmentTree(const vector<S> &v, const Op op, const S\
    \ &e) : op(op), e(e) {\n        org_size = v.size();\n        n = 1;\n       \
    \ while(n < org_size)\n            n *= 2;\n        dat.assign(2 * n, e);\n  \
    \      for(int i = 0; i < org_size; i++)\n            set(i, v[i]);\n        build();\n\
    \    }\n};\n\n// struct S {};\n// S op(const S &a, const S &b){};\n#line 1 \"\
    Others/template.cc\"\n#pragma region Macros\n#line 3 \"Others/template.cc\"\n\
    #define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)\n#define rrep(i, n) for(int(i)\
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
    \ fixed << setprecision(10);\n    }\n} io;\n#pragma endregion\n#line 4 \"verify/staticrmq.test.cpp\"\
    \n\nusing S = int;\nS op(S a, S b) { return min(a, b); };\nS e() { return INF;\
    \ }\n\nint main() {\n    INT(n, q);\n    VEC(int, a, n);\n    SegmentTree<S> st(a,\
    \ op, e());\n    rep(i, q) {\n        INT(l, r);\n        write(st.query(l, r));\n\
    \    }\n}\n"
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
  timestamp: '2021-07-10 17:10:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/verify/staticrmq.test.cpp
- /verify/verify/staticrmq.test.cpp.html
title: verify/staticrmq.test.cpp
---
