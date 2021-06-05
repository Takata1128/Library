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
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include \"../DataStructure/SegmentTreeBeats.cc\"\n#include \"../Others/template.cc\"\
    \n\nint main() {\n    INT(n, q);\n    VEC(ll, a, n);\n    SegmentTreeBeats<ll>\
    \ beats(a);\n    rep(i, q) {\n        INT(t);\n        if(t == 0) {\n        \
    \    LL(l, r, x);\n            beats.update_min(l, r, x);\n        } else if(t\
    \ == 1) {\n            LL(l, r, x);\n            beats.update_max(l, r, x);\n\
    \        } else if(t == 2) {\n            LL(l, r, x);\n            beats.add_val(l,\
    \ r, x);\n        } else {\n            INT(l, r);\n            write(beats.query_sum(l,\
    \ r));\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/range_chmin_chmax_add_range_sum.test.cpp
- /verify/verify/range_chmin_chmax_add_range_sum.test.cpp.html
title: verify/range_chmin_chmax_add_range_sum.test.cpp
---
