#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

struct SCC
{
    int n;
    vector<vector<int>> adj;
    vector<int> stk;
    vector<int> dfn, low, id;
    vector<int> siz, w;
    vector<vector<i64>> pre;
    vector<int> pos;
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
        w.assign(n, 0);
        pre.assign(n, {});
        pos.assign(n, 0);
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
            pre[cnt].emplace_back(0);
            do
            {
                y = stk.back();
                stk.pop_back();
                id[y] = cnt;
                siz[cnt] ++;
                w[cnt] += y;
                pre[cnt].emplace_back(y);
                // pos[y] = pre[cnt].size() - 1;
            }while(y != x);
        }
    }

    void work(int n, int q)
    {
        for(int i = 1; i <= n; i ++)
            if(!dfn[i])
                dfs(i);

        vector<int> step(n + 1, -1);
        vector<int> dist(n + 1, -1);
        vector<int> tonode(n + 1, -1);

        auto get = [&](auto &&self, int x, int &a, int &b, int &c)
        {
            int y = adj[x][0];
            if(id[x] == id[y])
            {
                a = 0;
                b = x;
                c = x;
                return;
            }
            int aa, bb, cc;
            self(self, y, aa, bb, cc);
            a = aa + 1;
            b = bb + x;
            c = cc;
        };

        for(int i = 1; i <= n; i ++)
        {
            if(step[i] == -1) get(get, i, step[i], dist[i], tonode[i]);
            dist[i] -= i;
        }

        for(int i = 1; i <= cnt; i ++)
        {
            reverse(pre[i].begin() + 1, pre[i].end());
            int len = pre[i].size() - 1;
            pre[i].resize(2 * len + 1);
            for(int j = 1; j <= len; j ++)
            {
                pre[i][j + len] = pre[i][j];
                pos[pre[i][j]] = j;
            }
            for(int j = 1; j <= len * 2; j ++)
            {
                pre[i][j] += pre[i][j - 1];
            }
        }

        while(q --)
        {
            i64 x, k;
            cin >> x >> k;
            i64 res = 0;
            if(k <= step[x])
            {
                while(k > 0 && id[x] != id[adj[x][0]])
                {
                    x = adj[x][0];
                    res += x;
                    k --;
                }
            }
            else
            {
                res += dist[x];
                k -= step[x];

                int tar = tonode[x];

                int stt = adj[tar][0];

                res += k / siz[id[tar]] * w[id[tar]];
                k %= siz[id[tar]];

                res += pre[id[tar]][pos[stt] + k - 1] - pre[id[tar]][pos[stt] - 1];
            }
            cout << res << '\n';
        }
    }
};


void solve()
{
    int n, q;
    cin >> n >> q;
    SCC scc(n);
    for(int i = 1; i <= n; i ++)
    {
        int y;
        cin >> y;
        scc.addEdge(i, y);
    }
    scc.work(n, q);
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --)
    {
        solve();
    }
}