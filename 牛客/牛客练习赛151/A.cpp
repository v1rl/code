#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        i64 x;
        cin >> x;
        if(x % k == 1) {
            ans ++;
        }
    }
    if(k == 1) {
        cout << n << '\n';
    } else {
        cout << ans << '\n';
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
