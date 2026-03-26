#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/knight-probability-in-chessboard/description/

/*
f[第k次操作][位于第i行][位于第j列]的概率
*/

const int mod = 1e9 + 7;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector f(m + 1, vector(n, vector(n, (double)0.0)));
    f[0][x][y] = 1;

    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    for(int k = 1; k <= m; k ++) {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                for(int p = 0; p < 8; p ++) {
                    int nx = i + dx[p], ny = j + dy[p];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
                        continue;
                    }
                    f[k][nx][ny] += f[k - 1][i][j] * 0.125;
                }
            }
        }
    }

    double ans = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            ans += f[m][i][j];
        }
    }

    cout << fixed << setprecision(10);
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
