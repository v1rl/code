#include <bits/stdc++.h>
using namespace std;
const int N = 110;
struct Node
{
	int v, w, l;
	bool operator < (const Node & W) const
	{
		return v * W.l < W.v * l;
	}
}dat[N];
int cnt;

void solve()
{
	int n, m = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		int v, w, l;
		cin >> v >> w >> l;
		dat[i] = {v, w, l};
		m += v;
	}
	sort(dat + 1, dat + n + 1);
	vector<int> f(m + 1, -1e9);
	f[0] = 0;
	for(int i = 1; i <= n; i ++)
	{
		int v = dat[i].v, w = dat[i].w, l = dat[i].l;
		for(int j = m; j >= v; j --)
		{
			f[j] = max(f[j], f[j - v] + max(0, w - (j - v) * l));
		}
	}
	int ans = 0;
	for(int i = 0; i <= m; i ++) ans = max(ans, f[i]);
	printf("Case #%d: %d\n", ++ cnt, ans);
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> T;
	while(T --)
	{
		solve();
	}
	return 0;
}