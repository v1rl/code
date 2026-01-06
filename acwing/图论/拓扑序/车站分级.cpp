#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
bool w[N][N];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> din(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int t;
		cin >> t;
		vector<bool> st(n + 1);
		vector<int> dat(t);
		for(int i = 0; i < t; i ++)
		{
			cin >> dat[i];
			st[dat[i]] = true;
		}

		for(int i = dat[0]; i <= dat[t - 1]; i ++)
		{
			if(st[i]) continue;
			for(auto j : dat) 
			{
				if(w[i][j]) continue;
				w[i][j] = true;
				din[j] ++;
			}
		}
	}

	queue<int> q;
	for(int i = 1; i <= n; i ++)
		if(din[i] == 0)
			q.push(i);

	vector<int> res;
	res.reserve(n);
	while(q.size())
	{
		int x = q.front();
		q.pop();
		res.emplace_back(x);
		for(int y = 1; y <= n; y ++)
			if(w[x][y])
				if(-- din[y] == 0)
					q.push(y);
	}

	// for(auto j : res) cout << j << ' ';

	vector<int> dist(n + 1, 1);
	for(auto x : res)
	{
		for(int y = 1; y <= n; y ++)
		{
			if(w[x][y]) dist[y] = max(dist[y], dist[x] + 1);
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i ++) ans = max(ans, dist[i]);
	cout << ans << '\n';
	return 0;

}