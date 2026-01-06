#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

struct SCC
{
    int n;
    vector<vector<int>> adj;
    vector<int> stk;
    vector<int> dfn, low, id;
    vector<int> siz;
    vector<vector<int>> s;
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
        s.assign(n + 1, {});
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
                s[cnt].emplace_back(y);
                siz[cnt] ++;
            }while(y != x);
        }
    }

    void work()
    {
        for(int i = 1; i <= n; i ++)
            if(!dfn[i])
                dfs(i);
        
 		vector<int> st(n + 1);
 		int cur = 0;
 		for(int i = 1; i <= n; i ++)
 		{
 			if(siz[id[i]] == 1 && adj[i][0] != i) cur ++;
 		}

 		for(int i = 1; i <= n; i ++)
 		{
 			int x;
 			cin >> x;
 			if(!st[x])
 			{
 				if(siz[id[x]] > 1)
 				{
 					cur += siz[id[x]];
 					for(auto c : s[id[x]])
 					{
 						st[c] = true;
 					}
 				}
 				else if(siz[id[x]] == 1 && adj[x][0] == x)
 				{
 					cur += 1;
 				}
 			}
 			cout << cur << ' ';
 		}
    }
};

void solve()
{
	int n;
	cin >> n;
	SCC scc(n);
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		scc.addEdge(i, x);
	}
	scc.work();
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	// t = 1;
	while(t --)
	{
		solve();
	}
	return 0;
}