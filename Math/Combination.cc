#include <bits/stdc++.h>
using namespace std;

//二項係数（nCk mod.p;1<=k<=n<=1e7,pは素数）for ModInt
template <class T> struct BiCoefficient {
    vector<T> fac, finv, inv;
    BiCoefficient(const int MAX) : fac(MAX), finv(MAX), inv(MAX) {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for(int i = 2; i < MAX; i++) {
            fac[i] = fac[i - 1] * i;
            inv[i] = -inv[MOD % i] * (MOD / i);
            finv[i] = finv[i - 1] * inv[i];
        }
    }
    T comb(int n, int k) {
        if(n < k)
            return 0;
        if(n < 0 || k < 0)
            return 0;
        return fac[n] * finv[k] * finv[n - k];
    }
};

// // 長さn,1<=a[i]<=mで単調増加の数列
// T inc_seq(int n, int m) { return comb(m, n); }
// // 長さn,1<=a[i]<=mで広義単調増加の数列(b[i]:=a[i]+iとおいて↑に帰着)
// // 片方もしくは両端を固定するとき:comb(m+n-1,(n-1 or n-2));
// T non_dec_seq(int n, int m) { return comb(m + n - 1, n); }
// // 足してSになる長さnの整数列
// T sum_seq(int n,int S){ return comb(S+n-1,n); }
// // 足してS以下になる長さnの整数列
// T sum_no_more_seq(int n,int S){return comb(S+n,n);}

//二項係数（nCk mod.p;1<=k<=n<=1e7,pは素数）for long long
struct Combination {
    const int MOD = 1000000007;
    vector<long long> fac, finv, inv;
    Combination(const int MAX) : fac(MAX), finv(MAX), inv(MAX) {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for(int i = 2; i < MAX; i++) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    long long comb(int n, int k) {
        if(n < k)
            return 0;
        if(n < 0 || k < 0)
            return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
};

//二項係数（nCk mod.p;1<=k<=n<=2000,pは素数でなくともよい）
const int MAX_C = 1000;
long long Com[MAX_C][MAX_C];
void calc_com(int MOD) {
    memset(Com, 0, sizeof(Com));
    Com[0][0] = 1;
    for(int i = 1; i < MAX_C; ++i) {
        Com[i][0] = 1;
        for(int j = 1; j < MAX_C; ++j) {
            Com[i][j] = (Com[i - 1][j - 1] + Com[i - 1][j]) % MOD;
        }
    }
}

//二項係数 (nCk mod.p; p is prime, Lucasの定理)
struct Lucas {
    vector<vector<long long>> com;
    long long p;
    Lucas(long long p) : p(p) { init(p); }

    void init(long long p) {
        com.assign(p, vector<long long>(p));
        com[0][0] = 1;
        for(int i = 1; i < p; i++) {
            com[i][0] = 1;
            for(int j = i; j > 0; j--) {
                com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % p;
            }
        }
    }

    long long comb(long long n, long long k) {
        long long ret = 1;
        while(n > 0) {
            int ni = n % p;
            int ki = k % p;
            ret *= com[ni][ki];
            ret %= p;
            n /= p;
            k /= p;
        }
        return ret;
    }
};

//二項係数 O(k)
// nとkのどちらかが変化していくとき、O(変化量)ですべて求められる　多分
// 参考：https://perogram.hateblo.jp/entry/2020/07/08/120017
// https://yukicoder.me/submissions/520882
template <class T> T nCk(long long n, long long k, map<pair<long long, long long>, T> &mp) {
    auto key = {n, k};
    if(mp.count(key))
        return mp[key];
    if(k == 0 || k == n) {
        T ret = 1;
        return ret;
    }
    if(k == 1 || k == n - 1) {
        T ret = n;
        return ret;
    }
    // return mp[key] = nCk(n, k - 1, mp) * (n - k + 1) / k;
    return mp[key] = nCk(n - 1, k, mp) * n / (n - k);
}