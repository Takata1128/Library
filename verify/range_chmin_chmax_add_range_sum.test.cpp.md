---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTreeBeats.cc
    title: DataStructure/SegmentTreeBeats.cc
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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"verify/range_chmin_chmax_add_range_sum.test.cpp\"\n#define\
    \ PROBLEM                                                                \\\n\
    \    \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\n#line\
    \ 1 \"DataStructure/SegmentTreeBeats.cc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <typename T> class SegmentTreeBeats {\n    const T inf = numeric_limits<T>::max();\n\
    \    int n, n2;\n    vector<T> f_max, s_max, max_n;\n    vector<T> f_min, s_min,\
    \ min_n;\n    vector<T> sum;\n    vector<T> len, ladd, lval;\n\n    void update_node_max(int\
    \ k, T x) {\n        sum[k] += (x - f_max[k]) * max_n[k];\n        if(f_max[k]\
    \ == f_min[k]) {\n            f_max[k] = f_min[k] = x;\n        } else if(f_max[k]\
    \ == s_min[k]) {\n            f_max[k] = s_min[k] = x;\n        } else {\n   \
    \         f_max[k] = x;\n        }\n        if(lval[k] != inf && x < lval[k])\n\
    \            lval[k] = x;\n    }\n    void update_node_min(int k, T x) {\n   \
    \     sum[k] += (x - f_min[k]) * min_n[k];\n        if(f_max[k] == f_min[k]) {\n\
    \            f_max[k] = f_min[k] = x;\n        } else if(s_max[k] == f_min[k])\
    \ {\n            s_max[k] = f_min[k] = x;\n        } else {\n            f_min[k]\
    \ = x;\n        }\n        if(lval[k] != inf && lval[k] < x)\n            lval[k]\
    \ = x;\n    }\n\n    void add_all(int k, T x) {\n        f_max[k] += x;\n    \
    \    if(s_max[k] != -inf)\n            s_max[k] += x;\n        f_min[k] += x;\n\
    \        if(s_min[k] != inf)\n            s_min[k] += x;\n\n        sum[k] +=\
    \ len[k] * x;\n        if(lval[k] != inf) {\n            lval[k] += x;\n     \
    \   } else\n            ladd[k] += x;\n    }\n\n    void update_all(int k, T x)\
    \ {\n        f_max[k] = x;\n        s_max[k] = -inf;\n        f_min[k] = x;\n\
    \        s_min[k] = inf;\n        max_n[k] = min_n[k] = len[k];\n        sum[k]\
    \ = x * len[k];\n        lval[k] = x;\n        ladd[k] = 0;\n    }\n\n    void\
    \ push(int k) {\n        if(n2 - 1 <= k)\n            return;\n\n        if(lval[k]\
    \ != inf) {\n            update_all(2 * k + 1, lval[k]);\n            update_all(2\
    \ * k + 2, lval[k]);\n            lval[k] = inf;\n            return;\n      \
    \  }\n\n        if(ladd[k] != 0) {\n            add_all(2 * k + 1, ladd[k]);\n\
    \            add_all(2 * k + 2, ladd[k]);\n            ladd[k] = 0;\n        }\n\
    \        if(f_max[k] < f_max[2 * k + 1])\n            update_node_max(2 * k +\
    \ 1, f_max[k]);\n        if(f_max[k] < f_max[2 * k + 2])\n            update_node_max(2\
    \ * k + 2, f_max[k]);\n\n        if(f_min[2 * k + 1] < f_min[k])\n           \
    \ update_node_min(2 * k + 1, f_min[k]);\n        if(f_min[2 * k + 2] < f_min[k])\n\
    \            update_node_min(2 * k + 2, f_min[k]);\n    }\n\n    void update(int\
    \ k) {\n        if(n2 - 1 <= k)\n            return;\n        sum[k] = sum[2 *\
    \ k + 1] + sum[2 * k + 2];\n        if(f_max[2 * k + 1] < f_max[2 * k + 2]) {\n\
    \            f_max[k] = f_max[2 * k + 2];\n            max_n[k] = max_n[2 * k\
    \ + 2];\n            s_max[k] = max(f_max[2 * k + 1], s_max[2 * k + 2]);\n   \
    \     } else if(f_max[2 * k + 1] > f_max[2 * k + 2]) {\n            f_max[k] =\
    \ f_max[2 * k + 1];\n            max_n[k] = max_n[2 * k + 1];\n            s_max[k]\
    \ = max(s_max[2 * k + 1], f_max[2 * k + 2]);\n        } else {\n            f_max[k]\
    \ = f_max[2 * k + 1];\n            max_n[k] = max_n[2 * k + 1] + max_n[2 * k +\
    \ 2];\n            s_max[k] = max(s_max[2 * k + 1], s_max[2 * k + 2]);\n     \
    \   }\n        if(f_min[2 * k + 1] < f_min[2 * k + 2]) {\n            f_min[k]\
    \ = f_min[2 * k + 1];\n            min_n[k] = min_n[2 * k + 1];\n            s_min[k]\
    \ = min(s_min[2 * k + 1], f_min[2 * k + 2]);\n        } else if(f_min[2 * k +\
    \ 1] > f_min[2 * k + 2]) {\n            f_min[k] = f_min[2 * k + 2];\n       \
    \     min_n[k] = min_n[2 * k + 2];\n            s_min[k] = min(f_min[2 * k + 1],\
    \ s_min[2 * k + 2]);\n        } else {\n            f_min[k] = f_min[2 * k + 1];\n\
    \            min_n[k] = min_n[2 * k + 1] + min_n[2 * k + 2];\n            s_min[k]\
    \ = min(s_min[2 * k + 1], s_min[2 * k + 2]);\n        }\n    }\n\n    void _update_min(T\
    \ x, int a, int b, int k, int l, int r) {\n        if(b <= l || r <= a || f_max[k]\
    \ <= x)\n            return;\n        if(a <= l && r <= b && s_max[k] < x) {\n\
    \            update_node_max(k, x);\n            return;\n        }\n        push(k);\n\
    \        _update_min(x, a, b, 2 * k + 1, l, (l + r) / 2);\n        _update_min(x,\
    \ a, b, 2 * k + 2, (l + r) / 2, r);\n        update(k);\n    }\n    void _update_max(T\
    \ x, int a, int b, int k, int l, int r) {\n        if(b <= l || r <= a || x <=\
    \ f_min[k])\n            return;\n        if(a <= l && r <= b && x < s_min[k])\
    \ {\n            update_node_min(k, x);\n            return;\n        }\n    \
    \    push(k);\n        _update_max(x, a, b, 2 * k + 1, l, (l + r) / 2);\n    \
    \    _update_max(x, a, b, 2 * k + 2, (l + r) / 2, r);\n        update(k);\n  \
    \  }\n\n    void _add_val(T x, int a, int b, int k, int l, int r) {\n        if(b\
    \ <= l || r <= a)\n            return;\n        if(a <= l && r <= b) {\n     \
    \       add_all(k, x);\n            return;\n        }\n        push(k);\n   \
    \     _add_val(x, a, b, 2 * k + 1, l, (l + r) / 2);\n        _add_val(x, a, b,\
    \ 2 * k + 2, (l + r) / 2, r);\n        update(k);\n    }\n\n    void _update_val(T\
    \ x, int a, int b, int k, int l, int r) {\n        if(b <= l || r <= a)\n    \
    \        return;\n        if(a <= l && r <= b) {\n            update_all(k, x);\n\
    \            return;\n        }\n        push(k);\n        _update_val(x, a, b,\
    \ 2 * k + 1, l, (l + r) / 2);\n        _update_val(x, a, b, 2 * k + 2, (l + r)\
    \ / 2, r);\n        update(k);\n    }\n    T _query_max(int a, int b, int k, int\
    \ l, int r) {\n        if(b <= l || r <= a)\n            return -inf;\n      \
    \  if(a <= l && r <= b) {\n            return f_max[k];\n        }\n        push(k);\n\
    \        T lv = _query_max(a, b, 2 * k + 1, l, (l + r) / 2);\n        T rv = _query_max(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n        return max(lv, rv);\n    }\n    T _query_min(int\
    \ a, int b, int k, int l, int r) {\n        if(b <= l || r <= a)\n           \
    \ return inf;\n        if(a <= l && r <= b) {\n            return f_min[k];\n\
    \        }\n        push(k);\n        T lv = _query_min(a, b, 2 * k + 1, l, (l\
    \ + r) / 2);\n        T rv = _query_min(a, b, 2 * k + 2, (l + r) / 2, r);\n  \
    \      return min(lv, rv);\n    }\n    T _query_sum(int a, int b, int k, int l,\
    \ int r) {\n        if(b <= l || r <= a)\n            return 0;\n        if(a\
    \ <= l && r <= b) {\n            return sum[k];\n        }\n        push(k);\n\
    \        T lv = _query_sum(a, b, 2 * k + 1, l, (l + r) / 2);\n        T rv = _query_sum(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n        return lv + rv;\n    }\n\n  public:\n\
    \    SegmentTreeBeats(int n) : SegmentTreeBeats(vector<T>(n)) {}\n    SegmentTreeBeats(const\
    \ vector<T> &a) : n(a.size()) {\n        n2 = 1;\n        while(n2 < n)\n    \
    \        n2 <<= 1;\n        f_max.assign(2 * n2, -inf);\n        s_max.assign(2\
    \ * n2, -inf);\n        max_n.resize(2 * n2);\n        f_min.assign(2 * n2, inf);\n\
    \        s_min.assign(2 * n2, inf);\n        min_n.resize(2 * n2);\n        sum.resize(2\
    \ * n2);\n        len.resize(2 * n2);\n        ladd.resize(2 * n2);\n        lval.assign(2\
    \ * n2, inf);\n        len[0] = n2;\n        for(int i = 0; i < n2 - 1; i++)\n\
    \            len[2 * i + 1] = len[2 * i + 2] = (len[i] >> 1);\n        for(int\
    \ i = 0; i < n; i++) {\n            f_max[n2 - 1 + i] = f_min[n2 - 1 + i] = sum[n2\
    \ - 1 + i] = a[i];\n            max_n[n2 - 1 + i] = min_n[n2 - 1 + i] = 1;\n \
    \       }\n        for(int i = n2 - 2; i >= 0; i--) {\n            update(i);\n\
    \        }\n    }\n\n    T at(int k) { return query_sum(k, k + 1); };\n\n    void\
    \ update_min(int a, int b, T x) { _update_min(x, a, b, 0, 0, n2); }\n    void\
    \ update_max(int a, int b, T x) { _update_max(x, a, b, 0, 0, n2); }\n    void\
    \ add_val(int a, int b, T x) { _add_val(x, a, b, 0, 0, n2); }\n    void update_val(int\
    \ a, int b, T x) { _update_val(x, a, b, 0, 0, n2); }\n    T query_max(int a, int\
    \ b) { return _query_max(a, b, 0, 0, n2); }\n    T query_min(int a, int b) { return\
    \ _query_min(a, b, 0, 0, n2); }\n    T query_sum(int a, int b) { return _query_sum(a,\
    \ b, 0, 0, n2); }\n};\n#line 1 \"Others/template.cc\"\n#pragma region Macros\n\
    #line 3 \"Others/template.cc\"\n#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)\n\
    #define rrep(i, n) for(int(i) = (n)-1; (i) >= 0; (i)--)\n#define FOR(i, m, n)\
    \ for(int(i) = (m); (i) < (n); (i)++)\n#define ROF(i, m, n) for(int(i) = (n)-1;\
    \ (i) >= (m); (i)--)\n#define ALL(v) (v).begin(), (v).end()\n#define LLA(v) (v).rbegin(),\
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
    #line 5 \"verify/range_chmin_chmax_add_range_sum.test.cpp\"\n\nint main() {\n\
    \    INT(n, q);\n    VEC(ll, a, n);\n    SegmentTreeBeats<ll> beats(a);\n    rep(i,\
    \ q) {\n        INT(t);\n        if(t == 0) {\n            LL(l, r, x);\n    \
    \        beats.update_min(l, r, x);\n        } else if(t == 1) {\n           \
    \ LL(l, r, x);\n            beats.update_max(l, r, x);\n        } else if(t ==\
    \ 2) {\n            LL(l, r, x);\n            beats.add_val(l, r, x);\n      \
    \  } else {\n            INT(l, r);\n            write(beats.query_sum(l, r));\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include \"../DataStructure/SegmentTreeBeats.cc\"\n#include \"../Others/template.cc\"\
    \n\nint main() {\n    INT(n, q);\n    VEC(ll, a, n);\n    SegmentTreeBeats<ll>\
    \ beats(a);\n    rep(i, q) {\n        INT(t);\n        if(t == 0) {\n        \
    \    LL(l, r, x);\n            beats.update_min(l, r, x);\n        } else if(t\
    \ == 1) {\n            LL(l, r, x);\n            beats.update_max(l, r, x);\n\
    \        } else if(t == 2) {\n            LL(l, r, x);\n            beats.add_val(l,\
    \ r, x);\n        } else {\n            INT(l, r);\n            write(beats.query_sum(l,\
    \ r));\n        }\n    }\n}"
  dependsOn:
  - DataStructure/SegmentTreeBeats.cc
  - Others/template.cc
  isVerificationFile: true
  path: verify/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-07-10 17:13:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/range_chmin_chmax_add_range_sum.test.cpp
- /verify/verify/range_chmin_chmax_add_range_sum.test.cpp.html
title: verify/range_chmin_chmax_add_range_sum.test.cpp
---
