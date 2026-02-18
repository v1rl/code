#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
数据范围极小，暴力搜索显然不行，考虑状压dp
题目的约束为行间的2*2约束，以及对合法状态的约束（只有黑变白）
转移的花费为当前状态与初始状态的黑白差异
*/

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector(m, '.'));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }

    int K = 1 << m;
    int raw = 0;
    vector<int> dp(K, inf);
    for(int j = 0; j < m; j ++) {
        if(g[0][j] == '#') {
            raw |= 1 << j;
        }
    }
    for(int x = 0; x < K; x ++) {
        if((x | raw) == raw) {
            dp[x] = __builtin_popcount(raw ^ x);
        }
    }

    vector ok(K, vector(K, 1));
    for(int i = 0; i < K; i ++) {
        for(int j = 0; j < K; j ++) {
            for(int k = 0; k < m - 1; k ++) {
                if((i >> k & 3) == 3 && (j >> k & 3) == 3) {
                    ok[i][j] = false;
                    break;
                }
            }
        }
    }

    for(int i = 1; i < n; i ++) {
        int raw = 0;
        for(int j = 0; j < m; j ++) {
            if(g[i][j] == '#') {
                raw |= 1 << j;
            }
        }

        vector<int> ndp(K, inf);
        for(int x = 0; x < K; x ++) {
            if((x | raw) != raw) {
                continue;
            }
            int c = __builtin_popcount(x ^ raw);
            for(int y = 0; y < K; y ++) {
                if(dp[y] == inf || !ok[x][y]) {
                    continue;
                }
                ndp[x] = min(ndp[x], dp[y] + c);
            }
        }

        dp = ndp;
    }

    int ans = inf;
    for(int x = 0; x < K; x ++) {
        ans = min(ans, dp[x]);
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