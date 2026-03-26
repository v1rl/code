#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/jump-game-ii/description/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int cur = 0;
    int mx = 0;
    int ans = 0;
    for(int i = 0; i < n - 1; i ++) {
        mx = max(mx, i + a[i]);
        if(i == cur) {
            ans ++;
            cur = mx;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}