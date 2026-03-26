#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/ugly-number-ii/description/

const int mod = 1e9 + 7;
const i64 inf = 1e18;


void solve() {
    int n;
    cin >> n;

    /*
    // 暴力打表排序
    int w[3] = {2, 3, 5};
    vector<i64> ans;
    auto dfs = [&](auto &&self, int u, i64 res) -> void {
        if(u == 3) {
            ans.emplace_back(res);
            return;
        }
        i64 cur = 1;
        for(int i = 0; (i128)res * cur < inf; i ++) {
            self(self, u + 1, res * cur);
            cur *= w[u];
        }
    };

    dfs(dfs, 0, 1);
    sort(ans.begin(), ans.end());
    cout << ans[n - 1] << '\n';
    */

    int p[3] {};
    int w[3] = {2, 3, 5};
    vector<int> f(n);
    f[0] = 1;
    for(int i = 1; i < n; i ++) {
        i64 mn = inf;
        for(int i = 0; i < 3; i ++) {
            mn = min(mn, 1ll * f[p[i]] * w[i]);
        }
        f[i] = mn;
        for(int i = 0; i < 3; i ++) {
            if(1ll * f[p[i]] * w[i] == mn) {
                p[i] ++;
            }
        }
    }
    cout << f[n - 1] << '\n';
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
