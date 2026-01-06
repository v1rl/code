#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
const int inf = 2e18;
const int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    // if(n % 2 == 0 && m % 2 == 0) {
    //     cout << "NO" << '\n';
    //     return;
    // }

    int c = m % n;
    vector ans(n + 1, vector(m + 1, 0));
    int x = (n + 1) / 2, y = (m + 1) / 2;
    int cnt = 1;
    for(int i = 1, cx = c; i <= n; i ++) {
        for(int j = 1, cy = 1; j <= m; j ++) {
            ans[x][y] = cnt ++;
            y += cy;
            // if(y > m) y -= m;
            // if(y < 1) y += m;
            y = ((y - 1) % m + m) % m + 1;
            cy = -cy;
            cy += (cy > 0 ? 1 : -1);
        }
        x += cx;
        // if(x > n) x -= n;
        // if(x < 1) x += n;
        x = ((x - 1) % n + n) % n + 1;
        cx = -cx;
        cx += (cx > 0 ? c : -c);
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(ans[i][j] == 0) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    cout << "YES" << '\n';
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cout << ans[i][j] << " \n"[j == m];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;  
    // cin >> t;
    while(t --) {
        solve();
    }
}