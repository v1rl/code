#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/longest-palindromic-subsequence/description/

/*
f[l][r]区间[l,r]中的最长回文串
*/

const int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = '#' + s;
    vector f(n + 1, vector(n + 1, 0));
    for(int len = 1; len <= n; len ++) {
        for(int l = 1; l <= n - len + 1; l ++) {
            int r = l + len - 1;
            if(len == 1) {
                f[l][r] = 1;
            } else if(len == 2) {
                f[l][r] = s[l] == s[r] ? 2 : 1;
            } else {
                if(s[l] == s[r]) {
                    f[l][r] = f[l + 1][r - 1] + 2;
                } else {
                    f[l][r] = max(f[l + 1][r], f[l][r - 1]);
                }
            }
        }
    }

    cout << f[1][n] << '\n';
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
