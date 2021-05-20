#include <bits/stdc++.h>
using namespace std;

template <typename Mint> struct FormalPowerSeries : public vector<Mint> {
    using vector<Mint>::vector;
    using F = FormalPowerSeries<Mint>;
    using CONV = function<vector<Mint>(vector<Mint>, vector<Mint>)>;

    static CONV &get_conv() {
        static CONV conv = nullptr;
        return conv;
    }

    static void set_conv(CONV f) { get_conv() = f; }

    void shrink() {
        while(this->size() && this->back() == Mint(0))
            this->pop_back();
    }

  public:
    template <typename T> FormalPowerSeries(vector<T> v) {
        *this = FormalPowerSeries(v.size());
        for(int i = 0; i < v.size(); i++)
            (*this)[i] = Mint(v[i]);
    }

    F operator*(const Mint &g) const { return F(*this) *= g; }
    F &operator*=(const Mint &g) {
        for(auto &e : *this)
            e *= g;
        return *this;
    }
    F operator*(const F &g) const { return F(*this) *= g; }
    F &operator*=(const F &g) {
        if((*this).empty() || g.empty()) {
            this->clear();
            return *this;
        }
        if(get_conv() == nullptr) {
            assert(false);
        } else {
            return *this = get_conv()(*this, g);
        }
    }
    F operator/(const Mint &g) const { return F(*this) /= g; }
    F &operator/=(const Mint &g) {
        assert(g != Mint(0));
        return (*this) *= g.inv();
    }
    F operator+(const F &g) const { return F(*this) += g; }
    F &operator+=(const F &g) {
        if(g.size() > this->size()) {
            this->resize(g.size());
        }
        for(int i = 0; i < this->size(); i++)
            (*this)[i] += g[i];
        return *this;
    }
    F operator-(const F &g) const { return F(*this) -= g; }
    F &operator-=(const F &g) {
        if(g.size() > this->size()) {
            this->resize(g.size());
        }
        for(int i = 0; i < this->size(); i++)
            (*this)[i] -= g[i];
        return *this;
    }
    F operator-() const {
        F res(*this);
        for(auto &e : *this)
            e = -e;
        return res;
    }
    F &operator<<=(const int d) {
        int n = (*this).size();
        (*this).insert((*this).begin(), d, 0);
        (*this).resize(n);
        return *this;
    }
    F &operator>>=(const int d) {
        int n = (*this).size();
        (*this).erase((*this).begin(), (*this).begin() + min(n, d));
        (*this).resize(n);
        return *this;
    }
    F &operator=(const F &g) {
        (*this).clear();
        (*this).resize(g.size());
        for(int i = 0; i < g.size(); i++)
            (*this)[i] = g[i];
        return *this;
    }
    template <typename T> F &operator=(const vector<T> &g) {
        (*this).clear();
        (*this).resize(g.size());
        for(int i = 0; i < g.size(); i++)
            (*this)[i] = Mint(g[i]);
        return *this;
    }

    F pre(int sz) const {
        return F((*this).begin(),
                 (*this).begin() + min(sz, (int)(*this).size()));
    }

    F inv(int d = -1) {
        int n = (*this).size();
        assert(n != 0 && (*this)[0] != Mint(0));
        if(d == -1)
            d = n;
        assert(d >= 0);
        F ret({Mint(1) / (*this)[0]});
        for(int i = 1; i < d; i <<= 1) {
            ret = (ret * 2 - ret * ret * pre(i << 1)).pre(i << 1);
        }
        return ret.pre(d);
    }

    // multiply and divide (1+cz^d)
    void multiply(const int d, const Mint c) {
        int n = this->size();
        if(c == Mint(1))
            for(int i = n - d; i >= 0; i--)
                (*this)[i + d] += (*this)[i];
        else if(c == Mint(-1))
            for(int i = n - d; i >= 0; i--)
                (*this)[i + d] -= (*this)[i];
        else
            for(int i = n - d; i >= 0; i--)
                (*this)[i + d] += (*this)[i] * c;
    }
    void divide(const int d, const Mint c) {
        int n = this->size();
        if(c == Mint(1))
            for(int i = 0; i < n - d; i++)
                (*this)[i + d] -= (*this)[i];
        else if(c == Mint(-1))
            for(int i = 0; i < n - d; i++)
                (*this)[i + d] += (*this)[i];
        else
            for(int i = 0; i < n - d; i++)
                (*this)[i + d] -= (*this)[i] * c;
    }
};
