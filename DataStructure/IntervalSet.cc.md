---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Manage interval by set. Note that interval is harf-open [l,r).
    links: []
  bundledCode: "#line 1 \"DataStructure/IntervalSet.cc\"\n#include <bits/stdc++.h>\n\
    \n/**\n * @brief Manage interval by set. Note that interval is harf-open [l,r).\n\
    \ *\n * @tparam T Universal set.\n */\ntemplate <typename T> class IntervalSet\
    \ : std::set<std::pair<T, T>> {\n  private:\n    const T INF = std::numeric_limits<T>::max()\
    \ - 65;\n    bool isMergeAdjacent;\n\n  public:\n    /**\n     * @brief Construct\
    \ a new Interval Set object\n     *\n     * @param f If merge adjacent interval\n\
    \     */\n    IntervalSet(bool f) : isMergeAdjacent(f) {\n        this->emplace(-INF,\
    \ -INF + 1);\n        this->emplace(INF, INF + 1);\n    }\n    /**\n     * @brief\
    \ Get a interval to which p belongs.\n     *\n     * @param p Element in T\n \
    \    * @return Iterator of interval to which p belongs. If not exists, return\n\
    \     * iterator end().\n     */\n    auto get(T p) const {\n        auto it =\
    \ this->upper_bound({p, INF});\n        if(it == this->begin() || (--it)->second\
    \ < p)\n            return this->end();\n        return it;\n    }\n    /**\n\
    \     * @brief Insert interval [l,r).\n     *\n     * @param l Left end of interval.\n\
    \     * @param r Right end of interval.\n     */\n    void insert(T l, T r) {\n\
    \        if(l >= r)\n            return;\n        auto it = std::prev(this->lower_bound({l,\
    \ r}));\n        if(it->first <= l && l + !isMergeAdjacent <= it->second) {\n\
    \            l = std::min(l, it->first);\n            r = std::max(r, it->second);\n\
    \            this->erase(it);\n        }\n        it = this->lower_bound({l, r});\n\
    \        while(1) {\n            if(l <= it->first && it->first <= r) {\n    \
    \            r = std::max(r, it->second);\n                it = this->erase(it);\n\
    \            } else\n                break;\n        }\n        this->emplace(l,\
    \ r);\n    }\n\n    /**\n     * @brief Insert element\n     *\n     * @param p\
    \ Element in T\n     */\n    void insert(T p) { insert(p, p + 1); }\n\n    T remove(const\
    \ T l, const T r) {\n        assert(l < r);\n        auto itr = std::prev(this->lower_bound({l\
    \ + 1, -INF}));\n        if(itr->first <= l and r <= itr->second) {\n        \
    \    if(itr->first < l)\n                this->emplace(itr->first, l);\n     \
    \       if(r < itr->second)\n                this->emplace(r, itr->second);\n\
    \            this->erase(itr);\n            return r - l;\n        }\n\n     \
    \   T ret = T(0);\n        if(itr->first <= l and l < itr->second) {\n       \
    \     ret += itr->second - l;\n            if(itr->first < l)\n              \
    \  this->emplace(itr->first, l);\n            itr = this->erase(itr);\n      \
    \  } else\n            itr = next(itr);\n        while(itr->second <= r) {\n \
    \           ret += itr->second - itr->first;\n            itr = this->erase(itr);\n\
    \        }\n        if(itr->first < r) {\n            ret += r - itr->first;\n\
    \            this->emplace(r, itr->second);\n            this->erase(itr);\n \
    \       }\n        return ret;\n    }\n\n    /**\n     * @brief\n     *\n    \
    \ * @param x\n     * @return T\n     */\n    T remove(const T x) { return remove(x,\
    \ x + 1); }\n\n    /**\n     * @brief Judge if p and q are in same interval.\n\
    \     *\n     * @param p Element in T.\n     * @param q Element in T.\n     *\
    \ @return If p and q are in same interval.\n     */\n    bool same(T p, T q) const\
    \ {\n        auto it = get(p);\n        return it != this->end() && it->first\
    \ <= q && q <= it->second;\n    }\n\n    /**\n     * @brief Count the number of\
    \ elements in intervals.\n     *\n     * @return T Summation of the number of\
    \ elements in intervals.\n     */\n    T sumAll() const {\n        T ret = 0;\n\
    \        for(auto it = this->begin(), e = this->end(); it != e; ++it) {\n    \
    \        if(std::abs(it->first) == INF)\n                continue;\n         \
    \   ret += it->second - it->first;\n        }\n        return ret;\n    }\n\n\
    \    /**\n     * @brief get mex in [x,)\n     *\n     * @param x\n     * @return\
    \ int\n     */\n    int mex(const T x = 0) {\n        auto itr = std::prev(this->lower_bound({x\
    \ + 1, -INF}));\n        if(itr->first <= x and x < itr->second)\n           \
    \ return itr->second;\n        else\n            return x;\n    }\n\n    /**\n\
    \     * @brief Show contents of set.\n     *\n     */\n    void dump() {\n   \
    \     for(auto it = this->begin(), e = this->end(); it != e; ++it) {\n       \
    \     if(std::abs(it->first) == INF)\n                continue;\n            std::cout\
    \ << \"[\" << it->first << \",\" << it->second\n                      << (it ==\
    \ std::prev(std::prev(e)) ? \")\" : \"), \");\n        }\n        std::cout <<\
    \ std::endl;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/**\n * @brief Manage interval by set. Note that\
    \ interval is harf-open [l,r).\n *\n * @tparam T Universal set.\n */\ntemplate\
    \ <typename T> class IntervalSet : std::set<std::pair<T, T>> {\n  private:\n \
    \   const T INF = std::numeric_limits<T>::max() - 65;\n    bool isMergeAdjacent;\n\
    \n  public:\n    /**\n     * @brief Construct a new Interval Set object\n    \
    \ *\n     * @param f If merge adjacent interval\n     */\n    IntervalSet(bool\
    \ f) : isMergeAdjacent(f) {\n        this->emplace(-INF, -INF + 1);\n        this->emplace(INF,\
    \ INF + 1);\n    }\n    /**\n     * @brief Get a interval to which p belongs.\n\
    \     *\n     * @param p Element in T\n     * @return Iterator of interval to\
    \ which p belongs. If not exists, return\n     * iterator end().\n     */\n  \
    \  auto get(T p) const {\n        auto it = this->upper_bound({p, INF});\n   \
    \     if(it == this->begin() || (--it)->second < p)\n            return this->end();\n\
    \        return it;\n    }\n    /**\n     * @brief Insert interval [l,r).\n  \
    \   *\n     * @param l Left end of interval.\n     * @param r Right end of interval.\n\
    \     */\n    void insert(T l, T r) {\n        if(l >= r)\n            return;\n\
    \        auto it = std::prev(this->lower_bound({l, r}));\n        if(it->first\
    \ <= l && l + !isMergeAdjacent <= it->second) {\n            l = std::min(l, it->first);\n\
    \            r = std::max(r, it->second);\n            this->erase(it);\n    \
    \    }\n        it = this->lower_bound({l, r});\n        while(1) {\n        \
    \    if(l <= it->first && it->first <= r) {\n                r = std::max(r, it->second);\n\
    \                it = this->erase(it);\n            } else\n                break;\n\
    \        }\n        this->emplace(l, r);\n    }\n\n    /**\n     * @brief Insert\
    \ element\n     *\n     * @param p Element in T\n     */\n    void insert(T p)\
    \ { insert(p, p + 1); }\n\n    T remove(const T l, const T r) {\n        assert(l\
    \ < r);\n        auto itr = std::prev(this->lower_bound({l + 1, -INF}));\n   \
    \     if(itr->first <= l and r <= itr->second) {\n            if(itr->first <\
    \ l)\n                this->emplace(itr->first, l);\n            if(r < itr->second)\n\
    \                this->emplace(r, itr->second);\n            this->erase(itr);\n\
    \            return r - l;\n        }\n\n        T ret = T(0);\n        if(itr->first\
    \ <= l and l < itr->second) {\n            ret += itr->second - l;\n         \
    \   if(itr->first < l)\n                this->emplace(itr->first, l);\n      \
    \      itr = this->erase(itr);\n        } else\n            itr = next(itr);\n\
    \        while(itr->second <= r) {\n            ret += itr->second - itr->first;\n\
    \            itr = this->erase(itr);\n        }\n        if(itr->first < r) {\n\
    \            ret += r - itr->first;\n            this->emplace(r, itr->second);\n\
    \            this->erase(itr);\n        }\n        return ret;\n    }\n\n    /**\n\
    \     * @brief\n     *\n     * @param x\n     * @return T\n     */\n    T remove(const\
    \ T x) { return remove(x, x + 1); }\n\n    /**\n     * @brief Judge if p and q\
    \ are in same interval.\n     *\n     * @param p Element in T.\n     * @param\
    \ q Element in T.\n     * @return If p and q are in same interval.\n     */\n\
    \    bool same(T p, T q) const {\n        auto it = get(p);\n        return it\
    \ != this->end() && it->first <= q && q <= it->second;\n    }\n\n    /**\n   \
    \  * @brief Count the number of elements in intervals.\n     *\n     * @return\
    \ T Summation of the number of elements in intervals.\n     */\n    T sumAll()\
    \ const {\n        T ret = 0;\n        for(auto it = this->begin(), e = this->end();\
    \ it != e; ++it) {\n            if(std::abs(it->first) == INF)\n             \
    \   continue;\n            ret += it->second - it->first;\n        }\n       \
    \ return ret;\n    }\n\n    /**\n     * @brief get mex in [x,)\n     *\n     *\
    \ @param x\n     * @return int\n     */\n    int mex(const T x = 0) {\n      \
    \  auto itr = std::prev(this->lower_bound({x + 1, -INF}));\n        if(itr->first\
    \ <= x and x < itr->second)\n            return itr->second;\n        else\n \
    \           return x;\n    }\n\n    /**\n     * @brief Show contents of set.\n\
    \     *\n     */\n    void dump() {\n        for(auto it = this->begin(), e =\
    \ this->end(); it != e; ++it) {\n            if(std::abs(it->first) == INF)\n\
    \                continue;\n            std::cout << \"[\" << it->first << \"\
    ,\" << it->second\n                      << (it == std::prev(std::prev(e)) ? \"\
    )\" : \"), \");\n        }\n        std::cout << std::endl;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/IntervalSet.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/IntervalSet.cc
layout: document
redirect_from:
- /library/DataStructure/IntervalSet.cc
- /library/DataStructure/IntervalSet.cc.html
title: Manage interval by set. Note that interval is harf-open [l,r).
---
