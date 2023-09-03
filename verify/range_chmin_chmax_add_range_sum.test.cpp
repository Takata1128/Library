#define PROBLEM \
    "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "./template.cc"
#include "../DataStructure/SegmentTreeBeats.cc"

int main() {
    INT(n, q);
    VEC(ll, a, n);
    SegmentTreeBeats<ll> beats(a);
    rep(i, q) {
        INT(t);
        if(t == 0) {
            LL(l, r, x);
            beats.update_min(l, r, x);
        } else if(t == 1) {
            LL(l, r, x);
            beats.update_max(l, r, x);
        } else if(t == 2) {
            LL(l, r, x);
            beats.add_val(l, r, x);
        } else {
            INT(l, r);
            write(beats.query_sum(l, r));
        }
    }
}