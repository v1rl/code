#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/edit-distance/description/

const int mod = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = '#' + s, t = '#' + t;

    int w[3] = {1, 1, 1};
    
    /*
    // 朴素
    vector f(n + 1, vector(m + 1, 0));


    for(int i = 0; i <= n; i ++) {
        f[i][0] = i * w[1];
    }
    for(int j = 0; j <= m; j ++) {
        f[0][j] = j * w[0];
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(s[i] == t[j]) {
                f[i][j] = f[i - 1][j - 1];
            } else {
                f[i][j] = min({f[i - 1][j - 1] + w[2], f[i][j - 1] + w[0], f[i - 1][j] + w[1]});
            }
        }
    }
    cout << f[n][m] << '\n';
    */

    vector dp(2, vector(m + 1, 0));
    for(int j = 0; j <= m; j ++) {
        dp[0][j] = j * w[0];
    }
    for(int i = 1; i <= n; i ++) {
        int cur = i & 1;
        dp[cur][0] = i * w[1];
        for(int j = 1; j <= m; j ++) {
            if(s[i] == t[j]) {
                dp[cur][j] = dp[cur ^ 1][j - 1];
            } else {
                dp[cur][j] = min({dp[cur ^ 1][j - 1] + w[2], dp[cur][j - 1] + w[0], dp[cur ^ 1][j] + w[1]});
            }
        }
    }

    cout << dp[n & 1][m] << '\n';
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
