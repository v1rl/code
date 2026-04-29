#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

typedef array<i64, 3> AL3;

const i64 inf = 1e18;

void solve() {
    int n, p, q;
    cin >> n >> p >> q;
    vector<array<int, 2>> a;
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        if(x + 1 > p || y + 1 > q) {
            continue;
        }
        a.push_back({x + 1, y + 1});
    }

    sort(a.begin(), a.end(), 
        [&](auto &x, auto & y) {
            if(x[0] != y[0]) {
                return x[0] < y[0];
            }
            return x[1] > y[1];
        });

    vector<int> f;
    i64 cur = 0;
    int lst = 0;
    i64 res = 0;
    for(int i = 0; i < a.size(); ) {
        int j = i;
        auto [cx, cy] = a[i];
        res += 1ll * (cx - lst) * cur;
        while(j < a.size() && a[j][0] == a[i][0]) {
            auto [x, y] = a[j];
            int pos = lower_bound(f.begin(), f.end(), y) - f.begin();
            if(pos == f.size()) {
                f.emplace_back(y);
            } else {
                cur -= (q - f[pos] + 1);
                f[pos] = y;
            }
            cur += (q - f[pos] + 1);
            j ++;
        }
        i = j;
        lst = cx;
    }
    res += 1ll * (p - lst + 1) * cur;

    i64 tq = 1ll * q * (q + 1) / 2;
    i64 tp = 1ll * p * (p + 1) / 2;
    i64 ans = tp * (1 + q) + tq * (1 + p);
    cout << ans - res << '\n';
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