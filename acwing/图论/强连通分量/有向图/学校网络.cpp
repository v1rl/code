#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
struct SCC
{
    int n;
    vector<vector<int>> adj;
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

    void addEdge(int x, int y)
    {
        adj[x].emplace_back(y);
    }

    void dfs(int x)
    {
        dfn[x] = low[x] = ++ tsp;
        stk.emplace_back(x);

        for(auto y : adj[x])
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

        vector<int> din(n + 1);
        vector<int> dout(n + 1);
        for(int i = 1; i <= n; i ++)
        {
            for(auto y : adj[i])
            {
                int a = id[i], b = id[y];
                if(a != b) din[b] ++, dout[a] ++;
            }
        }
        int ans1 = 0;
        int ans2 = 0;
        for(int i = 1; i <= cnt; i ++)
        {
            if(!din[i]) ans1 ++;
            if(!dout[i]) ans2 ++;
        }
        if(cnt == 1) cout << ans1 << '\n' << 0;
        else cout << ans1 << '\n' << max(ans1, ans2);
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    SCC scc(n);
    for(int i = 1; i <= n; i ++)
    {
        int y;
        while(cin >> y, y)
        {
            scc.addEdge(i, y);
        }
    }
    scc.work(n);
    return 0;
}
