#include <bits/stdc++.h>

/**
 * @brief 座標圧縮
 *
 * @tparam T データ型
 * @param X 圧縮する数列 副作用により圧縮後の値が入る
 * @return std::vector<T> ソートして重複を除去した元数列
 */
template <typename T> std::vector<T> compress(std::vector<T> &X) {
    std::vector<T> vals = X;
    std::sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for(int i = 0; i < X.size(); i++) {
        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
    return vals;
}

template <typename T>
std::vector<T> compress2P(std::vector<T> &X1, std::vector<T> &X2) {
    vector<T> vals;
    for(auto x : X1) {
        vals.pb(x);
        // vals.pb(x+1);
    }
    for(auto x : X2) {
        vals.pb(x);
        // vals.pb(x+1);
    }
    std::sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for(int i = 0; i < X1.size(); i++) {
        X1[i] = lower_bound(vals.begin(), vals.end(), X1[i]) - vals.begin();
        X2[i] = lower_bound(vals.begin(), vals.end(), X2[i]) - vals.begin();
    }
    return vals;
}