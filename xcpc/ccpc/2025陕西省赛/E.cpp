#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

/*
f[j][mask]，当前状态为mask，光标停在j之后的最小代价
*/

const int inf = 1e9;

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    string s;
    cin >> s;
    vector w(m, vector(m, 0));
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> w[i][j];
        }
    }

    vector f(n, vector(1 << n, inf));
    f[0][0] = 0;

    for(int k = 0; k < n; k ++) {
        f[k][1 << k] = min(f[k][1 << k], w[0][s[k] - 'a'] + t);
    }

    for(int mask = 1; mask < (1 << n); mask ++) {
        for(int j = 0; j < n; j ++) {
            if(f[j][mask] == inf) {
                continue;
            }

            int curPos = __builtin_popcount(mask & ((1 << (j + 1)) - 1));
            for(int k = 0; k < n; k ++) {
                if(~mask >> k & 1) {
                    int tarPos = __builtin_popcount(mask & ((1 << k) - 1));
                    int d = abs(tarPos - curPos);
                    f[k][mask ^ (1 << k)] = min(f[k][mask ^ (1 << k)], f[j][mask] + t * d + w[s[j] - 'a'][s[k] - 'a'] + t);
                }
            }
        }
    }

    int ans = inf;
    for(int j = 0; j < n; j ++) {
        ans = min(f[j][(1 << n) - 1], ans);
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
