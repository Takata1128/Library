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
  bundledCode: "#line 1 \"Math/ComvolutionFFT.cc\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nconst double PI = acos(-1);\n\nclass Complex {\n  private:\n\
    \    double re;\n    double im;\n\n  public:\n    Complex() : re(0), im(0) {}\n\
    \    Complex(double _re, double _im) : re(_re), im(_im) {}\n    Complex(double\
    \ _re) : re(_re), im(0) {}\n    double real() const { return re; }\n    double\
    \ imag() const { return re; }\n\n    Complex &operator=(const Complex &z) {\n\
    \        this->re = z.re;\n        this->im = z.im;\n        return *this;\n \
    \   }\n    Complex &operator=(const double k) {\n        this->re = k;\n     \
    \   this->im = 0;\n        return *this;\n    }\n    Complex operator+() const\
    \ { return *this; }\n    Complex operator-() const { return Complex(-re, -im);\
    \ }\n\n    Complex &operator+=(const Complex &z) {\n        this->re += z.re;\n\
    \        this->im += z.im;\n        return *this;\n    }\n    Complex &operator+=(const\
    \ double &k) {\n        this->re += k;\n        return *this;\n    }\n    Complex\
    \ &operator-=(const Complex &z) {\n        this->re -= z.re;\n        this->im\
    \ -= z.im;\n        return *this;\n    }\n    Complex &operator-=(const double\
    \ &k) {\n        this->re -= k;\n        return *this;\n    }\n    Complex &operator*=(const\
    \ Complex &z) {\n        double r = this->re * z.re - this->im * z.im;\n     \
    \   double i = this->re * z.im + this->im * z.re;\n        this->re = r;\n   \
    \     this->im = i;\n        return *this;\n    }\n    Complex &operator*=(const\
    \ double &k) {\n        this->re *= k;\n        this->im *= k;\n        return\
    \ *this;\n    }\n    Complex &operator/=(const Complex &z) {\n        double z_norm\
    \ = norm(z);\n        double r = (this->re * z.re + this->im * z.im) / z_norm;\n\
    \        double i = (this->im * z.re - this->re * z.im) / z_norm;\n        this->re\
    \ = r;\n        this->im = i;\n        return *this;\n    }\n    Complex &operator/=(const\
    \ double &k) {\n        this->re /= k;\n        this->im /= k;\n        return\
    \ *this;\n    }\n\n    Complex operator+(const Complex &rhs) const {\n       \
    \ return Complex(*this) += rhs;\n    }\n    Complex operator+(const double &rhs)\
    \ const { return Complex(*this) += rhs; }\n    Complex operator-(const Complex\
    \ &rhs) const {\n        return Complex(*this) -= rhs;\n    }\n    Complex operator-(const\
    \ double &rhs) const { return Complex(*this) -= rhs; }\n    Complex operator*(const\
    \ Complex &rhs) const {\n        return Complex(*this) *= rhs;\n    }\n    Complex\
    \ operator*(const double &rhs) const { return Complex(*this) *= rhs; }\n    Complex\
    \ operator/(const Complex &rhs) const {\n        return Complex(*this) /= rhs;\n\
    \    }\n    Complex operator/(const double &rhs) const { return Complex(*this)\
    \ /= rhs; }\n\n    double abs(const Complex &z) { return sqrt(z.re * z.re + z.im\
    \ * z.im); }\n    double norm(const Complex &z) { return z.re * z.re + z.im *\
    \ z.im; }\n    double arg(const Complex &z) { return atan2(z.im, z.re); }\n  \
    \  Complex conj(const Complex &z) { return Complex(z.re, -z.im); }\n    Complex\
    \ Polar(const double r, const double theta) {\n        return Complex(r * cos(theta),\
    \ r * sin(theta));\n    }\n};\n\nstruct ConvolutionFFT {\n    vector<Complex>\
    \ a, b;\n    ConvolutionFFT(vector<double> &_a, vector<double> &_b) {\n      \
    \  a.assign(_a.size(), Complex());\n        b.assign(_b.size(), Complex());\n\
    \        for(int i = 0; i < _a.size(); i++) {\n            a[i] = _a[i];\n   \
    \     }\n        for(int i = 0; i < _b.size(); i++) {\n            b[i] = _b[i];\n\
    \        }\n    }\n\n    vector<Complex> fft_rec(vector<Complex> a, bool is_inverse\
    \ = false) {\n        int n = a.size();\n        if(n == 1)\n            return\
    \ a;\n        vector<Complex> f0, f1;\n        for(int i = 0; i < (n / 2); i++)\
    \ {\n            f0.push_back(a[i * 2]);\n            f1.push_back(a[i * 2 + 1]);\n\
    \        }\n        f0 = fft_rec(f0, is_inverse), f1 = fft_rec(f1, is_inverse);\n\
    \        Complex zeta = Complex(cos(2.0 * PI / n),\n                         \
    \      sin(2.0 * PI / n) * (is_inverse ? -1 : 1));\n        Complex pow_zeta =\
    \ 1;\n        for(int i = 0; i < n; i++) {\n            a[i] = f0[i % (n / 2)]\
    \ + pow_zeta * f1[i % (n / 2)];\n            pow_zeta *= zeta;\n        }\n  \
    \      return a;\n    }\n\n    vector<Complex> fft(vector<Complex> a, bool is_inverse)\
    \ {\n        vector<Complex> ret = fft_rec(a, is_inverse);\n        int n = ret.size();\n\
    \        if(is_inverse) {\n            for(int i = 0; i < n; i++)\n          \
    \      ret[i] /= n;\n        }\n        return ret;\n    }\n\n    vector<double>\
    \ convolve() {\n        int s = a.size() + b.size() - 1;\n        int t = 1;\n\
    \        while(t < s)\n            t *= 2;\n        a.resize(t);\n        b.resize(t);\n\
    \n        vector<Complex> A = fft(a, false);\n        vector<Complex> B = fft(b,\
    \ false);\n        vector<Complex> C(t);\n        for(int i = 0; i < t; i++) {\n\
    \            C[i] = A[i] * B[i];\n        }\n        C = fft(C, true);\n     \
    \   vector<double> c(s);\n        for(int i = 0; i < s; i++)\n            c[i]\
    \ = C[i].real();\n        return c;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nconst double PI = acos(-1);\n\
    \nclass Complex {\n  private:\n    double re;\n    double im;\n\n  public:\n \
    \   Complex() : re(0), im(0) {}\n    Complex(double _re, double _im) : re(_re),\
    \ im(_im) {}\n    Complex(double _re) : re(_re), im(0) {}\n    double real() const\
    \ { return re; }\n    double imag() const { return re; }\n\n    Complex &operator=(const\
    \ Complex &z) {\n        this->re = z.re;\n        this->im = z.im;\n        return\
    \ *this;\n    }\n    Complex &operator=(const double k) {\n        this->re =\
    \ k;\n        this->im = 0;\n        return *this;\n    }\n    Complex operator+()\
    \ const { return *this; }\n    Complex operator-() const { return Complex(-re,\
    \ -im); }\n\n    Complex &operator+=(const Complex &z) {\n        this->re +=\
    \ z.re;\n        this->im += z.im;\n        return *this;\n    }\n    Complex\
    \ &operator+=(const double &k) {\n        this->re += k;\n        return *this;\n\
    \    }\n    Complex &operator-=(const Complex &z) {\n        this->re -= z.re;\n\
    \        this->im -= z.im;\n        return *this;\n    }\n    Complex &operator-=(const\
    \ double &k) {\n        this->re -= k;\n        return *this;\n    }\n    Complex\
    \ &operator*=(const Complex &z) {\n        double r = this->re * z.re - this->im\
    \ * z.im;\n        double i = this->re * z.im + this->im * z.re;\n        this->re\
    \ = r;\n        this->im = i;\n        return *this;\n    }\n    Complex &operator*=(const\
    \ double &k) {\n        this->re *= k;\n        this->im *= k;\n        return\
    \ *this;\n    }\n    Complex &operator/=(const Complex &z) {\n        double z_norm\
    \ = norm(z);\n        double r = (this->re * z.re + this->im * z.im) / z_norm;\n\
    \        double i = (this->im * z.re - this->re * z.im) / z_norm;\n        this->re\
    \ = r;\n        this->im = i;\n        return *this;\n    }\n    Complex &operator/=(const\
    \ double &k) {\n        this->re /= k;\n        this->im /= k;\n        return\
    \ *this;\n    }\n\n    Complex operator+(const Complex &rhs) const {\n       \
    \ return Complex(*this) += rhs;\n    }\n    Complex operator+(const double &rhs)\
    \ const { return Complex(*this) += rhs; }\n    Complex operator-(const Complex\
    \ &rhs) const {\n        return Complex(*this) -= rhs;\n    }\n    Complex operator-(const\
    \ double &rhs) const { return Complex(*this) -= rhs; }\n    Complex operator*(const\
    \ Complex &rhs) const {\n        return Complex(*this) *= rhs;\n    }\n    Complex\
    \ operator*(const double &rhs) const { return Complex(*this) *= rhs; }\n    Complex\
    \ operator/(const Complex &rhs) const {\n        return Complex(*this) /= rhs;\n\
    \    }\n    Complex operator/(const double &rhs) const { return Complex(*this)\
    \ /= rhs; }\n\n    double abs(const Complex &z) { return sqrt(z.re * z.re + z.im\
    \ * z.im); }\n    double norm(const Complex &z) { return z.re * z.re + z.im *\
    \ z.im; }\n    double arg(const Complex &z) { return atan2(z.im, z.re); }\n  \
    \  Complex conj(const Complex &z) { return Complex(z.re, -z.im); }\n    Complex\
    \ Polar(const double r, const double theta) {\n        return Complex(r * cos(theta),\
    \ r * sin(theta));\n    }\n};\n\nstruct ConvolutionFFT {\n    vector<Complex>\
    \ a, b;\n    ConvolutionFFT(vector<double> &_a, vector<double> &_b) {\n      \
    \  a.assign(_a.size(), Complex());\n        b.assign(_b.size(), Complex());\n\
    \        for(int i = 0; i < _a.size(); i++) {\n            a[i] = _a[i];\n   \
    \     }\n        for(int i = 0; i < _b.size(); i++) {\n            b[i] = _b[i];\n\
    \        }\n    }\n\n    vector<Complex> fft_rec(vector<Complex> a, bool is_inverse\
    \ = false) {\n        int n = a.size();\n        if(n == 1)\n            return\
    \ a;\n        vector<Complex> f0, f1;\n        for(int i = 0; i < (n / 2); i++)\
    \ {\n            f0.push_back(a[i * 2]);\n            f1.push_back(a[i * 2 + 1]);\n\
    \        }\n        f0 = fft_rec(f0, is_inverse), f1 = fft_rec(f1, is_inverse);\n\
    \        Complex zeta = Complex(cos(2.0 * PI / n),\n                         \
    \      sin(2.0 * PI / n) * (is_inverse ? -1 : 1));\n        Complex pow_zeta =\
    \ 1;\n        for(int i = 0; i < n; i++) {\n            a[i] = f0[i % (n / 2)]\
    \ + pow_zeta * f1[i % (n / 2)];\n            pow_zeta *= zeta;\n        }\n  \
    \      return a;\n    }\n\n    vector<Complex> fft(vector<Complex> a, bool is_inverse)\
    \ {\n        vector<Complex> ret = fft_rec(a, is_inverse);\n        int n = ret.size();\n\
    \        if(is_inverse) {\n            for(int i = 0; i < n; i++)\n          \
    \      ret[i] /= n;\n        }\n        return ret;\n    }\n\n    vector<double>\
    \ convolve() {\n        int s = a.size() + b.size() - 1;\n        int t = 1;\n\
    \        while(t < s)\n            t *= 2;\n        a.resize(t);\n        b.resize(t);\n\
    \n        vector<Complex> A = fft(a, false);\n        vector<Complex> B = fft(b,\
    \ false);\n        vector<Complex> C(t);\n        for(int i = 0; i < t; i++) {\n\
    \            C[i] = A[i] * B[i];\n        }\n        C = fft(C, true);\n     \
    \   vector<double> c(s);\n        for(int i = 0; i < s; i++)\n            c[i]\
    \ = C[i].real();\n        return c;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/ComvolutionFFT.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/ComvolutionFFT.cc
layout: document
redirect_from:
- /library/Math/ComvolutionFFT.cc
- /library/Math/ComvolutionFFT.cc.html
title: Math/ComvolutionFFT.cc
---
