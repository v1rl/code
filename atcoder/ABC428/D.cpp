#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
若已知数的取值范围（连续），则可以通过区间左右端点开跟相减的到答案
但本题采用了数位拼接的方式，这样得到的区间并不是连续的，而是多个间断区间的交集
于是我们考虑能不能得到所有的间断区间
不难发现，拼接的前段一定是C，后段 p 是一个区间
当后段的数位(digit)个数相同时，连续的p就对应着一个连续的答案区间
不过，因为后段的数位不是x而是C+x，所以我们需要做一些转换

x -- [10^(i - 1) - C, 10^i - 1 - C]
x -- [1, D]
-->
l -- max[1, 10^(i - 1) - C]
r -- min[10^i - 1 - C, D]

C * 10^i + C + [l, r];
*/

const i64 inf = 1e18;
i64 p[15];

void solve() {
    i64 c, d;
    cin >> c >> d;
    i64 ans = 0;
    for(int i = 1; i <= 10; i ++) {
        i64 l = max(1ll, p[i - 1] - c);
        i64 r = min(d, p[i] - c - 1);
        if(l > r) {
            continue;
        }
        i64 base = c * p[i] + c;
        // 需要注意：sqrt可能会出现精度不足的情况，大数最好用sqrtl
        ans += (i64)sqrtl(base + r) - (i64)sqrtl(base + l - 1);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    p[0] = 1;
    for(int i = 1; i <= 10; i ++) {
        p[i] = p[i - 1] * 10;
    }

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
