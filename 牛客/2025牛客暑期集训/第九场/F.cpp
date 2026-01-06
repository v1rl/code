#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
const int inf = 2e18;

void solve() {
    int sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2;
    cin >> sx1 >> sy1 >> sx2 >> sy2 >> tx1 >> ty1 >> tx2 >> ty2;

    int ans1 = max(abs(tx1 - sx1), abs(ty1 - sy1)) + max(abs(sx2 - tx2), abs(sy2 - ty2));
    int ans2 = max(abs(tx1 - sx2), abs(ty1 - sy2)) + max(abs(sx1 - tx2), abs(sy1 - ty2));
    if(abs(tx1 + ty1) % 2 == abs(sx1 + sy1) % 2) {
        cout << ans1 << '\n';
    } else {
        cout << ans2 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;  
    cin >> t;
    while(t --) {
        solve();
    }
}