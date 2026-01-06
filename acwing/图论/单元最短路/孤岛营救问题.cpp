#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
set<PII> edges;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m, p;
	cin >> n >> m >> p;
	vector<vector<int>> g(n + 1, vector<int>(m + 1));
	vector<vector<PII>> adj(n * m + 1);
	vector<int> key(n * m + 1);
	int cnt = 0;

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			g[i][j] = ++ cnt;
	
	int s;
	cin >> s;
	for(int i = 0; i < s; i ++)
	{
		int x1, y1, x2, y2, op;
		cin >> x1 >> y1 >> x2 >> y2 >> op;
		int a = g[x1][y1], b = g[x2][y2];
		edges.insert({a, b}), edges.insert({b, a});
		if(op) adj[a].emplace_back(b, 1 << (op - 1)), adj[b].emplace_back(a, 1 << (op - 1));
	}

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			for(int k = 0; k < 4; k ++)
			{
				int nx = i + dx[k], ny = j + dy[k];
				if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
				int a = g[i][j], b = g[nx][ny];
				if(edges.count({a, b})) continue;
				adj[a].emplace_back(b, 0);
			}
		}

	int num;
	cin >> num;
	for(int i = 0; i < num; i ++)
	{
		int x, y, op;
		cin >> x >> y >> op;
		key[g[x][y]] |= 1 << (op - 1);
	}

	queue<PII> q;
	vector<vector<int>> dist(n * m + 1, vector<int>(1 << p, 1e9));
	int stt = g[1][1], edd = g[n][m];
	dist[stt][key[stt]] = 0;
	q.push({stt, key[stt]});
	while(q.size())
	{
		auto [x, state] = q.front();
		q.pop();
		for(auto [y, need_state] : adj[x])
		{
			int nstate = state | key[y]; 
			if((nstate | need_state) != nstate) continue;
			
			if(dist[y][pos] > dist[x][state] + 1)
			{
				dist[y][pos] = dist[x][state] + 1;
				q.push({y, pos});
			}
		}
	}
	
	int ans = 1e9;
	for(int i = 0; i < (1 << p); i ++) ans = min(ans, dist[edd][i]);
	if(ans == 1e9) cout << -1 << '\n';
	else cout << ans << '\n';
}