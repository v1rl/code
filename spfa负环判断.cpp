#include <bits/stdc++.h>
using namespace std;
//https://www.luogu.com.cn/problem/P2850
int n, m, w;
const int N = 510;
typedef pair<int,int> PII;

bool spfa(vector<vector<PII>> adj)
{
//	vector<int> dist(n + 1, 0);
	vector<int> dist(n + 1);
	vector<int> st(n + 1, true);
	vector<int> cnt(n + 1, 0);
	queue<int> q;
	for(int i = 1; i <= n; i ++) q.push(i);

	while(q.size())
	{
		int x = q.front();
		q.pop();
		st[x] = false;
		for(auto [y, t] : adj[x])
		{
			if(dist[x] + t < dist[y])
			{
				dist[y] = dist[x] + t;
				cnt[y] = cnt[x] + 1;
				if(cnt[y] >= n) return true;
				if(!st[y])
				{
					q.push(y);
					st[y] = true;
				}
			}
		}
	}
	return false;
}

void solve()
{
	cin >> n >> m >> w;
	vector<vector<PII>> adj(n + 1);
	for(int i = 1; i <= m; i ++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		adj[x].push_back({y, t});
		adj[y].push_back({x, t});
	}
	for(int i = 1; i <= w; i ++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		adj[x].push_back({y, -t});
	}
	if(spfa(adj)) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
}