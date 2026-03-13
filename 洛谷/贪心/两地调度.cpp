#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    sort(a.begin(), a.end(), 
        [&](auto x, auto y) {
            return x[1] - x[0] < y[1] - y[0];
        });

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        if(i < n / 2) {
            ans += a[i][1];
        } else {
            ans += a[i][0];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}