---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/range_chmin_chmax_add_range_sum.test.cpp
    title: verify/range_chmin_chmax_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SegmentTreeBeats.cc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T> class SegmentTreeBeats {\n    const\
    \ T inf = numeric_limits<T>::max();\n    int n, n2;\n    vector<T> f_max, s_max,\
    \ max_n;\n    vector<T> f_min, s_min, min_n;\n    vector<T> sum;\n    vector<T>\
    \ len, ladd, lval;\n\n    void update_node_max(int k, T x) {\n        sum[k] +=\
    \ (x - f_max[k]) * max_n[k];\n        if(f_max[k] == f_min[k]) {\n           \
    \ f_max[k] = f_min[k] = x;\n        } else if(f_max[k] == s_min[k]) {\n      \
    \      f_max[k] = s_min[k] = x;\n        } else {\n            f_max[k] = x;\n\
    \        }\n        if(lval[k] != inf && x < lval[k])\n            lval[k] = x;\n\
    \    }\n    void update_node_min(int k, T x) {\n        sum[k] += (x - f_min[k])\
    \ * min_n[k];\n        if(f_max[k] == f_min[k]) {\n            f_max[k] = f_min[k]\
    \ = x;\n        } else if(s_max[k] == f_min[k]) {\n            s_max[k] = f_min[k]\
    \ = x;\n        } else {\n            f_min[k] = x;\n        }\n        if(lval[k]\
    \ != inf && lval[k] < x)\n            lval[k] = x;\n    }\n\n    void add_all(int\
    \ k, T x) {\n        f_max[k] += x;\n        if(s_max[k] != -inf)\n          \
    \  s_max[k] += x;\n        f_min[k] += x;\n        if(s_min[k] != inf)\n     \
    \       s_min[k] += x;\n\n        sum[k] += len[k] * x;\n        if(lval[k] !=\
    \ inf) {\n            lval[k] += x;\n        } else\n            ladd[k] += x;\n\
    \    }\n\n    void update_all(int k, T x) {\n        f_max[k] = x;\n        s_max[k]\
    \ = -inf;\n        f_min[k] = x;\n        s_min[k] = inf;\n        max_n[k] =\
    \ min_n[k] = len[k];\n        sum[k] = x * len[k];\n        lval[k] = x;\n   \
    \     ladd[k] = 0;\n    }\n\n    void push(int k) {\n        if(n2 - 1 <= k)\n\
    \            return;\n\n        if(lval[k] != inf) {\n            update_all(2\
    \ * k + 1, lval[k]);\n            update_all(2 * k + 2, lval[k]);\n          \
    \  lval[k] = inf;\n            return;\n        }\n\n        if(ladd[k] != 0)\
    \ {\n            add_all(2 * k + 1, ladd[k]);\n            add_all(2 * k + 2,\
    \ ladd[k]);\n            ladd[k] = 0;\n        }\n        if(f_max[k] < f_max[2\
    \ * k + 1])\n            update_node_max(2 * k + 1, f_max[k]);\n        if(f_max[k]\
    \ < f_max[2 * k + 2])\n            update_node_max(2 * k + 2, f_max[k]);\n\n \
    \       if(f_min[2 * k + 1] < f_min[k])\n            update_node_min(2 * k + 1,\
    \ f_min[k]);\n        if(f_min[2 * k + 2] < f_min[k])\n            update_node_min(2\
    \ * k + 2, f_min[k]);\n    }\n\n    void update(int k) {\n        if(n2 - 1 <=\
    \ k)\n            return;\n        sum[k] = sum[2 * k + 1] + sum[2 * k + 2];\n\
    \        if(f_max[2 * k + 1] < f_max[2 * k + 2]) {\n            f_max[k] = f_max[2\
    \ * k + 2];\n            max_n[k] = max_n[2 * k + 2];\n            s_max[k] =\
    \ max(f_max[2 * k + 1], s_max[2 * k + 2]);\n        } else if(f_max[2 * k + 1]\
    \ > f_max[2 * k + 2]) {\n            f_max[k] = f_max[2 * k + 1];\n          \
    \  max_n[k] = max_n[2 * k + 1];\n            s_max[k] = max(s_max[2 * k + 1],\
    \ f_max[2 * k + 2]);\n        } else {\n            f_max[k] = f_max[2 * k + 1];\n\
    \            max_n[k] = max_n[2 * k + 1] + max_n[2 * k + 2];\n            s_max[k]\
    \ = max(s_max[2 * k + 1], s_max[2 * k + 2]);\n        }\n        if(f_min[2 *\
    \ k + 1] < f_min[2 * k + 2]) {\n            f_min[k] = f_min[2 * k + 1];\n   \
    \         min_n[k] = min_n[2 * k + 1];\n            s_min[k] = min(s_min[2 * k\
    \ + 1], f_min[2 * k + 2]);\n        } else if(f_min[2 * k + 1] > f_min[2 * k +\
    \ 2]) {\n            f_min[k] = f_min[2 * k + 2];\n            min_n[k] = min_n[2\
    \ * k + 2];\n            s_min[k] = min(f_min[2 * k + 1], s_min[2 * k + 2]);\n\
    \        } else {\n            f_min[k] = f_min[2 * k + 1];\n            min_n[k]\
    \ = min_n[2 * k + 1] + min_n[2 * k + 2];\n            s_min[k] = min(s_min[2 *\
    \ k + 1], s_min[2 * k + 2]);\n        }\n    }\n\n    void _update_min(T x, int\
    \ a, int b, int k, int l, int r) {\n        if(b <= l || r <= a || f_max[k] <=\
    \ x)\n            return;\n        if(a <= l && r <= b && s_max[k] < x) {\n  \
    \          update_node_max(k, x);\n            return;\n        }\n        push(k);\n\
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
    \ b, 0, 0, n2); }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename T> class\
    \ SegmentTreeBeats {\n    const T inf = numeric_limits<T>::max();\n    int n,\
    \ n2;\n    vector<T> f_max, s_max, max_n;\n    vector<T> f_min, s_min, min_n;\n\
    \    vector<T> sum;\n    vector<T> len, ladd, lval;\n\n    void update_node_max(int\
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
    \ b, 0, 0, n2); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTreeBeats.cc
  requiredBy: []
  timestamp: '2021-07-10 17:13:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/range_chmin_chmax_add_range_sum.test.cpp
documentation_of: DataStructure/SegmentTreeBeats.cc
layout: document
redirect_from:
- /library/DataStructure/SegmentTreeBeats.cc
- /library/DataStructure/SegmentTreeBeats.cc.html
title: DataStructure/SegmentTreeBeats.cc
---
