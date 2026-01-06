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

    int work(int n)
    {
        for(int i = 1; i <= n; i ++)
            if(!dfn[i])
                dfs(i);
        
        vector<int> dout(n + 1);
        for(int x = 1; x <= n; x ++)
        {
            for(auto y : adj[x])
            {
                int a = id[x], b = id[y];
                if(a != b) dout[a] ++;
            }
        }

        int group = 0;
        int ans = 0;
        for(int i = 1; i <= cnt; i ++)
            if(!dout[i])
            {
                group ++;
                ans += siz[i];
            }
        if(group > 1) return 0;
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    SCC scc(n);
    while(m --)
    {
        int x, y;
        cin >> x >> y;
        scc.addEdge(x, y);
    }

    cout << scc.work(n) << '\n';
}
