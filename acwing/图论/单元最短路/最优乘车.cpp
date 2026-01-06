#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 510;
int g[N][N];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> m >> n;
	memset(g, 0x3f, sizeof g);
	string line;
	getline(cin, line);
	while(m --)
	{
		string line;
		getline(cin, line);
		stringstream ssin(line);
		vector<int> a;
		a.reserve(500);
		int t;
		while(ssin >> t) a.emplace_back(t - 1);
		for(int i = 0; i < a.size(); i ++)
		{
			for(int j = i + 1; j < a.size(); j ++)
			{
				int x = a[i], y = a[j];
				g[x][y] = true;
			}
		}
	}
	int stt = 0, edd = n - 1;

	vector<int> dist(n, 1e9);
	vector<int> st(n);
	dist[stt] = 0;
	for(int i = 0; i < n; i ++)
	{
		int x = -1;
		for(int j = 0; j < n; j ++)
		{
			if(!st[j] && (x == -1 || dist[x] > dist[j])) x = j;
		}
		st[x] = true;
		for(int j = 0; j < n; j ++) dist[j] = min(dist[j], dist[x] + g[x][j]);
	}
	if(dist[edd] == 1e9) cout << "NO" << '\n';
	else cout << dist[edd] - 1 << '\n';
	return 0;
}
