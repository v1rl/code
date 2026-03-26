#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/longest-common-subsequence/description/

const int mod = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = '#' + s, t = '#' + t;


    /*
    // 朴素
    vector f(n + 1, vector(m + 1, 0));

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(s[i] == t[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    cout << f[n][m] << '\n';
    */

    /*
    // 类轮廓线
    vector<int> dp(m + 2);

    for(int i = 1; i <= n; i ++) {
        dp[0] = 0;
        for(int j = 1; j <= m; j ++) {
            if(s[i] == t[j]) {
                dp[j] = dp[j] + 1;
            } else {
                dp[j] = max(dp[j - 1], dp[j + 1]);
            }
        }
        for(int j = m + 1; j >= 1; j --) {
            dp[j] = dp[j - 1];
        }
    }
    cout << dp[m + 1] << '\n';
    */

    // 滚动数组
    vector dp(2, vector(m + 1, 0));

    for(int i = 1; i <= n; i ++) {
        int cur = i & 1;
        for(int j = 1; j <= m; j ++) {
            if(s[i] == t[j]) {
                dp[cur][j] = dp[cur ^ 1][j - 1] + 1;
            } else {
                dp[cur][j] = max(dp[cur ^ 1][j], dp[cur][j - 1]);
            }
        }
    }

    cout << dp[n & 1][m];
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
