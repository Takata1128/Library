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
  bundledCode: "#line 1 \"String/RollingHash.cc\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\n/* \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\
    \u3000\u69CB\u7BC9O(N)\u3000\u30CF\u30C3\u30B7\u30E5\u53D6\u5F97O(1) */\r\n\r\n\
    class Rolling_hash {\r\n  private:\r\n    int n;\r\n    static const int MS =\
    \ 2;\r\n    const vector<long long> mod = {999999937LL, 1000000007LL};\r\n   \
    \ const long long base = 9973;\r\n    vector<long long> hs[MS], pw[MS];\r\n  \
    \  Rolling_hash(){};\r\n    Rolling_hash(const string &s) {\r\n        n = s.size();\r\
    \n        for(int i = 0; i < MS; i++) {\r\n            hs[i].assign(n + 1, 0);\r\
    \n            pw[i].assign(n + 1, 0);\r\n            hs[i][0] = 0;\r\n       \
    \     pw[i][0] = 1;\r\n            for(int j = 0; j < n; j++) {\r\n          \
    \      pw[i][j + 1] = pw[i][j] * base % mod[i];\r\n                hs[i][j + 1]\
    \ = (hs[i][j] * base + s[j]) % mod[i];\r\n            }\r\n        }\r\n    }\r\
    \n\r\n    long long get_hash(int l, int r, int i) {\r\n        return ((hs[i][r]\
    \ - hs[i][l] * pw[i][r - l]) % mod[i] + mod[i]) %\r\n               mod[i];\r\n\
    \    }\r\n\r\n  public:\r\n    /* get hash [l,r) */\r\n    pair<long long, long\
    \ long> get(int l, int r) {\r\n        return make_pair(get_hash(l, r, 0), get_hash(l,\
    \ r, 1));\r\n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n/* \u30ED\u30FC\u30EA\
    \u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u3000\u69CB\u7BC9O(N)\u3000\u30CF\u30C3\u30B7\
    \u30E5\u53D6\u5F97O(1) */\r\n\r\nclass Rolling_hash {\r\n  private:\r\n    int\
    \ n;\r\n    static const int MS = 2;\r\n    const vector<long long> mod = {999999937LL,\
    \ 1000000007LL};\r\n    const long long base = 9973;\r\n    vector<long long>\
    \ hs[MS], pw[MS];\r\n    Rolling_hash(){};\r\n    Rolling_hash(const string &s)\
    \ {\r\n        n = s.size();\r\n        for(int i = 0; i < MS; i++) {\r\n    \
    \        hs[i].assign(n + 1, 0);\r\n            pw[i].assign(n + 1, 0);\r\n  \
    \          hs[i][0] = 0;\r\n            pw[i][0] = 1;\r\n            for(int j\
    \ = 0; j < n; j++) {\r\n                pw[i][j + 1] = pw[i][j] * base % mod[i];\r\
    \n                hs[i][j + 1] = (hs[i][j] * base + s[j]) % mod[i];\r\n      \
    \      }\r\n        }\r\n    }\r\n\r\n    long long get_hash(int l, int r, int\
    \ i) {\r\n        return ((hs[i][r] - hs[i][l] * pw[i][r - l]) % mod[i] + mod[i])\
    \ %\r\n               mod[i];\r\n    }\r\n\r\n  public:\r\n    /* get hash [l,r)\
    \ */\r\n    pair<long long, long long> get(int l, int r) {\r\n        return make_pair(get_hash(l,\
    \ r, 0), get_hash(l, r, 1));\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: String/RollingHash.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/RollingHash.cc
layout: document
redirect_from:
- /library/String/RollingHash.cc
- /library/String/RollingHash.cc.html
title: String/RollingHash.cc
---
