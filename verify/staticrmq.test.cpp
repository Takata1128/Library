#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../DataStructure/SegmentTree.cc"
#include "../Others/template.cc"

using S = int;
S op(S a, S b) { return min(a, b); };
S e() { return INF; }

int main() {
    INT(n, q);
    VEC(int, a, n);
    SegmentTree<S> st(a, op, e());
    rep(i, q) {
        INT(l, r);
        write(st.query(l, r));
    }
}