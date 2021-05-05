#include <vector>
using namespace std;
using ll = long long;

/***ベルマンフォード法***/
const int INF = 1 << 30;
bool bellman_ford(int s, vector<vector<pair<int, ll>>> const &g,
                  vector<ll> &dist) {
    int n = g.size();
    vector<ll> dist(n, INF);
    bool negative_cycle = false;
    dist[s] = 0;
    for(int i = 0; i < n; i++) {
        for(int v = 0; v < n; v++) {
            for(auto e : g[v]) {
                if(dist[v] != INF && dist[e.first] > dist[v] + e.second) {
                    dist[e.first] = dist[v] + e.second;
                    if(i == n - 1) {
                        dist[e.first] = -INF;
                        negative_cycle = true;
                    }
                }
            }
        }
    }
    return negative_cycle;
}