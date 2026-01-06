#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/


void solve() {
    int n;
    cin >> n;
    int mx = 0;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        mx = max(mx, x);
    }
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}