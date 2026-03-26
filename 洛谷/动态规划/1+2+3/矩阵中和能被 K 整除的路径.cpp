nkinclude <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/

/*
f[位于第i行][位于第j列][余数为k]的情况数
*/

const int mod = 1e9 + 7;

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    vector g(n, vector(m + 1, 0));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }

    vector f(n, vector(m, vector(p, 0)));
    f[0][0][g[0][0] % p] = 1;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            for(int k = 0; k < p; k ++) {
                // if(i != n - 1) {
                //     int nk = (k + g[i + 1][j]) % p;
                //     f[i + 1][j][nk] += f[i][j][k];
                //     f[i + 1][j][nk] %= mod;
                // }
                // if(j != m - 1) {
                //     int nk = (k + g[i][j + 1]) % p;
                //     f[i][j + 1][nk] += f[i][j][k];
                //     f[i][j + 1][nk] %= mod;
                // }
                int nk = (k + g[i][j]) % p;
                if(i != 0) {
                    f[i][j][nk] += f[i - 1][j][k];
                    f[i][j][nk] %= mod;
                }
                if(j != 0) {
                    f[i][j][nk] += f[i][j - 1][k];
                    f[i][j][nk] %= mod;
                }
            }
        }
    }

    cout << f[n - 1][m - 1][0] << '\n';
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
