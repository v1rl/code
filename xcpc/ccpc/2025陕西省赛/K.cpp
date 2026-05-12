#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

/*
*/

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    if(x <= y) {
        cout << 1ll * (n + m) * y << '\n';
        return;
    }

    if(n == 0 && m == 0) {
        cout << 0 << '\n';
    } else if(n == 0) {
        cout << x << '\n';
    } else if(m == 0) {
        cout << 1ll * (n - 1) * y + x << '\n';
    } else {
        if(y == 0) {
            cout << x << '\n';
            return;
        }
        int B = (x + y - 1) / y - 1;
        i64 ans2 = 1ll * n * y + x;
        i64 ans1 = 0;
        if(n >= B) {
            ans1 = x + 1ll * (n - B + m) * y;
        }
        cout << max(ans1, ans2) << '\n';
    }
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
