#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "./template.cc"
#include "../DataStructure/UnionFind.cc"

int main() {
    INT(n, q);
    UnionFind uf(n);
    rep(i, q) {
        INT(t, u, v);
        if(t == 1) {
            write(uf.same(u, v) ? 1 : 0);
        } else {
            uf.unite(u, v);
        }
    }
    return 0;
}
