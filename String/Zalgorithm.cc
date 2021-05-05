#include <bits/stdc++.h>
using namespace std;

// S と　S[i:]の最長共通接頭辞の長さ
vector<int> z_algo(string S) {
    vector<int> ret(S.size());
    ret[0] = S.size();
    int i = 1, j = 0;
    while(i < S.size()) {
        while(i + j < S.size() && S[j] == S[i + j])
            ++j;
        ret[i] = j;
        if(j == 0) {
            ++i;
            continue;
        }
        int k = 1;
        while(i + k < S.size() && k + ret[k] < j)
            ret[i + k] = ret[k], k++;
        i += k;
        j -= k;
    }
    return ret;
}