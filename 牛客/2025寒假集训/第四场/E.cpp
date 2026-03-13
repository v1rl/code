#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;

/*
dp[第i行][第j列][雷数为x][状态为s]的 {贡献，当前是否为雷，上一步的状态}
mask:右上右的轮廓线，[0, j]当前行，[j+1,m-1]上一行
*/

const int inf = 1e9 + 10;
const int mod = 998244353;

void chmax(auto &a, auto b) {
    if(a < b) {
        a = b;
    }
}

int ans[10][10][82];
vector<string> grid[10][10][82];
array<int, 3> dp[10][10][82][1 << 10];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;


    cout << ans[n][m][k] << '\n';
    for(auto s : grid[n][m][k]) {
        cout << s << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int m = 1; m <= 9; m ++) {
        memset(dp, -1, sizeof(dp));

        dp[0][0][0][0] = {0, 0, -1};
        dp[0][0][1][1] = {0, 1, -1};

        for(int i = 0; i < 9; i ++) {
            for(int j = 0; j < m; j ++) {
                for(int k = 0; k <= i * m + j + 1; k ++) {
                    for(int s = 0; s < (2 << m); s ++) {
                        if(dp[i][j][k][s][0] == -1) {
                            continue;
                        }

                        if(j + 1 < m) {
                            for(int x = 0; x < 2; x ++) {
                                int ns = (s & ~(1 << (j + 1)) | x << (j + 1));
                                int v = dp[i][j][k][s][0];
                                v += (s >> j & 1) ^ x;
                                if(i) {
                                    v += (s >> (j + 1) & 1) ^ x;
                                    v += (s >> (j + 2) & 1) ^ x;
                                }
                                if(i && (j + 3) <= m) {
                                    v += (s >> (j + 3) & 1) ^ x;
                                }

                                chmax(dp[i][j + 1][k + x][ns], array{v, x, s});
                            }
                        } else if(i + 1 < 9) {
                            for(int x = 0; x < 2; x ++) {
                                int ns = (s & ~(1 << m)) << 1 | x;
                                int v = dp[i][j][k][s][0];
                                v += (s & 1) ^ x;
                                if(m > 1) {
                                    v += (s >> 1 & 1) ^ x;
                                }

                                chmax(dp[i + 1][0][k + x][ns], array{v, x, s});
                            }
                        }
                    }
                }
            }
        }

        for(int n = 1; n <= 9; n ++) {
            for(int k = 0; k <= n * m; k ++) {
                int s = -1;
                ans[n][m][k] = -1;
                for(int t = 0; t < (2 << m); t ++) {
                    if(dp[n - 1][m - 1][k][t][0] > ans[n][m][k]) {
                        ans[n][m][k] = dp[n - 1][m - 1][k][t][0];
                        s = t;
                    }
                }

                int i = n - 1, j = m - 1;
                int c = k;
                vector g(n, string(m, '.'));
                while(i + j) {
                    auto [_, x, ns] = dp[i][j][c][s];
                    if(x) {
                        g[i][j] = '*';
                    }
                    if(j) {
                        j --;
                    } else {
                        i --;
                        j = m - 1;
                    }
                    c -= x;
                    s = ns;
                }

                if(c) {
                    g[0][0] = '*';
                }

                grid[n][m][k] = g;
            }
        }
    }

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
