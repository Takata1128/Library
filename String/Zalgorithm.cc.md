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
  bundledCode: "#line 1 \"String/Zalgorithm.cc\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\n// S \u3068\u3000S[i:]\u306E\u6700\u9577\u5171\u901A\u63A5\
    \u982D\u8F9E\u306E\u9577\u3055\r\nvector<int> z_algo(string S) {\r\n    vector<int>\
    \ ret(S.size());\r\n    ret[0] = S.size();\r\n    int i = 1, j = 0;\r\n    while(i\
    \ < S.size()) {\r\n        while(i + j < S.size() && S[j] == S[i + j])\r\n   \
    \         ++j;\r\n        ret[i] = j;\r\n        if(j == 0) {\r\n            ++i;\r\
    \n            continue;\r\n        }\r\n        int k = 1;\r\n        while(i\
    \ + k < S.size() && k + ret[k] < j)\r\n            ret[i + k] = ret[k], k++;\r\
    \n        i += k;\r\n        j -= k;\r\n    }\r\n    return ret;\r\n}\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n// S \u3068\u3000\
    S[i:]\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\r\nvector<int>\
    \ z_algo(string S) {\r\n    vector<int> ret(S.size());\r\n    ret[0] = S.size();\r\
    \n    int i = 1, j = 0;\r\n    while(i < S.size()) {\r\n        while(i + j <\
    \ S.size() && S[j] == S[i + j])\r\n            ++j;\r\n        ret[i] = j;\r\n\
    \        if(j == 0) {\r\n            ++i;\r\n            continue;\r\n       \
    \ }\r\n        int k = 1;\r\n        while(i + k < S.size() && k + ret[k] < j)\r\
    \n            ret[i + k] = ret[k], k++;\r\n        i += k;\r\n        j -= k;\r\
    \n    }\r\n    return ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: String/Zalgorithm.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Zalgorithm.cc
layout: document
redirect_from:
- /library/String/Zalgorithm.cc
- /library/String/Zalgorithm.cc.html
title: String/Zalgorithm.cc
---
