#include <bits/stdc++.h>
using namespace std;
template <class S> struct SegmentTree {
  private:
    using Op = function<S(S, S)>;
    const Op op;
    const S e;
    int n;
    int org_size;
    vector<S> dat;

  public:
    void set(int k, S a) { dat[k + n] = a; }

    void build() {
        for(int i = n - 1; i > 0; i--) {
            dat[i] = op(dat[2 * i], dat[2 * i + 1]);
        }
    }

    void update(int k, const S &a) {
        k += n;
        dat[k] = a;
        while(k >>= 1) {
            dat[k] = op(dat[k * 2], dat[k * 2 + 1]);
        }
    }

    S at(int a) const { return query(a, a + 1); }

    // query for [a,b)
    S query(int a, int b) const {
        S vl = e, vr = e;
        a += n, b += n;
        for(; a < b; a >>= 1, b >>= 1) {
            if(a & 1)
                vl = op(vl, dat[a++]);
            if(b & 1)
                vr = op(dat[--b], vr);
        }
        return op(vl, vr);
    }

    int max_right(int l, function<bool(S)> f) const {
        if(l == org_size)
            return org_size;
        l += n;
        S cum = e;
        do {
            while(l % 2 == 0)
                l >>= 1;
            if(!f(op(cum, dat[l]))) {
                while(l < n) {
                    l = 2 * l;
                    if(f(op(cum, dat[l]))) {
                        cum = op(cum, dat[l]);
                        l++;
                    }
                }
                return l - n;
            }
            cum = op(cum, dat[l]);
            l++;
        } while((l & -l) != l);
        return org_size;
    }

    // !!未verify!!
    int min_left(int r, function<bool(S)> f) const {
        if(r == 0)
            return 0;
        r += n;
        S cum = e;
        do {
            r--;
            while(r > 1 && (r % 2))
                r >>= 1;
            if(!f(op(dat[r], cum))) {
                while(r < n) {
                    r = 2 * r + 1;
                    if(f(op(dat[r], cum))) {
                        cum = op(dat[r], cum);
                        r--;
                    }
                }
                return r + 1 - n;
            }
            cum = op(dat[r], cum);
        } while((r & (-r) != r));
        return 0;
    }

    SegmentTree(int _n, const Op op, const S &e) : op(op), e(e) {
        org_size = _n;
        n = 1;
        while(n < org_size)
            n *= 2;
        dat.assign(2 * n, e);
    }

    SegmentTree(const vector<S> &v, const Op op, const S &e) : op(op), e(e) {
        org_size = v.size();
        n = 1;
        while(n < org_size)
            n *= 2;
        dat.assign(2 * n, e);
        for(int i = 0; i < org_size; i++)
            set(i, v[i]);
        build();
    }
};

// struct S {};
// S op(const S &a, const S &b){};