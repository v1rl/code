#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://ac.nowcoder.com/acm/contest/77448/E

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 	int n;
 	cin >> n;
 	vector<int> a(n + 1);
 	for(int i = 1; i <= n; i ++)
 		cin >> a[i];
 	vector<vector<int>> adj(n + 1);
 	for(int i = 2; i <= n; i ++)
 	{
 		int x;
 		cin >> x;
 		adj[x].emplace_back(i);
	}

 	int tsp = 0;
 	vector<int> lst(n + 1);
 	int mx = 0;
 	int ans = 0;
 	vector<int> g(n + 1);			//序列

 	auto dfs = [&](auto &&self, int x)->void
 	{
 		int l = ++ tsp;
 		// g[x] = lst[a[x]];
 		mx = max(mx, lst[a[x]]);
 		lst[a[x]] = tsp;
 		for(auto y : adj[x])
 			self(self, y);
 		if(mx < l) ans ++;
 	};

 	dfs(dfs, 1);
 	// for(int i = 1; i <= n; i ++)
 	// 	cout << i << ' ' << g[i] << '\n';
 	cout << ans << '\n';
}