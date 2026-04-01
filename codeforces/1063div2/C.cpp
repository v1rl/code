#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;

    vector a(2, vector(n, 0));
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> a[i][j];
            a[i][j] --;
        }
    }

    auto pmx = a[0], pmn = a[0], smx = a[1], smn = a[1];
    for(int i = 1; i < n; i ++) {
        pmx[i] = max(pmx[i - 1], pmx[i]);
        pmn[i] = min(pmn[i - 1], pmn[i]);
    }
    for(int i = n - 2; i >= 0; i --) {
        smx[i] = max(smx[i + 1], smx[i]);
        smn[i] = min(smn[i + 1], smn[i]);
    }

    vector<int> f(2 * n + 1, 2 * n);
    for(int i = 0; i < n; i ++) {
        int l = min(pmn[i], smn[i]);
        int r = max(pmx[i], smx[i]);
        f[l] = min(f[l], r);
    }

    for(int i = 2 * n - 2; i >= 0; i --) {
        f[i] = min(f[i], f[i + 1]);
    }

    i64 ans = 0;
    for(int i = 2 * n - 1; i >= 0; i --) {
        ans += 2 * n - f[i];
    }

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
