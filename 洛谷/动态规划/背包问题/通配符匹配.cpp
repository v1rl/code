#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/wildcard-matching/description/

/*
*/

const int mod = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    s = '#' + s, t = '#' + t;
    vector f(n + 1, vector(m + 1, 0));
    f[0][0] = 1;
    for(int i = 0; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(t[j] == '?') {
                if(i > 0) {
                    f[i][j] |= f[i - 1][j - 1];
                }
            } else if(t[j] == '*') {
                f[i][j] |= f[i][j - 1];
                if(i > 0) {
                    f[i][j] |= f[i - 1][j];
                }
            } else {
                if(i > 0 && s[i] == t[j]) {
                    f[i][j] |= f[i - 1][j - 1];
                }
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
