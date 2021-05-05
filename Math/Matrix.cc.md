---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/luzhiled/snippets/math/matrix.html
    - https://yukicoder.me/submissions/523126
  bundledCode: "#line 1 \"Math/Matrix.cc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// \u53C2\u8003:https://ei1333.github.io/luzhiled/snippets/math/matrix.html\n\
    // (\u639B\u3051\u7B97\u3068\u7D2F\u4E57)https://yukicoder.me/submissions/523126\n\
    // \u4ED6\u306F\u77E5\u3089\u3093\ntemplate <class T> struct Matrix {\n    vector<vector<T>>\
    \ A;\n    Matrix() {}\n    Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0))\
    \ {}\n    Matrix(size_t n) : A(n, vector<T>(n, 0)) {}\n\n    size_t height() const\
    \ { return A.size(); }\n\n    size_t width() const { return A[0].size(); }\n\n\
    \    inline vector<T> &operator[](int k) { return A.at(k); }\n    inline const\
    \ vector<T> &operator[](int k) const { return A.at(k); }\n\n    static Matrix\
    \ I(size_t n) {\n        Matrix mat(n);\n        for(int i = 0; i < n; i++)\n\
    \            mat[i][i] = 1;\n        return mat;\n    }\n\n    Matrix &operator+=(const\
    \ Matrix &B) {\n        size_t h = height(), w = width();\n        assert(h ==\
    \ B.height() && w == B.width);\n        for(int i = 0; i < h; i++) {\n       \
    \     for(int j = 0; j < w; j++) {\n                (*this)[i][j] += B[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    Matrix &operator-=(const\
    \ Matrix &B) {\n        size_t h = height(), w = width();\n        assert(h ==\
    \ B.height() && w == B.width);\n        for(int i = 0; i < h; i++) {\n       \
    \     for(int j = 0; j < w; j++) {\n                (*this)[i][j] -= B[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    Matrix &operator*=(const\
    \ Matrix &B) {\n        size_t h = height(), w = B.width(), p = width();\n   \
    \     assert(p == B.height());\n        vector<vector<T>> C(h, vector<T>(w, 0));\n\
    \        for(int i = 0; i < h; i++) {\n            for(int j = 0; j < w; j++)\
    \ {\n                for(int k = 0; k < p; k++) {\n                    C[i][j]\
    \ += (*this)[i][k] * B[k][j];\n                }\n            }\n        }\n \
    \       A.swap(C);\n        return *this;\n    }\n\n    Matrix &operator^=(ll\
    \ k) {\n        Matrix B = Matrix::I(height());\n        while(k > 0) {\n    \
    \        if(k & 1)\n                B *= *this;\n            *this *= *this;\n\
    \            k >>= 1LL;\n        }\n        A.swap(B.A);\n        return *this;\n\
    \    }\n\n    Matrix operator+(const Matrix &B) const { return (Matrix(*this)\
    \ += B); }\n    Matrix operator-(const Matrix &B) const { return (Matrix(*this)\
    \ -= B); }\n    Matrix operator*(const Matrix &B) const { return (Matrix(*this)\
    \ *= B); }\n    Matrix operator^(const ll k) const { return (Matrix(*this) ^=\
    \ k); }\n\n    friend ostream &operator<<(ostream &os, const Matrix &p) {\n  \
    \      size_t h = p.height(), w = p.width();\n        for(int i = 0; i < h; i++)\
    \ {\n            os << \"[\";\n            for(int j = 0; j < w; j++) {\n    \
    \            os << p[i][j] << (j + 1 == w ? \"]\\n\" : \",\");\n            }\n\
    \        }\n        return os;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// \u53C2\u8003:https://ei1333.github.io/luzhiled/snippets/math/matrix.html\n\
    // (\u639B\u3051\u7B97\u3068\u7D2F\u4E57)https://yukicoder.me/submissions/523126\n\
    // \u4ED6\u306F\u77E5\u3089\u3093\ntemplate <class T> struct Matrix {\n    vector<vector<T>>\
    \ A;\n    Matrix() {}\n    Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0))\
    \ {}\n    Matrix(size_t n) : A(n, vector<T>(n, 0)) {}\n\n    size_t height() const\
    \ { return A.size(); }\n\n    size_t width() const { return A[0].size(); }\n\n\
    \    inline vector<T> &operator[](int k) { return A.at(k); }\n    inline const\
    \ vector<T> &operator[](int k) const { return A.at(k); }\n\n    static Matrix\
    \ I(size_t n) {\n        Matrix mat(n);\n        for(int i = 0; i < n; i++)\n\
    \            mat[i][i] = 1;\n        return mat;\n    }\n\n    Matrix &operator+=(const\
    \ Matrix &B) {\n        size_t h = height(), w = width();\n        assert(h ==\
    \ B.height() && w == B.width);\n        for(int i = 0; i < h; i++) {\n       \
    \     for(int j = 0; j < w; j++) {\n                (*this)[i][j] += B[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    Matrix &operator-=(const\
    \ Matrix &B) {\n        size_t h = height(), w = width();\n        assert(h ==\
    \ B.height() && w == B.width);\n        for(int i = 0; i < h; i++) {\n       \
    \     for(int j = 0; j < w; j++) {\n                (*this)[i][j] -= B[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    Matrix &operator*=(const\
    \ Matrix &B) {\n        size_t h = height(), w = B.width(), p = width();\n   \
    \     assert(p == B.height());\n        vector<vector<T>> C(h, vector<T>(w, 0));\n\
    \        for(int i = 0; i < h; i++) {\n            for(int j = 0; j < w; j++)\
    \ {\n                for(int k = 0; k < p; k++) {\n                    C[i][j]\
    \ += (*this)[i][k] * B[k][j];\n                }\n            }\n        }\n \
    \       A.swap(C);\n        return *this;\n    }\n\n    Matrix &operator^=(ll\
    \ k) {\n        Matrix B = Matrix::I(height());\n        while(k > 0) {\n    \
    \        if(k & 1)\n                B *= *this;\n            *this *= *this;\n\
    \            k >>= 1LL;\n        }\n        A.swap(B.A);\n        return *this;\n\
    \    }\n\n    Matrix operator+(const Matrix &B) const { return (Matrix(*this)\
    \ += B); }\n    Matrix operator-(const Matrix &B) const { return (Matrix(*this)\
    \ -= B); }\n    Matrix operator*(const Matrix &B) const { return (Matrix(*this)\
    \ *= B); }\n    Matrix operator^(const ll k) const { return (Matrix(*this) ^=\
    \ k); }\n\n    friend ostream &operator<<(ostream &os, const Matrix &p) {\n  \
    \      size_t h = p.height(), w = p.width();\n        for(int i = 0; i < h; i++)\
    \ {\n            os << \"[\";\n            for(int j = 0; j < w; j++) {\n    \
    \            os << p[i][j] << (j + 1 == w ? \"]\\n\" : \",\");\n            }\n\
    \        }\n        return os;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/Matrix.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Matrix.cc
layout: document
redirect_from:
- /library/Math/Matrix.cc
- /library/Math/Matrix.cc.html
title: Math/Matrix.cc
---
