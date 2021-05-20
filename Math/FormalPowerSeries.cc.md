---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/inv_of_formal_power_series.test.cpp
    title: verify/inv_of_formal_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/FormalPowerSeries.cc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename Mint> struct FormalPowerSeries : public\
    \ vector<Mint> {\n    using vector<Mint>::vector;\n    using F = FormalPowerSeries<Mint>;\n\
    \    using CONV = function<vector<Mint>(vector<Mint>, vector<Mint>)>;\n\n    static\
    \ CONV &get_conv() {\n        static CONV conv = nullptr;\n        return conv;\n\
    \    }\n\n    static void set_conv(CONV f) { get_conv() = f; }\n\n    void shrink()\
    \ {\n        while(this->size() && this->back() == Mint(0))\n            this->pop_back();\n\
    \    }\n\n  public:\n    template <typename T> FormalPowerSeries(vector<T> v)\
    \ {\n        *this = FormalPowerSeries(v.size());\n        for(int i = 0; i <\
    \ v.size(); i++)\n            (*this)[i] = Mint(v[i]);\n    }\n\n    F operator*(const\
    \ Mint &g) const { return F(*this) *= g; }\n    F &operator*=(const Mint &g) {\n\
    \        for(auto &e : *this)\n            e *= g;\n        return *this;\n  \
    \  }\n    F operator*(const F &g) const { return F(*this) *= g; }\n    F &operator*=(const\
    \ F &g) {\n        if((*this).empty() || g.empty()) {\n            this->clear();\n\
    \            return *this;\n        }\n        if(get_conv() == nullptr) {\n \
    \           assert(false);\n        } else {\n            return *this = get_conv()(*this,\
    \ g);\n        }\n    }\n    F operator/(const Mint &g) const { return F(*this)\
    \ /= g; }\n    F &operator/=(const Mint &g) {\n        assert(g != Mint(0));\n\
    \        return (*this) *= g.inv();\n    }\n    F operator+(const F &g) const\
    \ { return F(*this) += g; }\n    F &operator+=(const F &g) {\n        if(g.size()\
    \ > this->size()) {\n            this->resize(g.size());\n        }\n        for(int\
    \ i = 0; i < this->size(); i++)\n            (*this)[i] += g[i];\n        return\
    \ *this;\n    }\n    F operator-(const F &g) const { return F(*this) -= g; }\n\
    \    F &operator-=(const F &g) {\n        if(g.size() > this->size()) {\n    \
    \        this->resize(g.size());\n        }\n        for(int i = 0; i < this->size();\
    \ i++)\n            (*this)[i] -= g[i];\n        return *this;\n    }\n    F operator-()\
    \ const {\n        F res(*this);\n        for(auto &e : *this)\n            e\
    \ = -e;\n        return res;\n    }\n    F &operator<<=(const int d) {\n     \
    \   int n = (*this).size();\n        (*this).insert((*this).begin(), d, 0);\n\
    \        (*this).resize(n);\n        return *this;\n    }\n    F &operator>>=(const\
    \ int d) {\n        int n = (*this).size();\n        (*this).erase((*this).begin(),\
    \ (*this).begin() + min(n, d));\n        (*this).resize(n);\n        return *this;\n\
    \    }\n    F &operator=(const F &g) {\n        (*this).clear();\n        (*this).resize(g.size());\n\
    \        for(int i = 0; i < g.size(); i++)\n            (*this)[i] = g[i];\n \
    \       return *this;\n    }\n    template <typename T> F &operator=(const vector<T>\
    \ &g) {\n        (*this).clear();\n        (*this).resize(g.size());\n       \
    \ for(int i = 0; i < g.size(); i++)\n            (*this)[i] = Mint(g[i]);\n  \
    \      return *this;\n    }\n\n    F pre(int sz) const {\n        return F((*this).begin(),\n\
    \                 (*this).begin() + min(sz, (int)(*this).size()));\n    }\n\n\
    \    F inv(int d = -1) {\n        int n = (*this).size();\n        assert(n !=\
    \ 0 && (*this)[0] != Mint(0));\n        if(d == -1)\n            d = n;\n    \
    \    assert(d >= 0);\n        F ret({Mint(1) / (*this)[0]});\n        for(int\
    \ i = 1; i < d; i <<= 1) {\n            ret = (ret * 2 - ret * ret * pre(i <<\
    \ 1)).pre(i << 1);\n        }\n        return ret.pre(d);\n    }\n\n    // multiply\
    \ and divide (1+cz^d)\n    void multiply(const int d, const Mint c) {\n      \
    \  int n = this->size();\n        if(c == Mint(1))\n            for(int i = n\
    \ - d; i >= 0; i--)\n                (*this)[i + d] += (*this)[i];\n        else\
    \ if(c == Mint(-1))\n            for(int i = n - d; i >= 0; i--)\n           \
    \     (*this)[i + d] -= (*this)[i];\n        else\n            for(int i = n -\
    \ d; i >= 0; i--)\n                (*this)[i + d] += (*this)[i] * c;\n    }\n\
    \    void divide(const int d, const Mint c) {\n        int n = this->size();\n\
    \        if(c == Mint(1))\n            for(int i = 0; i < n - d; i++)\n      \
    \          (*this)[i + d] -= (*this)[i];\n        else if(c == Mint(-1))\n   \
    \         for(int i = 0; i < n - d; i++)\n                (*this)[i + d] += (*this)[i];\n\
    \        else\n            for(int i = 0; i < n - d; i++)\n                (*this)[i\
    \ + d] -= (*this)[i] * c;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename Mint>\
    \ struct FormalPowerSeries : public vector<Mint> {\n    using vector<Mint>::vector;\n\
    \    using F = FormalPowerSeries<Mint>;\n    using CONV = function<vector<Mint>(vector<Mint>,\
    \ vector<Mint>)>;\n\n    static CONV &get_conv() {\n        static CONV conv =\
    \ nullptr;\n        return conv;\n    }\n\n    static void set_conv(CONV f) {\
    \ get_conv() = f; }\n\n    void shrink() {\n        while(this->size() && this->back()\
    \ == Mint(0))\n            this->pop_back();\n    }\n\n  public:\n    template\
    \ <typename T> FormalPowerSeries(vector<T> v) {\n        *this = FormalPowerSeries(v.size());\n\
    \        for(int i = 0; i < v.size(); i++)\n            (*this)[i] = Mint(v[i]);\n\
    \    }\n\n    F operator*(const Mint &g) const { return F(*this) *= g; }\n   \
    \ F &operator*=(const Mint &g) {\n        for(auto &e : *this)\n            e\
    \ *= g;\n        return *this;\n    }\n    F operator*(const F &g) const { return\
    \ F(*this) *= g; }\n    F &operator*=(const F &g) {\n        if((*this).empty()\
    \ || g.empty()) {\n            this->clear();\n            return *this;\n   \
    \     }\n        if(get_conv() == nullptr) {\n            assert(false);\n   \
    \     } else {\n            return *this = get_conv()(*this, g);\n        }\n\
    \    }\n    F operator/(const Mint &g) const { return F(*this) /= g; }\n    F\
    \ &operator/=(const Mint &g) {\n        assert(g != Mint(0));\n        return\
    \ (*this) *= g.inv();\n    }\n    F operator+(const F &g) const { return F(*this)\
    \ += g; }\n    F &operator+=(const F &g) {\n        if(g.size() > this->size())\
    \ {\n            this->resize(g.size());\n        }\n        for(int i = 0; i\
    \ < this->size(); i++)\n            (*this)[i] += g[i];\n        return *this;\n\
    \    }\n    F operator-(const F &g) const { return F(*this) -= g; }\n    F &operator-=(const\
    \ F &g) {\n        if(g.size() > this->size()) {\n            this->resize(g.size());\n\
    \        }\n        for(int i = 0; i < this->size(); i++)\n            (*this)[i]\
    \ -= g[i];\n        return *this;\n    }\n    F operator-() const {\n        F\
    \ res(*this);\n        for(auto &e : *this)\n            e = -e;\n        return\
    \ res;\n    }\n    F &operator<<=(const int d) {\n        int n = (*this).size();\n\
    \        (*this).insert((*this).begin(), d, 0);\n        (*this).resize(n);\n\
    \        return *this;\n    }\n    F &operator>>=(const int d) {\n        int\
    \ n = (*this).size();\n        (*this).erase((*this).begin(), (*this).begin()\
    \ + min(n, d));\n        (*this).resize(n);\n        return *this;\n    }\n  \
    \  F &operator=(const F &g) {\n        (*this).clear();\n        (*this).resize(g.size());\n\
    \        for(int i = 0; i < g.size(); i++)\n            (*this)[i] = g[i];\n \
    \       return *this;\n    }\n    template <typename T> F &operator=(const vector<T>\
    \ &g) {\n        (*this).clear();\n        (*this).resize(g.size());\n       \
    \ for(int i = 0; i < g.size(); i++)\n            (*this)[i] = Mint(g[i]);\n  \
    \      return *this;\n    }\n\n    F pre(int sz) const {\n        return F((*this).begin(),\n\
    \                 (*this).begin() + min(sz, (int)(*this).size()));\n    }\n\n\
    \    F inv(int d = -1) {\n        int n = (*this).size();\n        assert(n !=\
    \ 0 && (*this)[0] != Mint(0));\n        if(d == -1)\n            d = n;\n    \
    \    assert(d >= 0);\n        F ret({Mint(1) / (*this)[0]});\n        for(int\
    \ i = 1; i < d; i <<= 1) {\n            ret = (ret * 2 - ret * ret * pre(i <<\
    \ 1)).pre(i << 1);\n        }\n        return ret.pre(d);\n    }\n\n    // multiply\
    \ and divide (1+cz^d)\n    void multiply(const int d, const Mint c) {\n      \
    \  int n = this->size();\n        if(c == Mint(1))\n            for(int i = n\
    \ - d; i >= 0; i--)\n                (*this)[i + d] += (*this)[i];\n        else\
    \ if(c == Mint(-1))\n            for(int i = n - d; i >= 0; i--)\n           \
    \     (*this)[i + d] -= (*this)[i];\n        else\n            for(int i = n -\
    \ d; i >= 0; i--)\n                (*this)[i + d] += (*this)[i] * c;\n    }\n\
    \    void divide(const int d, const Mint c) {\n        int n = this->size();\n\
    \        if(c == Mint(1))\n            for(int i = 0; i < n - d; i++)\n      \
    \          (*this)[i + d] -= (*this)[i];\n        else if(c == Mint(-1))\n   \
    \         for(int i = 0; i < n - d; i++)\n                (*this)[i + d] += (*this)[i];\n\
    \        else\n            for(int i = 0; i < n - d; i++)\n                (*this)[i\
    \ + d] -= (*this)[i] * c;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/FormalPowerSeries.cc
  requiredBy: []
  timestamp: '2021-05-20 17:44:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/inv_of_formal_power_series.test.cpp
documentation_of: Math/FormalPowerSeries.cc
layout: document
redirect_from:
- /library/Math/FormalPowerSeries.cc
- /library/Math/FormalPowerSeries.cc.html
title: Math/FormalPowerSeries.cc
---
