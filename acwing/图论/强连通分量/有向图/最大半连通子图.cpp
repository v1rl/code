#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// 选一点必选强连通分量中的的所有其他点，考虑scc缩点
// 拓扑序最长链数量dp，类似最优方案数量dp

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

    void work(int n, int mod)
    {
        for(int i = 1; i <= n; i ++)
            if(!dfn[i])
                dfs(i);

        vector<vector<int>> scc_adj(cnt + 1);
        unordered_set<i64> S;
        for(int x = 1; x <= n; x ++)
        {
            for(auto y : adj[x])
            {
                int a = id[x], b = id[y];
                i64 hash = a * 100000ll + b;
                if(a != b && !S.count(hash))
                {
                    scc_adj[a].emplace_back(b);
                    S.insert(hash);
                }
            }
        }

        vector<int> f(n + 1);
        vector<int> g(n + 1);
        for(int x = cnt; x >= 1; x --)
        {
            if(!f[x])
            {
                f[x] = siz[x];
                g[x] = 1;
            }
            for(auto y : scc_adj[x])
            {
                if(f[x] + siz[y] > f[y])
                {
                    f[y] = f[x] + siz[y];
                    g[y] = g[x];
                }
                else if(f[x] + siz[y] == f[y])
                {
                    g[y] = (g[y] + g[x]) % mod;
                }
            }
        }

        int max_num = 0;
        int max_cnt = 0;
        for(int i = 1; i <= cnt; i ++)
        {
            if(f[i] > max_num)
            {
                max_num = f[i];
                max_cnt = g[i];
            }
            else if(f[i] == max_num)
            {
                max_cnt = (max_cnt + g[i]) % mod;
            }
        }

        cout << max_num << ' ' << max_cnt << '\n';
    }
};

int main()
{
    int n, m, mod;
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> mod;
    SCC scc(n);
    while(m --)
    {
        int x, y;
        cin >> x >> y;
        scc.addEdge(x, y);
    }

    scc.work(n, mod);
}