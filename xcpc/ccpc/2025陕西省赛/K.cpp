#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

/*
恰好+1个人平分会低于y
*/

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    if(y == 0) {
        if(n + m > 0) {
            cout << x << '\n';
        } else {
            cout << 0 << '\n';
        }
        return;
    }

    if(x <= y) {
        cout << 1ll * (n + m) * y << '\n';
        return;
    }

    if(n == 0) {
        if(m) {
            cout << x << '\n';
        } else {
            cout << 0 << '\n';
        }
        return;
    }

    if(m == 0) {
        i64 ans = 0;
        if(n) {
            ans += x;
            n --;
            ans += 1ll * n * y;
        }
        cout << ans << '\n';
        return;
    }

    i64 ans = 0;
    int t = (x - 1) / y;
    bool f = false;

    i64 all = 1ll * n * y + x;

    if(n >= t) {
        ans += x;
        n -= t;
        ans += 1ll * y * n;
        f = true;
    } else {
        ans += 1ll * y * n;
    }

    if(f) {
        ans += 1ll * m * y;
    } else {
        ans += x;
    }
    cout << max(ans, all) << '\n';
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
