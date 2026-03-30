#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
前缀最值，整体+1/-1不改变最值
*/

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int mx = -inf, mn = inf;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        mx --, mn ++;
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);

        ans = max({ans, a[i] - mn, mx - a[i]});
    }
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
