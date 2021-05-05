#include <bits/stdc++.h>
using namespace std;

/*
    トポロジカルソート　O(V+E)
    G: 有向グラフ
    in: 頂点の入次数　
*/
vector<int> topological_sort(const vector<vector<int>> &G, vector<int> in) {
    vector<int> ret;
    stack<int> st;
    for(int i = 0; i < in.size(); i++)
        if(in[i] == 0)
            st.push(i);
    while(st.size()) {
        int v = st.top();
        st.pop();
        ret.push_back(v);
        for(auto &nv : G[v]) {
            in[nv]--;
            if(in[nv] == 0)
                st.push(nv);
        }
    }
    return ret;
}