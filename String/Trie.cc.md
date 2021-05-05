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
    - https://algo-logic.info/trie-tree/
  bundledCode: "#line 1 \"String/Trie.cc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Trie\u6728\n// \u53C2\u8003\uFF1Ahttps://algo-logic.info/trie-tree/\n\
    // \u633F\u5165\u3001\u691C\u7D22\u3068\u3082\u306BO(|\u6587\u5B57\u5217\u306E\
    \u9577\u3055|)\ntemplate <int char_size, int base> struct Trie {\n    struct Node\
    \ {\n        vector<int> next; //\u5B50\u306E\u9802\u70B9\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\n        int last;         // \u7D42\u7AEF\u3059\u308B\u5358\
    \u8A9E\u6570\n        int count;        // Node\u3092\u5171\u6709\u3059\u308B\u5358\
    \u8A9E\u6570\n        Node() : count(0), last(0) { next.assign(char_size, -1);\
    \ }\n    };\n    vector<Node> nodes; // Trie\u6728\u672C\u4F53\n    Trie() { nodes.push_back(Node(0));\
    \ }\n\n    // \u5358\u8A9E\u306E\u633F\u5165\n    void insert(const string &word)\
    \ {\n        int node_idx = 0;\n        for(int i = 0; i < word.size(); i++) {\n\
    \            int c = word[i] - base;\n            int next_idx = nodes[node_idx].next[c];\n\
    \            if(next_idx == -1) {\n                next_idx = nodes.size();\n\
    \                nodes.push_back(Node());\n            }\n            nodes[node_idx].count++;\n\
    \            node_idx = next_idx;\n        }\n        nodes[node_idx].count++;\n\
    \        nodes[node_idx].last++;\n    }\n\n    // \u5358\u8A9E\u306E\u691C\u7D22\
    \uFF08\u6570\u3092\u8FD4\u3059\uFF09\n    int search_count(const string &word,\
    \ bool prefix = false) {\n        int node_idx = 0;\n        for(int i = 0; i\
    \ < word.size(); i++) {\n            int c = word[i] - base;\n            int\
    \ next_idx = nodes[node_idx].next[c];\n            if(next_idx == -1) {\n    \
    \            return 0;\n            }\n            node_idx = next_idx;\n    \
    \    }\n        return prefix ? nodes[node_idx].count : nodes[node_idx].last;\n\
    \    }\n\n    // prefix\u3092\u6301\u3064\u5358\u8A9E\u306E\u691C\u7D22\uFF08\u6570\
    \u3092\u8FD4\u3059\uFF09\n    int prefix_count(const string &prefix) {\n     \
    \   return search_count(prefix, true);\n    }\n\n    int word_count() { return\
    \ nodes[0].count; }\n\n    int size() { return nodes.size(); }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// Trie\u6728\n// \u53C2\
    \u8003\uFF1Ahttps://algo-logic.info/trie-tree/\n// \u633F\u5165\u3001\u691C\u7D22\
    \u3068\u3082\u306BO(|\u6587\u5B57\u5217\u306E\u9577\u3055|)\ntemplate <int char_size,\
    \ int base> struct Trie {\n    struct Node {\n        vector<int> next; //\u5B50\
    \u306E\u9802\u70B9\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n        int last;\
    \         // \u7D42\u7AEF\u3059\u308B\u5358\u8A9E\u6570\n        int count;  \
    \      // Node\u3092\u5171\u6709\u3059\u308B\u5358\u8A9E\u6570\n        Node()\
    \ : count(0), last(0) { next.assign(char_size, -1); }\n    };\n    vector<Node>\
    \ nodes; // Trie\u6728\u672C\u4F53\n    Trie() { nodes.push_back(Node(0)); }\n\
    \n    // \u5358\u8A9E\u306E\u633F\u5165\n    void insert(const string &word) {\n\
    \        int node_idx = 0;\n        for(int i = 0; i < word.size(); i++) {\n \
    \           int c = word[i] - base;\n            int next_idx = nodes[node_idx].next[c];\n\
    \            if(next_idx == -1) {\n                next_idx = nodes.size();\n\
    \                nodes.push_back(Node());\n            }\n            nodes[node_idx].count++;\n\
    \            node_idx = next_idx;\n        }\n        nodes[node_idx].count++;\n\
    \        nodes[node_idx].last++;\n    }\n\n    // \u5358\u8A9E\u306E\u691C\u7D22\
    \uFF08\u6570\u3092\u8FD4\u3059\uFF09\n    int search_count(const string &word,\
    \ bool prefix = false) {\n        int node_idx = 0;\n        for(int i = 0; i\
    \ < word.size(); i++) {\n            int c = word[i] - base;\n            int\
    \ next_idx = nodes[node_idx].next[c];\n            if(next_idx == -1) {\n    \
    \            return 0;\n            }\n            node_idx = next_idx;\n    \
    \    }\n        return prefix ? nodes[node_idx].count : nodes[node_idx].last;\n\
    \    }\n\n    // prefix\u3092\u6301\u3064\u5358\u8A9E\u306E\u691C\u7D22\uFF08\u6570\
    \u3092\u8FD4\u3059\uFF09\n    int prefix_count(const string &prefix) {\n     \
    \   return search_count(prefix, true);\n    }\n\n    int word_count() { return\
    \ nodes[0].count; }\n\n    int size() { return nodes.size(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: String/Trie.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Trie.cc
layout: document
redirect_from:
- /library/String/Trie.cc
- /library/String/Trie.cc.html
title: String/Trie.cc
---
