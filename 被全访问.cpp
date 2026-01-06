#include <bits/stdc++.h>
using namespace std;
//https://www.luogu.com.cn/problem/P2341
const int N = 1e4 + 10;
int dfn[N], low[N], timestamp = 0;
bool in_stack[N];
vector<vector<int>> adj(N);
int stk[N], top = 0;
int id[N], scc_cnt = 0;
int siz[N];
int dout[N];
int n, m;

void tarjan(int x)
{
	dfn[x] = low[x] = ++ timestamp;
	stk[++ top] = x, in_stack[x] = true;

	for(auto y : adj[x])
	{
		if(!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if(in_stack[y]) low[x] = min(low[x], dfn[y]);		// 二者皆可，用dfn可以体现小环
	}

	if(dfn[x] == low[x])
	{
		int t;
		++ scc_cnt;
		do
		{
			t = stk[top --];
			in_stack[t] = false;
			id[t] = scc_cnt;
			siz[scc_cnt] ++;
		}while(t != x);
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;	
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

	for(int i = 1; i <= n; i ++)
	{
		for(auto y : adj[i])
		{
			int a = id[i], b = id[y];
			if(a != b) dout[a] ++;
		}
	}

	int sum = 0, zeros = 0;
	for(int i = 1; i <= scc_cnt; i ++)
	{
		if(!dout[i])
		{
			sum += siz[i];
			zeros ++;
			if(zeros > 1)
			{ 
				sum = 0;
				break;
			}
		}
	}

	for(int i = 1; i <= n; i ++)
	{
		cout << dfn[i] << ' ' << low[i] << endl;
	}

	cout << sum << "\n";
	return 0;
}