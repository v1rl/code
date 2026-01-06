#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m, k, t;
	cin >> n >> m >> k >> t;
	vector<int> nums(n + 1);
	for(int i = 1; i <= n; i ++) cin >> nums[i];

	vector<array<int, 3>> doors(k);
	vector<array<int, 3>> node;
	node.reserve(k * 2);
	for(int i = 0; i < k; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		node.push_back({b, 0, i});
		node.push_back({c, 1, i});
		doors[i] = {a, b, c};
	}
	sort(node.begin(), node.end());

	vector<vector<PII>> adj(n + 1);
	for(int i = 1; i <= m; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
	}

	vector<i64> ck(1 << k, -1);
	int res = 0;

	for(int i = 0; i < 2 * k; i ++)
	{
		auto [_, op, t] = node[i];
		if(op == 0) res += 1 << t;
		else res -= 1 << t;

		vector<int> state;
		for(int j = 0; j < k; j ++) 
			if(res >> j & 1)
				state.emplace_back(j);

		vector<int> dist(n + 1, 1e9);
		priority_queue<PII, vector<PII>, greater<PII>> heap;
		for(auto j : state)
		{
			dist[doors[j][0]] = 0;
			heap.push({0, doors[j][0]});
		}
		vector<bool> st(n + 1);

		while(heap.size())
		{
			auto [_, x] = heap.top();
			heap.pop();
			if(st[x]) continue;
			st[x] = true;
			for(auto [y, w] : adj[x])
			{
				if(dist[y] > dist[x] + w)
				{
					dist[y] = dist[x] + w;
					heap.push({dist[y], y});
				}
			}
		}

		i64 ans = 0;
		for(int j = 1; j <= n; j ++) 
		{
			if(dist[j] == 1e9)
			{
				ans = -1;
				break;
			}
			ans += dist[j] * (i64)nums[j];
		}
		ck[res] = ans;
	}

	for(int i = 1; i <= t; i ++)
	{
		int res = 0;
		for(int j = 0; j < k; j ++)
		{
			auto [a, l, r] = doors[j];
			if(i >= l && i <= r) 
				res += 1 << j;
		}

		cout << ck[res] << '\n';
	}
	return 0;
}