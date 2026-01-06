#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	vector<int> din(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int x;
		while(cin >> x, x)
		{
			adj[i].emplace_back(x);
			din[x] ++;
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

		for(auto y : adj[x])
			if(-- din[y] == 0) 
				q.push(y);
	}

	for(auto t : res) cout << t << ' ';
	return 0;
}