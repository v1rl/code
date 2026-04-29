#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9 + 10;

void solve() {
    int n;
    cin >> n;
    int mn = inf, mx = 0;
    int cmin = 0, cmax = 0;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if(x > mx) {
            mx = x;
            cmax = 1;
        } else if(x == mx) {
            cmax ++;
        }
        if(x < mn) {
            mn = x;
            cmin = 1;
        } else if(x == mn) {
            cmin ++;
        }

        if(mn < mx && cmin == 1 && cmin + cmax == i + 1) {
            cout << mx * 2 << ' ';
        } else {
            cout << mn + mx << ' ';
        }
    }
    cout << '\n';
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
