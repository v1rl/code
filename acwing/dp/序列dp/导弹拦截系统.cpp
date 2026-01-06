#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	while(cin >> n, n)
	{
		vector<int> a(n);
		vector<int> up(n);
		vector<int> down(n);
		for(int i = 0; i < n; i ++)
		{
			cin >> a[i];
		}
		int ans = n;
		auto dfs = [&](auto && self, int u, int su, int sd)->void
		{
			if(su + sd >= ans) return;

			if(u == n)
			{
				ans = min(ans, su + sd);
				return;
			}

			int k = 0;
			while(k < su && a[u] <= up[k]) k ++;
			int t = up[k];
			up[k] = a[u];
			if(k < su) self(self, u + 1, su, sd);
			else self(self, u + 1, su + 1, sd);
			up[k] = t;

			k = 0;
			while(k < sd && a[u] >= down[k]) k ++;
			t = down[k];
			down[k] = a[u];
			if(k < sd) self(self, u + 1, su, sd);
			else self(self, u + 1, su, sd + 1);
			down[k] = t;
		};

		dfs(dfs, 0, 0, 0);
		cout << ans << '\n';
	}
	return 0;
}