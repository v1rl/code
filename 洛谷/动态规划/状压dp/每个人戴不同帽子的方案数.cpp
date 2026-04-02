#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/number-of-ways-to-wear-different-hats-to-each-other/description/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int m = 40;
    vector f(m + 1, vector(1 << n, 0));

    vector<vector<int>> g(n);
    vector<vector<int>> hat(m + 1);
    for(int i = 0; i < n; i ++) {
        int t;
        cin >> t;
        for(int j = 0; j < t; j ++) {
            int x;
            cin >> x;
            g[i].emplace_back(x);
            hat[x].emplace_back(i);
        }
    }

    f[0][0] = 1;
    for(int i = 1; i <= m; i ++) {
        for(int mask = 0; mask < (1 << n); mask ++) {
            if(f[i - 1][mask] == 0) {
                continue;
            }
            f[i][mask] += f[i - 1][mask];
            f[i][mask] %= mod;
            for(auto j : hat[i]) {
                if(~mask >> j & 1) {
                    f[i][mask ^ (1 << j)] += f[i - 1][mask];
                    f[i][mask ^ (1 << j)] %= mod;
                }
            }
        }
    }

    cout << f[m][(1 << n) - 1] << '\n';
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
