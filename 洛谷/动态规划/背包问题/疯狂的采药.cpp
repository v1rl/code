#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P1616

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> m >> n;
    vector<int> v(n), w(n);
    for(int i = 0; i < n; i ++) {
        cin >> v[i] >> w[i];
    }

    vector<i64> f(m + 1);
    for(int i = 0; i < n; i ++) {
        for(int j = v[i]; j <= m; j ++) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m] << '\n';
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
