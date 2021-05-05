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
    - https://yukicoder.me/problems/no/1036
  bundledCode: "#line 1 \"DataStructure/SlidingWindowAggregation.cc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n// SWAG\n// https://yukicoder.me/problems/no/1036\ntemplate\
    \ <typename SemiGroup> class SlidingWindowAggregation {\n    using F = function<SemiGroup(SemiGroup,\
    \ SemiGroup)>;\n\n  private:\n    const F f;\n    stack<pair<SemiGroup, SemiGroup>>\
    \ front, back;\n\n  public:\n    SlidingWindowAggregation(F f) : f(f) {}\n\n \
    \   bool empty() { return front.empty() && back.empty(); }\n\n    size_t size()\
    \ { return front.size() + back.size(); }\n\n    SemiGroup fold_all() {\n     \
    \   assert(!this->empty());\n        if(front.empty()) {\n            return back.top().second;\n\
    \        } else if(back.empty()) {\n            return front.top().second;\n \
    \       } else {\n            return f(front.top().second, back.top().second);\n\
    \        }\n    }\n\n    void push(const SemiGroup &x) {\n        if(front.empty())\
    \ {\n            front.emplace(x, x);\n        } else {\n            front.emplace(x,\
    \ f(front.top().second, x));\n        }\n    }\n\n    void pop() {\n        if(back.empty())\
    \ {\n            back.emplace(front.top().first, front.top().first);\n       \
    \     front.pop();\n            while(!front.empty()) {\n                back.emplace(front.top().first,\n\
    \                             f(front.top().first, back.top().second));\n    \
    \            front.pop();\n            }\n        }\n        back.pop();\n   \
    \ }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n// SWAG\n// https://yukicoder.me/problems/no/1036\n\
    template <typename SemiGroup> class SlidingWindowAggregation {\n    using F =\
    \ function<SemiGroup(SemiGroup, SemiGroup)>;\n\n  private:\n    const F f;\n \
    \   stack<pair<SemiGroup, SemiGroup>> front, back;\n\n  public:\n    SlidingWindowAggregation(F\
    \ f) : f(f) {}\n\n    bool empty() { return front.empty() && back.empty(); }\n\
    \n    size_t size() { return front.size() + back.size(); }\n\n    SemiGroup fold_all()\
    \ {\n        assert(!this->empty());\n        if(front.empty()) {\n          \
    \  return back.top().second;\n        } else if(back.empty()) {\n            return\
    \ front.top().second;\n        } else {\n            return f(front.top().second,\
    \ back.top().second);\n        }\n    }\n\n    void push(const SemiGroup &x) {\n\
    \        if(front.empty()) {\n            front.emplace(x, x);\n        } else\
    \ {\n            front.emplace(x, f(front.top().second, x));\n        }\n    }\n\
    \n    void pop() {\n        if(back.empty()) {\n            back.emplace(front.top().first,\
    \ front.top().first);\n            front.pop();\n            while(!front.empty())\
    \ {\n                back.emplace(front.top().first,\n                       \
    \      f(front.top().first, back.top().second));\n                front.pop();\n\
    \            }\n        }\n        back.pop();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SlidingWindowAggregation.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SlidingWindowAggregation.cc
layout: document
redirect_from:
- /library/DataStructure/SlidingWindowAggregation.cc
- /library/DataStructure/SlidingWindowAggregation.cc.html
title: DataStructure/SlidingWindowAggregation.cc
---
