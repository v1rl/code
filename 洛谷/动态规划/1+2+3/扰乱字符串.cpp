#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/scramble-string/description/

/*
f[位于第i行][位于第j列][余数为k]的情况数
*/

const int mod = 1e9 + 7;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    vector f(n, vector(n, vector(n + 1, -1)));

    /*
    // 记忆化搜索
    auto dfs = [&](auto &&self, int l1, int l2, int len) -> bool {
        if(len == 1) {
            return s1[l1] == s2[l2];
        }
        if(f[l1][l2][len] != -1) {
            return f[l1][l2][len];
        }

        for(int i = 1; i < len; i ++) {
            if(self(self, l1, l2, i) && self(self, l1 + i, l2 + i, len - i)) {
                return f[l1][l2][len] = true;
            }
            if(self(self, l1, l2 + len - i, i) && self(self, l1 + i, l2, len - i)) {
                return f[l1][l2][len] = true;
            }
        }
        return f[l1][l2][len] = false;
    };

    cout << dfs(dfs, 0, 0, n) << '\n';
    */

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            f[i][j][1] = s1[i] == s2[j];
        }
    }

    for(int len = 2; len <= n; len ++) {
        for(int i = 0; i <= n - len; i ++) {
            for(int j = 0; j <= n - len; j ++) {
                bool ok = false;
                for(int k = 1; k < len; k ++) {
                    ok |= (f[i][j][k] && f[i + k][j + k][len - k]);
                    ok |= (f[i][j + len - k][k] && f[i + k][j][len - k]);
                }
                f[i][j][len] = ok;
            }
        }
    }

    cout << f[0][0][n] << '\n';
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
