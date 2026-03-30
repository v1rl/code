#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

/*
*/

const int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    /*
    // 常规区间dp
    vector f(n, vector(n, 0));
    for(int len = 1; len <= n; len ++) {
        for(int l = 0; l + len - 1 < n; l ++) {
            int r = l + len - 1;
            if(len == 1) {
                f[l][r] = 0;
            } else if(len == 2) {
                f[l][r] = (s[l] != s[r]);
            } else {
                if(s[l] == s[r]) {
                    f[l][r] = f[l + 1][r - 1];
                } else {
                    f[l][r] = min(f[l + 1][r], f[l][r - 1]) + 1;
                }
            }
        }
    }
    */

    /*
    // 线性递推dp
    vector f(n, vector(n, 0));
    for(int i = n - 1; i >= 0; i --) {
        for(int j = i; j < n; j ++) {
            if(i == j) {
                f[i][j] = 0;
            } else if(i + 1 == j) {
                f[i][j] = (s[i] != s[j]);
            } else {
                if(s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1];
                } else {
                    f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
                }
            }
        }
    }
    */

    vector<int> dp(n);
    for(int i = n - 1; i >= 0; i --) {
        vector<int> ndp(n);
        for(int j = i; j < n; j ++) {
            if(i == j) {
                ndp[j] = 0;
            } else if(i + 1 == j) {
                ndp[j] = (s[i] != s[j]);
            } else {
                if(s[i] == s[j]) {
                    ndp[j] = dp[j - 1];
                } else {
                    ndp[j] = min(ndp[j - 1], dp[j]) + 1;
                }
            }
        }
        dp = move(ndp);
    }

    cout << dp[n - 1] << '\n';
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
