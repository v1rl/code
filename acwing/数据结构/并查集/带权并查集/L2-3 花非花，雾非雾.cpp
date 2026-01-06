#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

//https://pintia.cn/problem-sets/1901208334336921600/exam/problems/type/7?problemSetProblemId=1901208334366281738&page=0

struct DSU
{
	int n;
	vector<int> p, siz, dist;
	DSU(int n_)
	{
		init(n_);
	}

	void init(int n_)
	{
		n = n_;
		p.resize(n + 1);
		iota(p.begin(), p.end(), 0);
		dist.assign(n + 1, 0);
	}

	int find(int x)
	{
		if(x != p[x])
		{
			int t = find(p[x]);
			dist[x] ^= dist[p[x]];
			p[x] = t;
		}
		return p[x];
	}

	bool merge(int x, int y, int w)
	{
		int rx = find(x), ry = find(y);
		if(rx == ry) return false;
		if(ry == 0) swap(rx, ry), swap(x, y);
		p[ry] = rx;
		dist[ry] = dist[x] ^ dist[y] ^ w;
		return true;
	}

	void work(int n, int q)
	{
		int cnt = n + 1;
		while(q --)
		{
			char op;
			cin >> op;
			if(op == 'U')
			{
				int x, y, w;
				cin >> x >> y >> w;
				if(merge(x, y, w)) cnt --;
			}
			else
			{
				int x, w;
				cin >> x >> w;
				if(merge(x, 0, w)) cnt --;
			}
		}
		if(cnt == 1)
		{
			for(int i = 1; i <= n; i ++)
			{
				find(i);
				cout << dist[i] << ' ';
			}
		}
		else cout << "sad" << '\n';
	}
};

void solve()
{
	int n, q;
	cin >> n >> q;
	DSU dsu(n);
	dsu.work(n, q);
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --)
	{
		solve();
	}
}