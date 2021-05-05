#include <bits/stdc++.h>

/**
 * @brief Manage interval by set. Note that interval is harf-open [l,r).
 *
 * @tparam T Universal set.
 */
template <typename T> class IntervalSet : std::set<std::pair<T, T>> {
  private:
    const T INF = std::numeric_limits<T>::max() - 65;
    bool isMergeAdjacent;

  public:
    /**
     * @brief Construct a new Interval Set object
     *
     * @param f If merge adjacent interval
     */
    IntervalSet(bool f) : isMergeAdjacent(f) {
        this->emplace(-INF, -INF + 1);
        this->emplace(INF, INF + 1);
    }
    /**
     * @brief Get a interval to which p belongs.
     *
     * @param p Element in T
     * @return Iterator of interval to which p belongs. If not exists, return
     * iterator end().
     */
    auto get(T p) const {
        auto it = this->upper_bound({p, INF});
        if(it == this->begin() || (--it)->second < p)
            return this->end();
        return it;
    }
    /**
     * @brief Insert interval [l,r).
     *
     * @param l Left end of interval.
     * @param r Right end of interval.
     */
    void insert(T l, T r) {
        if(l >= r)
            return;
        auto it = std::prev(this->lower_bound({l, r}));
        if(it->first <= l && l + !isMergeAdjacent <= it->second) {
            l = std::min(l, it->first);
            r = std::max(r, it->second);
            this->erase(it);
        }
        it = this->lower_bound({l, r});
        while(1) {
            if(l <= it->first && it->first <= r) {
                r = std::max(r, it->second);
                it = this->erase(it);
            } else
                break;
        }
        this->emplace(l, r);
    }

    /**
     * @brief Insert element
     *
     * @param p Element in T
     */
    void insert(T p) { insert(p, p + 1); }

    T remove(const T l, const T r) {
        assert(l < r);
        auto itr = std::prev(this->lower_bound({l + 1, -INF}));
        if(itr->first <= l and r <= itr->second) {
            if(itr->first < l)
                this->emplace(itr->first, l);
            if(r < itr->second)
                this->emplace(r, itr->second);
            this->erase(itr);
            return r - l;
        }

        T ret = T(0);
        if(itr->first <= l and l < itr->second) {
            ret += itr->second - l;
            if(itr->first < l)
                this->emplace(itr->first, l);
            itr = this->erase(itr);
        } else
            itr = next(itr);
        while(itr->second <= r) {
            ret += itr->second - itr->first;
            itr = this->erase(itr);
        }
        if(itr->first < r) {
            ret += r - itr->first;
            this->emplace(r, itr->second);
            this->erase(itr);
        }
        return ret;
    }

    /**
     * @brief
     *
     * @param x
     * @return T
     */
    T remove(const T x) { return remove(x, x + 1); }

    /**
     * @brief Judge if p and q are in same interval.
     *
     * @param p Element in T.
     * @param q Element in T.
     * @return If p and q are in same interval.
     */
    bool same(T p, T q) const {
        auto it = get(p);
        return it != this->end() && it->first <= q && q <= it->second;
    }

    /**
     * @brief Count the number of elements in intervals.
     *
     * @return T Summation of the number of elements in intervals.
     */
    T sumAll() const {
        T ret = 0;
        for(auto it = this->begin(), e = this->end(); it != e; ++it) {
            if(std::abs(it->first) == INF)
                continue;
            ret += it->second - it->first;
        }
        return ret;
    }

    /**
     * @brief get mex in [x,)
     *
     * @param x
     * @return int
     */
    int mex(const T x = 0) {
        auto itr = std::prev(this->lower_bound({x + 1, -INF}));
        if(itr->first <= x and x < itr->second)
            return itr->second;
        else
            return x;
    }

    /**
     * @brief Show contents of set.
     *
     */
    void dump() {
        for(auto it = this->begin(), e = this->end(); it != e; ++it) {
            if(std::abs(it->first) == INF)
                continue;
            std::cout << "[" << it->first << "," << it->second
                      << (it == std::prev(std::prev(e)) ? ")" : "), ");
        }
        std::cout << std::endl;
    }
};