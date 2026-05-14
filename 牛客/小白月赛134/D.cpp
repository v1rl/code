#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

const i64 inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(n + m);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0];
        a[i][1] = 0;
    }
    for(int i = 0; i < m; i ++) {
        cin >> a[i + n][0];
        a[i + n][1] = 1;
    }
    sort(a.begin(), a.end());
    i64 A0 = inf, B0 = inf, AB = inf;
    for(int i = 0; i < n + m; i ++) {
        auto [x, op] = a[i];
        if(op) {
            A0 = min<i64>(A0, abs(x));
        } else {
            B0 = min<i64>(B0, abs(x));
        }
        if(i != 0 && a[i - 1][1] != a[i][1]) {
            AB = min<i64>(AB, abs(x - a[i - 1][0]));
        }
    }

    cout << min({A0 + B0 + AB, (AB + A0) * 2, (AB + B0) * 2}) << '\n';
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
