#include <bits/stdc++.h>

namespace math {

std::set<long long> divisor(long long n) {
    std::set<long long> ret;
    for(long long i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.insert(i);
            if(i * i != n)
                ret.insert(n / i);
        }
    }
    return ret;
}

// 素数篩＋素因数分解
// 初期化O(N),素因数分解O(logN)
// たくさん素因数分解するときはこっち
struct Sieve {
    int N;
    std::vector<int> sieve;
    std::vector<int> primes;
    Sieve(int n) : N(n), sieve(n + 1) { init(); }
    void init() {
        std::iota(sieve.begin(), sieve.end(), 0);
        for(int i = 2; i * i <= N; i++) {
            if(sieve[i] < i)
                continue;
            for(int j = i * i; j <= N; j += i) {
                if(sieve[j] == j)
                    sieve[j] = i;
            }
        }
        for(int i = 2; i <= N; i++) {
            if(is_prime(i)) primes.push_back(i);
        }
    }

    bool is_prime(int x) {
        assert(x <= N);
        if(x == 1)
            return false;
        return sieve[x] == x;
    }

    std::map<long long, int> prime_factorize(int n) {
        assert(n <= N);
        std::map<long long, int> ret;
        while(n > 1) {
            ret[sieve[n]]++;
            n = n / sieve[n];
        }
        return ret;
    }

    std::map<long long, int> prime_factorize_large(long long n) {
        std::map<long long, int> ret;
        for(auto p : primes) {
            while(n % p == 0) {
                ret[p]++;
                n /= p;
            }
        }
        if(n > 1) ret[n] = 1;
        return ret;
    }
};

// 素因数分解
// O(sqrt(N))
std::map<long long, int> prime_factor(long long n) {
    std::map<long long, int> ret;
    for(long long i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1)
        ret[n] = 1;
    return ret;
}

long long mod_pow(long long x, long long n, long long mod) {
    if(n == 0)
        return 1;
    long long res = mod_pow(x * x % mod, n / 2, mod);
    if(n & 1)
        res = res * x % mod;
    return res;
}

long long euler_phi(long long n) {
    long long ret = n;
    for(long long i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ret -= ret / i;
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1)
        ret -= ret / n;
    return ret;
}

long long extgcd(long long a, long long b, long long &x, long long &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

long long mod_inv(long long a, long long mod) {
    long long b = mod, u = 1, v = 0;
    while(b) {
        long long t = a / b;
        std::swap(a -= t * b, b);
        std::swap(u -= t * b, v);
    }
    u %= mod;
    if(u < 0)
        u += mod;
    return u;
}

std::pair<long long, long long>
crt2(const std::pair<long long, long long> &rm1,
     const std::pair<long long, long long> &rm2) {
    long long p, q;
    auto [r1, m1] = rm1;
    auto [r2, m2] = rm2;
    long long d = extgcd(r1, m2, p, q);
    if((r2 - r1) % d != 0)
        return {0, -1};
    long long m = m1 * (m2 / d);
    long long tmp = (r2 - r1) / d * p % (m2 / d);
    long long c = (r1 + m1 * tmp);
    long long r = (c % m + m) % m;
    return {r, m};
}

/**
 * @brief  Garnerのアルゴリズム. x % m[i] == b[i] % m[i]を満たす最小のxを求める.
 *
 * @param rm {あまり,法}の配列. !!法はすべて互いに素!!
 * @return long long x % m[i] == b[i] % m[i]を満たす最小のx.
 */
long long garner(const std::vector<std::pair<long long, long long>> &rm) {
    int n = rm.size();
    long long m_prod = 1;
    long long res = rm[0].first % rm[0].second;
    for(int i = 1; i < n; i++) {
        auto [r, m] = rm[i];
        m_prod *= rm[i - 1].second;
        long long t = (((r - res) * mod_inv(m_prod, m)) % m + m) % m;
        res += t * m_prod;
    }
    return res;
}

/**
 * @brief  Garnerのアルゴリズム. x % m[i] == b[i] % m[i]を満たす最小のxを求める.
 *
 * @param rm {あまり,法}の配列. !!法はすべて互いに素!!
 * @param mod 答えの法.
 * @return long long x % m[i] == b[i] % m[i]を満たす最小のx (mod M).
 */
long long garner_mod(std::vector<std::pair<long long, long long>> rm,
                     long long mod) {
    rm.emplace_back(0, mod);
    int n = rm.size();
    std::vector<long long> coffs(n, 1), constants(n, 0);
    for(int i = 0; i < n - 1; i++) {
        auto [r, m] = rm[i];
        long long t = ((r - constants[i]) * mod_inv(coffs[i], m) % m + m) & m;
        for(int j = i + 1; j < n; j++) {
            (constants[j] += coffs[j] * t) %= rm[j].second;
            (coffs[j] *= m) %= rm[j].second;
        }
    }
    return constants.back();
}

long long floor_div(long long a, long long b) {
    assert(b != 0);
    if(b < 0)
        a = -a, b = -b;
    return a >= 0 ? a / b : (a - (b - 1)) / b;
}

long long ceil_div(long long a, long long b) {
    assert(b != 0);
    if(b < 0)
        a = -a, b = -b;
    return a >= 0 ? (a + b - 1) / b : a / b;
}

int bit_length(long long x) {
    assert(x >= 0);
    int ret = 0;
    while(x > 0) {
        ret++;
        x /= 2;
    }
    return ret;
}

long long ll_sqrt(long long x) {
    long long ret = sqrt(x) - 1;
    while((ret + 1) * (ret + 1) <= x)
        ret++;
    return ret;
}

// multiple of d in [left,right],left>0
long long cmul(long long left, long long right, long long d) {
    if(left == 0)
        return right / d;
    return right / d - (left - 1) / d;
}

// multiple of d in [left,right]
long long count_multiple(long long left, long long right, long long d) {
    if(right < 0)
        return cmul(-right, -left, d);
    if(left > 0)
        return cmul(left, right, d);
    return cmul(0, right, d) + cmul(0, -left, d) + 1;
}

}; // namespace math

using namespace math;