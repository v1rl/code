#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    auto query = [&](auto &&self, int p, i64 l, i64 r, i64 x, i64 y, int val) {
        if(r < x || l > y) {
            return 0;
        }
        if(l >= x && r <= y) {
            if(p == n) {
                return val;
            } else {
                return val ^ a[p + 1];
            }
        }
        i64 mid = l + r >> 1;
        return self(self, p + 1, l, mid, x, y, val & a[p + 1]) ^ self(self, p + 1, mid + 1, r, x, y, val | a[p + 1]);
    };

    while(q --) {
        int op;
        cin >> op;
        if(op == 2) {
            int pos, x;
            cin >> pos >> x;
            a[pos] ^= x;
        } else {
            i64 l, r;
            cin >> l >> r;
            cout << query(query, 1, 1, 1ll << n - 1, l, r, a[1]) << '\n';
        }
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
