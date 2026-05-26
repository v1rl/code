#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
dfn[x] 执行dfs时x被遍历到的次序
low[x] x为根的子树最多经过一个回边的最小节点
回边：目标点已访问过但尚且还在栈中的边
*/

struct SCC {
    int n;
    vector<vector<int>> adj;
    vector<int> stk;
    vector<int> dfn, low, bel;
    vector<int> siz;
    int tsp, cnt;

    SCC(int n_) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        adj.assign(n + 1, {});
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        bel.assign(n + 1, 0);
        siz.assign(n + 1, 0);
        stk.clear();
        tsp = cnt = 0;
    }

    void addEdge(int x, int y) {
        adj[x].emplace_back(y);
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

    void work() {
        for(int i = 1; i <= n; i ++) {
            if(!dfn[i]) {
                dfs(i);
            }
        }
        
        for(int i = 1; i <= n; i ++) {
            cout << i << ' ' << bel[i] << '\n';
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    SCC scc(n);
    while(m --) {
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
