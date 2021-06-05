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
  bundledCode: "#line 1 \"Math/Matrix.cc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T> struct Matrix {\n    vector<vector<T>> A;\n    Matrix()\
    \ {}\n    Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}\n    Matrix(size_t\
    \ n) : A(n, vector<T>(n, 0)) {}\n    Matrix(initializer_list<initializer_list<T>>\
    \ init) : A(init.begin(), init.end()){};\n\n    constexpr size_t height() const\
    \ { return A.size(); }\n\n    constexpr size_t width() const { return A[0].size();\
    \ }\n\n    inline constexpr vector<T> &operator[](int k) { return A.at(k); }\n\
    \    inline constexpr const vector<T> &operator[](int k) const { return A.at(k);\
    \ }\n\n    static Matrix I(size_t n) {\n        Matrix mat(n);\n        for(int\
    \ i = 0; i < n; i++)\n            mat[i][i] = 1;\n        return mat;\n    }\n\
    \n    constexpr Matrix &operator+=(const Matrix &B) {\n        size_t h = height(),\
    \ w = width();\n        assert(h == B.height() && w == B.width);\n        for(int\
    \ i = 0; i < h; i++) {\n            for(int j = 0; j < w; j++) {\n           \
    \     (*this)[i][j] += B[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n\n    constexpr Matrix &operator-=(const Matrix &B) {\n        size_t\
    \ h = height(), w = width();\n        assert(h == B.height() && w == B.width);\n\
    \        for(int i = 0; i < h; i++) {\n            for(int j = 0; j < w; j++)\
    \ {\n                (*this)[i][j] -= B[i][j];\n            }\n        }\n   \
    \     return *this;\n    }\n\n    constexpr Matrix &operator*=(const Matrix &B)\
    \ {\n        size_t h = height(), w = B.width(), p = width();\n        assert(p\
    \ == B.height());\n        vector<vector<T>> C(h, vector<T>(w, 0));\n        for(int\
    \ i = 0; i < h; i++) {\n            for(int j = 0; j < w; j++) {\n           \
    \     for(int k = 0; k < p; k++) {\n                    C[i][j] += (*this)[i][k]\
    \ * B[k][j];\n                }\n            }\n        }\n        A.swap(C);\n\
    \        return *this;\n    }\n\n    constexpr Matrix &operator^=(long long k)\
    \ {\n        Matrix B = Matrix::I(height());\n        while(k > 0) {\n       \
    \     if(k & 1)\n                B *= *this;\n            *this *= *this;\n  \
    \          k >>= 1LL;\n        }\n        A.swap(B.A);\n        return *this;\n\
    \    }\n\n    constexpr Matrix operator+(const Matrix &B) const { return (Matrix(*this)\
    \ += B); }\n    constexpr Matrix operator-(const Matrix &B) const { return (Matrix(*this)\
    \ -= B); }\n    constexpr Matrix operator*(const Matrix &B) const { return (Matrix(*this)\
    \ *= B); }\n    constexpr Matrix operator^(const long long k) const { return (Matrix(*this)\
    \ ^= k); }\n    constexpr bool operator==(const Matrix &B) const { return ((*this).A\
    \ == B.A); }\n\n    constexpr friend ostream &operator<<(ostream &os, const Matrix\
    \ &p) {\n        size_t h = p.height(), w = p.width();\n        for(int i = 0;\
    \ i < h; i++) {\n            os << \"[\";\n            for(int j = 0; j < w; j++)\
    \ {\n                os << p[i][j] << (j + 1 == w ? \"]\\n\" : \",\");\n     \
    \       }\n        }\n        return os;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T> struct\
    \ Matrix {\n    vector<vector<T>> A;\n    Matrix() {}\n    Matrix(size_t n, size_t\
    \ m) : A(n, vector<T>(m, 0)) {}\n    Matrix(size_t n) : A(n, vector<T>(n, 0))\
    \ {}\n    Matrix(initializer_list<initializer_list<T>> init) : A(init.begin(),\
    \ init.end()){};\n\n    constexpr size_t height() const { return A.size(); }\n\
    \n    constexpr size_t width() const { return A[0].size(); }\n\n    inline constexpr\
    \ vector<T> &operator[](int k) { return A.at(k); }\n    inline constexpr const\
    \ vector<T> &operator[](int k) const { return A.at(k); }\n\n    static Matrix\
    \ I(size_t n) {\n        Matrix mat(n);\n        for(int i = 0; i < n; i++)\n\
    \            mat[i][i] = 1;\n        return mat;\n    }\n\n    constexpr Matrix\
    \ &operator+=(const Matrix &B) {\n        size_t h = height(), w = width();\n\
    \        assert(h == B.height() && w == B.width);\n        for(int i = 0; i <\
    \ h; i++) {\n            for(int j = 0; j < w; j++) {\n                (*this)[i][j]\
    \ += B[i][j];\n            }\n        }\n        return *this;\n    }\n\n    constexpr\
    \ Matrix &operator-=(const Matrix &B) {\n        size_t h = height(), w = width();\n\
    \        assert(h == B.height() && w == B.width);\n        for(int i = 0; i <\
    \ h; i++) {\n            for(int j = 0; j < w; j++) {\n                (*this)[i][j]\
    \ -= B[i][j];\n            }\n        }\n        return *this;\n    }\n\n    constexpr\
    \ Matrix &operator*=(const Matrix &B) {\n        size_t h = height(), w = B.width(),\
    \ p = width();\n        assert(p == B.height());\n        vector<vector<T>> C(h,\
    \ vector<T>(w, 0));\n        for(int i = 0; i < h; i++) {\n            for(int\
    \ j = 0; j < w; j++) {\n                for(int k = 0; k < p; k++) {\n       \
    \             C[i][j] += (*this)[i][k] * B[k][j];\n                }\n       \
    \     }\n        }\n        A.swap(C);\n        return *this;\n    }\n\n    constexpr\
    \ Matrix &operator^=(long long k) {\n        Matrix B = Matrix::I(height());\n\
    \        while(k > 0) {\n            if(k & 1)\n                B *= *this;\n\
    \            *this *= *this;\n            k >>= 1LL;\n        }\n        A.swap(B.A);\n\
    \        return *this;\n    }\n\n    constexpr Matrix operator+(const Matrix &B)\
    \ const { return (Matrix(*this) += B); }\n    constexpr Matrix operator-(const\
    \ Matrix &B) const { return (Matrix(*this) -= B); }\n    constexpr Matrix operator*(const\
    \ Matrix &B) const { return (Matrix(*this) *= B); }\n    constexpr Matrix operator^(const\
    \ long long k) const { return (Matrix(*this) ^= k); }\n    constexpr bool operator==(const\
    \ Matrix &B) const { return ((*this).A == B.A); }\n\n    constexpr friend ostream\
    \ &operator<<(ostream &os, const Matrix &p) {\n        size_t h = p.height(),\
    \ w = p.width();\n        for(int i = 0; i < h; i++) {\n            os << \"[\"\
    ;\n            for(int j = 0; j < w; j++) {\n                os << p[i][j] <<\
    \ (j + 1 == w ? \"]\\n\" : \",\");\n            }\n        }\n        return os;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/Matrix.cc
  requiredBy: []
  timestamp: '2021-06-05 15:25:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Matrix.cc
layout: document
redirect_from:
- /library/Math/Matrix.cc
- /library/Math/Matrix.cc.html
title: Math/Matrix.cc
---
