#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
int p[N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}, dw[4] = {1, 2, 1, 2};

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++) p[i] = i;
	vector<vector<int>> g(n + 1, vector<int>(m + 1));
	int cnt = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			g[i][j] = ++ cnt;

	vector<array<int, 3>> edges;
	edges.reserve(n * m * 2);
	int x1, y1, x2, y2;
	while(cin >> x1 >> y1 >> x2 >> y2)
	{
		int a = find(g[x1][y1]), b = find(g[x2][y2]);
		p[a] = b;
	}

	for(int z = 0; z < 2; z ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				for(int k = 0; k < 4; k ++)
					if(k & 1 == z)
					{
						int wx = i + dx[k], wy = j + dy[k];
						if(wx < 1 || wx > n || wy < 1 || wy > m) continue;
						int a = g[i][j], b = g[wx][wy];
						if(a > b) continue;
						int pa = find(a), pb = find(b);
						if(pa == pb) continue;
						edges.push_back({dw[k], a, b});
					}

	int res = 0;
	for(auto [w, x, y] : edges)
	{
		x = find(x), y = find(y);
		if(x == y) continue;
		res += w;
		p[x] = y;
	}

	cout << res << '\n';
	return 0;
}