#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/* ModInt */
template <uint_fast64_t MOD> class ModInt {
    using u64 = uint_fast64_t;

  public:
    u64 val;

    ModInt(const u64 x = 0) : val((x + MOD) % MOD) {}
    constexpr u64 &value() { return val; }
    static const u64 get_mod() { return MOD; }
    constexpr ModInt operator-() { return val ? MOD - val : 0; }
    constexpr ModInt operator+(const ModInt &rhs) const {
        return ModInt(*this) += rhs;
    }
    constexpr ModInt operator-(const ModInt &rhs) const {
        return ModInt(*this) -= rhs;
    }
    constexpr ModInt operator*(const ModInt &rhs) const {
        return ModInt(*this) *= rhs;
    }
    constexpr ModInt operator/(const ModInt &rhs) const {
        return ModInt(*this) /= rhs;
    }
    constexpr ModInt &operator+=(const ModInt &rhs) {
        val += rhs.val;
        if(val >= MOD) {
            val -= MOD;
        }
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs) {
        if(val < rhs.val) {
            val += MOD;
        }
        val -= rhs.val;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &rhs) {
        val = val * rhs.val % MOD;
        return *this;
    }

    constexpr ModInt &operator/=(const ModInt &rhs) {
        *this *= rhs.inv();
        return *this;
    }

    constexpr bool operator==(const ModInt &rhs) { return this->a == rhs.a; }
    constexpr bool operator!=(const ModInt &rhs) { return this->a != rhs.a; }
    friend constexpr ostream &operator<<(ostream &os, const ModInt<MOD> &x) {
        return os << x.val;
    }
    friend constexpr istream &operator>>(istream &is, ModInt<MOD> &x) {
        return is >> x.val;
    }

    constexpr ModInt inv() const { return ModInt(*this).pow(MOD - 2); }

    constexpr ModInt pow(long long e) const {
        u64 x = 1, p = val;
        while(e > 0) {
            if(e % 2 == 0) {
                p = (p * p) % MOD;
                e /= 2;
            } else {
                x = (x * p) % MOD;
                e--;
            }
        }
        return ModInt(x);
    }
};

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
        int s = a.size() + b.size() - 1;
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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    using mint = ModInt<998244353>;
    Convolution<mint> ntt;
    auto ans = ntt.convolution(a, b);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
}
