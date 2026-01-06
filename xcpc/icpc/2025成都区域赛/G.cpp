#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
m次固定变成k
确定不会占用k的倍数
k的倍数有多少个
k单独删除，它的倍数成对删除
*/

void solve() {
    i64 n, k, m;
    cin >> n >> k >> m;
    i64 t = n / k;
    i64 ls = n - t;
    i64 ans = 0;
    i64 bg = m - ls;
    if(bg > 0) {
        t -= bg;
    }
    ans = t ? 1 + (t - 1) / 2 : 0;
    ans += m;
    cout << ans << '\n';
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