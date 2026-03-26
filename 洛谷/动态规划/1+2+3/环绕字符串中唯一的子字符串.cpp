#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/unique-substrings-in-wraparound-string/description/

const i64 inf = 1e18;

void solve() {
    string s;
    cin >> s;
    i64 dp[26] {};
    dp[s[0] - 'a'] = 1;
    for(int i = 1, len = 1; i < s.size(); i ++) {
        if(s[i - 1] + 1 == s[i] || (s[i - 1] == 'z' && s[i] == 'a')) {
            len ++;
        } else {
            len = 1;
        }
        dp[s[i] - 'a'] = max<i64>(dp[s[i] - 'a'], len);
    }

    int ans = 0;
    for(int i = 0; i < 26; i ++) {
        ans += dp[i];
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
