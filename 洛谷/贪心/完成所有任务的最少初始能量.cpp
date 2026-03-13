#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/minimum-initial-energy-to-finish-tasks/description/

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end(), 
        [&](auto &x, auto &y) {
            return x[0] - x[1] > y[0] - y[1];
        });

    int res = 0;
    for(auto [x, y] : a) {
        res = max(res + x, y);
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}