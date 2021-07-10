#include <bits/stdc++.h>
using namespace std;

template <class T> struct Matrix {
    vector<vector<T>> A;
    Matrix() {}
    Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}
    Matrix(size_t n) : A(n, vector<T>(n, 0)) {}
    Matrix(initializer_list<initializer_list<T>> init)
        : A(init.begin(), init.end()){};

    constexpr size_t height() const { return A.size(); }

    constexpr size_t width() const { return A[0].size(); }

    inline constexpr vector<T> &operator[](int k) { return A.at(k); }
    inline constexpr const vector<T> &operator[](int k) const {
        return A.at(k);
    }

    static Matrix I(size_t n) {
        Matrix mat(n);
        for(int i = 0; i < n; i++)
            mat[i][i] = 1;
        return mat;
    }

    constexpr Matrix &operator+=(const Matrix &B) {
        size_t h = height(), w = width();
        assert(h == B.height() && w == B.width);
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return *this;
    }

    constexpr Matrix &operator-=(const Matrix &B) {
        size_t h = height(), w = width();
        assert(h == B.height() && w == B.width);
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return *this;
    }

    constexpr Matrix &operator*=(const Matrix &B) {
        size_t h = height(), w = B.width(), p = width();
        assert(p == B.height());
        vector<vector<T>> C(h, vector<T>(w, 0));
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                for(int k = 0; k < p; k++) {
                    C[i][j] += (*this)[i][k] * B[k][j];
                }
            }
        }
        A.swap(C);
        return *this;
    }

    constexpr Matrix &operator^=(long long k) {
        Matrix B = Matrix::I(height());
        while(k > 0) {
            if(k & 1)
                B *= *this;
            *this *= *this;
            k >>= 1LL;
        }
        A.swap(B.A);
        return *this;
    }

    constexpr Matrix operator+(const Matrix &B) const {
        return (Matrix(*this) += B);
    }
    constexpr Matrix operator-(const Matrix &B) const {
        return (Matrix(*this) -= B);
    }
    constexpr Matrix operator*(const Matrix &B) const {
        return (Matrix(*this) *= B);
    }
    constexpr Matrix operator^(const long long k) const {
        return (Matrix(*this) ^= k);
    }
    constexpr bool operator==(const Matrix &B) const {
        return ((*this).A == B.A);
    }

    constexpr friend ostream &operator<<(ostream &os, const Matrix &p) {
        size_t h = p.height(), w = p.width();
        for(int i = 0; i < h; i++) {
            os << "[";
            for(int j = 0; j < w; j++) {
                os << p[i][j] << (j + 1 == w ? "]\n" : ",");
            }
        }
        return os;
    }
};