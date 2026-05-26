#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve() {
    i64 x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    i64 d1 = abs(x1 - x2);
    i64 d2 = abs(y1 - y2);

    // if(d1 > d2) {
    //     swap(d1, d2);
    // }

    // if(d1 == 0 && d2 == 0) {
    //     cout << 0 << '\n';
    // } else if(d1 == 0 && d2 <= 2) {
    //     cout << 2 << '\n';
    // } else {
    //     cout << (d2 + 1) / 2 << '\n';
    // }

    int ans = max((d1 + 1) / 2, (d2 + 1) / 2);
    if(ans == 1 && (d1 == 0 || d2 == 0)) {
        ans ++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}