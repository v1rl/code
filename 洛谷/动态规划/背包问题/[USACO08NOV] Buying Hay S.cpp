#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P2918

/*
f[买了至少i榜干草]的最少花销
*/

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n), w(n);
    for(int i = 0; i < n; i ++) {
        cin >> v[i] >> w[i];
    }

    vector f(m + 1, inf);
    f[0] = 0;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j <= m; j ++) {
            f[j] = min(f[j], f[max(0, j - v[i])] + w[i]);
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
