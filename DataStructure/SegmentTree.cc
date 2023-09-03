#include <bits/stdc++.h>
using namespace std;
template <typename S> class SegmentTree {
  private:
    using Op = function<S(S, S)>;

    int n;
    int org_size;
    const Op op;
    const function<S()> e;
    vector<S> node;

  public:
    SegmentTree(int _n, const Op &op, const function<S()> &e) : op(op), e(e) {
        org_size = _n;
        n = 1;
        while(n < org_size)
            n *= 2;
        node.assign(2 * n, e());
    }

    SegmentTree(const vector<S> &v, const Op &op, const function<S()> &e) : op(op), e(e) {
        org_size = v.size();
        n = 1;
        while(n < org_size)
            n *= 2;
        node.assign(2 * n, e());
        for(int i = 0; i < org_size; i++)
            set(i, v[i]);
        build();
    }
    void set(int k, S a) { node[k + n] = a; }

    void build() {
        for(int i = n - 1; i > 0; i--) {
            node[i] = op(node[2 * i], node[2 * i + 1]);
        }
    }

    void update(int k, const S &a) {
        k += n;
        node[k] = a;
        while(k >>= 1) {
            node[k] = op(node[k * 2], node[k * 2 + 1]);
        }
    }

    S at(int a) const { return query(a, a + 1); }

    // query for [a,b)
    S query(int a, int b) const {
        S vl = e(), vr = e();
        a += n, b += n;
        for(; a < b; a >>= 1, b >>= 1) {
            if(a & 1)
                vl = op(vl, node[a++]);
            if(b & 1)
                vr = op(node[--b], vr);
        }
        return op(vl, vr);
    }

    int max_right(int l, function<bool(S)> f) const {
        if(l == org_size)
            return org_size;
        l += n;
        S cum = e();
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
        S cum = e();
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
};

// using S = int;
// S op(const S &a, const S &b) {
//     return a + b;
// };
// S e() { return 0; };