#include <bits/stdc++.h>
using namespace std;
//https://www.acwing.com/problem/content/description/369/
const int N = 110;
int dfn[N], low[N], timestamp;
int id[N], scc_cnt;
int din[N], dout[N];
int stk[N], top;
bool in_stk[N];
vector<vector<int>> adj(N);

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
		int t;
		scc_cnt ++;
		do
		{
			t = stk[top --];
			in_stk[t] = false;
			id[t] = scc_cnt;
		}while(t != x);
	}
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		int t;
		while(cin >> t, t)
		{
			adj[i].push_back(t);
		}
	}

	for(int i = 1; i <= n; i ++)
	{
		if(!dfn[i]) tarjan(i);
	}

	for(int i = 1; i <= n; i ++)
	{
		int a = id[i];
		for(auto y : adj[i])
		{
			int b = id[y];
			if(a != b) din[b] ++, dout[a] ++;
		}
	}

	int num_in = 0;
	int num_out = 0;
	for(int i = 1; i <= scc_cnt; i ++)
	{
		if(!din[i]) num_in ++;
		if(!dout[i]) num_out ++;
	}
	int add = max(num_in, num_out);
	if(scc_cnt == 1) add = 0;

	cout << num_in << "\n";
	cout << add << "\n";
}