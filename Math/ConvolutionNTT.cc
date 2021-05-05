#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <int MOD = 998244353, int primroot = 3> class ConvolutionNTT {
  private:
    vector<ll> a, b;
    ll modpow(ll v, ll n) {
        ll x = 1, p = v;
        while(n > 0) {
            if(n % 2 == 0) {
                p = (p * p) % MOD;
                n /= 2;
            } else {
                x = (x * p) % MOD;
                n--;
            }
        }
        return x;
    }
    ll modinv(ll v) { return modpow(v, MOD - 2); }

  public:
    ConvolutionNTT(vector<ll> &_a, vector<ll> &_b) {
        a = _a;
        b = _b;
    }

    vector<ll> ntt_rec(vector<ll> a, bool is_inverse = false) {
        int n = a.size();
        if(n == 1)
            return a;
        vector<ll> f0(n / 2), f1(n / 2);
        for(int i = 0; i < (n / 2); i++) {
            f0[i] = (a[i * 2]);
            f1[i] = (a[i * 2 + 1]);
        }
        f0 = ntt_rec(f0, is_inverse), f1 = ntt_rec(f1, is_inverse);
        ll zeta = modpow(is_inverse ? modinv(primroot) : primroot, MOD / n);
        ll pow_zeta = 1;
        for(int i = 0; i < n; i++) {
            a[i] = (f0[i % (n / 2)] + pow_zeta * f1[i % (n / 2)]) % MOD;
            pow_zeta *= zeta;
            pow_zeta %= MOD;
        }
        return a;
    }

    vector<ll> ntt(vector<ll> a, bool is_inverse) {
        vector<ll> ret = ntt_rec(a, is_inverse);
        int n = ret.size();
        if(is_inverse) {
            for(int i = 0; i < n; i++) {
                ret[i] *= modinv(n);
                ret[i] %= MOD;
            }
        }
        return ret;
    }

    vector<ll> convolve() {
        int s = a.size() + b.size() - 1;
        int t = 1;
        while(t < s)
            t *= 2;
        a.resize(t);
        b.resize(t);

        vector<ll> A = ntt(a, false);
        vector<ll> B = ntt(b, false);
        vector<ll> C(t);
        for(int i = 0; i < t; i++) {
            C[i] = (A[i] * B[i]) % MOD;
        }
        C = ntt(C, true);
        return C;
    }
};
