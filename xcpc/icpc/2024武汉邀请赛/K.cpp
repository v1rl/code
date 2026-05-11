#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    // auto dfs = [&](auto &&self, int l, int r) {
    //     // cerr << l << ' ' << r << '\n';
    //     if(l == r) {
    //         return true;
    //     }
    //     int s = 0;
    //     for(int i = l; i <= r; i ++) {
    //         s ^= i;
    //     }
    //     if(s == 0) {
    //         return false;
    //     }

    //     bool ok = true;
    //     ok &= self(self, l + 1, r);
    //     ok &= self(self, l, r - 1);
    //     return !ok;
    // };

    // for(int i = 1; i <= 36; i ++) {
    //     cout << (dfs(dfs, 1, i) ? "Fluttershy" : "Pinkie Pie") << '\n';
    // }
    int n;
    cin >> n;
    if((n / 2) % 2 == 0) {
        cout << "Fluttershy" << '\n';
    } else {
        cout << "Pinkie Pie" << '\n';
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
