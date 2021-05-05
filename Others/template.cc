#pragma once
#pragma region Macros
#include <bits/stdc++.h>
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define ALL(v) (v).begin(), (v).end()
#define LLA(v) (v).rbegin(), (v).rend()
#define SZ(v) (int)(v).size()
#define INT(...)                                                               \
    int __VA_ARGS__;                                                           \
    read(__VA_ARGS__)
#define LL(...)                                                                \
    ll __VA_ARGS__;                                                            \
    read(__VA_ARGS__)
#define DOUBLE(...)                                                            \
    double __VA_ARGS__;                                                        \
    read(__VA_ARGS__)
#define CHAR(...)                                                              \
    char __VA_ARGS__;                                                          \
    read(__VA_ARGS__)
#define STRING(...)                                                            \
    string __VA_ARGS__;                                                        \
    read(__VA_ARGS__)
#define VEC(type, name, size)                                                  \
    vector<type> name(size);                                                   \
    read(name)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
template <typename T> struct edge {
    int from, to;
    T cost;
    edge(int f, int t, T c) : from(f), to(t), cost(c) {}
};
template <typename T> using WGraph = vector<vector<edge<T>>>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;
const char newl = '\n';
template <class T> inline vector<T> make_vec(size_t a, T val) {
    return vector<T>(a, val);
}
template <class... Ts> inline auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));
}
void read() {}
template <class T> inline void read(T &a) { cin >> a; }
template <class T, class S> inline void read(pair<T, S> &p) {
    read(p.first), read(p.second);
}
template <class T> inline void read(vector<T> &v) {
    for(auto &a : v)
        read(a);
}
template <class Head, class... Tail>
inline void read(Head &head, Tail &...tail) {
    read(head), read(tail...);
}
template <class T> void write(const T &a) { cout << a << '\n'; }
template <class T> void write(const vector<T> &a) {
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << (i + 1 == a.size() ? '\n' : ' ');
}
template <class Head, class... Tail>
void write(const Head &head, const Tail &...tail) {
    cout << head << ' ';
    write(tail...);
}
template <class T> void writel(const T &a) { cout << a << '\n'; }
template <class T> void writel(const vector<T> &a) {
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << '\n';
}
template <class Head, class... Tail>
void writel(const Head &head, const Tail &...tail) {
    cout << head << '\n';
    write(tail...);
}
template <class T> auto sum(const T &a) { return accumulate(ALL(a), T(0)); }
template <class T> auto min(const T &a) { return *min_element(ALL(a)); }
template <class T> auto max(const T &a) { return *max_element(ALL(a)); }
template <class T> inline void chmax(T &a, T b) { (a < b ? a = b : a); }
template <class T> inline void chmin(T &a, T b) { (a > b ? a = b : a); }
struct IO {
    IO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(10);
    }
} io;
#pragma endregion
