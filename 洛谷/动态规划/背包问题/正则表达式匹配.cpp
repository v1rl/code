#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/regular-expression-matching/description/

/*
*/

const int mod = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();


    /*
    // 记忆化搜索
    vector f(n + 1, vector(m + 1, -1));
    auto dfs = [&](auto &&self, int i, int j) -> bool{
        if(i == n && j == m) {
            return true;
        } else if(j == m) {
            return false;
        } else if(i == n) {
            return j + 1 < m && t[j + 1] == '*' && self(self, i, j + 2);
        }

        if(f[i][j] != -1) {
            return f[i][j];
        }

        if(j + 1 < m && t[j + 1] == '*') {
            bool ok = false;
            ok |= self(self, i, j + 2);
            // for(int k = i + 1; k <= n; k ++) {
            //     if(t[j] == '.' || s[k - 1] == t[j]) {
            //         ok |= self(self, k, j + 2);
            //     } else {
            //         break;
            //     }
            // }
            if(t[j] == '.' || s[i] == t[j]) {
                ok |= self(self, i + 1, j);
            }
            return f[i][j] = ok;
        } else {
            if(t[j] == '.' || s[i] == t[j]) {
                return f[i][j] = self(self, i + 1, j + 1);
            } else {
                return f[i][j] = false;
            }
        }
    };

    cout << dfs(dfs, 0, 0) << '\n';
    */
    

    /*
    vector f(n + 1, vector(m + 1, 0));
    f[n][m] = 1;
    for(int j = m - 1; j >= 0; j --) {
        f[n][j] = j + 1 < m && t[j + 1] == '*' && f[n][j + 2];
    }

    for(int i = n - 1; i >= 0; i --) {
        for(int j = m - 1; j >= 0; j --) {
            if(j + 1 < m && t[j + 1] == '*') {
                f[i][j] |= f[i][j + 2];
                if(t[j] == '.' || s[i] == t[j]) {
                    f[i][j] |= f[i + 1][j];
                }
            } else {
                if(t[j] == '.' || s[i] == t[j]) {
                    f[i][j] |= f[i + 1][j + 1];
                }
            }
        }
    }

    cout << f[0][0] << '\n';
    */

    s = '#' + s, t = '#' + t;
    vector f(n + 1, vector(m + 1, 0));
    f[0][0] = 1;
    for(int i = 0; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(t[j] == '*') {
                f[i][j] |= f[i][j - 2];
                if(i > 0 && (t[j - 1] == '.' || s[i] == t[j - 1])) {
                    f[i][j] |= f[i - 1][j];
                }
            } else {
                if(i > 0 && (t[j] == '.' || s[i] == t[j])) {
                    f[i][j] |= f[i - 1][j - 1];
                }
            }
        }
    }

    cout << f[n][m];
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
