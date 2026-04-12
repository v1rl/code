#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

const int inf = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    if(n == 1) {
        cout << 0 << '\n';
        return;
    }

    vector f(2, vector(n + 1, 0));
    f[1][0] = -inf;
    f[1][1] = -a[1];
    for(int i = 2; i <= n; i ++) {
        f[0][i] = max(f[0][i - 1], f[1][i - 1] + a[i]);
        f[1][i] = max(f[1][i - 1], f[0][i - 2] - a[i]);
    }
    cout << f[0][n] << '\n';
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
