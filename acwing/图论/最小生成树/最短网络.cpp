#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> w(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cin >> w[i][j];

	int res = 0;
	vector<int> dist(n + 1, 1e9);
	vector<bool> st(n + 1);
	dist[1] = 0;
	for(int i = 0; i < n; i ++)
	{
		int t = -1;
		for(int j = 1; j <= n; j ++)
		{
			if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
		}
		st[t] = true;	
		res += dist[t];
		for(int j = 1; j <= n; j ++)
		{
			dist[j] = min(dist[j], w[t][j]);
		}
	}
	cout << res << '\n';
}