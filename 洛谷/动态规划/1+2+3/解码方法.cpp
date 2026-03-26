#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/decode-ways/description/

const int inf = 1e9;

void solve() {
    /*
    // 记忆化搜索倒推
    string s;
    cin >> s;

    vector<int> f(s.size());

    bool ok = true;
    auto dfs = [&](auto &&self, int u) {
        if(!ok) {
            return 0;
        }

        if(u == -1) {
            return 1;
        }

        if(f[u]) {
            return f[u];
        }

        if(s[u] == '0') {
            if(u == 0 || s[u - 1] == '0' || s[u - 1] > '2') {
                ok = false;
                return 0;
            }
            return f[u] = self(self, u - 2);
        }

        int res = 0;
        res += self(self, u - 1);
        if(u > 0 && ((s[u] <= '6' && s[u - 1] == '2') || s[u - 1] == '1')) {
            res += self(self, u - 2);
        }
        return f[u] = res;
    };

    int ans = dfs(dfs, s.size() - 1);
    cout << (ok ? ans : 0) << '\n';
    */

    string s;
    cin >> s;

    int n = s.size();
    s = '#' + s;

    int dp[3] {};
    dp[1] = 1;
    for(int i = 1; i <= n; i ++) {
        dp[2] = 0;
        if(s[i] != '0') {
            dp[2] += dp[1];
        }
        if(i > 1 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
            dp[2] += dp[0];
        }
        dp[0] = dp[1], dp[1] = dp[2];
    }
    cout << dp[2] << '\n';
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
