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
  bundledCode: "#line 1 \"Math/Geometry.cc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// \u672Averify\nnamespace geometry {\nusing ld = long double;\nconst\
    \ ld INF = 1LL << 60;\nconst ld EPS = 1e-10;\nconst ld PI = acosl(-1.0);\nld radian(ld\
    \ degree) { return (ld)(degree)*PI / 180; };\nld degree(ld radian) { return radian\
    \ * 180 / PI; }\n\nclass Point {\n  public:\n    ld x, y;\n    Point(ld x = 0.0,\
    \ ld y = 0.0) : x(x), y(y) {}\n    friend ostream &operator<<(ostream &s, const\
    \ Point &p) {\n        return s << '(' << p.x << ',' << p.y << ')';\n    }\n\n\
    \    Point operator+(const Point &rhs) const { return Point(*this) += rhs; }\n\
    \    Point operator-(const Point &rhs) const { return Point(*this) -= rhs; }\n\
    \    Point operator*(const Point &rhs) const { return Point(*this) *= rhs; }\n\
    \    Point operator*(const ld &rhs) const { return Point(*this) *= rhs; }\n  \
    \  Point operator/(const ld &rhs) const { return Point(*this) /= rhs; }\n    bool\
    \ operator==(const Point &p) { return (p - (*this)).abs() < EPS; }\n\n    Point\
    \ conj() const { return Point((*this).x, -(*this).y); }\n    Point rotate(const\
    \ ld radian) const {\n        return Point(cos(radian) * (*this).x - sin(radian)\
    \ * (*this).y,\n                     sin(radian) * (*this).x + cos(radian) * (*this).y);\n\
    \    }\n    Point rotate90() const { return Point(-(*this).y, (*this).x); }\n\n\
    \    ld dot(const Point &p) const { return p.x * (*this).x + p.y * (*this).y;\
    \ }\n    ld norm() const { return (*this).dot((*this)); }\n    ld abs() const\
    \ { return sqrt((*this).norm()); }\n    ld amp() const {\n        ld res = atan2((*this).y,\
    \ (*this).x);\n        return res < 0 ? res + PI * 2 : res;\n    }\n    constexpr\
    \ Point &operator+=(const Point &rhs) {\n        x += rhs.x, y += rhs.y;\n   \
    \     return *this;\n    }\n    constexpr Point &operator-=(const Point &rhs)\
    \ {\n        x -= rhs.x, y -= rhs.y;\n        return *this;\n    }\n    constexpr\
    \ Point &operator*=(const ld &rhs) {\n        x *= rhs, y *= rhs;\n        return\
    \ *this;\n    }\n    constexpr Point &operator*=(const Point &rhs) {\n       \
    \ ld nx = x * rhs.x - y * rhs.y, ny = x * rhs.y + y * rhs.x;\n        x = nx,\
    \ y = ny;\n        return *this;\n    }\n    constexpr Point &operator/=(const\
    \ ld &rhs) {\n        x /= rhs, y /= rhs;\n        return *this;\n    }\n};\n\n\
    inline ld cross(const Point &p, const Point &q) {\n    return p.x * q.y - p.y\
    \ * q.x;\n}\ninline ld dot(const Point &p, const Point &q) { return p.x * q.x\
    \ + p.y * q.y; }\n\ninline bool operator<(const Point &p, const Point &q) {\n\
    \    return (std::abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y);\n}\ninline bool\
    \ operator>(const Point &p, const Point &q) {\n    return (std::abs(p.x - q.x)\
    \ > EPS ? p.x > q.x : p.y > q.y);\n}\ninline Point operator/(const Point &p, const\
    \ Point &q) {\n    return p * q.conj() / q.norm();\n}\n\nclass Line : vector<Point>\
    \ {\n  public:\n    Line(Point a = Point(), Point b = Point()) {\n        this->push_back(a);\n\
    \        this->push_back(b);\n    }\n    bool crossPoint(const Line &l, Point\
    \ &p) const {\n        ld d = cross(l[1] - l[0], (*this)[1] - (*this)[0]);\n \
    \       if(abs(d) < EPS)\n            return false;\n        p = (*this)[0] +\
    \ ((*this)[1] - (*this)[0]) *\n                             cross(l[1] - l[0],\
    \ l[1] - (*this)[0]) / d;\n        return true;\n    }\n    friend ostream &operator<<(ostream\
    \ &s, const Line &l) {\n        return s << '{' << l[0] << \", \" << l[1] << '}';\n\
    \    }\n};\n\n// 0:\u4E00\u76F4\u7DDA\u4E0A,1:c\u304Ca-b\u304B\u3089\u898B\u3066\
    \u53CD\u6642\u8A08\u56DE\u308A\u3067\u5DE6\u5074,2:c\u304Ca-b\u304B\u3089\u898B\
    \u3066\u53F3\u5074\ninline int ccw(const Point &a, const Point &b, const Point\
    \ &c) {\n    if(cross(b - a, c - a) > EPS)\n        return 1;\n    if(cross(b\
    \ - a, c - a) < -EPS)\n        return -1;\n    return 0;\n}\n\ninline bool circumcenter(Point\
    \ &a, Point &b, Point &c, Point &p) {\n    Line ab((a + b) / 2, (a + b) / 2 +\
    \ (a - b).rotate90());\n    Line bc((b + c) / 2, (b + c) / 2 + (b - c).rotate90());\n\
    \    return ab.crossPoint(bc, p);\n}\n\n}; // namespace geometry\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// \u672Averify\nnamespace\
    \ geometry {\nusing ld = long double;\nconst ld INF = 1LL << 60;\nconst ld EPS\
    \ = 1e-10;\nconst ld PI = acosl(-1.0);\nld radian(ld degree) { return (ld)(degree)*PI\
    \ / 180; };\nld degree(ld radian) { return radian * 180 / PI; }\n\nclass Point\
    \ {\n  public:\n    ld x, y;\n    Point(ld x = 0.0, ld y = 0.0) : x(x), y(y) {}\n\
    \    friend ostream &operator<<(ostream &s, const Point &p) {\n        return\
    \ s << '(' << p.x << ',' << p.y << ')';\n    }\n\n    Point operator+(const Point\
    \ &rhs) const { return Point(*this) += rhs; }\n    Point operator-(const Point\
    \ &rhs) const { return Point(*this) -= rhs; }\n    Point operator*(const Point\
    \ &rhs) const { return Point(*this) *= rhs; }\n    Point operator*(const ld &rhs)\
    \ const { return Point(*this) *= rhs; }\n    Point operator/(const ld &rhs) const\
    \ { return Point(*this) /= rhs; }\n    bool operator==(const Point &p) { return\
    \ (p - (*this)).abs() < EPS; }\n\n    Point conj() const { return Point((*this).x,\
    \ -(*this).y); }\n    Point rotate(const ld radian) const {\n        return Point(cos(radian)\
    \ * (*this).x - sin(radian) * (*this).y,\n                     sin(radian) * (*this).x\
    \ + cos(radian) * (*this).y);\n    }\n    Point rotate90() const { return Point(-(*this).y,\
    \ (*this).x); }\n\n    ld dot(const Point &p) const { return p.x * (*this).x +\
    \ p.y * (*this).y; }\n    ld norm() const { return (*this).dot((*this)); }\n \
    \   ld abs() const { return sqrt((*this).norm()); }\n    ld amp() const {\n  \
    \      ld res = atan2((*this).y, (*this).x);\n        return res < 0 ? res + PI\
    \ * 2 : res;\n    }\n    constexpr Point &operator+=(const Point &rhs) {\n   \
    \     x += rhs.x, y += rhs.y;\n        return *this;\n    }\n    constexpr Point\
    \ &operator-=(const Point &rhs) {\n        x -= rhs.x, y -= rhs.y;\n        return\
    \ *this;\n    }\n    constexpr Point &operator*=(const ld &rhs) {\n        x *=\
    \ rhs, y *= rhs;\n        return *this;\n    }\n    constexpr Point &operator*=(const\
    \ Point &rhs) {\n        ld nx = x * rhs.x - y * rhs.y, ny = x * rhs.y + y * rhs.x;\n\
    \        x = nx, y = ny;\n        return *this;\n    }\n    constexpr Point &operator/=(const\
    \ ld &rhs) {\n        x /= rhs, y /= rhs;\n        return *this;\n    }\n};\n\n\
    inline ld cross(const Point &p, const Point &q) {\n    return p.x * q.y - p.y\
    \ * q.x;\n}\ninline ld dot(const Point &p, const Point &q) { return p.x * q.x\
    \ + p.y * q.y; }\n\ninline bool operator<(const Point &p, const Point &q) {\n\
    \    return (std::abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y);\n}\ninline bool\
    \ operator>(const Point &p, const Point &q) {\n    return (std::abs(p.x - q.x)\
    \ > EPS ? p.x > q.x : p.y > q.y);\n}\ninline Point operator/(const Point &p, const\
    \ Point &q) {\n    return p * q.conj() / q.norm();\n}\n\nclass Line : vector<Point>\
    \ {\n  public:\n    Line(Point a = Point(), Point b = Point()) {\n        this->push_back(a);\n\
    \        this->push_back(b);\n    }\n    bool crossPoint(const Line &l, Point\
    \ &p) const {\n        ld d = cross(l[1] - l[0], (*this)[1] - (*this)[0]);\n \
    \       if(abs(d) < EPS)\n            return false;\n        p = (*this)[0] +\
    \ ((*this)[1] - (*this)[0]) *\n                             cross(l[1] - l[0],\
    \ l[1] - (*this)[0]) / d;\n        return true;\n    }\n    friend ostream &operator<<(ostream\
    \ &s, const Line &l) {\n        return s << '{' << l[0] << \", \" << l[1] << '}';\n\
    \    }\n};\n\n// 0:\u4E00\u76F4\u7DDA\u4E0A,1:c\u304Ca-b\u304B\u3089\u898B\u3066\
    \u53CD\u6642\u8A08\u56DE\u308A\u3067\u5DE6\u5074,2:c\u304Ca-b\u304B\u3089\u898B\
    \u3066\u53F3\u5074\ninline int ccw(const Point &a, const Point &b, const Point\
    \ &c) {\n    if(cross(b - a, c - a) > EPS)\n        return 1;\n    if(cross(b\
    \ - a, c - a) < -EPS)\n        return -1;\n    return 0;\n}\n\ninline bool circumcenter(Point\
    \ &a, Point &b, Point &c, Point &p) {\n    Line ab((a + b) / 2, (a + b) / 2 +\
    \ (a - b).rotate90());\n    Line bc((b + c) / 2, (b + c) / 2 + (b - c).rotate90());\n\
    \    return ab.crossPoint(bc, p);\n}\n\n}; // namespace geometry\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Geometry.cc
  requiredBy: []
  timestamp: '2021-05-05 18:25:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Geometry.cc
layout: document
redirect_from:
- /library/Math/Geometry.cc
- /library/Math/Geometry.cc.html
title: Math/Geometry.cc
---
