#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

/*
3 2 1 3 1 2
4 3 2 1 4 1 2 3
7 6 5 4 3 2 1 7 1 2 3 4 5 6
*/

void solve() {
    int n;
    cin >> n;
    for(int i = n; i >= 1; i --) {
        cout << i << ' ';
    }
    cout << n << ' ';
    for(int i = 1; i < n; i ++) {
        cout << i << ' ';
    }
    cout << '\n';
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