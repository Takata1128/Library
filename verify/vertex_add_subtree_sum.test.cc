#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
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
        INT(p);
        g.unite(i + 1, p);
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
            INT(u, x);
            hld.apply_path(u, u, [&](int l, int r) {
                st.update(l, st.at(l) + x);
            });
        } else {
            INT(u);
            ll res = hld.prod_subtree<S>(
                u, [&](int l, int r) {
                    return st.query(l, r + 1);
                });
            write(res);
        }
    }
}