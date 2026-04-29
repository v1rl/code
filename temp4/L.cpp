#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;
#define int long long

const int N = 1e6 + 10;

void solve() {
    i64 n;
    cin >> n;
    i64 mn = n + 1;
    i64 mx = (n * n + n + 2) / 2;
    cout << mn << ' ' << mx << '\n';
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

