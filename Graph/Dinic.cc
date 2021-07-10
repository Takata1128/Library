#include <bits/stdc++.h>
using namespace std;

// Dinic algorithm
// max_flow:O(|E||V|^2) （実際はもっと速い？）
// https://atcoder.jp/contests/practice2/submissions/17017654
template <class Cap> class Dinic {
  private:
    int n;
    struct _edge {
        int to;
        Cap cap;
        int rev;
    };
    vector<vector<_edge>> G;
    vector<int> level, iter;
    vector<pair<int, int>> pos;

  public:
    Dinic(int _n) : n(_n) {
        G.resize(n);
        level.resize(n);
        iter.resize(n);
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        assert(0 <= i && i < pos.size());
        auto _e = G[pos[i].first][pos[i].second];
        auto _re = G[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }

    vector<edge> get_all_edge() {
        vector<edge> ret;
        for(int i = 0; i < pos.size(); i++) {
            ret.push_back(get_edge(i));
        }
        return ret;
    }

    void add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        assert(0 <= cap);
        pos.push_back({from, int(G[from].size())});
        G[from].push_back(_edge{to, cap, (int)G[to].size()});
        G[to].push_back(_edge{from, 0, (int)G[from].size() - 1});
    }

    void unite(int from, int to, Cap cap) {
        add_edge(from, to, cap);
        add_edge(to, from, cap);
    }

    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()) {
            int v = que.front();
            que.pop();
            for(_edge &e : G[v]) {
                if(e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    Cap dfs(int v, int t, Cap f) {
        if(v == t)
            return f;
        for(int &i = iter[v]; i < G[v].size(); i++) {
            _edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if(d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    Cap max_flow(int s, int t) {
        return max_flow(s, t, numeric_limits<Cap>::max());
    }

    Cap max_flow(int s, int t, Cap limit) {
        assert(0 <= s && s < n);
        assert(0 <= t && t < n);
        assert(s != t);
        Cap flow = 0;
        while(flow < limit) {
            bfs(s);
            if(level[t] < 0)
                return flow;
            fill(iter.begin(), iter.end(), 0);
            Cap f;
            while((f = dfs(s, t, limit - flow)) > 0) {
                flow += f;
            }
        }
        return flow;
    }
};