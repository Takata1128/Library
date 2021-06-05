#include <bits/stdc++.h>
using namespace std;

template <typename T> class GaussianElimination {
    vector<vector<T>> mat;

  public:
    GaussianElimination(vector<vector<int>> mat(n, vector<T>(m))) : mat(mat) {}

    int sweep(bool is_extended = false) {
        int rank = 0;
        for(int col = 0; col < n; col++) {
            if(is_extended && col == n - 1)
                break;
            int pivot = -1;
            for(int row = rank; row < m; row++) {
                if(mat[row][col] != 0) {
                    pivot = row;
                    break;
                }
            }
            if(pivot == -1)
                continue;
            swap(mat[pivot], mat[rank]);
            for(int col2 = 0; col2 < n; col2++) {
                mat[rank][col2] = mat[rank][col2] / mat[rank][col];
            }
            for(int row = 0; row < m; row++) {
                if(row != rank && mat[row][col]) {
                    for(int col2 = 0; col2 < n; col2++) {
                        mat[row][col2] -= mat[rank][col2] / mat[row][col];
                    }
                }
            }
        }
    }
};