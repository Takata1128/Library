#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> void write(const T &a) { cout << a << '\n'; }
template <class T> void write(const vector<T> &a) {
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << (i + 1 == a.size() ? '\n' : ' ');
}
struct IO {
    IO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(10);
    }
} io;

#pragma endregion

template <uint_fast64_t MOD> class ModInt {
    using u64 = uint_fast64_t;

  public:
    u64 val;

    ModInt(const u64 x = 0) : val((x + MOD) % MOD) {}
    constexpr u64 &value() { return val; }
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

    constexpr bool operator==(const ModInt &rhs) {
        return this->val == rhs.val;
    }
    constexpr bool operator!=(const ModInt &rhs) {
        return this->val != rhs.val;
    }
    friend constexpr ostream &operator<<(ostream &os, const ModInt<MOD> &x) {
        return os << x.val;
    }
    friend constexpr istream &operator>>(istream &is, ModInt<MOD> &x) {
        return is >> x.val;
    }

    constexpr ModInt inv() const { return ModInt(*this).pow(MOD - 2); }

    constexpr ModInt pow(ll e) const {
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

template <typename T> struct FormalPowerSeries : public vector<T> {
    using vector<T>::vector;
    using Mint = T;
    using F = FormalPowerSeries<T>;
    template <int prime>
    inline vector<ModInt<prime>> ntt(vector<ModInt<prime>> a, bool is_inverse) {
        auto f = [&](auto &&f, vector<ModInt<prime>> a,
                     bool is_inverse) -> vector<ModInt<prime>> {
            int n = a.size();
            if(n == 1)
                return a;
            vector<ModInt<prime>> f0(n / 2), f1(n / 2);
            for(int i = 0; i < (n / 2); i++) {
                f0[i] = (a[i * 2]);
                f1[i] = (a[i * 2 + 1]);
            }
            f0 = f(f, f0, is_inverse), f1 = f(f, f1, is_inverse);
            ModInt<prime> zeta =
                (is_inverse
                     ? ModInt<prime>(primroot(prime)).inv().pow(prime / n)
                     : ModInt<prime>(primroot(prime)).pow(prime / n));
            ModInt<prime> pow_zeta = 1;
            for(int i = 0; i < n; i++) {
                a[i] = (f0[i % (n / 2)] + pow_zeta * f1[i % (n / 2)]);
                pow_zeta *= zeta;
            }
            return a;
        };
        vector<ModInt<prime>> ret = f(f, a, is_inverse);
        int n = ret.size();
        if(is_inverse) {
            for(int i = 0; i < n; i++) {
                ret[i] *= ModInt<prime>(n).inv();
            }
        }
        return ret;
    }
    template <int prime>
    inline vector<ModInt<prime>> convolve(const vector<Mint> &_a,
                                          const vector<Mint> &_b) {
        vector<Mint> a(_a), b(_b);
        int s = a.size() + b.size() - 1;
        int t = 1;
        while(t < s)
            t *= 2;
        a.resize(t);
        b.resize(t);
        vector<ModInt<prime>> A = ntt<prime>(a, false);
        vector<ModInt<prime>> B = ntt<prime>(b, false);
        vector<ModInt<prime>> C(t);
        for(int i = 0; i < t; i++) {
            C[i] = (A[i] * B[i]);
        }
        C = ntt<prime>(C, true);
        return C;
    }

    inline vector<ModInt<998244353>>
    convolution(const vector<ModInt<998244353>> &g,
                const vector<ModInt<998244353>> &h) {
        return convolve<998244353>(g, h);
    }

    void shrink() {
        while(this->size() && this->back() == T(0))
            this->pop_back();
    }

  public:
    FormalPowerSeries(vector<Mint> v) {
        *this = FormalPowerSeries(v.size());
        for(int i = 0; i < v.size(); i++)
            (*this)[i] = v[i];
    }
    F operator*(const Mint &g) const { return F(*this) *= g; }
    F &operator*=(const Mint &g) {
        for(auto &e : *this)
            e *= g;
        return *this;
    }
    F operator*(const F &g) const { return F(*this) *= g; }
    F &operator*=(const F &g) {
        if((*this).empty() || g.empty()) {
            this->clear();
            return *this;
        }
        return *this = convolution(*this, g);
    }
    F operator/(const Mint &g) const { return F(*this) /= g; }
    F &operator/=(const Mint &g) {
        assert(g != Mint(0));
        return (*this) *= g.inv();
    }
    F operator+(const F &g) const { return F(*this) += g; }
    F &operator+=(const F &g) {
        if(g.size() > this->size()) {
            this->resize(g.size());
        }
        for(int i = 0; i < this->size(); i++)
            (*this)[i] += g[i];
        return *this;
    }
    F operator-(const F &g) const { return F(*this) -= g; }
    F &operator-=(const F &g) {
        if(g.size() > this->size()) {
            this->resize(g.size());
        }
        for(int i = 0; i < this->size(); i++)
            (*this)[i] -= g[i];
        return *this;
    }
    F operator-() const {
        F res(*this);
        for(auto &e : *this)
            e = -e;
        return res;
    }
    F &operator<<=(const int d) {
        int n = (*this).size();
        (*this).insert((*this).begin(), d, 0);
        (*this).resize(n);
        return *this;
    }
    F &operator>>=(const int d) {
        int n = (*this).size();
        (*this).erase((*this).begin(), (*this).begin() + min(n, d));
        (*this).resize(n);
        return *this;
    }
    F &operator=(const F &g) {
        (*this).clear();
        (*this).resize(g.size());
        for(int i = 0; i < g.size(); i++)
            (*this)[i] = g[i];
        return *this;
    }

    F pre(int sz) const {
        return F((*this).begin(),
                 (*this).begin() + min(sz, (int)(*this).size()));
    }

    F inv(int d = -1) {
        int n = (*this).size();
        assert(n != 0 && (*this)[0] != Mint(0));
        if(d == -1)
            d = n;
        assert(d >= 0);
        F ret({Mint(1) / (*this)[0]});
        for(int i = 1; i < d; i <<= 1) {
            ret = (ret * 2 - ret * ret * pre(i << 1)).pre(i << 1);
        }
        return ret.pre(d);
    }
};

int main() {
    int n;
    cin >> n;
    using mint = ModInt<998244353>;
    FormalPowerSeries<mint> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    auto b = a.inv();
    for(int i = 0; i < n; i++) {
        cout << b[i] << (i == n - 1 ? '\n' : ' ');
    }
}