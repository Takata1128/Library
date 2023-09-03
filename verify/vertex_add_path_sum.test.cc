#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "./template.cc"
#include "../DataStructure/SegmentTree.cc"
#include "../Graph/Graph.cc"
#include "../Graph/HLDecomposition.cc"

using S = ll;
S op(const S &a, const S &b) { return a + b; };
S e() { return 0; }

int main() {
    INT(n, Q);
    VEC(ll, a, n);
    Graph g(n);
    rep(i, n - 1) {
        INT(u, v);
        g.unite(u, v);
    }
    HeavyLightDecomposition hld(g);
    SegmentTree<S> st(n, op, e);
    rep(i, n) {
        st.set(hld.index(i), a[i]);
    }
    st.build();
    rep(i, Q) {
        INT(q);
        if(q == 0) {
            INT(p, x);
            hld.apply_path(
                p, p, [&](int l, int r) {
                    st.update(l, st.at(l) + x);
                });
        } else {
            INT(u, v);
            ll res = hld.prod_path(
                u, v, e(), op, [&](int l, int r) {
                    return st.query(l, r + 1);
                });
            write(res);
        }
    }
}