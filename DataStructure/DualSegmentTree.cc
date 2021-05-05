#include <bits/stdc++.h>
using namespace std;

/*** DualSegmentTree ***/
template <class F> class DualSegTree {
  private:
    using Composition = function<F(F, F)>;

    size_t n;
    const Composition composition;
    const F oe;
    vector<F> lazy;

    // 子に伝播
    inline void propagate(int k) {
        if(lazy[k] != oe) {
            lazy[2 * k] = composition(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = composition(lazy[2 * k + 1], lazy[k]);
            lazy[k] = oe;
        }
    }

    // 上から伝播
    inline void thrust(int k) {
        for(int i = 31 - __builtin_clz(k); i > 0; i--) {
            if((k >> i) >= 1)
                propagate(k >> i);
        }
    }

  public:
    DualSegTree(int sz, const Composition _h, const F &_oe)
        : composition(_h), oe(_oe) {
        n = 1;
        while(n < sz) {
            n <<= 1;
        }
        lazy.resize(2 * n, oe);
    }

    DualSegTree(const vector<F> &v, const Composition _h, const F &_oe)
        : composition(_h), oe(_oe) {
        int sz = v.size();
        n = 1;
        while(n < sz) {
            n <<= 1;
        }
        lazy.resize(2 * n, oe);
        for(int i = 0; i < sz; i++)
            set(i, v[i]);
    }

    void set(int k, const F &x) {
        k += n;
        thrust(k);
        lazy[k] = x;
    }

    // [L,R)区間作用
    void update(int L, int R, const F &x) {
        L += n, R += n;
        int L0 = L / (L & -L), R0 = R / (R & -R) - 1;
        thrust(L0);
        thrust(R0);
        while(L < R) {
            if(L & 1) {
                lazy[L] = composition(x, lazy[L]);
                L++;
            }
            if(R & 1) {
                R--;
                lazy[R] = composition(lazy[R], x);
            }
            L >>= 1;
            R >>= 1;
        }
    }

    // 一点取得
    F at(int k) {
        k += n;
        thrust(k);
        return lazy[k];
    }

    F operator[](int k) { return at(k); }
};

struct F {};
F composition(F f, F g){};
F id() {}