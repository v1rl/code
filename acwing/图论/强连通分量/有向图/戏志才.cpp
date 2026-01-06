#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

// https://ac.nowcoder.com/acm/contest/106250/D

// 找环问题

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
        n = n_;
        adj.assign(n + 1, {});
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        id.assign(n + 1, 0);
        siz.assign(n + 1, 0);
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
            else if(!id[y]) low[x] = min(low[x], dfn[y]);          //若y还在栈中，则当前点一定为返祖边或横插边
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

    void work(int m)
    {
        for(int i = 1; i <= n; i ++)
            if(!dfn[i])
                dfs(i);
        
        if(siz[id[m]] > 1) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
};

void solve()
{
	int n, m;
	cin >> n >> m;
	SCC scc(n);
	for(int y = 1; y <= n; y ++)
	{
		int x;
		cin >> x;
		scc.addEdge(x, y);
	}
	scc.work(m);
}

signed main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --)
	{
		solve();
	}
	return 0;
}