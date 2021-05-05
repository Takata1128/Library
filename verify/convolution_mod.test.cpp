#include "../Math/Convolution.cc"
#include "../Math/ModInt.cc"
#include "../Others/template.cc"

int main() {
    INT(n, m);
    VEC(int, a, n);
    VEC(int, b, m);
    using mint = ModInt<998244353>;
    Convolution<mint> ntt;
    auto ans = ntt.convolution(a, b);
    for(int i = 0; i < n + m - 1; i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
}
