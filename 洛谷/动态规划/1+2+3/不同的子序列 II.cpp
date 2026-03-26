#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/distinct-subsequences-ii/description/

const int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    s = '#' + s;
    int dp[26] {};
    int f[2] {};
    
    for(int i = 1; i < s.size(); i ++) {
        f[1] = ((f[0] * 2 + 1 - dp[s[i] - 'a']) % mod + mod) % mod;
        dp[s[i] - 'a'] = (f[0] + 1) % mod;
        f[0] = f[1];
    }
    cout << f[1] << '\n';
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
