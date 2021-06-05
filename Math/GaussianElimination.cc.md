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
  bundledCode: "#line 1 \"Math/GaussianElimination.cc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T> class GaussianElimination {\n  \
    \  vector<vector<T>> mat;\n\n  public:\n    GaussianElimination(vector<vector<int>>\
    \ mat(n, vector<T>(m))) : mat(mat) {}\n\n    int sweep(bool is_extended = false)\
    \ {\n        int rank = 0;\n        for(int col = 0; col < n; col++) {\n     \
    \       if(is_extended && col == n - 1)\n                break;\n            int\
    \ pivot = -1;\n            for(int row = rank; row < m; row++) {\n           \
    \     if(mat[row][col] != 0) {\n                    pivot = row;\n           \
    \         break;\n                }\n            }\n            if(pivot == -1)\n\
    \                continue;\n            swap(mat[pivot], mat[rank]);\n       \
    \     for(int col2 = 0; col2 < n; col2++) {\n                mat[rank][col2] =\
    \ mat[rank][col2] / mat[rank][col];\n            }\n            for(int row =\
    \ 0; row < m; row++) {\n                if(row != rank && mat[row][col]) {\n \
    \                   for(int col2 = 0; col2 < n; col2++) {\n                  \
    \      mat[row][col2] -= mat[rank][col2] / mat[row][col];\n                  \
    \  }\n                }\n            }\n        }\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename T> class\
    \ GaussianElimination {\n    vector<vector<T>> mat;\n\n  public:\n    GaussianElimination(vector<vector<int>>\
    \ mat(n, vector<T>(m))) : mat(mat) {}\n\n    int sweep(bool is_extended = false)\
    \ {\n        int rank = 0;\n        for(int col = 0; col < n; col++) {\n     \
    \       if(is_extended && col == n - 1)\n                break;\n            int\
    \ pivot = -1;\n            for(int row = rank; row < m; row++) {\n           \
    \     if(mat[row][col] != 0) {\n                    pivot = row;\n           \
    \         break;\n                }\n            }\n            if(pivot == -1)\n\
    \                continue;\n            swap(mat[pivot], mat[rank]);\n       \
    \     for(int col2 = 0; col2 < n; col2++) {\n                mat[rank][col2] =\
    \ mat[rank][col2] / mat[rank][col];\n            }\n            for(int row =\
    \ 0; row < m; row++) {\n                if(row != rank && mat[row][col]) {\n \
    \                   for(int col2 = 0; col2 < n; col2++) {\n                  \
    \      mat[row][col2] -= mat[rank][col2] / mat[row][col];\n                  \
    \  }\n                }\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/GaussianElimination.cc
  requiredBy: []
  timestamp: '2021-06-05 15:25:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/GaussianElimination.cc
layout: document
redirect_from:
- /library/Math/GaussianElimination.cc
- /library/Math/GaussianElimination.cc.html
title: Math/GaussianElimination.cc
---
