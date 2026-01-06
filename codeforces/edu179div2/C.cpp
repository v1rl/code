#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

// 贪心：一连串相等数的最左和最优
// 暴力：找所有连续相等子串

void solve() {
	int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    i64 ans = inf;

    i64 lst = -1;
    for(int i = 1; i <= n; i ++) {
        if(a[i] != a[i - 1]) {
            if(lst != -1) {
                // 乘法时注意越界问题
                ans = min(ans, lst + 1ll * (n - i + 1) * a[i - 1]);
            }
            lst = 1ll * (i - 1) * a[i];
        }
    }
    // 结尾单独处理
    ans = min(ans, lst);

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}