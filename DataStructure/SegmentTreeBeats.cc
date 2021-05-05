#include <bits/stdc++.h>
using namespace std;

template <typename T> class SegmentTreeBeats {
    const T inf = 1e18;
    int n, n0;
    vector<T> max_v, smax_v, max_c;
    vector<T> min_v, smin_v, min_c;
    vector<T> sum;
    vector<T> len, ladd, lval;

    void update_node_max(int k, T x) {
        sum[k] += (x - max_v[k]) * max_c[k];
        if(max_v[k] == min_v[k]) {
            max_v[k] = min_v[k] = x;
        } else if(max_v[k] == smin_v[k]) {
            max_v[k] = smin_v[k] = x;
        } else {
            max_v[k] = x;
        }
        if(lval[k] != inf && x < lval[k])
            lval[k] = x;
    }
    void update_node_min(int k, T x) {
        sum[k] += (x - min_v[k]) * min_c[k];
        if(max_v[k] == min_v[k]) {
            max_v[k] = min_v[k] = x;
        } else if(max_v[k] == smin_v[k]) {
            min_v[k] = smax_v[k] = x;
        } else {
            min_v[k] = x;
        }
        if(lval[k] != inf && lval[k] < x)
            lval[k] = x;
    }
    void push(int k) {
        if(n0 - 1 <= k)
            return;
        if(lval[l] != inf) {
            update_all(2 * k + 1, lval[k]);
            update_all(2 * k + 2, lval[k]);
            lval[k] = inf;
            return;
        }
        if(ladd[k] != 0) {
            add_all(2 * k + 1, ladd[k]);
            add_all(2 * k + 2, ladd[k]);
            ladd[k] = 0;
        }
        if(max_v[k] < max_v[2 * k + 1])
            update_node_max(2 * k + 1, max_v[k]);
        if(max_v[k] < max_v[2 * k + 2])
            update_node_max(2 * k + 2, max_v[k]);
        if(min_v[2 * k + 1] < min_v[k])
            update_node_min(2 * k + 1, min_v[k]);
        if(max_v[2 * k + 2] < min_v[k])
            update_node_min(2 * k + 2, min_v[k]);
    }

    void update(int k) {
        sum[k] = sum[2 * k + 1] + sum[2 * k + 2];
        if(max_v[2 * k + 1] < max_v[2 * k + 2]) {
            max_v[k] = max_v[2 * k + 2];
            max_c[k] = max_c[2 * k + 2];
            smax_v[k] = max(max_v[2 * k + 1], smax_v[2 * k + 2]);
        } else if(max_v[2 * k + 1] > max_v[2 * k + 2]) {

            max_v[k] = max_v[2 * k + 1];
            max_c[k] = max_c[2 * k + 1];
            smax_v[k] = max(smax_v[2 * k + 1], max_v[2 * k + 2]);
        } else {
            max_v[k] = max_v[2 * k + 1];
            max_c[k] = max_c[2 * k + 1] + max_c[2 * k + 2];
            smax_v[k] = max(smax_v[2 * k + 1], smax_v[2 * k + 2]);
        }
        if(min_v[2 * k + 1] < min_v[2 * k + 2]) {
            min_v[k] = min_v[2 * k + 2];
            min_c[k] = min_c[2 * k + 2];
            smin_v[k] = min(min_v[2 * k + 1], smin_v[2 * k + 2]);
        } else if(min_v[2 * k + 1] > min_v[2 * k + 2]) {
            min_v[k] = min_v[2 * k + 1];
            min_c[k] = min_c[2 * k + 1];
            smin_v[k] = min(smin_v[2 * k + 1], min_v[2 * k + 2]);
        } else {
            min_v[k] = min_v[2 * k + 1];
            min_c[k] = min_c[2 * k + 1] + min_c[2 * k + 2];
            smin_v[k] = min(smin_v[2 * k + 1], smin_v[2 * k + 2]);
        }
    }

    void _update_min(T x, int a, int b, int k, int l, int r) {
        if(b <= l || r <= a || max_v[k] <= x)
            return;
        if(a <= l && r <= b && smax_v[k] < x) {
            update_node_max(k, x);
            return;
        }
        push(k);
        _update_min(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_min(x, a, b, 2 * k + 2, l, (l + r) / 2);
        update(k);
    }
    void _update_max(T x, int a, int b, int k, int l, int r) {
        if(b <= l || r <= a || max_v[k] <= x)
            return;
        if(a <= l && r <= b && smax_v[k] < x) {
            update_node_min(k, x);
            return;
        }
        push(k);
        _update_max(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_max(x, a, b, 2 * k + 2, l, (l + r) / 2);
        update(k);
    }
    void add_all(int k, T x) {
        max_v[k] += x;
        if(smax_v[k] != -inf)
            smax_v[k] += x;
        min_v[k] += x;
        if(smin_v[k] != inf)
            smin_v[k] += x;
        if(lval[k] != inf) {
            lval[k] += x;
        } else
            ladd[k] += x;
    }
    void update_all(int k, T x) {
        max_v[k] = x;
        smax_v[k] = -inf;
        min_v[k] = x;
        smin_v[k] = inf;
        max_c[k] = min_c[k] = len[k];
        sum[k] = x * len[k];
        lval[k] = x;
        ladd[k] = 0;
    }
    void _add_val(T x, int a, int b, int k, int l, int r) {}
};