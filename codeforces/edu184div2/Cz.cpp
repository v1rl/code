#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
注意到：(r - l + 1) * (r + 1)的值其实就是2l + 2(l + 1) + ... + 2(r - 1) + 2r
所以将连续区间变成(l + r)其实就是将连续区间的a[i]值变成i * 2，我们令b[i] = i * 2
让b数组减去a，答案即为数组b的最大连续子段和 + sum(a)

或者，对式子进行推导，得到形如f(r) - f(l) / g(l)的f函数 / f函数和g函数
于是，我们可以通过前缀min / max O(n)枚举得到结果
*/

const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<i64> pmn(n + 1, inf);
    vector<i64> psum(n + 1);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        psum[i + 1] = psum[i] + a[i];
        pmn[i + 1] = min(pmn[i], 1ll * (i + 1) * (i + 1) - (i + 1) - psum[i]);
    }

    i64 ans = 0;
    for(int i = 0; i < n; i ++) {
        ans = max(1ll * (i + 1) * (i + 1) + (i + 1) - psum[i + 1] - pmn[i + 1], ans);
    }
    cout << psum[n] + ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
