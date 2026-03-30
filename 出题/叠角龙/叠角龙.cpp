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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<int> f(n + 1);
    int mx = -inf;
    for(int i = 1; i <= n; i ++) {
        f[i] = max(f[i - 1], min(m, a[i]));
        if(i > k) {
            f[i] = max(f[i], f[i - k - 1] + min(m, a[i]));
        }
        mx = max(mx, f[i]);
    }

    cout << mx << '\n';
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
