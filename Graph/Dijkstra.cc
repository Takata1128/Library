#include <bits/stdc++.h>
using namespace std;

template <typename T> struct edge {
    int to;
    T cost;
    edge(int t, T c) : to(t), cost(c) {}
};

template <typename T> using Graph = vector<vector<edge<T>>>;

template <typename T, T INF> void dijkstra(int s, vector<T> &d, Graph<T> &G) {
    priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>>
        que;
    fill(All(d), INF);
    d[s] = 0;
    que.push(make_pair(0, s));
    while(!que.empty()) {
        pair<int, T> p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first)
            continue;
        for(auto e : G[v]) {
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(make_pair(d[e.to], e.to));
            }
        }
    }
}