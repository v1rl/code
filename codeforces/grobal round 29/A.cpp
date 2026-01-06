#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

/*
x <= y
x >= y + 2 && x <= 2 * y
*/

void solve() {
    int x, y;
    cin >> x >> y;
    if(y == 1) {
        cout << -1 << '\n';
        return;
    }
    if(x < y) {
        cout << 2 << '\n';
    } else if(x >= y + 2) {
        cout << 3 << '\n';
    } else {
        cout << -1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}