#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/maximum-sum-circular-subarray/description/

/*
*/

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    auto work = [&](int l, int r) {
        if(l > r) {
            return 0;
        }
        int dp[3] {};
        int mx = -inf;
        for(int i = l; i <= r; i ++) {
            dp[2] = a[i];
            if(i > l) {
                dp[2] = max(dp[2], dp[1]);
            }
            if(i > l + 1) {
                dp[2] = max(dp[2], dp[0] + a[i]);
            }
            dp[0] = dp[1], dp[1] = dp[2];
            mx = max(mx, dp[2]);
        }
        return mx;
    };

    cout << max(a[0] + work(2, n - 2), work(1, n - 1)) << '\n';
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
