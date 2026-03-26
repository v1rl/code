#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/maximum-sum-circular-subarray/description/

/*
*/

const int inf = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    auto check = [&](int x) {
        vector<int> dp(n);
        int mx = 0;
        for(int i = 0; i < n; i ++) {
            dp[i] = a[i] <= x;
            if(i > 0) {
                dp[i] = max(dp[i], dp[i - 1]);
            }
            if(i > 1) {
                dp[i] = max(dp[i], dp[i - 2] + (a[i] <= x));
            }
            mx = max(mx, dp[i]);
        }
        return mx >= k;
    };

    int l = 0, r = 1e9;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
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
