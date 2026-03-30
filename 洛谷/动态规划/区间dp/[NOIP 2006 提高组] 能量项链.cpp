#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P1063

/*
f[左l][右r]的最大能量
*/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    vector f(n * 2, vector(n * 2, 0));
    for(int len = 2; len <= n; len ++) {
        for(int l = 0; l + len - 1 < n * 2 - 1; l ++) {
            int r = l + len - 1;

            for(int k = l; k < r; k ++) {
                f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + a[l] * a[k + 1] * a[r + 1]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        ans = max(ans, f[i][i + n - 1]);
    }

    cout << ans << '\n';
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