#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
比较直观的想法是，用染色法判断二分图的同款方式正向染色去搜索，并对颜色相同的边进行删除操作
但显然，这样的贪心是不正确的，我们不一定非得删那条边
注意到本题特殊的取值范围，不难联想到做法大概为 2^n
由此，我们可以反向去考虑，先指定颜色然后判断当前图需要删除多少条边
取所有可能染色图的最小结果即为最终答案
*/

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n + 1);
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    int ans = inf;

    vector<int> st(n + 1);
    int res = 0;
    auto dfs1 = [&](auto &&self, int x) -> void {
        st[x] = true;
        for(auto y : adj[x]) {
            // 需要注意，确保一条边会被统计且一定统计两次，统计操作应该在判断若则访问跳过
            if(c[y] == c[x]) {
                res ++;
            }
            if(st[y]) {
                continue;
            }
            self(self, y);
        }
    };

    auto dfs = [&](auto &&self, int cur) ->void {
        if(cur == n + 1) {
            st.assign(n + 1, 0);
            res = 0;
            st[1] = true;
            dfs1(dfs1, 1);
            ans = min(ans, res / 2);
            return;
        }

        c[cur] = 1;
        self(self, cur + 1);
        c[cur] = 2;
        self(self, cur + 1);
    };

    dfs(dfs, 1);

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
