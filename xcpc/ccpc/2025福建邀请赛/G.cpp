#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for(int i = 1; i < n; i ++) {
        b[i] = max(0, a[i + 1] - a[i]);
    }

    vector<i64> s(n);
    for(int i = 1; i < n; i ++) {
        s[i] = s[i - 1] + b[i];
    }

    i64 k;
    cin >> k;
    while(m --) {
        int l, r;
        cin >> l >> r;
        cout << k + s[r - 1] - s[l - 1] << '\n';
    }
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
