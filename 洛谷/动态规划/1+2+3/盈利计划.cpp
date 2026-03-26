#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/ones-and-zeroes/description/

/*
f[前i个数][人数为j][收益为k]的情况数
*/

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(m + 1), w(m + 1);
    for(int i = 1; i <= m; i ++) {
        cin >> v[i];
    }
    for(int i = 1; i <= m; i ++) {
        cin >> w[i];
    }

    int tar;
    cin >> tar;

    vector f(n + 1, vector(tar + 1, 0));
    f[0][0] = 1;

    for(int i = 1; i <= m; i ++) {
        for(int j = n; j >= v[i]; j --) {
            for(int k = tar; k >= 0; k --) {
                f[j][k] += f[j - v[i]][max(0, k - w[i])];
                f[j][k] %= mod;
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= n; j ++) {
        ans += f[j][tar];
        ans %= mod;
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
