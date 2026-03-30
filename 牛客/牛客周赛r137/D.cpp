#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
*/

const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<i64> f(n + 1, inf);
    vector<i64> suf(n + 1), mn(n + 1, inf);
    f[0] = 0;
    for(int i = 1; i <= n; i ++) {
        suf[i] = a[i];
        for(int j = i - 1; j >= 0; j --) {
            suf[j] = suf[j + 1] ^ a[j];
            mn[j] = min(mn[j + 1], f[j]);
        }
        for(int j = i; j >= 1; j --) {
            f[i] = min(f[i], suf[j] + mn[j - 1]);
        }
    }

    cout << f[n] << '\n';
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
