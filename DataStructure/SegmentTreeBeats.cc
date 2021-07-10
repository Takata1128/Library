#include <bits/stdc++.h>
using namespace std;

template <typename T> class SegmentTreeBeats {
    const T inf = numeric_limits<T>::max();
    int n, n2;
    vector<T> f_max, s_max, max_n;
    vector<T> f_min, s_min, min_n;
    vector<T> sum;
    vector<T> len, ladd, lval;

    void update_node_max(int k, T x) {
        sum[k] += (x - f_max[k]) * max_n[k];
        if(f_max[k] == f_min[k]) {
            f_max[k] = f_min[k] = x;
        } else if(f_max[k] == s_min[k]) {
            f_max[k] = s_min[k] = x;
        } else {
            f_max[k] = x;
        }
        if(lval[k] != inf && x < lval[k])
            lval[k] = x;
    }
    void update_node_min(int k, T x) {
        sum[k] += (x - f_min[k]) * min_n[k];
        if(f_max[k] == f_min[k]) {
            f_max[k] = f_min[k] = x;
        } else if(s_max[k] == f_min[k]) {
            s_max[k] = f_min[k] = x;
        } else {
            f_min[k] = x;
        }
        if(lval[k] != inf && lval[k] < x)
            lval[k] = x;
    }

    void add_all(int k, T x) {
        f_max[k] += x;
        if(s_max[k] != -inf)
            s_max[k] += x;
        f_min[k] += x;
        if(s_min[k] != inf)
            s_min[k] += x;

        sum[k] += len[k] * x;
        if(lval[k] != inf) {
            lval[k] += x;
        } else
            ladd[k] += x;
    }

    void update_all(int k, T x) {
        f_max[k] = x;
        s_max[k] = -inf;
        f_min[k] = x;
        s_min[k] = inf;
        max_n[k] = min_n[k] = len[k];
        sum[k] = x * len[k];
        lval[k] = x;
        ladd[k] = 0;
    }

    void push(int k) {
        if(n2 - 1 <= k)
            return;

        if(lval[k] != inf) {
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
        if(f_max[k] < f_max[2 * k + 1])
            update_node_max(2 * k + 1, f_max[k]);
        if(f_max[k] < f_max[2 * k + 2])
            update_node_max(2 * k + 2, f_max[k]);

        if(f_min[2 * k + 1] < f_min[k])
            update_node_min(2 * k + 1, f_min[k]);
        if(f_min[2 * k + 2] < f_min[k])
            update_node_min(2 * k + 2, f_min[k]);
    }

    void update(int k) {
        if(n2 - 1 <= k)
            return;
        sum[k] = sum[2 * k + 1] + sum[2 * k + 2];
        if(f_max[2 * k + 1] < f_max[2 * k + 2]) {
            f_max[k] = f_max[2 * k + 2];
            max_n[k] = max_n[2 * k + 2];
            s_max[k] = max(f_max[2 * k + 1], s_max[2 * k + 2]);
        } else if(f_max[2 * k + 1] > f_max[2 * k + 2]) {
            f_max[k] = f_max[2 * k + 1];
            max_n[k] = max_n[2 * k + 1];
            s_max[k] = max(s_max[2 * k + 1], f_max[2 * k + 2]);
        } else {
            f_max[k] = f_max[2 * k + 1];
            max_n[k] = max_n[2 * k + 1] + max_n[2 * k + 2];
            s_max[k] = max(s_max[2 * k + 1], s_max[2 * k + 2]);
        }
        if(f_min[2 * k + 1] < f_min[2 * k + 2]) {
            f_min[k] = f_min[2 * k + 1];
            min_n[k] = min_n[2 * k + 1];
            s_min[k] = min(s_min[2 * k + 1], f_min[2 * k + 2]);
        } else if(f_min[2 * k + 1] > f_min[2 * k + 2]) {
            f_min[k] = f_min[2 * k + 2];
            min_n[k] = min_n[2 * k + 2];
            s_min[k] = min(f_min[2 * k + 1], s_min[2 * k + 2]);
        } else {
            f_min[k] = f_min[2 * k + 1];
            min_n[k] = min_n[2 * k + 1] + min_n[2 * k + 2];
            s_min[k] = min(s_min[2 * k + 1], s_min[2 * k + 2]);
        }
    }

    void _update_min(T x, int a, int b, int k, int l, int r) {
        if(b <= l || r <= a || f_max[k] <= x)
            return;
        if(a <= l && r <= b && s_max[k] < x) {
            update_node_max(k, x);
            return;
        }
        push(k);
        _update_min(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_min(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }
    void _update_max(T x, int a, int b, int k, int l, int r) {
        if(b <= l || r <= a || x <= f_min[k])
            return;
        if(a <= l && r <= b && x < s_min[k]) {
            update_node_min(k, x);
            return;
        }
        push(k);
        _update_max(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_max(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _add_val(T x, int a, int b, int k, int l, int r) {
        if(b <= l || r <= a)
            return;
        if(a <= l && r <= b) {
            add_all(k, x);
            return;
        }
        push(k);
        _add_val(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _add_val(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _update_val(T x, int a, int b, int k, int l, int r) {
        if(b <= l || r <= a)
            return;
        if(a <= l && r <= b) {
            update_all(k, x);
            return;
        }
        push(k);
        _update_val(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_val(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }
    T _query_max(int a, int b, int k, int l, int r) {
        if(b <= l || r <= a)
            return -inf;
        if(a <= l && r <= b) {
            return f_max[k];
        }
        push(k);
        T lv = _query_max(a, b, 2 * k + 1, l, (l + r) / 2);
        T rv = _query_max(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(lv, rv);
    }
    T _query_min(int a, int b, int k, int l, int r) {
        if(b <= l || r <= a)
            return inf;
        if(a <= l && r <= b) {
            return f_min[k];
        }
        push(k);
        T lv = _query_min(a, b, 2 * k + 1, l, (l + r) / 2);
        T rv = _query_min(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(lv, rv);
    }
    T _query_sum(int a, int b, int k, int l, int r) {
        if(b <= l || r <= a)
            return 0;
        if(a <= l && r <= b) {
            return sum[k];
        }
        push(k);
        T lv = _query_sum(a, b, 2 * k + 1, l, (l + r) / 2);
        T rv = _query_sum(a, b, 2 * k + 2, (l + r) / 2, r);
        return lv + rv;
    }

  public:
    SegmentTreeBeats(int n) : SegmentTreeBeats(vector<T>(n)) {}
    SegmentTreeBeats(const vector<T> &a) : n(a.size()) {
        n2 = 1;
        while(n2 < n)
            n2 <<= 1;
        f_max.assign(2 * n2, -inf);
        s_max.assign(2 * n2, -inf);
        max_n.resize(2 * n2);
        f_min.assign(2 * n2, inf);
        s_min.assign(2 * n2, inf);
        min_n.resize(2 * n2);
        sum.resize(2 * n2);
        len.resize(2 * n2);
        ladd.resize(2 * n2);
        lval.assign(2 * n2, inf);
        len[0] = n2;
        for(int i = 0; i < n2 - 1; i++)
            len[2 * i + 1] = len[2 * i + 2] = (len[i] >> 1);
        for(int i = 0; i < n; i++) {
            f_max[n2 - 1 + i] = f_min[n2 - 1 + i] = sum[n2 - 1 + i] = a[i];
            max_n[n2 - 1 + i] = min_n[n2 - 1 + i] = 1;
        }
        for(int i = n2 - 2; i >= 0; i--) {
            update(i);
        }
    }

    T at(int k) { return query_sum(k, k + 1); };

    void update_min(int a, int b, T x) { _update_min(x, a, b, 0, 0, n2); }
    void update_max(int a, int b, T x) { _update_max(x, a, b, 0, 0, n2); }
    void add_val(int a, int b, T x) { _add_val(x, a, b, 0, 0, n2); }
    void update_val(int a, int b, T x) { _update_val(x, a, b, 0, 0, n2); }
    T query_max(int a, int b) { return _query_max(a, b, 0, 0, n2); }
    T query_min(int a, int b) { return _query_min(a, b, 0, 0, n2); }
    T query_sum(int a, int b) { return _query_sum(a, b, 0, 0, n2); }
};
