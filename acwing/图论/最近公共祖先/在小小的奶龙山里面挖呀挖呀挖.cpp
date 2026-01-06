#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

// https://www.luogu.com.cn/problem/P12001

vector<int> minp, primes;
void sieve(int n)
{
	minp.assign(n + 1, 0);
	for(int i = 2; i <= n; i ++)
	{
		if(!minp[i])
		{
			minp[i] = i;
			primes.emplace_back(i);
		}
		for(auto p : primes)
		{
			if(p * i > n) break;
			minp[p * i] = p;
			if(minp[i] == p) break;
		}
	}
}

vector<int> p;
int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void solve()
{
	sieve(1e5);
	int n, q;
	cin >> n >> q;
	p.resize(n + 1);
	iota(p.begin(), p.end(), 0);
	vector<vector<int>> adj(n + 1);
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	vector<vector<array<int, 2>>> query(n + 1);
	for(int i = 1; i <= q; i ++)
	{
		int x, y;
		cin >> x >> y;
		query[x].push_back({y, i});
		if(x != y) query[y].push_back({x, i});
	}

	vector<int> ans(q + 1);
	vector<int> fa(n + 1);

	for(auto pm : primes)
	{
		vector<int> st(n + 1);
		vector<int> ct(n + 1);
		iota(p.begin(), p.end(), 0);
		ct[1] = (a[1] / pm * pm == a[1]);
		auto tarjan = [&](auto &&self, int x, int pa)->void
		{
			for(auto y : adj[x])
			{
				if(y == pa) continue;
				fa[y] = x;
				ct[y] = ct[x] + (a[y] / pm * pm == a[y]);
				self(self, y, x);
				p[y] = x;
			}

			st[x] = true;
			for(auto [y, id] : query[x])
			{
				if(!st[y]) continue;
				int anc = find(y);
				if(ct[x] + ct[y] - ct[anc] - ct[fa[anc]]) ans[id] ++;
			}
		};
		tarjan(tarjan, 1, 0);
	}

	for(int i = 1; i <= q; i ++)
		cout << ans[i] << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --)
	{
		solve();
	}
	return 0;
}