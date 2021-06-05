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
  bundledCode: "#line 1 \"Math/ConvolutionFFT.cc\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nclass ConvolutionFFT {\n  private:\n    const double PI =\
    \ acos(-1);\n    class Complex {\n      private:\n        double re;\n       \
    \ double im;\n\n      public:\n        Complex() : re(0), im(0) {}\n        Complex(double\
    \ _re, double _im) : re(_re), im(_im) {}\n        Complex(double _re) : re(_re),\
    \ im(0) {}\n        double real() const { return re; }\n        double imag()\
    \ const { return re; }\n\n        Complex &operator=(const Complex &z) {\n   \
    \         this->re = z.re;\n            this->im = z.im;\n            return *this;\n\
    \        }\n        Complex &operator=(const double k) {\n            this->re\
    \ = k;\n            this->im = 0;\n            return *this;\n        }\n    \
    \    Complex operator+() const { return *this; }\n        Complex operator-()\
    \ const { return Complex(-re, -im); }\n\n        Complex &operator+=(const Complex\
    \ &z) {\n            this->re += z.re;\n            this->im += z.im;\n      \
    \      return *this;\n        }\n        Complex &operator+=(const double &k)\
    \ {\n            this->re += k;\n            return *this;\n        }\n      \
    \  Complex &operator-=(const Complex &z) {\n            this->re -= z.re;\n  \
    \          this->im -= z.im;\n            return *this;\n        }\n        Complex\
    \ &operator-=(const double &k) {\n            this->re -= k;\n            return\
    \ *this;\n        }\n        Complex &operator*=(const Complex &z) {\n       \
    \     double r = this->re * z.re - this->im * z.im;\n            double i = this->re\
    \ * z.im + this->im * z.re;\n            this->re = r;\n            this->im =\
    \ i;\n            return *this;\n        }\n        Complex &operator*=(const\
    \ double &k) {\n            this->re *= k;\n            this->im *= k;\n     \
    \       return *this;\n        }\n        Complex &operator/=(const Complex &z)\
    \ {\n            double z_norm = norm(z);\n            double r = (this->re *\
    \ z.re + this->im * z.im) / z_norm;\n            double i = (this->im * z.re -\
    \ this->re * z.im) / z_norm;\n            this->re = r;\n            this->im\
    \ = i;\n            return *this;\n        }\n        Complex &operator/=(const\
    \ double &k) {\n            this->re /= k;\n            this->im /= k;\n     \
    \       return *this;\n        }\n\n        Complex operator+(const Complex &rhs)\
    \ const {\n            return Complex(*this) += rhs;\n        }\n        Complex\
    \ operator+(const double &rhs) const {\n            return Complex(*this) += rhs;\n\
    \        }\n        Complex operator-(const Complex &rhs) const {\n          \
    \  return Complex(*this) -= rhs;\n        }\n        Complex operator-(const double\
    \ &rhs) const {\n            return Complex(*this) -= rhs;\n        }\n      \
    \  Complex operator*(const Complex &rhs) const {\n            return Complex(*this)\
    \ *= rhs;\n        }\n        Complex operator*(const double &rhs) const {\n \
    \           return Complex(*this) *= rhs;\n        }\n        Complex operator/(const\
    \ Complex &rhs) const {\n            return Complex(*this) /= rhs;\n        }\n\
    \        Complex operator/(const double &rhs) const {\n            return Complex(*this)\
    \ /= rhs;\n        }\n\n        double abs(const Complex &z) { return sqrt(z.re\
    \ * z.re + z.im * z.im); }\n        double norm(const Complex &z) { return z.re\
    \ * z.re + z.im * z.im; }\n        double arg(const Complex &z) { return atan2(z.im,\
    \ z.re); }\n        Complex conj(const Complex &z) { return Complex(z.re, -z.im);\
    \ }\n        Complex Polar(const double r, const double theta) {\n           \
    \ return Complex(r * cos(theta), r * sin(theta));\n        }\n    };\n\n  public:\n\
    \    void _fft(vector<Complex> &a, bool is_inverse) {\n        const int n = a.size();\n\
    \        assert(n ^ (n & -n) == 0);\n        int i = 0;\n        for(int j = 1;\
    \ j < n - 1; j++) {\n            for(int k = n >> 1; k > (i ^= k); k >>= 1)\n\
    \                ;\n            if(j < i)\n                swap(a[i], a[j]);\n\
    \        }\n\n        for(int m = 1; m < n; m *= 2) {\n            const int m2\
    \ = 2 * m;\n            const Complex base = Complex(\n                cos(2.0\
    \ * PI / m2), sin(2.0 * PI / m2) * (is_inverse ? -1 : 1));\n            Complex\
    \ w = 1;\n            for(int x = 0; x < m; x++) {\n                for(int s\
    \ = x; s < n; s += m2) {\n                    Complex u = a[s];\n            \
    \        Complex d = a[s + m] * w;\n                    a[s] = u + d;\n      \
    \              a[s + m] = u - d;\n                }\n                w *= base;\n\
    \            }\n        }\n    }\n\n    void fft(vector<Complex> &a) { _fft(a,\
    \ false); }\n    void ifft(vector<Complex> &a) {\n        _fft(a, true);\n   \
    \     int n = a.size();\n        for(auto &x : a)\n            x /= n;\n    }\n\
    \n    vector<Complex> convolution(const vector<Complex> &_a,\n               \
    \                 const vector<Complex> &_b) {\n        vector<Complex> a(_a),\
    \ b(_b);\n        int s = a.size() + b.size(), t = 1;\n        while(t < s)\n\
    \            t *= 2;\n        a.resize(t), b.resize(t);\n        fft(a), fft(b);\n\
    \        for(int i = 0; i < t; i++)\n            a[i] *= b[i];\n        ifft(a);\n\
    \        return a;\n    }\n\n    vector<Complex> convolution(const vector<double>\
    \ &_a,\n                                const vector<double> &_b) {\n        vector<Complex>\
    \ a(_a.size()), b(_b.size());\n        for(int i = 0; i < a.size(); i++)\n   \
    \         a[i] = _a[i];\n        for(int i = 0; i < b.size(); i++)\n         \
    \   b[i] = _b[i];\n        return convolution(a, b);\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nclass ConvolutionFFT {\n\
    \  private:\n    const double PI = acos(-1);\n    class Complex {\n      private:\n\
    \        double re;\n        double im;\n\n      public:\n        Complex() :\
    \ re(0), im(0) {}\n        Complex(double _re, double _im) : re(_re), im(_im)\
    \ {}\n        Complex(double _re) : re(_re), im(0) {}\n        double real() const\
    \ { return re; }\n        double imag() const { return re; }\n\n        Complex\
    \ &operator=(const Complex &z) {\n            this->re = z.re;\n            this->im\
    \ = z.im;\n            return *this;\n        }\n        Complex &operator=(const\
    \ double k) {\n            this->re = k;\n            this->im = 0;\n        \
    \    return *this;\n        }\n        Complex operator+() const { return *this;\
    \ }\n        Complex operator-() const { return Complex(-re, -im); }\n\n     \
    \   Complex &operator+=(const Complex &z) {\n            this->re += z.re;\n \
    \           this->im += z.im;\n            return *this;\n        }\n        Complex\
    \ &operator+=(const double &k) {\n            this->re += k;\n            return\
    \ *this;\n        }\n        Complex &operator-=(const Complex &z) {\n       \
    \     this->re -= z.re;\n            this->im -= z.im;\n            return *this;\n\
    \        }\n        Complex &operator-=(const double &k) {\n            this->re\
    \ -= k;\n            return *this;\n        }\n        Complex &operator*=(const\
    \ Complex &z) {\n            double r = this->re * z.re - this->im * z.im;\n \
    \           double i = this->re * z.im + this->im * z.re;\n            this->re\
    \ = r;\n            this->im = i;\n            return *this;\n        }\n    \
    \    Complex &operator*=(const double &k) {\n            this->re *= k;\n    \
    \        this->im *= k;\n            return *this;\n        }\n        Complex\
    \ &operator/=(const Complex &z) {\n            double z_norm = norm(z);\n    \
    \        double r = (this->re * z.re + this->im * z.im) / z_norm;\n          \
    \  double i = (this->im * z.re - this->re * z.im) / z_norm;\n            this->re\
    \ = r;\n            this->im = i;\n            return *this;\n        }\n    \
    \    Complex &operator/=(const double &k) {\n            this->re /= k;\n    \
    \        this->im /= k;\n            return *this;\n        }\n\n        Complex\
    \ operator+(const Complex &rhs) const {\n            return Complex(*this) +=\
    \ rhs;\n        }\n        Complex operator+(const double &rhs) const {\n    \
    \        return Complex(*this) += rhs;\n        }\n        Complex operator-(const\
    \ Complex &rhs) const {\n            return Complex(*this) -= rhs;\n        }\n\
    \        Complex operator-(const double &rhs) const {\n            return Complex(*this)\
    \ -= rhs;\n        }\n        Complex operator*(const Complex &rhs) const {\n\
    \            return Complex(*this) *= rhs;\n        }\n        Complex operator*(const\
    \ double &rhs) const {\n            return Complex(*this) *= rhs;\n        }\n\
    \        Complex operator/(const Complex &rhs) const {\n            return Complex(*this)\
    \ /= rhs;\n        }\n        Complex operator/(const double &rhs) const {\n \
    \           return Complex(*this) /= rhs;\n        }\n\n        double abs(const\
    \ Complex &z) { return sqrt(z.re * z.re + z.im * z.im); }\n        double norm(const\
    \ Complex &z) { return z.re * z.re + z.im * z.im; }\n        double arg(const\
    \ Complex &z) { return atan2(z.im, z.re); }\n        Complex conj(const Complex\
    \ &z) { return Complex(z.re, -z.im); }\n        Complex Polar(const double r,\
    \ const double theta) {\n            return Complex(r * cos(theta), r * sin(theta));\n\
    \        }\n    };\n\n  public:\n    void _fft(vector<Complex> &a, bool is_inverse)\
    \ {\n        const int n = a.size();\n        assert(n ^ (n & -n) == 0);\n   \
    \     int i = 0;\n        for(int j = 1; j < n - 1; j++) {\n            for(int\
    \ k = n >> 1; k > (i ^= k); k >>= 1)\n                ;\n            if(j < i)\n\
    \                swap(a[i], a[j]);\n        }\n\n        for(int m = 1; m < n;\
    \ m *= 2) {\n            const int m2 = 2 * m;\n            const Complex base\
    \ = Complex(\n                cos(2.0 * PI / m2), sin(2.0 * PI / m2) * (is_inverse\
    \ ? -1 : 1));\n            Complex w = 1;\n            for(int x = 0; x < m; x++)\
    \ {\n                for(int s = x; s < n; s += m2) {\n                    Complex\
    \ u = a[s];\n                    Complex d = a[s + m] * w;\n                 \
    \   a[s] = u + d;\n                    a[s + m] = u - d;\n                }\n\
    \                w *= base;\n            }\n        }\n    }\n\n    void fft(vector<Complex>\
    \ &a) { _fft(a, false); }\n    void ifft(vector<Complex> &a) {\n        _fft(a,\
    \ true);\n        int n = a.size();\n        for(auto &x : a)\n            x /=\
    \ n;\n    }\n\n    vector<Complex> convolution(const vector<Complex> &_a,\n  \
    \                              const vector<Complex> &_b) {\n        vector<Complex>\
    \ a(_a), b(_b);\n        int s = a.size() + b.size(), t = 1;\n        while(t\
    \ < s)\n            t *= 2;\n        a.resize(t), b.resize(t);\n        fft(a),\
    \ fft(b);\n        for(int i = 0; i < t; i++)\n            a[i] *= b[i];\n   \
    \     ifft(a);\n        return a;\n    }\n\n    vector<Complex> convolution(const\
    \ vector<double> &_a,\n                                const vector<double> &_b)\
    \ {\n        vector<Complex> a(_a.size()), b(_b.size());\n        for(int i =\
    \ 0; i < a.size(); i++)\n            a[i] = _a[i];\n        for(int i = 0; i <\
    \ b.size(); i++)\n            b[i] = _b[i];\n        return convolution(a, b);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/ConvolutionFFT.cc
  requiredBy: []
  timestamp: '2021-06-05 15:25:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/ConvolutionFFT.cc
layout: document
redirect_from:
- /library/Math/ConvolutionFFT.cc
- /library/Math/ConvolutionFFT.cc.html
title: Math/ConvolutionFFT.cc
---
