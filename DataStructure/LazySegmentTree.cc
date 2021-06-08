#include <bits/stdc++.h>
using namespace std;

template <class S, class F> class LazySegTree {
  private:
    using Op = function<S(S, S)>;
    using Mapping = function<S(S, F)>;
    using Composition = function<F(F, F)>;

    int n;
    int org_size;
    const Op op;
    const Mapping mapping;
    const Composition composition;
    const S e;
    const F oe;
    vector<S> node;
    vector<F> lazy;

    // ノードの評価
    inline S eval(int k) const { return mapping(node[k], lazy[k]); }

    // 子に伝播
    inline void propagate(int k) {
        lazy[2 * k] = composition(lazy[2 * k], lazy[k]);
        lazy[2 * k + 1] = composition(lazy[2 * k + 1], lazy[k]);
        node[k] = eval(k);
        lazy[k] = oe;
    }

    // 上から伝播
    inline void thrust(int k) {
        for(int i = 31 - __builtin_clz(k); i > 0; i--) {
            if((k >> i) >= 1)
                propagate(k >> i);
        }
    }

    // 下から再計算
    inline void recalc(int k) {
        while(k > 1) {
            k >>= 1;
            node[k] = op(eval(2 * k), eval(2 * k + 1));
        }
    }

  public:
    void set(int k, const S &x) { node[k + n] = x; }

    void build() {
        for(int i = n - 1; i > 0; i--)
            node[i] = op(node[2 * i], node[2 * i + 1]);
    }

    // [L,R)区間作用
    void update(int L, int R, F x) {
        L += n, R += n;
        int L0 = L / (L & -L), R0 = R / (R & -R) - 1;
        thrust(L0);
        thrust(R0);
        while(L < R) {
            if(L & 1) {
                lazy[L] = composition(lazy[L], x);
                L++;
            }
            if(R & 1) {
                R--;
                lazy[R] = composition(lazy[R], x);
            }
            L >>= 1;
            R >>= 1;
        }
        recalc(L0);
        recalc(R0);
    }

    // [L,R)区間取得
    S query(int L, int R) {
        L += n, R += n;
        thrust(L / (L & -L));
        thrust(R / (R & -R) - 1);
        S vl = e, vr = e;
        while(L < R) {
            if(L & 1) {
                vl = op(vl, eval(L));
                L++;
            }
            if(R & 1) {
                R--;
                vr = op(eval(R), vr);
            }
            L >>= 1;
            R >>= 1;
        }
        return op(vl, vr);
    }

    S at(int k) const { return query(k, k + 1); };

    // !!未verify!!
    int max_right(int l, function<bool(S)> f) const {
        if(l == org_size)
            return org_size;
        l += n;
        thrust(l / (l & -l));
        S cum = e;
        do {
            while(l % 2 == 0)
                l >>= 1;
            if(!f(op(cum, node[l]))) {
                while(l < n) {
                    l = 2 * l;
                    if(f(op(cum, node[l]))) {
                        cum = op(cum, node[l]);
                        l++;
                    }
                }
                return l - n;
            }
            cum = op(cum, node[l]);
            l++;
        } while((l & -l) != l);
        return org_size;
    }

    // !!未verify!!
    int min_left(int r, function<bool(S)> f) const {
        if(r == 0)
            return 0;
        r += n;
        thrust(r / (r & -r) - 1);
        S cum = e;
        do {
            r--;
            while(r > 1 && (r % 2))
                r >>= 1;
            if(!f(op(node[r], cum))) {
                while(r < n) {
                    r = 2 * r + 1;
                    if(f(op(node[r], cum))) {
                        cum = op(node[r], cum);
                        r--;
                    }
                }
                return r + 1 - n;
            }
            cum = op(node[r], cum);
        } while((r & (-r) != r));
        return 0;
    }

    LazySegTree(int sz, const Op op, const Mapping mapping,
                const Composition composition, const S &e, const F &oe)
        : op(op), mapping(mapping), composition(composition), e(e), oe(oe) {
        org_size = sz;
        n = 1;
        while(n < org_size) {
            n <<= 1;
        }
        node.resize(2 * n, e);
        lazy.resize(2 * n, oe);
    }
    LazySegTree(const vector<S> &v, const Op op, const Mapping mapping,
                const Composition composition, const S &e, const F &oe)
        : op(op), mapping(mapping), composition(composition), e(e), oe(oe) {
        org_size = v.size();
        n = 1;
        while(n < org_size) {
            n <<= 1;
        }
        node.resize(2 * n, e);
        lazy.resize(2 * n, oe);
        for(int i = 0; i < org_size; i++)
            set(i, v[i]);
        build();
    }
};
struct S {};
struct F {};
S op(S a, S b){};
S mapping(S a, F f){};
F composition(F f, F g){};
S e() {}
F id() {}
