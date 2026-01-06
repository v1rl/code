#include <bits/stdc++.h>
using namespace std;
//https://ybt.ssoier.cn/problem_show.php?pid=1525
const int N = 10010, M = 30010;
int dfn[N], low[N], timestamp;
int root, ans;
int n, m;

int h[N], v[M], ne[M], idx;

void add(int x, int y)
{
	v[idx] = y, ne[idx] = h[x], h[x] = idx ++;
}

void tarjan(int x)
{
	dfn[x] = low[x] = ++ timestamp;
	int cnt = 0;

	for(int i = h[x]; i != -1; i = ne[i])
	{
		int y = v[i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
			if(low[y] >= dfn[x]) cnt ++;
		}
		else low[x] = min(low[x], dfn[y]);
	}

	if(x != root && cnt) cnt ++;

	ans = max(ans, cnt);
}

void solve()
{
	memset(dfn, 0, sizeof dfn);
	memset(h, -1, sizeof h);
	idx = timestamp = 0;
	while(m --)
	{
		int x, y;
		cin >> x >> y;
		add(x, y), add(y, x);
	}

	int cnt = 0;
	ans = 0;
	for(root = 0; root < n; root ++)
	{
		if(!dfn[root])
		{
			cnt ++;
			tarjan(root);
		}
	}
	cout << ans + cnt - 1 << "\n";
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	while(cin >> n >> m, n || m)
	{
		solve();
	}
}