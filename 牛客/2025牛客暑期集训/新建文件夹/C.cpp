#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
#define int long long

void solve() {
    int n, h;
    cin >> n >> h;
    vector<array<int, 3>> a(n + 1);

    for(int i = 1; i <= n; i ++) {
        cin >> a[i][0];
        a[i][1] = h - a[i][0];
        a[i][2] = i;
    }

    sort(a.begin() + 1, a.end(), 
        [&](auto x, auto y) {
            return x[0] * x[1] < y[0] * y[1];
        });

    for(int i = 1; i <= n; i ++) {
        cout << a[i][2] << ' ';
    }

    cout << '\n';

}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
}