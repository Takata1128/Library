#include <bits/stdc++.h>
using namespace std;

/* ローリングハッシュ　構築O(N)　ハッシュ取得O(1) */

class Rolling_hash {
  private:
    int n;
    static const int MS = 2;
    const vector<long long> mod = {999999937LL, 1000000007LL};
    const long long base = 9973;
    vector<long long> hs[MS], pw[MS];
    Rolling_hash(){};
    Rolling_hash(const string &s) {
        n = s.size();
        for(int i = 0; i < MS; i++) {
            hs[i].assign(n + 1, 0);
            pw[i].assign(n + 1, 0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            for(int j = 0; j < n; j++) {
                pw[i][j + 1] = pw[i][j] * base % mod[i];
                hs[i][j + 1] = (hs[i][j] * base + s[j]) % mod[i];
            }
        }
    }

    long long get_hash(int l, int r, int i) {
        return ((hs[i][r] - hs[i][l] * pw[i][r - l]) % mod[i] + mod[i]) %
               mod[i];
    }

  public:
    /* get hash [l,r) */
    pair<long long, long long> get(int l, int r) {
        return make_pair(get_hash(l, r, 0), get_hash(l, r, 1));
    }
};