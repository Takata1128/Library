#include <bits/stdc++.h>
using namespace std;

// UnionFind
struct UnionFind {
    vector<int> par;
    vector<int> siz;

    UnionFind(int N) : par(N), siz(N, 1) {
        for(int i = 0; i < N; i++)
            par[i] = i;
    }
    int root(int x) {
        if(par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if(rx == ry)
            return;
        if(siz[rx] < siz[ry])
            swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
    }
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    int size(int x) { return siz[root(x)]; }
};

//　重み付きUnionFind
template <typename T> struct WeightedUnionFind {
    vector<int> par;
    vector<int> siz;
    vector<T> diff_weight;

    WeightedUnionFind(int N) : par(N), siz(N, 1), diff_weight(N, T(0)) {
        for(int i = 0; i < N; i++) {
            par[i] = i;
        }
    }

    T weight(int x) {
        root(x);
        return diff_weight[x];
    }

    T diff(int x, int y) { return weight(y) - weight(x); }

    int root(int x) {
        if(par[x] == x)
            return x;
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }
    void unite(int x, int y, T w) {
        w += weight(x), w -= weight(y);
        int rx = root(x);
        int ry = root(y);
        if(rx == ry)
            return;
        if(siz[rx] < siz[ry])
            swap(rx, ry), w = -w;
        siz[rx] += siz[ry];
        par[ry] = rx;
        diff_weight[ry] = w;
    }
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    int size(int x) { return siz[root(x)]; }
};