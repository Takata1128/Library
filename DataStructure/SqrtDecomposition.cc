#include <bits/stdc++.h>

template <typename T> class SqrtDecomposition {
    class bucket {
        int l, r;
        std::vector<T> v;
        T min_val;
        T add_val;

        void update_all(T x) { add_val += x; }

        T calc_all() { return min_val + add_val; }

        void reflect_update() {
            for(auto &i : v)
                i += add_val;
            add_val = 0;
        }

        void reflect_calc() {
            min_val = std::numeric_limits<T>::max();
            for(auto &i : v) {
                min_val = min(min_val, i);
            }
        }

        void update_partial(int l, int r, T x) {
            reflect_update();
            for(int i = l; i < r; i++) {
                v[i] += x;
            }
            reflect_calc();
        }

        T calc_partial(int l, int r) {
            reflect_update();
            reflect_calc();
            T res = std::numeric_limits<T>::max();
            for(int i = l; i < r; i++) {
                res = std::min(res, v[i]);
            }
            return res;
        }

      public:
        bucket(const std::vector<T> &a, int l, int r) : l(l), r(r) {
            v = std::vector<T>(r - l);
            for(int i = 0; i < r - l; ++i)
                v[i] = a[i + l];
        }
        void update(int s, int t, T x) {
            if(r <= s || t <= l)
                return;
            else if(s <= l && r <= t)
                update_all(x);
            else
                update_partial(std::max(s, l) - l, std::min(t, r) - l, x);
        }
        T calc(int s, int t) {
            if(r <= s || t <= l)
                return;
            else if(s <= l && r <= t)
                return calc_all();
            else
                return calc_partial(std::max(s, l) - l, std::min(t, r) - l);
        }
    };

    std::vector<bucket> v;

  public:
    SqrtDecomposition(const std::vector<T> &a, int bucket_size) {
        v = std::vector<bucket>();
        for(int i = 0; i < (int)a.size(); i += bucket_size) {
            v.emplace_back(a, i, std::min(i + bucket_size, (int)a.size()));
        }
    }

    void update(int l, int r, T x) {
        for(auto &i : v) {
            i.update(l, r, x);
        }
    }

    T calc(int l, int r) {
        T res = std::numeric_limits<T>::max();
        for(auto &i : v) {
            res = std::min(res, i.calc(l, r));
        }
        return res;
    }
};