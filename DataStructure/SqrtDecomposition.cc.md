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
  bundledCode: "#line 1 \"DataStructure/SqrtDecomposition.cc\"\n#include <bits/stdc++.h>\n\
    \ntemplate <typename T> class SqrtDecomposition {\n    class bucket {\n      \
    \  int l, r;\n        std::vector<T> v;\n        T min_val;\n        T add_val;\n\
    \n        void update_all(T x) { add_val += x; }\n\n        T calc_all() { return\
    \ min_val + add_val; }\n\n        void reflect_update() {\n            for(auto\
    \ &i : v)\n                i += add_val;\n            add_val = 0;\n        }\n\
    \n        void reflect_calc() {\n            min_val = std::numeric_limits<T>::max();\n\
    \            for(auto &i : v) {\n                min_val = min(min_val, i);\n\
    \            }\n        }\n\n        void update_partial(int l, int r, T x) {\n\
    \            reflect_update();\n            for(int i = l; i < r; i++) {\n   \
    \             v[i] += x;\n            }\n            reflect_calc();\n       \
    \ }\n\n        T calc_partial(int l, int r) {\n            reflect_update();\n\
    \            reflect_calc();\n            T res = std::numeric_limits<T>::max();\n\
    \            for(int i = l; i < r; i++) {\n                res = std::min(res,\
    \ v[i]);\n            }\n            return res;\n        }\n\n      public:\n\
    \        bucket(const std::vector<T> &a, int l, int r) : l(l), r(r) {\n      \
    \      v = std::vector<T>(r - l);\n            for(int i = 0; i < r - l; ++i)\n\
    \                v[i] = a[i + l];\n        }\n        void update(int s, int t,\
    \ T x) {\n            if(r <= s || t <= l)\n                return;\n        \
    \    else if(s <= l && r <= t)\n                update_all(x);\n            else\n\
    \                update_partial(std::max(s, l) - l, std::min(t, r) - l, x);\n\
    \        }\n        T calc(int s, int t) {\n            if(r <= s || t <= l)\n\
    \                return;\n            else if(s <= l && r <= t)\n            \
    \    return calc_all();\n            else\n                return calc_partial(std::max(s,\
    \ l) - l, std::min(t, r) - l);\n        }\n    };\n\n    std::vector<bucket> v;\n\
    \n  public:\n    SqrtDecomposition(const std::vector<T> &a, int bucket_size) {\n\
    \        v = std::vector<bucket>();\n        for(int i = 0; i < (int)a.size();\
    \ i += bucket_size) {\n            v.emplace_back(a, i, std::min(i + bucket_size,\
    \ (int)a.size()));\n        }\n    }\n\n    void update(int l, int r, T x) {\n\
    \        for(auto &i : v) {\n            i.update(l, r, x);\n        }\n    }\n\
    \n    T calc(int l, int r) {\n        T res = std::numeric_limits<T>::max();\n\
    \        for(auto &i : v) {\n            res = std::min(res, i.calc(l, r));\n\
    \        }\n        return res;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <typename T> class SqrtDecomposition\
    \ {\n    class bucket {\n        int l, r;\n        std::vector<T> v;\n      \
    \  T min_val;\n        T add_val;\n\n        void update_all(T x) { add_val +=\
    \ x; }\n\n        T calc_all() { return min_val + add_val; }\n\n        void reflect_update()\
    \ {\n            for(auto &i : v)\n                i += add_val;\n           \
    \ add_val = 0;\n        }\n\n        void reflect_calc() {\n            min_val\
    \ = std::numeric_limits<T>::max();\n            for(auto &i : v) {\n         \
    \       min_val = min(min_val, i);\n            }\n        }\n\n        void update_partial(int\
    \ l, int r, T x) {\n            reflect_update();\n            for(int i = l;\
    \ i < r; i++) {\n                v[i] += x;\n            }\n            reflect_calc();\n\
    \        }\n\n        T calc_partial(int l, int r) {\n            reflect_update();\n\
    \            reflect_calc();\n            T res = std::numeric_limits<T>::max();\n\
    \            for(int i = l; i < r; i++) {\n                res = std::min(res,\
    \ v[i]);\n            }\n            return res;\n        }\n\n      public:\n\
    \        bucket(const std::vector<T> &a, int l, int r) : l(l), r(r) {\n      \
    \      v = std::vector<T>(r - l);\n            for(int i = 0; i < r - l; ++i)\n\
    \                v[i] = a[i + l];\n        }\n        void update(int s, int t,\
    \ T x) {\n            if(r <= s || t <= l)\n                return;\n        \
    \    else if(s <= l && r <= t)\n                update_all(x);\n            else\n\
    \                update_partial(std::max(s, l) - l, std::min(t, r) - l, x);\n\
    \        }\n        T calc(int s, int t) {\n            if(r <= s || t <= l)\n\
    \                return;\n            else if(s <= l && r <= t)\n            \
    \    return calc_all();\n            else\n                return calc_partial(std::max(s,\
    \ l) - l, std::min(t, r) - l);\n        }\n    };\n\n    std::vector<bucket> v;\n\
    \n  public:\n    SqrtDecomposition(const std::vector<T> &a, int bucket_size) {\n\
    \        v = std::vector<bucket>();\n        for(int i = 0; i < (int)a.size();\
    \ i += bucket_size) {\n            v.emplace_back(a, i, std::min(i + bucket_size,\
    \ (int)a.size()));\n        }\n    }\n\n    void update(int l, int r, T x) {\n\
    \        for(auto &i : v) {\n            i.update(l, r, x);\n        }\n    }\n\
    \n    T calc(int l, int r) {\n        T res = std::numeric_limits<T>::max();\n\
    \        for(auto &i : v) {\n            res = std::min(res, i.calc(l, r));\n\
    \        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SqrtDecomposition.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SqrtDecomposition.cc
layout: document
redirect_from:
- /library/DataStructure/SqrtDecomposition.cc
- /library/DataStructure/SqrtDecomposition.cc.html
title: DataStructure/SqrtDecomposition.cc
---
