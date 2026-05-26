#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://www.luogu.com.cn/problem/B3609

struct SCC {
    int n;
    vector<vector<int>> adj;
    vector<int> siz;
    vector<int> dfn, low, bel;
    vector<int> stk;
    int tsp, cnt;

    SCC(int n_) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        bel.assign(n + 1, 0);
        siz.resize(n + 1);
        adj.resize(n + 1);
        stk.clear();
        tsp = cnt = 0;
    }

    void dfs(int x) {
        dfn[x] = low[x] = ++ tsp;
        stk.emplace_back(x);
        for(auto y : adj[x]) {
            if(!dfn[y]) {
                dfs(y);
                low[x] = min(low[x], low[y]);
            } else if(!bel[y]) {
                low[x] = min(low[x], dfn[y]);
            }
        }

        if(dfn[x] == low[x]) {
            int y = stk.back();
            stk.pop_back();
            bel[y] = ++ cnt;
            siz[cnt] ++;
            while(y != x) {
                y = stk.back();
                stk.pop_back();
                bel[y] = cnt;
                siz[cnt] ++;
            }
        }
    }

    void addEdge(int x, int y) {
        adj[x].emplace_back(y);
    }

    void work() {
        for(int i = 1; i <= n; i ++) {
            if(!dfn[i]) {
                dfs(i);
            }
        }

        cout << cnt << '\n';
        vector<vector<int>> ans(cnt + 1);
        for(int i = 1; i <= n; i ++) {
            ans[bel[i]].emplace_back(i);
        }

        vector<int> vis(n + 1);
        for(int i = 1; i <= n; i ++) {
            if(!vis[i]) {
                vis[i] = true;
                for(auto x : ans[bel[i]]) {
                    vis[x] = true;
                    cout << x << ' ';
                }
                cout << '\n';
            }
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    SCC scc(n);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        scc.addEdge(x, y);
    }
    scc.work();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
