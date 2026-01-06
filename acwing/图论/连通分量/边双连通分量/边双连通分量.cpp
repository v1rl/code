#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;
struct EBCC
{
    int n;
    vector<vector<PII>> adj;
    vector<int> stk;
    vector<int> dfn, low, id;
    vector<int> siz;
    int tsp, cnt, m;

    EBCC(int n_)
    {
        init(n_);
    }

    void init(int n_)
    {
        n = n_ + 1;
        adj.assign(n + 1, {});
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        id.assign(n + 1, 0);
        siz.assign(n + 1, 0);
        stk.clear();
        m = tsp = cnt = 0;
    }

    void addEdge(int x, int y)
    {
        adj[x].emplace_back(y, m ++);
        adj[y].emplace_back(x, m ++);
    }

    void dfs(int x, int from)
    {
        dfn[x] = low[x] = ++ tsp;
        stk.emplace_back(x);

        for(auto [y, eid] : adj[x])
        {
            if(eid == (from ^ 1)) continue;
            if(!dfn[y])
            {
                dfs(y, eid);
                low[x] = min(low[x], low[y]);
            }
            else low[x] = min(low[x], dfn[y]);
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
                dfs(i, -1);
        
        vector<vector<int>> ans(cnt + 1);
        for(int i = 1; i <= n; i ++)
        {
            ans[id[i]].emplace_back(i);
        }
        cout << cnt << '\n';
        for(int i = 1; i <= cnt; i ++)
        {
            cout << ans[i].size() << ' ';
            for(auto j : ans[i]) cout << j << ' ';
            cout << '\n';
        }
    }
};

int main()
{
    int n, m;
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    EBCC ebcc(n);
    while(m --)
    {
        int x, y;
        cin >> x >> y;
        ebcc.addEdge(x, y);
    }

    ebcc.work(n);
}