#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
struct SCC {
    int n;
    vector<vector<int>> adj;
    vector<int> stk;
    // dfn[x]--执行dfs时x被遍历到的次序，low[x]--在x为根的子树能回溯到的第一个更早的节点(不需要是最早的节点)
    // 二者相等代表x即为环的起点
    vector<int> dfn, low, id;
    vector<int> siz;
    // cnt表示缩点后点的数量
    int tsp, cnt;

    SCC(int n_) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        adj.assign(n + 1, {});
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        id.assign(n + 1, 0);
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
            if(!dfn[y]) {       //树边
                dfs(y);
                low[x] = min(low[x], low[y]);
            }
            else if(!id[y]) {
                low[x] = min(low[x], dfn[y]);   //若y还在栈中，以x为根的子树中一定存在一条返祖边，x是以这条返祖边为基础的环的一部分
            }
        }

        if(dfn[x] == low[x]) {
            int y;
            cnt ++;
            do {
                y = stk.back();
                stk.pop_back();
                id[y] = cnt;
                siz[cnt] ++;
            } while(y != x);
        }
    }

    void work() {
        for(int i = 1; i <= n; i ++)
            if(!dfn[i])
                dfs(i);
        
        for(int i = 1; i <= n; i ++) {
            cout << i << ' ' << id[i] << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    SCC scc(n);
    while(m --) {
        int x, y;
        cin >> x >> y;
        scc.addEdge(x, y);
    }
    scc.work();
    return 0;
}
