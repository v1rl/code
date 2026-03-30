#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
*/

const int inf = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    set<int> Sx, Sy;
    for(int i = 0; i < k; i ++) {
        int op, x;
        cin >> op >> x;
        if(op == 0) {
            Sx.insert(x);
        } else {
            Sy.insert(x);
        }
    }

    cout << 1ll * n * m - (1ll * Sx.size() * m + 1ll * Sy.size() * n - Sx.size() * Sy.size()) << '\n';
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
