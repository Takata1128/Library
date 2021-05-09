#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename Mint> class Convolution {
  private:
    constexpr int primroot(int p) {
        if(p == 2)
            return 1;
        if(p == 167772161)
            return 3;
        if(p == 469762049)
            return 3;
        if(p == 754974721)
            return 11;
        if(p == 998244353)
            return 3;
        assert(false);
    }

  public:
    void _ntt(vector<Mint> &a, bool is_inverse) {
        const int n = a.size();
        const int mod = Mint::get_mod();
        const int g = primroot(mod);
        assert((n ^ (n & -n)) == 0);
        Mint h = Mint(g).pow((mod - 1) / n);
        h = (is_inverse ? h.inv() : h);

        int i = 0;
        for(int j = 1; j < n - 1; j++) {
            for(int k = n >> 1; k > (i ^= k); k >>= 1)
                ;
            if(j < i)
                swap(a[i], a[j]);
        }

        for(int m = 1; m < n; m *= 2) {
            const int m2 = 2 * m;
            const Mint base = h.pow(n / m2);
            Mint w = 1;
            for(int x = 0; x < m; x++) {
                for(int s = x; s < n; s += m2) {
                    Mint u = a[s];
                    Mint d = a[s + m] * w;
                    a[s] = u + d;
                    a[s + m] = u - d;
                }
                w *= base;
            }
        }
    }

    void ntt(vector<Mint> &a) { _ntt(a, false); }
    void intt(vector<Mint> &a) {
        _ntt(a, true);
        int n = a.size();
        Mint n_inv = Mint(n).inv();
        for(auto &x : a)
            x *= n_inv;
    }

    vector<Mint> convolution(const vector<Mint> &_a, const vector<Mint> &_b) {
        vector<Mint> a(_a), b(_b);
        int s = a.size() + b.size();
        int t = 1;
        while(t < s)
            t *= 2;
        a.resize(t);
        b.resize(t);
        ntt(a);
        ntt(b);
        for(int i = 0; i < t; i++) {
            a[i] *= b[i];
        }
        intt(a);
        return a;
    }

    template <typename T>
    vector<Mint> convolution(const vector<T> &_a, const vector<T> &_b) {
        vector<Mint> a(_a.size()), b(_b.size());
        for(int i = 0; i < a.size(); i++)
            a[i] = _a[i];
        for(int i = 0; i < b.size(); i++)
            b[i] = _b[i];
        return convolution(a, b);
    }
};
