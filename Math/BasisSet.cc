#include <bits/stdc++.h>

class BasisSet {
    std::vector<int64_t> v;

  public:
    BasisSet(){};

    std::vector<int64_t> get_v() { return v; }
    size_t size() { return v.size(); }

    bool contain(int64_t num) {
        for(auto e : v) {
            if((e & (-e)) & num) { // 最下位bitが立っているならば
                num ^= e;
            }
        }
        return num == 0;
    }

    bool insert(int64_t num) {
        if(contain(num)) return false;
        v.push_back(num);
        return true;
    }
};