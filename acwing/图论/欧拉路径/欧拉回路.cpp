#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e5 + 10, M = 4e5 + 10;
int h[N], v[M], ne[M], idx;
bool st[M]; 
int din[N], dout[N];
int ans[M], cnt;
int type;


void add(int x, int y)
{
	v[idx] = y, ne[idx] = h[x], h[x] = idx ++;
}

void dfs(int x)
{
	for(int i = h[x]; i != -1; i = h[x])
	{
		if(st[i])
		{
			h[x] = ne[i];
			continue;
		}
		int y = v[i];
 
		st[i] = true;
		if(type == 1) st[i ^ 1] = true;

		h[x] = ne[i];
		dfs(y);

		if(type == 1)
		{
			int t = i / 2 + 1;
			if(i & 1) t = -t;
			ans[++ cnt] = t;
		}
		else ans[++ cnt] = i + 1;
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> type;
	int n, m;
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		if(type == 1) add(y, x);
		din[y] ++, dout[x] ++;
	}

	if(type == 1)
	{
		for(int i = 1; i <= n; i ++)
			if(din[i] + dout[i] & 1)
			{
				cout << "NO" << '\n';
				return 0;
			}
	}
	else
	{
		for(int i = 1; i <= n; i ++)
			if(din[i] != dout[i])
			{
				cout << "NO" << '\n';
				return 0;
			}
	}

	for(int i = 1; i <= n; i ++)
	{
		if(h[i] != -1)
		{
			dfs(i);
			break;
		}
	}

	if(cnt < m)
	{
		cout << "NO" << '\n';
		return 0;
	}

	cout << "YES" << '\n';
	for(int i = cnt; i; i --) cout << ans[i] << ' ';
	return 0;
}