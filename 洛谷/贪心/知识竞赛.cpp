#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://www.nowcoder.com/practice/2a9089ea7e5b474fa8f688eae76bc050

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end(), 
        [&](auto x, auto y) {
            return abs(x[0] - x[1]) < abs(y[0] - y[1]);
        });

    int mxX = a[0][0], mxY = a[0][1];
    int ans = 0;
    for(int i = 1; i < n; i ++) {
        auto [x, y] = a[i];
        if(x > y) {
            ans = max(ans, y + mxY);
        } else {
            ans = max(ans, x + mxX);
        } 
        mxX = max(mxX, x);
        mxY = max(mxY, y);
    }
    cout << fixed << setprecision(2);
    cout << ans / 2.0 << '\n';
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