#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
给你一个表示交易的数组 transactions
其中 transactions[i] = [fromi, toi, amounti]
表示 ID = fromi 的人给 ID = toi 的人共计 amounti
请你计算并返回还清所有债务的最小交易笔数
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < m; i ++) {
        int x, y, v;
        cin >> x >> y >> v;
        a[x] -= v, a[y] += v;
    }

    vector<int> w;
    for(int i = 0; i < n; i ++) {
        if(a[i] != 0) {
            w.emplace_back(a[i]);
        }
    }
    n = w.size();

    vector<int> f(1 << n, -1);
    auto dfs = [&](auto &&self, int s, int sum) -> int {
        if(s == 0) {
            return 0;
        }
        if(f[s] != -1) {
            return f[s];
        }

        int res = 0;
        for(int i = 0; i < n; i ++) {
            if(s >> i & 1) {
                res = max(res, self(self, s ^ (1 << i), sum - w[i]));
            }
        }

        if(sum == 0) {
            res ++;
        }

        return f[s] = res;
    };

    cout << n - dfs(dfs, (1 << n) - 1, 0);
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
