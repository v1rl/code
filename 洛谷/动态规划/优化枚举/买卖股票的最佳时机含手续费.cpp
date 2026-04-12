#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

const int inf = 1e9 + 7;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    /*
    vector<int> f(n + 1);
    vector<int> pmx(n + 1, -inf);
    for(int i = 1; i <= n; i ++) {
        f[i] = max(f[i - 1], pmx[i - 1] + a[i] - c);
        pmx[i] = max(pmx[i - 1], f[i] - a[i]);
    }

    cout << f[n] << '\n';
    */

    int cur = inf;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i] > cur) {
            ans += a[i] - cur;
            cur = a[i];
        }
        if(a[i] + c < cur) {
            cur = a[i] + c;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
