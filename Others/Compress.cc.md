---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "#line 1 \"Others/Compress.cc\"\n#include <bits/stdc++.h>\n\n/**\n\
    \ * @brief \u5EA7\u6A19\u5727\u7E2E\n *\n * @tparam T \u30C7\u30FC\u30BF\u578B\
    \n * @param X \u5727\u7E2E\u3059\u308B\u6570\u5217 \u526F\u4F5C\u7528\u306B\u3088\
    \u308A\u5727\u7E2E\u5F8C\u306E\u5024\u304C\u5165\u308B\n * @return std::vector<T>\
    \ \u30BD\u30FC\u30C8\u3057\u3066\u91CD\u8907\u3092\u9664\u53BB\u3057\u305F\u5143\
    \u6570\u5217\n */\ntemplate <typename T> std::vector<T> compress(std::vector<T>\
    \ &X) {\n    std::vector<T> vals = X;\n    std::sort(vals.begin(), vals.end());\n\
    \    vals.erase(unique(vals.begin(), vals.end()), vals.end());\n    for(int i\
    \ = 0; i < X.size(); i++) {\n        X[i] = lower_bound(vals.begin(), vals.end(),\
    \ X[i]) - vals.begin();\n    }\n    return vals;\n}\n\ntemplate <typename T>\n\
    std::vector<T> compress2P(std::vector<T> &X1, std::vector<T> &X2) {\n    vector<T>\
    \ vals;\n    for(auto x : X1) {\n        vals.pb(x);\n        // vals.pb(x+1);\n\
    \    }\n    for(auto x : X2) {\n        vals.pb(x);\n        // vals.pb(x+1);\n\
    \    }\n    std::sort(vals.begin(), vals.end());\n    vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\n    for(int i = 0; i < X1.size(); i++) {\n      \
    \  X1[i] = lower_bound(vals.begin(), vals.end(), X1[i]) - vals.begin();\n    \
    \    X2[i] = lower_bound(vals.begin(), vals.end(), X2[i]) - vals.begin();\n  \
    \  }\n    return vals;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\n *\n\
    \ * @tparam T \u30C7\u30FC\u30BF\u578B\n * @param X \u5727\u7E2E\u3059\u308B\u6570\
    \u5217 \u526F\u4F5C\u7528\u306B\u3088\u308A\u5727\u7E2E\u5F8C\u306E\u5024\u304C\
    \u5165\u308B\n * @return std::vector<T> \u30BD\u30FC\u30C8\u3057\u3066\u91CD\u8907\
    \u3092\u9664\u53BB\u3057\u305F\u5143\u6570\u5217\n */\ntemplate <typename T> std::vector<T>\
    \ compress(std::vector<T> &X) {\n    std::vector<T> vals = X;\n    std::sort(vals.begin(),\
    \ vals.end());\n    vals.erase(unique(vals.begin(), vals.end()), vals.end());\n\
    \    for(int i = 0; i < X.size(); i++) {\n        X[i] = lower_bound(vals.begin(),\
    \ vals.end(), X[i]) - vals.begin();\n    }\n    return vals;\n}\n\ntemplate <typename\
    \ T>\nstd::vector<T> compress2P(std::vector<T> &X1, std::vector<T> &X2) {\n  \
    \  vector<T> vals;\n    for(auto x : X1) {\n        vals.pb(x);\n        // vals.pb(x+1);\n\
    \    }\n    for(auto x : X2) {\n        vals.pb(x);\n        // vals.pb(x+1);\n\
    \    }\n    std::sort(vals.begin(), vals.end());\n    vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\n    for(int i = 0; i < X1.size(); i++) {\n      \
    \  X1[i] = lower_bound(vals.begin(), vals.end(), X1[i]) - vals.begin();\n    \
    \    X2[i] = lower_bound(vals.begin(), vals.end(), X2[i]) - vals.begin();\n  \
    \  }\n    return vals;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Others/Compress.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/Compress.cc
layout: document
redirect_from:
- /library/Others/Compress.cc
- /library/Others/Compress.cc.html
title: "\u5EA7\u6A19\u5727\u7E2E"
---
