#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int n, m, k;

bool check(int mid, vector<vector<PII>> &adj)
{
	vector<int> dist(n + 1, 1e9);
	vector<bool> st(n + 1);
	dist[1] = 0;
	deque<int> q;
	q.push_back(1);
	while(q.size())
	{
		int x = q.front();
		q.pop_front();
		if(st[x]) continue;
		st[x] = true;
		for(auto [y, w] : adj[x])
		{
			if(w > mid && dist[y] > dist[x] + 1) dist[y] = dist[x] + 1, q.push_back(y);
			else if(w <= mid && dist[y] > dist[x]) dist[y] = dist[x], q.push_front(y);
		}
	}
	if(dist[n] <= k) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k;
	vector<vector<PII>> adj(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
	}

	int l = 0, r = 1000001;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid, adj)) r = mid;
		else l = mid + 1;
	}
	if(l == 1000001) cout << -1 << '\n';
	else cout << l << '\n';

}