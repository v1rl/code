#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

const int inf = 1e9 + 10;
const int M = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector(m + 1, 0));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }

    vector dX(n + 2, vector(m + 2, 0));
    vector dY(n + 2, vector(m + 2, 0));
    vector res(n + 2, vector(m + 2, n * m));

    auto workX = [&](int x, int l, int r) {
        if(l > r) {
            return;
        }
        dX[x][l] -= 1;
        dX[x][r + 1] += 1;
    };

    auto workY = [&](int y, int l, int r) {
        if(l > r) {
            return;
        }
        dY[l][y] -= 1;
        dY[r + 1][y] += 1;
    };

    for(int x = 1; x <= n; x ++) {
        for(int y = 1; y <= m; y ++) {
            int v = g[x][y];
            if(v == 0) {
                res[x][y] --;
                continue;
            }
            int L = y - v;
            int R = y + v;
            int U = x - v;
            int D = x + v;

            int l = max(L, 1);
            int r = min(R, m);
            int u = max(U + 1, 1);
            int d = min(D - 1, n);

            if(U >= 1) {
                workX(U, l, r);
            }
            if(D <= n) {
                workX(D, l, r);
            }
            if(L >= 1) {
                workY(L, u, d);
            }
            if(R <= m) {
                workY(R, u, d);
            }
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            dX[i][j] += dX[i][j - 1];
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            dY[i][j] += dY[i - 1][j];
        }
    }

    int ans = n * m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            ans = min(ans, res[i][j] + dX[i][j] + dY[i][j]);
        }
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
