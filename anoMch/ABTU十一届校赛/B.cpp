#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int mod = 998244353;

/*
f[i][op][j][k] 处理了前i个数，首位奇偶性为op，第一个不同奇偶位为j，有效点的个数为k的 方案数
*/

void chadd(int &x, int y) {
    x += y;
    if(x >= mod) {
        x -= mod;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end(), greater());
    vector dp(2, vector(n + 2, vector(n + 1, 0)));
    dp[a[1] & 1][2][0] = 1;

    for(int i = 1; i < n; i ++) {
        vector ndp(2, vector(n + 2, vector(n + 1, 0)));
        for(int op = 0; op < 2; op ++) {
            if((a[i + 1] & 1) == op) {
                for(int j = 2; j <= i + 1; j ++) {
                    for(int k = 0; k <= i; k ++) {
                        chadd(ndp[op][j + 1][k], 1ll * j * dp[op][j][k] % mod);
                        chadd(ndp[op][j][k + 1], 1ll * (i + 1 - j) * dp[op][j][k] % mod);
                    }
                }
            } else {
                for(int k = 0; k <= i; k ++) {
                    int suf = 0;
                    for(int j = i + 1; j >= 2; j --) {
                        chadd(ndp[op ^ 1][2][k], dp[op][j][k]);
                        chadd(ndp[op][j][k + 1], 1ll * (i + 1 - j) * dp[op][j][k] % mod);

                        chadd(suf, dp[op][j][k]);
                        chadd(ndp[op][j][k + 1], suf);
                    }
                }
            }        
        }
        dp = move(ndp);
    }

    i64 ans = 0;
    for(int op = 0; op < 2; op ++) {
        for(int j = 2; j <= n + 1; j ++) {
            for(int k = m; k <= n; k ++) {
                ans = (ans + dp[op][j][k]) % mod;
            }
        }
    }

    cout << ans << '\n';


    /*
    // 滚动
    sort(a.begin() + 1, a.end(), greater());
    vector dp(2, vector(2, vector(n + 2, vector(n + 1, 0))));
    dp[1][a[1] & 1][2][0] = 1;

    for(int i = 1; i < n; i ++) {
        int cur = (i + 1) & 1;
        for(auto &c1 : dp[cur]) {
            for(auto &c2 : c1) {
                for(auto &c3 : c2) {
                    c3 = 0;
                }
            }
        }
        for(int op = 0; op < 2; op ++) {
            if((a[i + 1] & 1) == op) {
                for(int j = 2; j <= i + 1; j ++) {
                    for(int k = 0; k <= i; k ++) {
                        chadd(dp[cur][op][j + 1][k], 1ll * j * dp[cur ^ 1][op][j][k] % mod);
                        chadd(dp[cur][op][j][k + 1], 1ll * (i + 1 - j) * dp[cur ^ 1][op][j][k] % mod);
                    }
                }
            } else {
                for(int k = 0; k <= i; k ++) {
                    int suf = 0;
                    for(int j = i + 1; j >= 2; j --) {
                        chadd(dp[cur][op ^ 1][2][k], dp[cur ^ 1][op][j][k]);
                        chadd(dp[cur][op][j][k + 1], 1ll * (i + 1 - j) * dp[cur ^ 1][op][j][k] % mod);

                        chadd(suf, dp[cur ^ 1][op][j][k]);
                        chadd(dp[cur][op][j][k + 1], suf);
                    }
                }
            }        
        }
    }

    i64 ans = 0;
    for(int op = 0; op < 2; op ++) {
        for(int j = 2; j <= n + 1; j ++) {
            for(int k = m; k <= n; k ++) {
                ans = (ans + dp[n & 1][op][j][k]) % mod;
            }
        }
    }

    cout << ans << '\n';
    */
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
