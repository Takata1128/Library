#include <bits/stdc++.h>

template <class T> T determinant(std::vector<std::vector<T>> &mat) {
    int n = mat.size();
    assert(n == mat[0].size());
    T ret = 1;
    for(int i = 0; i < n; i++) {
        if(mat[i][i] == 0) {
            T t;
            for(t = i + 1; t < n; t++) {
                if(mat[t][i] != 0)
                    break;
            }
            if(t < n) {
                for(int k = 0; k < n; k++) {
                    std::swap(mat[t][k], mat[i][k]);
                }
                ret = -ret;
            }
        }
        for(int j = i + 1; j < n; j++) {
            T buf = mat[j][i] / mat[i][i];
            for(int k = 0; k < n; k++) {
                mat[j][k] -= mat[i][k] * buf;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        ret *= mat[i][i];
    }
    return ret;
}