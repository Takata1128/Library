---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/SuffixArray.cc\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// Suffix Array\n// build:O(N*(logN)^2)\nclass SuffixArray\
    \ {\n  private:\n    const int n;\n    vector<int> sa, rank, tmp;\n\n  public:\n\
    \    const string s;\n    SuffixArray(string _s) : n(_s.size()), s(_s) {\n   \
    \     sa.resize(n);\n        rank.resize(n);\n        tmp.resize(n);\n       \
    \ build();\n    }\n\n    void build() {\n        for(int i = 0; i < n; i++)\n\
    \            rank[i] = s[i];\n        iota(sa.begin(), sa.end(), 0);\n       \
    \ for(int k = 1; k < n; k *= 2) {\n            auto cmp = [&](int i, int j) {\n\
    \                if(rank[i] != rank[j])\n                    return rank[i] <\
    \ rank[j];\n                int ri = i + k < n ? rank[i + k] : -1;\n         \
    \       int rj = j + k < n ? rank[j + k] : -1;\n                return ri < rj;\n\
    \            };\n            sort(sa.begin(), sa.end(), cmp);\n            tmp[sa[0]]\
    \ = 0;\n            for(int i = 1; i < n; i++) {\n                tmp[sa[i]] =\
    \ tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n            }\n         \
    \   swap(tmp, rank);\n        }\n    }\n\n    int operator[](int k) const { return\
    \ sa[k]; }\n    size_t size() const { return n; }\n\n    void print() {\n    \
    \    for(int i = 0; i < n; i++) {\n            cout << i << \": \" << s.substr(sa[i])\
    \ << endl;\n        }\n    }\n};\n\n// LongestCommonPrefix\nclass LongestCommonPrefix\
    \ {\n  private:\n    const int n;\n    const SuffixArray &sa;\n    vector<int>\
    \ lcp, rank;\n\n  public:\n    LongestCommonPrefix(const SuffixArray &_sa) : n(_sa.size()),\
    \ sa(_sa) {\n        lcp.resize(n);\n        rank.resize(n);\n        build();\n\
    \    }\n\n    void build() {\n        for(int i = 0; i < sa.size(); i++) {\n \
    \           rank[sa[i]] = i;\n        }\n        for(int i = 0, h = 0; i < sa.size();\
    \ i++) {\n            if(rank[i] + 1 < sa.size()) {\n                for(int j\
    \ = sa[rank[i] + 1];\n                    max(i, j) + h < sa.size() && sa.s[i\
    \ + h] == sa.s[j + h];\n                    h++)\n                    ;\n    \
    \            lcp[rank[i] + 1] = h;\n                if(h > 0)\n              \
    \      h--;\n            }\n        }\n    }\n    int operator[](int k) const\
    \ { return lcp[k]; }\n    size_t size() const { return n; }\n    void print()\
    \ {\n        for(int i = 0; i < size(); i++) {\n            cout << i << \": \"\
    \ << lcp[i] << \" \" << sa.s.substr(sa[i]) << endl;\n        }\n    }\n};\n\n\
    int main() {\n    string s;\n    cin >> s;\n    int n = s.size();\n    SuffixArray\
    \ sa(s);\n    LongestCommonPrefix lcp(sa);\n    int res = 0;\n    for(int i =\
    \ 0; i < n; i++) {\n        res += n - sa[i] - lcp[i];\n    }\n    cout << res\
    \ << endl;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// Suffix Array\n// build:O(N*(logN)^2)\n\
    class SuffixArray {\n  private:\n    const int n;\n    vector<int> sa, rank, tmp;\n\
    \n  public:\n    const string s;\n    SuffixArray(string _s) : n(_s.size()), s(_s)\
    \ {\n        sa.resize(n);\n        rank.resize(n);\n        tmp.resize(n);\n\
    \        build();\n    }\n\n    void build() {\n        for(int i = 0; i < n;\
    \ i++)\n            rank[i] = s[i];\n        iota(sa.begin(), sa.end(), 0);\n\
    \        for(int k = 1; k < n; k *= 2) {\n            auto cmp = [&](int i, int\
    \ j) {\n                if(rank[i] != rank[j])\n                    return rank[i]\
    \ < rank[j];\n                int ri = i + k < n ? rank[i + k] : -1;\n       \
    \         int rj = j + k < n ? rank[j + k] : -1;\n                return ri <\
    \ rj;\n            };\n            sort(sa.begin(), sa.end(), cmp);\n        \
    \    tmp[sa[0]] = 0;\n            for(int i = 1; i < n; i++) {\n             \
    \   tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n         \
    \   }\n            swap(tmp, rank);\n        }\n    }\n\n    int operator[](int\
    \ k) const { return sa[k]; }\n    size_t size() const { return n; }\n\n    void\
    \ print() {\n        for(int i = 0; i < n; i++) {\n            cout << i << \"\
    : \" << s.substr(sa[i]) << endl;\n        }\n    }\n};\n\n// LongestCommonPrefix\n\
    class LongestCommonPrefix {\n  private:\n    const int n;\n    const SuffixArray\
    \ &sa;\n    vector<int> lcp, rank;\n\n  public:\n    LongestCommonPrefix(const\
    \ SuffixArray &_sa) : n(_sa.size()), sa(_sa) {\n        lcp.resize(n);\n     \
    \   rank.resize(n);\n        build();\n    }\n\n    void build() {\n        for(int\
    \ i = 0; i < sa.size(); i++) {\n            rank[sa[i]] = i;\n        }\n    \
    \    for(int i = 0, h = 0; i < sa.size(); i++) {\n            if(rank[i] + 1 <\
    \ sa.size()) {\n                for(int j = sa[rank[i] + 1];\n               \
    \     max(i, j) + h < sa.size() && sa.s[i + h] == sa.s[j + h];\n             \
    \       h++)\n                    ;\n                lcp[rank[i] + 1] = h;\n \
    \               if(h > 0)\n                    h--;\n            }\n        }\n\
    \    }\n    int operator[](int k) const { return lcp[k]; }\n    size_t size()\
    \ const { return n; }\n    void print() {\n        for(int i = 0; i < size();\
    \ i++) {\n            cout << i << \": \" << lcp[i] << \" \" << sa.s.substr(sa[i])\
    \ << endl;\n        }\n    }\n};\n\nint main() {\n    string s;\n    cin >> s;\n\
    \    int n = s.size();\n    SuffixArray sa(s);\n    LongestCommonPrefix lcp(sa);\n\
    \    int res = 0;\n    for(int i = 0; i < n; i++) {\n        res += n - sa[i]\
    \ - lcp[i];\n    }\n    cout << res << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: String/SuffixArray.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/SuffixArray.cc
layout: document
redirect_from:
- /library/String/SuffixArray.cc
- /library/String/SuffixArray.cc.html
title: String/SuffixArray.cc
---
