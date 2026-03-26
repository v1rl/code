#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://www.luogu.com.cn/problem/P1417

const i64 inf = 1e18;

void solve() {
    int n, m;
    cin >> m >> n;
    vector<array<int, 3>> d(n);
    for(int i = 0; i < n; i ++) {
        cin >> d[i][0];
    }
    for(int i = 0; i < n; i ++) {
        cin >> d[i][1];
    }
    for(int i = 0; i < n; i ++) {
        cin >> d[i][2];
    }

    sort(d.begin(), d.end(), 
        [&](auto x, auto y) {
            return 1ll * x[2] * y[1] < 1ll * y[2] * x[1];
        });

    vector<i64> f(m + 1, -inf);
    f[0] = 0;

    for(int i = 0; i < n; i ++) {
        auto [a, b, c] = d[i];
        for(int j = m; j >= c; j --) {
            f[j] = max(f[j], f[j - c] + a - 1ll * j * b);
        }
    }

    cout << *max_element(f.begin(), f.end()) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}