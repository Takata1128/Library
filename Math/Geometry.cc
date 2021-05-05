#include <bits/stdc++.h>
using namespace std;

// 未verify
namespace geometry {
using ld = long double;
const ld INF = 1LL << 60;
const ld EPS = 1e-10;
const ld PI = acosl(-1.0);
ld radian(ld degree) { return (ld)(degree)*PI / 180; };
ld degree(ld radian) { return radian * 180 / PI; }

class Point {
  public:
    ld x, y;
    Point(ld x = 0.0, ld y = 0.0) : x(x), y(y) {}
    friend ostream &operator<<(ostream &s, const Point &p) {
        return s << '(' << p.x << ',' << p.y << ')';
    }

    Point operator+(const Point &rhs) const { return Point(*this) += rhs; }
    Point operator-(const Point &rhs) const { return Point(*this) -= rhs; }
    Point operator*(const Point &rhs) const { return Point(*this) *= rhs; }
    Point operator*(const ld &rhs) const { return Point(*this) *= rhs; }
    Point operator/(const ld &rhs) const { return Point(*this) /= rhs; }
    bool operator==(const Point &p) { return (p - (*this)).abs() < EPS; }

    Point conj() const { return Point((*this).x, -(*this).y); }
    Point rotate(const ld radian) const {
        return Point(cos(radian) * (*this).x - sin(radian) * (*this).y,
                     sin(radian) * (*this).x + cos(radian) * (*this).y);
    }
    Point rotate90() const { return Point(-(*this).y, (*this).x); }

    ld dot(const Point &p) const { return p.x * (*this).x + p.y * (*this).y; }
    ld norm() const { return (*this).dot((*this)); }
    ld abs() const { return sqrt((*this).norm()); }
    ld amp() const {
        ld res = atan2((*this).y, (*this).x);
        return res < 0 ? res + PI * 2 : res;
    }
    constexpr Point &operator+=(const Point &rhs) {
        x += rhs.x, y += rhs.y;
        return *this;
    }
    constexpr Point &operator-=(const Point &rhs) {
        x -= rhs.x, y -= rhs.y;
        return *this;
    }
    constexpr Point &operator*=(const ld &rhs) {
        x *= rhs, y *= rhs;
        return *this;
    }
    constexpr Point &operator*=(const Point &rhs) {
        ld nx = x * rhs.x - y * rhs.y, ny = x * rhs.y + y * rhs.x;
        x = nx, y = ny;
        return *this;
    }
    constexpr Point &operator/=(const ld &rhs) {
        x /= rhs, y /= rhs;
        return *this;
    }
};

inline ld cross(const Point &p, const Point &q) {
    return p.x * q.y - p.y * q.x;
}
inline ld dot(const Point &p, const Point &q) { return p.x * q.x + p.y * q.y; }

inline bool operator<(const Point &p, const Point &q) {
    return (std::abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y);
}
inline bool operator>(const Point &p, const Point &q) {
    return (std::abs(p.x - q.x) > EPS ? p.x > q.x : p.y > q.y);
}
inline Point operator/(const Point &p, const Point &q) {
    return p * q.conj() / q.norm();
}

class Line : vector<Point> {
  public:
    Line(Point a = Point(), Point b = Point()) {
        this->push_back(a);
        this->push_back(b);
    }
    bool crossPoint(const Line &l, Point &p) const {
        ld d = cross(l[1] - l[0], (*this)[1] - (*this)[0]);
        if(abs(d) < EPS)
            return false;
        p = (*this)[0] + ((*this)[1] - (*this)[0]) *
                             cross(l[1] - l[0], l[1] - (*this)[0]) / d;
        return true;
    }
    friend ostream &operator<<(ostream &s, const Line &l) {
        return s << '{' << l[0] << ", " << l[1] << '}';
    }
};

// 0:一直線上,1:cがa-bから見て反時計回りで左側,2:cがa-bから見て右側
inline int ccw(const Point &a, const Point &b, const Point &c) {
    if(cross(b - a, c - a) > EPS)
        return 1;
    if(cross(b - a, c - a) < -EPS)
        return -1;
    return 0;
}

inline bool circumcenter(Point &a, Point &b, Point &c, Point &p) {
    Line ab((a + b) / 2, (a + b) / 2 + (a - b).rotate90());
    Line bc((b + c) / 2, (b + c) / 2 + (b - c).rotate90());
    return ab.crossPoint(bc, p);
}

}; // namespace geometry
