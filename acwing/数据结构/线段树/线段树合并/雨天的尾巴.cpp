#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

struct Info
{
	int ls = 0, rs = 0;
	int sum = 0;
	int num = 0;
};

template<class Info>
struct Segmentree
{
	int n;
	vector<Info> info;
	int idx = 0;

	Segmentree(int n_) : n(n_), info(n * 4 * (__lg(n) + 2) + 1) {};

	void pushup(int p)
	{
		int ls = info[p].ls, rs = info[p].rs;
		if(info[ls].sum >= info[rs].sum)
		{
			info[p].sum = info[ls].sum;
			info[p].num = info[ls].num;
		}
		else
		{
			info[p].sum = info[rs].sum;
			info[p].num = info[rs].num;
		}
	}

	void modify(int &p, int l, int r, int pos, int d)
	{
		if(!p) p = ++ idx;
		if(l == r) 
		{
			info[p].sum += d;
			info[p].num = pos;
			return;
		}
		int mid = l + r >> 1;
		if(pos <= mid) modify(info[p].ls, l, mid, pos, d);
		else modify(info[p].rs, mid + 1, r, pos, d);
		pushup(p);
	}

	void modify(int &p, int pos, int d)
	{
		modify(p, 1, n, pos, d);
	}

	void merge(int p, int &q, int l, int r)
	{
		if(!p || !q) 
		{
			q = p + q;
			return;
		}
		if(l == r)
		{
			info[q].sum += info[p].sum;
			return;
		}
		int mid = l + r >> 1;
		merge(info[p].ls, info[q].ls, l, mid);
		merge(info[p].rs, info[q].rs, mid + 1, r);
		pushup(q);
	}

	void merge(int p, int &q)
	{
		merge(p, q, 1, n);
	}

	int query(int p)
	{
		return (info[p].sum > 0 ? info[p].num : 0);
	}
};

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	vector<int> dep(n + 1);
	vector<array<int, 18>> f(n + 1);

	queue<int> q;
	q.push(1);
	dep[1] = 1;
	while(q.size())
	{
		int x = q.front();
		q.pop();
		for(auto y : adj[x])
		{
			if(dep[y]) continue;
			dep[y] = dep[x] + 1;
			f[y][0] = x;
			for(int i = 1; i <= 17; i ++)
				f[y][i] = f[f[y][i - 1]][i - 1];
			q.push(y);
		}
	}

	auto lca = [&](int x, int y)->int
	{
		if(dep[x] > dep[y])
			swap(x, y);
		for(int i = 17; i >= 0; i --)
			if(dep[f[y][i]] >= dep[x])
				y = f[y][i];
		if(x == y) return x;
		for(int i = 17; i >= 0; i --)
			if(f[y][i] != f[x][i])
				y = f[y][i], x = f[x][i];
		return f[x][0];
	};

	vector<int> root(n + 1);
	Segmentree<Info> tr(1e5);
	for(int i = 1; i <= m; i ++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		tr.modify(root[x], c, 1);
		tr.modify(root[y], c, 1);
		int p = lca(x, y);
		tr.modify(root[p], c, -1);
		tr.modify(root[f[p][0]], c, -1);
	}

	vector<int> ans(n + 1);
	auto dfs = [&](auto &&self, int x, int p)->void
	{
		for(auto y : adj[x])
		{
			if(y == p) continue;
			self(self, y, x);
			tr.merge(root[y], root[x]);
		}
		ans[x] = tr.query(root[x]);
	};

	dfs(dfs, 1, -1);

	for(int i = 1; i <= n; i ++)
		cout << ans[i] << '\n';
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
    return 0;
}