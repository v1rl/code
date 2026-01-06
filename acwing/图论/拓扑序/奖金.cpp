#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<int> din(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x >> y;
		adj[y].emplace_back(x);
		din[x] ++;
	}

/*
	queue<int> q1;
	queue<int> q2;
	for(int i = 1; i <= n; i ++)
		if(din[i] == 0)
			q1.push(i);


	// 双队列循环
	int d = 100;
	int ans = 0;
	int num = 0;
	while(q1.size() || q2.size())
	{
		ans += d * q1.size();
		num += q1.size();
		if(q1.size()) d ++;
		while(q1.size())
		{
			int x = q1.front();
			q1.pop();

			for(auto y : adj[x])
				if(-- din[y] == 0)
					q2.push(y);
		}
		ans += q2.size() * d;
		num += q2.size();
		if(q2.size()) d ++;
		while(q2.size())
		{
			int x = q2.front();
			q2.pop();

			for(auto y : adj[x])
				if(-- din[y] == 0)
					q1.push(y);

		}
	}
	if(num == n) cout << ans << '\n';
	else cout << "Poor Xed" << '\n';
*/
	// 类差分约束
	queue<int> q;
	for(int i = 1; i <= n; i ++)
		if(din[i] == 0)
			q.push(i);

	vector<int> ans;
	ans.reserve(n);
	while(q.size())
	{
		int x = q.front();
		q.pop();
		ans.emplace_back(x);
		for(auto y : adj[x])
			if(-- din[y] == 0)
				q.push(y);
	}

	vector<int> dist(n + 1, 100);
	int res = 0;
	for(auto x : ans)
	{
		res += dist[x];
		for(auto y : adj[x])
		{
			dist[y] = max(dist[y], dist[x] + 1);
		}
	}
	if(ans.size() != n) cout << "Poor Xed" << '\n';
	else cout << res << '\n';
	return 0;
}