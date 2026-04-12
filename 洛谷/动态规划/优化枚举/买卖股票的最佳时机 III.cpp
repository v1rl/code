#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector f(2, vector(n + 1, 0));
    auto mn = a;
    vector<int> pmx(n);
    pmx[0] = -a[0];
    for(int i = 1; i < n; i ++) {
        mn[i] = min(mn[i - 1], a[i]);
        f[0][i] = max(f[0][i - 1], a[i] - mn[i]);
        pmx[i] = max(pmx[i - 1], f[0][i] - a[i]);
        f[1][i] = max(f[1][i - 1], pmx[i] + a[i]);
    }

    cout << f[1][n - 1] << '\n';
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
