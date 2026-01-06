#include <bits/stdc++.h>
using namespace std;
//https://www.luogu.com.cn/problem/P2272
const int N = 1e5 + 10;						//最长链
typedef long long LL;
int dfn[N], low[N], timestamp;
int id[N], scc_cnt;
int stk[N], top;
bool in_stk[N];
int siz[N];
vector<vector<int>> adj(N);
vector<vector<int>> scc_adj(N);
int n, m, mod;
int f[N], g[N];

void tarjan(int x)
{
	dfn[x] = low[x] = ++ timestamp;
	stk[++ top] = x, in_stk[x] = true;
	for(auto y : adj[x])
	{
		if(!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if(in_stk[y]) low[x] = min(low[x], dfn[y]);
	}

	if(dfn[x] == low[x])
	{
		scc_cnt ++;
		int t;
		do
		{
			t = stk[top --];
			in_stk[t] = false;
			id[t] = scc_cnt;
			siz[scc_cnt] ++;
		}while(t != x);
	}
}
 
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> mod;
	for(int i = 1; i <= m; i ++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
	}

	for(int i = 1; i <= n; i ++)
	{
		if(!dfn[i]) tarjan(i);
	}

	unordered_set<LL> S;
	for(int i = 1; i <= n; i ++)
	{
		int a = id[i];
		for(auto y : adj[i])
		{
			int b = id[y];
			LL hash = a * 100000ll + b;
			if(a != b && !S.count(hash)) 
			{
				scc_adj[a].emplace_back(b);
				S.insert(hash);
			}
		}
	}

	for(int i = scc_cnt; i; i --)
	{
		if(!f[i])
		{
			f[i] = siz[i];
			g[i] = 1;
		}
		int x = i;
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

	int max_num = 0, max_cnt = 0;
	for(int i = 1; i <= scc_cnt; i ++)
	{
		if(f[i] > max_num)
		{
			max_num = f[i];
			max_cnt = g[i]; 
		}
		else if(f[i] == max_num) max_cnt = (max_cnt + g[i]) % mod;
	}
	cout << max_num << "\n";
	cout << max_cnt << "\n";
	return 0;
}