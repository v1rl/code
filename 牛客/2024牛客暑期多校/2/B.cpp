#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 100010;
constexpr int B = 100;
int p[200010];

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;

	vector<array<int, 3>> edges(m);
	for(int i = 0; i < m; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x --, y --;
		edges[i] = {w, x, y};
	}
	
	sort(edges.begin(), edges.end());

	vector<vector<int>> v(q);
	vector<vector<int>> e(q);
	vector<vector<int>> query(n);
 
	for(int i = 0; i < q; i ++)
	{
		int k;
		cin >> k;
		v[i].resize(k);

		for(int j = 0; j < k; j ++)
		{
			cin >> v[i][j];
			v[i][j] --;
			query[v[i][j]].push_back(i);
		}

		e[i].reserve(min(m, k * (k - 1) / 2));
	} 

	vector<bitset<N> *> bit(n);
	for(int i = 0; i < n; i ++)
	{
		if(query[i].size() > B)
		{
			bit[i] = new bitset<N>;
			for(auto j : query[i])
			{
				bit[i]->set(j);
				// bit[i][j] = 1;
			}
		}
	}


	for(int i = 0; i < m; i ++)
	{
		auto [w, x, y] = edges[i];
		if(query[x].size() > query[y].size()) swap(x, y);

		if(query[y].size() > B)
		{
			for(auto j : query[x])
			{
				if((*bit[y])[j]) e[j].push_back(i);
			}
		}
		else
		{
			int k = 0;
			for(auto j : query[x])
			{
				while(k < query[y].size() && query[y][k] < j) k ++;
				if(k < query[y].size() && query[y][k] == j) e[j].push_back(i);
			}
		}
	}

	for(int i = 0; i < q; i ++)
	{
		int comp = v[i].size();
		i64 ans = 0;
		for(auto j : v[i]) p[j] = j;
		for(auto j : e[i])
		{
			auto [w, x, y] = edges[j];
			x = find(x), y = find(y);
			if(x == y) continue;
			comp --;
			ans += w;
			p[x] = y;
		}
		if(comp > 1) ans = -1;
		cout << ans << "\n";
	}

	return 0;
}