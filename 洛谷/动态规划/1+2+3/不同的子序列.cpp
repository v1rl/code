#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/distinct-subsequences/description/

const int mod = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector f(n + 1, vector(m + 1, 0ull));
    s = '#' + s, t = '#' + t;

    for(int i = 0; i <= n; i ++) {
        f[i][0] = 1;
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            f[i][j] = f[i - 1][j];
            if(s[i] == t[j]) {
                f[i][j] += f[i - 1][j - 1];
            }
        }
    }
    cout << f[n][m] << '\n';
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
