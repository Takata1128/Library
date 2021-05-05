#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);

class Complex {
  private:
    double re;
    double im;

  public:
    Complex() : re(0), im(0) {}
    Complex(double _re, double _im) : re(_re), im(_im) {}
    Complex(double _re) : re(_re), im(0) {}
    double real() const { return re; }
    double imag() const { return re; }

    Complex &operator=(const Complex &z) {
        this->re = z.re;
        this->im = z.im;
        return *this;
    }
    Complex &operator=(const double k) {
        this->re = k;
        this->im = 0;
        return *this;
    }
    Complex operator+() const { return *this; }
    Complex operator-() const { return Complex(-re, -im); }

    Complex &operator+=(const Complex &z) {
        this->re += z.re;
        this->im += z.im;
        return *this;
    }
    Complex &operator+=(const double &k) {
        this->re += k;
        return *this;
    }
    Complex &operator-=(const Complex &z) {
        this->re -= z.re;
        this->im -= z.im;
        return *this;
    }
    Complex &operator-=(const double &k) {
        this->re -= k;
        return *this;
    }
    Complex &operator*=(const Complex &z) {
        double r = this->re * z.re - this->im * z.im;
        double i = this->re * z.im + this->im * z.re;
        this->re = r;
        this->im = i;
        return *this;
    }
    Complex &operator*=(const double &k) {
        this->re *= k;
        this->im *= k;
        return *this;
    }
    Complex &operator/=(const Complex &z) {
        double z_norm = norm(z);
        double r = (this->re * z.re + this->im * z.im) / z_norm;
        double i = (this->im * z.re - this->re * z.im) / z_norm;
        this->re = r;
        this->im = i;
        return *this;
    }
    Complex &operator/=(const double &k) {
        this->re /= k;
        this->im /= k;
        return *this;
    }

    Complex operator+(const Complex &rhs) const {
        return Complex(*this) += rhs;
    }
    Complex operator+(const double &rhs) const { return Complex(*this) += rhs; }
    Complex operator-(const Complex &rhs) const {
        return Complex(*this) -= rhs;
    }
    Complex operator-(const double &rhs) const { return Complex(*this) -= rhs; }
    Complex operator*(const Complex &rhs) const {
        return Complex(*this) *= rhs;
    }
    Complex operator*(const double &rhs) const { return Complex(*this) *= rhs; }
    Complex operator/(const Complex &rhs) const {
        return Complex(*this) /= rhs;
    }
    Complex operator/(const double &rhs) const { return Complex(*this) /= rhs; }

    double abs(const Complex &z) { return sqrt(z.re * z.re + z.im * z.im); }
    double norm(const Complex &z) { return z.re * z.re + z.im * z.im; }
    double arg(const Complex &z) { return atan2(z.im, z.re); }
    Complex conj(const Complex &z) { return Complex(z.re, -z.im); }
    Complex Polar(const double r, const double theta) {
        return Complex(r * cos(theta), r * sin(theta));
    }
};

struct ConvolutionFFT {
    vector<Complex> a, b;
    ConvolutionFFT(vector<double> &_a, vector<double> &_b) {
        a.assign(_a.size(), Complex());
        b.assign(_b.size(), Complex());
        for(int i = 0; i < _a.size(); i++) {
            a[i] = _a[i];
        }
        for(int i = 0; i < _b.size(); i++) {
            b[i] = _b[i];
        }
    }

    vector<Complex> fft_rec(vector<Complex> a, bool is_inverse = false) {
        int n = a.size();
        if(n == 1)
            return a;
        vector<Complex> f0, f1;
        for(int i = 0; i < (n / 2); i++) {
            f0.push_back(a[i * 2]);
            f1.push_back(a[i * 2 + 1]);
        }
        f0 = fft_rec(f0, is_inverse), f1 = fft_rec(f1, is_inverse);
        Complex zeta = Complex(cos(2.0 * PI / n),
                               sin(2.0 * PI / n) * (is_inverse ? -1 : 1));
        Complex pow_zeta = 1;
        for(int i = 0; i < n; i++) {
            a[i] = f0[i % (n / 2)] + pow_zeta * f1[i % (n / 2)];
            pow_zeta *= zeta;
        }
        return a;
    }

    vector<Complex> fft(vector<Complex> a, bool is_inverse) {
        vector<Complex> ret = fft_rec(a, is_inverse);
        int n = ret.size();
        if(is_inverse) {
            for(int i = 0; i < n; i++)
                ret[i] /= n;
        }
        return ret;
    }

    vector<double> convolve() {
        int s = a.size() + b.size() - 1;
        int t = 1;
        while(t < s)
            t *= 2;
        a.resize(t);
        b.resize(t);

        vector<Complex> A = fft(a, false);
        vector<Complex> B = fft(b, false);
        vector<Complex> C(t);
        for(int i = 0; i < t; i++) {
            C[i] = A[i] * B[i];
        }
        C = fft(C, true);
        vector<double> c(s);
        for(int i = 0; i < s; i++)
            c[i] = C[i].real();
        return c;
    }
};
