#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T> struct edge {
    int to;
    T cost;
};

using Graph = vector<vector<edge<ll>>>;

template <typename T> pair<T, int> dfs(int v, int p, const Graph &G) {
    auto ret = MP((T)0, v);
    for(auto e : G[v]) {
        if(e.to == p)
            continue;
        auto next = dfs<T>(e.to, v, G);
        next.first += e.cost;
        ret = max(ret, next);
    }
    return ret;
}

template <typename T> T tree_diameter(const vector<vector<edge<T>>> &G) {
    auto s = dfs<T>(0, -1, G);
    auto t = dfs<T>(s.second, -1, G);
    return t.first;
}
