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
  bundledCode: "#line 1 \"DataStructure/SegmentTreeBeats.cc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T> class SegmentTreeBeats {\n    const\
    \ T inf = 1e18;\n    int n, n0;\n    vector<T> max_v, smax_v, max_c;\n    vector<T>\
    \ min_v, smin_v, min_c;\n    vector<T> sum;\n    vector<T> len, ladd, lval;\n\n\
    \    void update_node_max(int k, T x) {\n        sum[k] += (x - max_v[k]) * max_c[k];\n\
    \        if(max_v[k] == min_v[k]) {\n            max_v[k] = min_v[k] = x;\n  \
    \      } else if(max_v[k] == smin_v[k]) {\n            max_v[k] = smin_v[k] =\
    \ x;\n        } else {\n            max_v[k] = x;\n        }\n        if(lval[k]\
    \ != inf && x < lval[k])\n            lval[k] = x;\n    }\n    void update_node_min(int\
    \ k, T x) {\n        sum[k] += (x - min_v[k]) * min_c[k];\n        if(max_v[k]\
    \ == min_v[k]) {\n            max_v[k] = min_v[k] = x;\n        } else if(max_v[k]\
    \ == smin_v[k]) {\n            min_v[k] = smax_v[k] = x;\n        } else {\n \
    \           min_v[k] = x;\n        }\n        if(lval[k] != inf && lval[k] < x)\n\
    \            lval[k] = x;\n    }\n    void push(int k) {\n        if(n0 - 1 <=\
    \ k)\n            return;\n        if(lval[l] != inf) {\n            update_all(2\
    \ * k + 1, lval[k]);\n            update_all(2 * k + 2, lval[k]);\n          \
    \  lval[k] = inf;\n            return;\n        }\n        if(ladd[k] != 0) {\n\
    \            add_all(2 * k + 1, ladd[k]);\n            add_all(2 * k + 2, ladd[k]);\n\
    \            ladd[k] = 0;\n        }\n        if(max_v[k] < max_v[2 * k + 1])\n\
    \            update_node_max(2 * k + 1, max_v[k]);\n        if(max_v[k] < max_v[2\
    \ * k + 2])\n            update_node_max(2 * k + 2, max_v[k]);\n        if(min_v[2\
    \ * k + 1] < min_v[k])\n            update_node_min(2 * k + 1, min_v[k]);\n  \
    \      if(max_v[2 * k + 2] < min_v[k])\n            update_node_min(2 * k + 2,\
    \ min_v[k]);\n    }\n\n    void update(int k) {\n        sum[k] = sum[2 * k +\
    \ 1] + sum[2 * k + 2];\n        if(max_v[2 * k + 1] < max_v[2 * k + 2]) {\n  \
    \          max_v[k] = max_v[2 * k + 2];\n            max_c[k] = max_c[2 * k +\
    \ 2];\n            smax_v[k] = max(max_v[2 * k + 1], smax_v[2 * k + 2]);\n   \
    \     } else if(max_v[2 * k + 1] > max_v[2 * k + 2]) {\n\n            max_v[k]\
    \ = max_v[2 * k + 1];\n            max_c[k] = max_c[2 * k + 1];\n            smax_v[k]\
    \ = max(smax_v[2 * k + 1], max_v[2 * k + 2]);\n        } else {\n            max_v[k]\
    \ = max_v[2 * k + 1];\n            max_c[k] = max_c[2 * k + 1] + max_c[2 * k +\
    \ 2];\n            smax_v[k] = max(smax_v[2 * k + 1], smax_v[2 * k + 2]);\n  \
    \      }\n        if(min_v[2 * k + 1] < min_v[2 * k + 2]) {\n            min_v[k]\
    \ = min_v[2 * k + 2];\n            min_c[k] = min_c[2 * k + 2];\n            smin_v[k]\
    \ = min(min_v[2 * k + 1], smin_v[2 * k + 2]);\n        } else if(min_v[2 * k +\
    \ 1] > min_v[2 * k + 2]) {\n            min_v[k] = min_v[2 * k + 1];\n       \
    \     min_c[k] = min_c[2 * k + 1];\n            smin_v[k] = min(smin_v[2 * k +\
    \ 1], min_v[2 * k + 2]);\n        } else {\n            min_v[k] = min_v[2 * k\
    \ + 1];\n            min_c[k] = min_c[2 * k + 1] + min_c[2 * k + 2];\n       \
    \     smin_v[k] = min(smin_v[2 * k + 1], smin_v[2 * k + 2]);\n        }\n    }\n\
    \n    void _update_min(T x, int a, int b, int k, int l, int r) {\n        if(b\
    \ <= l || r <= a || max_v[k] <= x)\n            return;\n        if(a <= l &&\
    \ r <= b && smax_v[k] < x) {\n            update_node_max(k, x);\n           \
    \ return;\n        }\n        push(k);\n        _update_min(x, a, b, 2 * k + 1,\
    \ l, (l + r) / 2);\n        _update_min(x, a, b, 2 * k + 2, l, (l + r) / 2);\n\
    \        update(k);\n    }\n    void _update_max(T x, int a, int b, int k, int\
    \ l, int r) {\n        if(b <= l || r <= a || max_v[k] <= x)\n            return;\n\
    \        if(a <= l && r <= b && smax_v[k] < x) {\n            update_node_min(k,\
    \ x);\n            return;\n        }\n        push(k);\n        _update_max(x,\
    \ a, b, 2 * k + 1, l, (l + r) / 2);\n        _update_max(x, a, b, 2 * k + 2, l,\
    \ (l + r) / 2);\n        update(k);\n    }\n    void add_all(int k, T x) {\n \
    \       max_v[k] += x;\n        if(smax_v[k] != -inf)\n            smax_v[k] +=\
    \ x;\n        min_v[k] += x;\n        if(smin_v[k] != inf)\n            smin_v[k]\
    \ += x;\n        if(lval[k] != inf) {\n            lval[k] += x;\n        } else\n\
    \            ladd[k] += x;\n    }\n    void update_all(int k, T x) {\n       \
    \ max_v[k] = x;\n        smax_v[k] = -inf;\n        min_v[k] = x;\n        smin_v[k]\
    \ = inf;\n        max_c[k] = min_c[k] = len[k];\n        sum[k] = x * len[k];\n\
    \        lval[k] = x;\n        ladd[k] = 0;\n    }\n    void _add_val(T x, int\
    \ a, int b, int k, int l, int r) {}\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename T> class\
    \ SegmentTreeBeats {\n    const T inf = 1e18;\n    int n, n0;\n    vector<T> max_v,\
    \ smax_v, max_c;\n    vector<T> min_v, smin_v, min_c;\n    vector<T> sum;\n  \
    \  vector<T> len, ladd, lval;\n\n    void update_node_max(int k, T x) {\n    \
    \    sum[k] += (x - max_v[k]) * max_c[k];\n        if(max_v[k] == min_v[k]) {\n\
    \            max_v[k] = min_v[k] = x;\n        } else if(max_v[k] == smin_v[k])\
    \ {\n            max_v[k] = smin_v[k] = x;\n        } else {\n            max_v[k]\
    \ = x;\n        }\n        if(lval[k] != inf && x < lval[k])\n            lval[k]\
    \ = x;\n    }\n    void update_node_min(int k, T x) {\n        sum[k] += (x -\
    \ min_v[k]) * min_c[k];\n        if(max_v[k] == min_v[k]) {\n            max_v[k]\
    \ = min_v[k] = x;\n        } else if(max_v[k] == smin_v[k]) {\n            min_v[k]\
    \ = smax_v[k] = x;\n        } else {\n            min_v[k] = x;\n        }\n \
    \       if(lval[k] != inf && lval[k] < x)\n            lval[k] = x;\n    }\n \
    \   void push(int k) {\n        if(n0 - 1 <= k)\n            return;\n       \
    \ if(lval[l] != inf) {\n            update_all(2 * k + 1, lval[k]);\n        \
    \    update_all(2 * k + 2, lval[k]);\n            lval[k] = inf;\n           \
    \ return;\n        }\n        if(ladd[k] != 0) {\n            add_all(2 * k +\
    \ 1, ladd[k]);\n            add_all(2 * k + 2, ladd[k]);\n            ladd[k]\
    \ = 0;\n        }\n        if(max_v[k] < max_v[2 * k + 1])\n            update_node_max(2\
    \ * k + 1, max_v[k]);\n        if(max_v[k] < max_v[2 * k + 2])\n            update_node_max(2\
    \ * k + 2, max_v[k]);\n        if(min_v[2 * k + 1] < min_v[k])\n            update_node_min(2\
    \ * k + 1, min_v[k]);\n        if(max_v[2 * k + 2] < min_v[k])\n            update_node_min(2\
    \ * k + 2, min_v[k]);\n    }\n\n    void update(int k) {\n        sum[k] = sum[2\
    \ * k + 1] + sum[2 * k + 2];\n        if(max_v[2 * k + 1] < max_v[2 * k + 2])\
    \ {\n            max_v[k] = max_v[2 * k + 2];\n            max_c[k] = max_c[2\
    \ * k + 2];\n            smax_v[k] = max(max_v[2 * k + 1], smax_v[2 * k + 2]);\n\
    \        } else if(max_v[2 * k + 1] > max_v[2 * k + 2]) {\n\n            max_v[k]\
    \ = max_v[2 * k + 1];\n            max_c[k] = max_c[2 * k + 1];\n            smax_v[k]\
    \ = max(smax_v[2 * k + 1], max_v[2 * k + 2]);\n        } else {\n            max_v[k]\
    \ = max_v[2 * k + 1];\n            max_c[k] = max_c[2 * k + 1] + max_c[2 * k +\
    \ 2];\n            smax_v[k] = max(smax_v[2 * k + 1], smax_v[2 * k + 2]);\n  \
    \      }\n        if(min_v[2 * k + 1] < min_v[2 * k + 2]) {\n            min_v[k]\
    \ = min_v[2 * k + 2];\n            min_c[k] = min_c[2 * k + 2];\n            smin_v[k]\
    \ = min(min_v[2 * k + 1], smin_v[2 * k + 2]);\n        } else if(min_v[2 * k +\
    \ 1] > min_v[2 * k + 2]) {\n            min_v[k] = min_v[2 * k + 1];\n       \
    \     min_c[k] = min_c[2 * k + 1];\n            smin_v[k] = min(smin_v[2 * k +\
    \ 1], min_v[2 * k + 2]);\n        } else {\n            min_v[k] = min_v[2 * k\
    \ + 1];\n            min_c[k] = min_c[2 * k + 1] + min_c[2 * k + 2];\n       \
    \     smin_v[k] = min(smin_v[2 * k + 1], smin_v[2 * k + 2]);\n        }\n    }\n\
    \n    void _update_min(T x, int a, int b, int k, int l, int r) {\n        if(b\
    \ <= l || r <= a || max_v[k] <= x)\n            return;\n        if(a <= l &&\
    \ r <= b && smax_v[k] < x) {\n            update_node_max(k, x);\n           \
    \ return;\n        }\n        push(k);\n        _update_min(x, a, b, 2 * k + 1,\
    \ l, (l + r) / 2);\n        _update_min(x, a, b, 2 * k + 2, l, (l + r) / 2);\n\
    \        update(k);\n    }\n    void _update_max(T x, int a, int b, int k, int\
    \ l, int r) {\n        if(b <= l || r <= a || max_v[k] <= x)\n            return;\n\
    \        if(a <= l && r <= b && smax_v[k] < x) {\n            update_node_min(k,\
    \ x);\n            return;\n        }\n        push(k);\n        _update_max(x,\
    \ a, b, 2 * k + 1, l, (l + r) / 2);\n        _update_max(x, a, b, 2 * k + 2, l,\
    \ (l + r) / 2);\n        update(k);\n    }\n    void add_all(int k, T x) {\n \
    \       max_v[k] += x;\n        if(smax_v[k] != -inf)\n            smax_v[k] +=\
    \ x;\n        min_v[k] += x;\n        if(smin_v[k] != inf)\n            smin_v[k]\
    \ += x;\n        if(lval[k] != inf) {\n            lval[k] += x;\n        } else\n\
    \            ladd[k] += x;\n    }\n    void update_all(int k, T x) {\n       \
    \ max_v[k] = x;\n        smax_v[k] = -inf;\n        min_v[k] = x;\n        smin_v[k]\
    \ = inf;\n        max_c[k] = min_c[k] = len[k];\n        sum[k] = x * len[k];\n\
    \        lval[k] = x;\n        ladd[k] = 0;\n    }\n    void _add_val(T x, int\
    \ a, int b, int k, int l, int r) {}\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTreeBeats.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegmentTreeBeats.cc
layout: document
redirect_from:
- /library/DataStructure/SegmentTreeBeats.cc
- /library/DataStructure/SegmentTreeBeats.cc.html
title: DataStructure/SegmentTreeBeats.cc
---
