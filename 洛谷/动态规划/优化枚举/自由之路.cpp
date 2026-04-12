#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/freedom-trail/description/

/*
f[i][j] 处理了前i个字符，当前轮盘停留在位置j的最小次数
*/

const int inf = 1e9 + 7;

void solve() {
    string s, key;
    cin >> s >> key;
    int n = key.size(), m = s.size();

    key = '#' + key;
    vector f(n + 1, vector(m, inf));
    f[0][0] = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(s[j] != key[i + 1]) {
                continue;
            }
            // 可以通过预处理左侧最近和右侧最近优化枚举
            for(int k = 0; k < m; k ++) {
                int d = abs(k - j);
                f[i][j] = min(f[i][j], f[i][k] + min(d, m - d));
            }
            f[i + 1][j] = min(f[i + 1][j], f[i][j] + 1);
        }
    }

    int ans = inf;
    for(int j = 0; j < m; j ++) {
        ans = min(ans, f[n][j]);
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
