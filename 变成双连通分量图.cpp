#include <bits/stdc++.h>
using namespace std;
//https://www.acwing.com/problem/content/397/
const int N = 1e4 + 10;
const int M = 2e4 + 10;

int dfn[N], low[N], timestamp;
int id[N], dcc_cnt;
bool is_bridge[M];
int stk[N], top;
int d[N];

int h[N], v[M], ne[M], idx;

void add(int x, int y)
{
	v[idx] = y, ne[idx] = h[x], h[x] = idx ++;
}

void tarjan(int x, int from)
{
	dfn[x] = low[x] = ++ timestamp;
	stk[++ top] = x;

	for(int i = h[x]; i != -1; i = ne[i])
	{
		int y = v[i];
		if(!dfn[y])
		{
			tarjan(y, i);
			low[x] = min(low[x], low[y]);
			if(low[y] > dfn[x]) is_bridge[i] = is_bridge[i ^ 1] = true;
		}
		else if(i != (from ^ 1)) low[x] = min(low[x], dfn[y]);
	}	

	if(dfn[x] == low[x])
	{
		dcc_cnt ++;
		int t;
		do {
			t = stk[top --];
			id[t] = dcc_cnt;
		} while(t != x);
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	memset(h, -1, sizeof h);
	for(int i = 1; i <= m; i ++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y), add(y, x);
	}

	tarjan(1, -1);

	for(int i = 0; i < idx; i ++)
	{
		if(is_bridge[i]) d[id[v[i]]] ++;
	}

	int cnt = 0;
	for(int i = 1; i <= dcc_cnt; i ++)
	{
		if(d[i] == 1) cnt ++;
	}
	
	cout << (cnt + 1) / 2 << "\n";
}