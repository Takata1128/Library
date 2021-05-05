#include <bits/stdc++.h>
using namespace std;
// SWAG
// https://yukicoder.me/problems/no/1036
template <typename SemiGroup> class SlidingWindowAggregation {
    using F = function<SemiGroup(SemiGroup, SemiGroup)>;

  private:
    const F f;
    stack<pair<SemiGroup, SemiGroup>> front, back;

  public:
    SlidingWindowAggregation(F f) : f(f) {}

    bool empty() { return front.empty() && back.empty(); }

    size_t size() { return front.size() + back.size(); }

    SemiGroup fold_all() {
        assert(!this->empty());
        if(front.empty()) {
            return back.top().second;
        } else if(back.empty()) {
            return front.top().second;
        } else {
            return f(front.top().second, back.top().second);
        }
    }

    void push(const SemiGroup &x) {
        if(front.empty()) {
            front.emplace(x, x);
        } else {
            front.emplace(x, f(front.top().second, x));
        }
    }

    void pop() {
        if(back.empty()) {
            back.emplace(front.top().first, front.top().first);
            front.pop();
            while(!front.empty()) {
                back.emplace(front.top().first,
                             f(front.top().first, back.top().second));
                front.pop();
            }
        }
        back.pop();
    }
};