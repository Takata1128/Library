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
  bundledCode: "#line 1 \"Math/Determinant.cc\"\n#include <bits/stdc++.h>\n\ntemplate\
    \ <class T> T determinant(std::vector<std::vector<T>> &mat) {\n    int n = mat.size();\n\
    \    assert(n == mat[0].size());\n    T ret = 1;\n    for(int i = 0; i < n; i++)\
    \ {\n        if(mat[i][i] == 0) {\n            T t;\n            for(t = i + 1;\
    \ t < n; t++) {\n                if(mat[t][i] != 0)\n                    break;\n\
    \            }\n            if(t < n) {\n                for(int k = 0; k < n;\
    \ k++) {\n                    std::swap(mat[t][k], mat[i][k]);\n             \
    \   }\n                ret = -ret;\n            }\n        }\n        for(int\
    \ j = i + 1; j < n; j++) {\n            T buf = mat[j][i] / mat[i][i];\n     \
    \       for(int k = 0; k < n; k++) {\n                mat[j][k] -= mat[i][k] *\
    \ buf;\n            }\n        }\n    }\n    for(int i = 0; i < n; i++) {\n  \
    \      ret *= mat[i][i];\n    }\n    return ret;\n}\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <class T> T determinant(std::vector<std::vector<T>>\
    \ &mat) {\n    int n = mat.size();\n    assert(n == mat[0].size());\n    T ret\
    \ = 1;\n    for(int i = 0; i < n; i++) {\n        if(mat[i][i] == 0) {\n     \
    \       T t;\n            for(t = i + 1; t < n; t++) {\n                if(mat[t][i]\
    \ != 0)\n                    break;\n            }\n            if(t < n) {\n\
    \                for(int k = 0; k < n; k++) {\n                    std::swap(mat[t][k],\
    \ mat[i][k]);\n                }\n                ret = -ret;\n            }\n\
    \        }\n        for(int j = i + 1; j < n; j++) {\n            T buf = mat[j][i]\
    \ / mat[i][i];\n            for(int k = 0; k < n; k++) {\n                mat[j][k]\
    \ -= mat[i][k] * buf;\n            }\n        }\n    }\n    for(int i = 0; i <\
    \ n; i++) {\n        ret *= mat[i][i];\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Determinant.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Determinant.cc
layout: document
redirect_from:
- /library/Math/Determinant.cc
- /library/Math/Determinant.cc.html
title: Math/Determinant.cc
---
