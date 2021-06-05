---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Others/template.cc:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n#include \"../Math/ConvolutionNTT.cc\"\n#include \"../Math/FormalPowerSeries.cc\"\
    \n#include \"../Math/ModInt.cc\"\n#include \"../Others/template.cc\"\n\nint main()\
    \ {\n    INT(n);\n    VEC(int, a, n);\n    using mint = ModInt<998244353>;\n \
    \   auto f = [&](vector<mint> a, vector<mint> b) {\n        Convolution<mint>\
    \ ntt;\n        return ntt.convolution(a, b);\n    };\n    FormalPowerSeries<mint>\
    \ fps(a);\n    FormalPowerSeries<mint>::set_conv(f);\n    auto v = fps.inv();\n\
    \    write(vector<mint>(v));\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/inv_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/inv_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/verify/inv_of_formal_power_series.test.cpp
- /verify/verify/inv_of_formal_power_series.test.cpp.html
title: verify/inv_of_formal_power_series.test.cpp
---
