#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<double> c(n + 1), r(n + 1);
    double p;
    double L, R;
    cin >> r[0] >> c[0] >> p >> L >> R;

    for(int i = 1; i <= n; i ++) {
        r[i] = L;
    }

    while(m --) {
        int id;
        double x;
        cin >> id >> x;
        r[id] = x;
    }

    double ans = 0;
    for(int i = 1; i <= n; i ++) {
        c[i] = c[i - 1] * p + (1 - p) * r[i - 1];
        ans += c[i] - r[i];
    }

    cout << fixed << setprecision(10);
    cout << ans << '\n';
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
