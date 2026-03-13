#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/minimum-number-of-operations-to-make-arrays-similar/description/

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(2), b(2);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a[x & 1].emplace_back(x);
    }
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        b[x & 1].emplace_back(x);
    }

    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    sort(b[0].begin(), b[0].end());
    sort(b[1].begin(), b[1].end());

    long long ans = 0;
    for(int i = 0; i < a[0].size(); i ++) {
        ans += abs(a[0][i] - b[0][i]) / 2;
    }
    for(int i = 0; i < a[1].size(); i ++) {
        ans += abs(a[1][i] - b[1][i]) / 2;
    }
    cout << ans / 2 << '\n';
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