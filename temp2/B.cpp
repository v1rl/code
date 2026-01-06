#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

/*
左侧统计数量
右侧访问到则加
*/

void solve() {
    int n;
    cin >> n;
    if(n & 1) {
        cout << (n + 1) / 2 * n << '\n';
        for(int i = 1; i <= n; i ++) {
            cout << n - i + 1 << ' ';
        }
        cout << '\n';
    } else {
        int t = n / 2;
        cout << t * t + (t + 1) * t << '\n';
        for(int i = 1; i <= n; i ++) {
            cout << n - i + 1 << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}