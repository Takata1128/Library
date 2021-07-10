---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/practice2/submissions/17017654
  bundledCode: "#line 1 \"Graph/Dinic.cc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Dinic algorithm\n// max_flow:O(|E||V|^2) \uFF08\u5B9F\u969B\u306F\
    \u3082\u3063\u3068\u901F\u3044\uFF1F\uFF09\n// https://atcoder.jp/contests/practice2/submissions/17017654\n\
    template <class Cap> class Dinic {\n  private:\n    int n;\n    struct _edge {\n\
    \        int to;\n        Cap cap;\n        int rev;\n    };\n    vector<vector<_edge>>\
    \ G;\n    vector<int> level, iter;\n    vector<pair<int, int>> pos;\n\n  public:\n\
    \    Dinic(int _n) : n(_n) {\n        G.resize(n);\n        level.resize(n);\n\
    \        iter.resize(n);\n    }\n\n    struct edge {\n        int from, to;\n\
    \        Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n        assert(0\
    \ <= i && i < pos.size());\n        auto _e = G[pos[i].first][pos[i].second];\n\
    \        auto _re = G[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to,\
    \ _e.cap + _re.cap, _re.cap};\n    }\n\n    vector<edge> get_all_edge() {\n  \
    \      vector<edge> ret;\n        for(int i = 0; i < pos.size(); i++) {\n    \
    \        ret.push_back(get_edge(i));\n        }\n        return ret;\n    }\n\n\
    \    void add_edge(int from, int to, Cap cap) {\n        assert(0 <= from && from\
    \ < n);\n        assert(0 <= to && to < n);\n        assert(0 <= cap);\n     \
    \   pos.push_back({from, int(G[from].size())});\n        G[from].push_back(_edge{to,\
    \ cap, (int)G[to].size()});\n        G[to].push_back(_edge{from, 0, (int)G[from].size()\
    \ - 1});\n    }\n\n    void unite(int from, int to, Cap cap) {\n        add_edge(from,\
    \ to, cap);\n        add_edge(to, from, cap);\n    }\n\n    void bfs(int s) {\n\
    \        fill(level.begin(), level.end(), -1);\n        queue<int> que;\n    \
    \    level[s] = 0;\n        que.push(s);\n        while(!que.empty()) {\n    \
    \        int v = que.front();\n            que.pop();\n            for(_edge &e\
    \ : G[v]) {\n                if(e.cap > 0 && level[e.to] < 0) {\n            \
    \        level[e.to] = level[v] + 1;\n                    que.push(e.to);\n  \
    \              }\n            }\n        }\n    }\n\n    Cap dfs(int v, int t,\
    \ Cap f) {\n        if(v == t)\n            return f;\n        for(int &i = iter[v];\
    \ i < G[v].size(); i++) {\n            _edge &e = G[v][i];\n            if(e.cap\
    \ > 0 && level[v] < level[e.to]) {\n                int d = dfs(e.to, t, min(f,\
    \ e.cap));\n                if(d > 0) {\n                    e.cap -= d;\n   \
    \                 G[e.to][e.rev].cap += d;\n                    return d;\n  \
    \              }\n            }\n        }\n        return 0;\n    }\n\n    Cap\
    \ max_flow(int s, int t) {\n        return max_flow(s, t, numeric_limits<Cap>::max());\n\
    \    }\n\n    Cap max_flow(int s, int t, Cap limit) {\n        assert(0 <= s &&\
    \ s < n);\n        assert(0 <= t && t < n);\n        assert(s != t);\n       \
    \ Cap flow = 0;\n        while(flow < limit) {\n            bfs(s);\n        \
    \    if(level[t] < 0)\n                return flow;\n            fill(iter.begin(),\
    \ iter.end(), 0);\n            Cap f;\n            while((f = dfs(s, t, limit\
    \ - flow)) > 0) {\n                flow += f;\n            }\n        }\n    \
    \    return flow;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// Dinic algorithm\n//\
    \ max_flow:O(|E||V|^2) \uFF08\u5B9F\u969B\u306F\u3082\u3063\u3068\u901F\u3044\uFF1F\
    \uFF09\n// https://atcoder.jp/contests/practice2/submissions/17017654\ntemplate\
    \ <class Cap> class Dinic {\n  private:\n    int n;\n    struct _edge {\n    \
    \    int to;\n        Cap cap;\n        int rev;\n    };\n    vector<vector<_edge>>\
    \ G;\n    vector<int> level, iter;\n    vector<pair<int, int>> pos;\n\n  public:\n\
    \    Dinic(int _n) : n(_n) {\n        G.resize(n);\n        level.resize(n);\n\
    \        iter.resize(n);\n    }\n\n    struct edge {\n        int from, to;\n\
    \        Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n        assert(0\
    \ <= i && i < pos.size());\n        auto _e = G[pos[i].first][pos[i].second];\n\
    \        auto _re = G[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to,\
    \ _e.cap + _re.cap, _re.cap};\n    }\n\n    vector<edge> get_all_edge() {\n  \
    \      vector<edge> ret;\n        for(int i = 0; i < pos.size(); i++) {\n    \
    \        ret.push_back(get_edge(i));\n        }\n        return ret;\n    }\n\n\
    \    void add_edge(int from, int to, Cap cap) {\n        assert(0 <= from && from\
    \ < n);\n        assert(0 <= to && to < n);\n        assert(0 <= cap);\n     \
    \   pos.push_back({from, int(G[from].size())});\n        G[from].push_back(_edge{to,\
    \ cap, (int)G[to].size()});\n        G[to].push_back(_edge{from, 0, (int)G[from].size()\
    \ - 1});\n    }\n\n    void unite(int from, int to, Cap cap) {\n        add_edge(from,\
    \ to, cap);\n        add_edge(to, from, cap);\n    }\n\n    void bfs(int s) {\n\
    \        fill(level.begin(), level.end(), -1);\n        queue<int> que;\n    \
    \    level[s] = 0;\n        que.push(s);\n        while(!que.empty()) {\n    \
    \        int v = que.front();\n            que.pop();\n            for(_edge &e\
    \ : G[v]) {\n                if(e.cap > 0 && level[e.to] < 0) {\n            \
    \        level[e.to] = level[v] + 1;\n                    que.push(e.to);\n  \
    \              }\n            }\n        }\n    }\n\n    Cap dfs(int v, int t,\
    \ Cap f) {\n        if(v == t)\n            return f;\n        for(int &i = iter[v];\
    \ i < G[v].size(); i++) {\n            _edge &e = G[v][i];\n            if(e.cap\
    \ > 0 && level[v] < level[e.to]) {\n                int d = dfs(e.to, t, min(f,\
    \ e.cap));\n                if(d > 0) {\n                    e.cap -= d;\n   \
    \                 G[e.to][e.rev].cap += d;\n                    return d;\n  \
    \              }\n            }\n        }\n        return 0;\n    }\n\n    Cap\
    \ max_flow(int s, int t) {\n        return max_flow(s, t, numeric_limits<Cap>::max());\n\
    \    }\n\n    Cap max_flow(int s, int t, Cap limit) {\n        assert(0 <= s &&\
    \ s < n);\n        assert(0 <= t && t < n);\n        assert(s != t);\n       \
    \ Cap flow = 0;\n        while(flow < limit) {\n            bfs(s);\n        \
    \    if(level[t] < 0)\n                return flow;\n            fill(iter.begin(),\
    \ iter.end(), 0);\n            Cap f;\n            while((f = dfs(s, t, limit\
    \ - flow)) > 0) {\n                flow += f;\n            }\n        }\n    \
    \    return flow;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Dinic.cc
  requiredBy: []
  timestamp: '2021-07-10 17:10:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Dinic.cc
layout: document
redirect_from:
- /library/Graph/Dinic.cc
- /library/Graph/Dinic.cc.html
title: Graph/Dinic.cc
---
