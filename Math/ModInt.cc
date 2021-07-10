#include <bits/stdc++.h>
using namespace std;
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

using mint = ModInt<1000000007UL>;
// using mint = ModInt<998244353UL>;
