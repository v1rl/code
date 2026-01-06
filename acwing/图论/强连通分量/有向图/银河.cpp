#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// 对题目性质下的环特殊处理

struct SCC
{
    int n;
    vector<vector<PII>> adj;
    vector<int> stk;
    vector<int> dfn, low, id;
    vector<int> siz;
    int tsp, cnt;

    SCC(int n_)
    {
        init(n_);
    }

    void init(int n_)
    {
        n = n_ + 1;
        adj.assign(n, {});
        dfn.assign(n, 0);
        low.assign(n, 0);
        id.assign(n, 0);
        siz.assign(n, 0);
        stk.clear();
        tsp = cnt = 0;
    }

    void addEdge(int x, int y, int w)
    {
        adj[x].emplace_back(y, w);
    }

    void dfs(int x)
    {
        dfn[x] = low[x] = ++ tsp;
        stk.emplace_back(x);

        for(auto [y, w] : adj[x])
        {
            if(!dfn[y])
            {
                dfs(y);
                low[x] = min(low[x], low[y]);
            }
            else if(!id[y]) low[x] = min(low[x], dfn[y]);
        }

        if(dfn[x] == low[x])
        {
            int y;
            cnt ++;
            do
            {
                y = stk.back();
                stk.pop_back();
                id[y] = cnt;
                siz[cnt] ++;
            }while(y != x);
        }
    }

    void work(int n)
    {
        for(int i = 1; i <= n; i ++)
            if(!dfn[i])
                dfs(i);

        vector<vector<PII>> scc_adj(n + 1);
        for(int x = 1; x <= n; x ++)
        {
            for(auto [y, w] : adj[x])
            {
                int a = id[x], b = id[y];
                if(a != b) scc_adj[a].emplace_back(b, w);
                else if(w == 1)
                {
                    cout << "-1" << '\n';
                    return;
                }
            }
        }

        vector<int> f(cnt + 1);
        for(int x = cnt; x; x --)
        {
            if(!f[x]) f[x] = 1;
            for(auto [y, w] : scc_adj[x])
            {
                f[y] = max(f[y], f[x] + w);
            }
        }

        i64 ans = 0;
        for(int i = 1; i <= cnt; i ++)
        {
            ans += siz[i] * f[i];
        }
        cout << ans << '\n';
    }
};

int main()
{
    int n, m;
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    SCC scc(n);
    while(m --)
    {
        int x, y, op;
        cin >> op >> x >> y;
        if(op == 1) scc.addEdge(x, y, 0), scc.addEdge(y, x, 0);
        else if(op == 2) scc.addEdge(x, y, 1);
        else if(op == 3) scc.addEdge(y, x, 0);
        else if(op == 4) scc.addEdge(y, x, 1);
        else scc.addEdge(x, y, 0);
    }

    scc.work(n);
}