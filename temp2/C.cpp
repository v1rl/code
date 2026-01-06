#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    for(int x = 0; x <= n; x ++) {
        for(int y = 0; y <= m; y ++) {
            int l = x;
            int r = n - x;
            int u = m - y;
            int d = y;
            // cout << u << ' ' << r << ' ' << d << ' ' << l << '\n';

            vector<int> ops{u, r, d, l};
            int ans = 0;
            for(int i = 0; i < 4; i ++) {
                int t1 = ops[i];
                int t2 = ops[(i + 1) % 4];
                int t3 = ops[(i + 2) % 4];

                // cout << t1 << ' ' << t2 << ' ' << t3 << '\n';

                int x1 = t2 - t1;
                int x2 = min(t2 - 1, t3);

                // cout << x1 << ' ' << x2 << '\n';
                if(x1 > 0) {
                    ans += min(x1, x2 + 1) * t1;
                }
                x1 = max(0ll, x1);
                if(x2 >= x1) {
                    int d1 = min(t2, n) - x1;
                    int d2 = min(t2, n) - x2;
                    ans += 1ll * d1 * (d1 + 1) / 2 - 1ll * d2 * (d2 - 1) / 2;
                }
                // cout << ans << '\n';
            }

            cout << ans << " \n"[y == m];
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}