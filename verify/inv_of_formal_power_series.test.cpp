#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
#include "./template.cc"
#include "../Math/ConvolutionNTT.cc"
#include "../Math/FormalPowerSeries.cc"
#include "../Math/ModInt.cc"

int main() {
    INT(n);
    VEC(int, a, n);
    using mint = ModInt<998244353>;
    auto f = [&](vector<mint> a, vector<mint> b) {
        Convolution<mint> ntt;
        return ntt.convolution(a, b);
    };
    FormalPowerSeries<mint> fps(a);
    FormalPowerSeries<mint>::set_conv(f);
    auto v = fps.inv();
    write(vector<mint>(v));
}