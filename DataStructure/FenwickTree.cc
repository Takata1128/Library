#include <bits/stdc++.h>

/**
 * @brief 0-indexed (Internally 1-indexed) Fenwick Tree
 *
 * @tparam T Universal set.
 */
template <typename T> struct FenwickTree {
    int n;
    std::vector<T> dat;

    FenwickTree(int n) : n(++n), dat(n, 0) {}

    void add(int i, T x) {
        for(++i; i < n; i += i & -i)
            dat[i] = dat[i] + x;
    }

    /**
     * @brief Sum values in [0,i]
     *
     * @param i Right end of interval. Note that closed-interval [0,i].
     * @return T Summation values in [0,i].
     */
    T sum(int i) {
        T res = 0;
        for(++i; i > 0; i -= i & -i) {
            res = res + dat[i];
        }
        return res;
    }

    /**
     * @brief Sum values in [l,r]
     *
     * @param l Left end of interval.
     * @param r Right end of interval.
     * @return T Summation values in [l,r]
     */
    T sum(int l, int r) { return sum(r) - sum(l - 1); }

    /**
     * @brief Sum all values.
     *
     * @return T Summation values.
     */
    T sumAll() { return sum(n - 1); }

    /**
     * @brief If regard as histogram of elements, get k-th element.
     *
     * @param k Get k-th element.
     * @return int Index to which k-th element belongs.
     */
    int get(T k) {
        ++k;
        int res = 0;
        int N = 1;
        while(N < n)
            N *= 2;
        for(int i = N / 2; i > 0; i /= 2) {
            if(res + i < n && dat[res + i] < k) {
                k = k - dat[res + i];
                res = res + i;
            }
        }
        return res + 1;
    }
};
