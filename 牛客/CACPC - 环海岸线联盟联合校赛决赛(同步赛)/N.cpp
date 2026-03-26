#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7;

void solve() {
    i64 x, y;
    cin >> x >> y;
    if(x == 0) {
        if(y == 1) {
            cout << 0 << ' ' << 0 << '\n';
        } else if(y == 2) {
            cout << 0 << ' ' << 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    } else {
        if(y == 0) {
            cout << x << ' ' << x << '\n';
        } else {
            cout << -1 << '\n';
        }
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
