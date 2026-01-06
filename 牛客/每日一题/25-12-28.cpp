#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int x, y;
    cin >> x >> y;   
    if(x == y) {
        cout << 0 << '\n';
    } else if(y == 0) {
        cout << 1 << '\n';
    } else if(x == 0) {
        cout << 2 << '\n';
    } else if(x == -y) {
        cout << 3 << '\n';
    } else {
        cout << -1 << '\n';
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
