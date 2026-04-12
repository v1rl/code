#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/

const int inf = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector f(k, vector(n + 1, 0));
    vector<int> mn(n + 1, inf);
    vector pmx(k - 1, vector(n + 1, -inf));

    for(int i = 1; i <= n; i ++) {
        mn[i] = min(mn[i - 1], a[i]);
        f[0][i] = max(f[0][i - 1], a[i] - mn[i]);

        for(int j = 1; j < k; j ++) {
            pmx[j - 1][i] = max(pmx[j - 1][i - 1], f[j - 1][i] - a[i]);
            f[j][i] = max(f[j][i - 1], pmx[j - 1][i] + a[i]);
        }
    }

    cout << f[k - 1][n] << '\n';
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
