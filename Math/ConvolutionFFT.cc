#include <bits/stdc++.h>
using namespace std;

class ConvolutionFFT {
  private:
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
        Complex operator+(const double &rhs) const {
            return Complex(*this) += rhs;
        }
        Complex operator-(const Complex &rhs) const {
            return Complex(*this) -= rhs;
        }
        Complex operator-(const double &rhs) const {
            return Complex(*this) -= rhs;
        }
        Complex operator*(const Complex &rhs) const {
            return Complex(*this) *= rhs;
        }
        Complex operator*(const double &rhs) const {
            return Complex(*this) *= rhs;
        }
        Complex operator/(const Complex &rhs) const {
            return Complex(*this) /= rhs;
        }
        Complex operator/(const double &rhs) const {
            return Complex(*this) /= rhs;
        }

        double abs(const Complex &z) { return sqrt(z.re * z.re + z.im * z.im); }
        double norm(const Complex &z) { return z.re * z.re + z.im * z.im; }
        double arg(const Complex &z) { return atan2(z.im, z.re); }
        Complex conj(const Complex &z) { return Complex(z.re, -z.im); }
        Complex Polar(const double r, const double theta) {
            return Complex(r * cos(theta), r * sin(theta));
        }
    };

  public:
    void _fft(vector<Complex> &a, bool is_inverse) {
        const int n = a.size();
        assert(n ^ (n & -n) == 0);
        int i = 0;
        for(int j = 1; j < n - 1; j++) {
            for(int k = n >> 1; k > (i ^= k); k >>= 1)
                ;
            if(j < i)
                swap(a[i], a[j]);
        }

        for(int m = 1; m < n; m *= 2) {
            const int m2 = 2 * m;
            const Complex base = Complex(
                cos(2.0 * PI / m2), sin(2.0 * PI / m2) * (is_inverse ? -1 : 1));
            Complex w = 1;
            for(int x = 0; x < m; x++) {
                for(int s = x; s < n; s += m2) {
                    Complex u = a[s];
                    Complex d = a[s + m] * w;
                    a[s] = u + d;
                    a[s + m] = u - d;
                }
                w *= base;
            }
        }
    }

    void fft(vector<Complex> &a) { _fft(a, false); }
    void ifft(vector<Complex> &a) {
        _fft(a, true);
        int n = a.size();
        for(auto &x : a)
            x /= n;
    }

    vector<Complex> convolution(const vector<Complex> &_a,
                                const vector<Complex> &_b) {
        vector<Complex> a(_a), b(_b);
        int s = a.size() + b.size(), t = 1;
        while(t < s)
            t *= 2;
        a.resize(t), b.resize(t);
        fft(a), fft(b);
        for(int i = 0; i < t; i++)
            a[i] *= b[i];
        ifft(a);
        return a;
    }

    vector<Complex> convolution(const vector<double> &_a,
                                const vector<double> &_b) {
        vector<Complex> a(_a.size()), b(_b.size());
        for(int i = 0; i < a.size(); i++)
            a[i] = _a[i];
        for(int i = 0; i < b.size(); i++)
            b[i] = _b[i];
        return convolution(a, b);
    }
};
