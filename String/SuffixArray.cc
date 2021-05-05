#include <bits/stdc++.h>
using namespace std;

// Suffix Array
// build:O(N*(logN)^2)
class SuffixArray {
  private:
    const int n;
    vector<int> sa, rank, tmp;

  public:
    const string s;
    SuffixArray(string _s) : n(_s.size()), s(_s) {
        sa.resize(n);
        rank.resize(n);
        tmp.resize(n);
        build();
    }

    void build() {
        for(int i = 0; i < n; i++)
            rank[i] = s[i];
        iota(sa.begin(), sa.end(), 0);
        for(int k = 1; k < n; k *= 2) {
            auto cmp = [&](int i, int j) {
                if(rank[i] != rank[j])
                    return rank[i] < rank[j];
                int ri = i + k < n ? rank[i + k] : -1;
                int rj = j + k < n ? rank[j + k] : -1;
                return ri < rj;
            };
            sort(sa.begin(), sa.end(), cmp);
            tmp[sa[0]] = 0;
            for(int i = 1; i < n; i++) {
                tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            }
            swap(tmp, rank);
        }
    }

    int operator[](int k) const { return sa[k]; }
    size_t size() const { return n; }

    void print() {
        for(int i = 0; i < n; i++) {
            cout << i << ": " << s.substr(sa[i]) << endl;
        }
    }
};

// LongestCommonPrefix
class LongestCommonPrefix {
  private:
    const int n;
    const SuffixArray &sa;
    vector<int> lcp, rank;

  public:
    LongestCommonPrefix(const SuffixArray &_sa) : n(_sa.size()), sa(_sa) {
        lcp.resize(n);
        rank.resize(n);
        build();
    }

    void build() {
        for(int i = 0; i < sa.size(); i++) {
            rank[sa[i]] = i;
        }
        for(int i = 0, h = 0; i < sa.size(); i++) {
            if(rank[i] + 1 < sa.size()) {
                for(int j = sa[rank[i] + 1];
                    max(i, j) + h < sa.size() && sa.s[i + h] == sa.s[j + h];
                    h++)
                    ;
                lcp[rank[i] + 1] = h;
                if(h > 0)
                    h--;
            }
        }
    }
    int operator[](int k) const { return lcp[k]; }
    size_t size() const { return n; }
    void print() {
        for(int i = 0; i < size(); i++) {
            cout << i << ": " << lcp[i] << " " << sa.s.substr(sa[i]) << endl;
        }
    }
};

int main() {
    string s;
    cin >> s;
    int n = s.size();
    SuffixArray sa(s);
    LongestCommonPrefix lcp(sa);
    int res = 0;
    for(int i = 0; i < n; i++) {
        res += n - sa[i] - lcp[i];
    }
    cout << res << endl;
}