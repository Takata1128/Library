#include <bits/stdc++.h>
using namespace std;

// template <typename T> class Elimination {
//     int h, w;
//     vector<vector<T>> mat;

//   public:
//     Elimination(vector<vector<T>> mat)
//         : mat(mat), h(mat.size()), w(mat[0].size()) {}

//     int sweep(bool is_extended = false) {
//         int rank = 0;
//         for(int col = 0; col < w; col++) {
//             if(is_extended && col == w - 1)
//                 break;
//             int pivot = -1;
//             for(int row = rank; row < h; row++) {
//                 if(mat[row][col] != 0) {
//                     pivot = row;
//                     break;
//                 }
//             }
//             if(pivot == -1)
//                 continue;
//             swap(mat[pivot], mat[rank]);

//             auto f = mat[rank][col];
//             for(int col2 = 0; col2 < w; col2++) {
//                 mat[rank][col2] = mat[rank][col2] / f;
//             }

//             for(int row = 0; row < h; row++) {
//                 if(row != rank && mat[row][col]) {
//                     auto f = mat[row][col];
//                     for(int col2 = 0; col2 < w; col2++) {
//                         mat[row][col2] -= mat[rank][col2] * f;
//                     }
//                 }
//             }
//             ++rank;
//         }
//         return rank;
//     }
// };

class BitElimination {
  public:
    static int sweep(vector<vector<int>> &A, bool is_extended = false) {
        int h = A.size(), w = A[0].size();
        int rank = 0;
        for(int col = 0; col < w; col++) {
            if(is_extended && col == w - 1)
                break;
            int pivot = -1;
            for(int row = rank; row < h; row++) {
                if(A[row][col] != 0) {
                    pivot = row;
                    break;
                }
            }
            if(pivot == -1)
                continue;
            swap(A[pivot], A[rank]);
            for(int row = 0; row < h; row++) {
                if(row != rank && A[row][col]) {
                    for(int col2 = 0; col2 < w; col2++) {
                        A[row][col2] ^= A[rank][col2];
                    }
                }
            }
            ++rank;
        }
        return rank;
    }

    // solve Ax = b
    static pair<vector<int>, int> solve(vector<vector<int>> A, vector<int> b,
                                        bool is_extended = false) {
        int h = A.size(), w = A[0].size();
        assert(b.size() == h);
        vector M = vector(h, vector<int>(w + 1, 0));
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                M[i][j] = A[i][j];
            }
            M[i][w] = b[i];
        }
        vector<int> res;
        int rank = sweep(M, true);
        for(int row = rank; row < h; row++)
            if(M[row][w])
                return {res, -1};

        res.assign(w, 0);
        for(int i = 0; i < rank; i++)
            res[i] = M[i][w];
        return {res, rank};
    }
};