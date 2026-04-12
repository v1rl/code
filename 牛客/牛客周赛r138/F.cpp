#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int N = 500;
int a[N];
int f[N][N];

/*
*/

const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    /*
    int ans = 0;
    for(int s = 2; s <= 2000; s ++) {
        for(int len = 1; len <= n; len ++) {
            for(int l = 0; l + len - 1 < n; l ++) {
                int r = l + len - 1;
                if(len == 1) {
                    if(a[l] * 2 == s) {
                        f[l][r] = 1;
                    } else {
                        f[l][r] = 0;
                    }
                } else {
                    if(a[l] + a[r] == s) {
                        f[l][r] = f[l + 1][r - 1] + 2;
                    } else {
                        f[l][r] = max(f[l + 1][r], f[l][r - 1]);
                    }
                }
            }
        }
        ans = max(ans, f[0][n - 1]);
    }
    cout << ans << '\n';
    */

    vector pos(n, vector(1001, -1));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < i; j ++) {
            pos[i][a[j]] = j;
        }
    }

    int ans = 0;
    memset(f, 0, sizeof(f));
    for(int len = 1; len <= n; len ++) {
        for(int l = 0; l + len - 1 < n; l ++) {
            int r = l + len - 1;
            if(len <= 2) {
                f[l][r] = len;
            } else {
                // 注意初始化
                f[l][r] = 2;
                int s = a[l] + a[r];
                for(int k = l + 1; k < r; k ++) {
                    int v = s - a[k];
                    if(v < 0 || v > 1000) {
                        continue;
                    }
                    if(pos[r][v] >= k) {
                        f[l][r] = max(f[l][r], f[k][pos[r][v]] + 2);
                    }
                }
            }
            ans = max(ans, f[l][r]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
