#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://ac.nowcoder.com/acm/contest/104870/H

template<class Info> 
struct Segmentree
{
	int n;
	vector<Info> info;
	int idx = 0;
	Segmentree(int n_) : n(n_), info(25 * 4 * n + 1) {};

	void pushup(int p)
	{
		info[p].sum = info[info[p].ls].sum + info[info[p].rs].sum;
	}

	void build(int &p, int l, int r, vector<int> &a, int op)
	{
		if(!p) p = ++ idx;
		if(l == r)
		{
			info[p].sum = a[l] == op ? 1 : 0;
			return;
		}
		int mid = l + r >> 1;
		build(info[p].ls, l, mid, a, op);
		build(info[p].rs, mid + 1, r, a, op);
		pushup(p);
	}

	void build(int &p, vector<int> &a, int op)
	{
		build(p, 1, n, a, op);
	}

	void modify(int &p, int &q, int l, int r, int x, int y)
	{
		if(y < l || x > r) return;
		if(x <= l && y >= r)
		{
			swap(p, q);
			return;
		}
		int mid = l + r >> 1;
		modify(info[p].ls, info[q].ls, l, mid, x, y);
		modify(info[p].rs, info[q].rs, mid + 1, r, x, y);
		pushup(p);pushup(q);
	}

	void modify(int &p, int &q, int x, int y)
	{
		modify(p, q, 1, n, x, y);
	}

	int query(int p, int l, int r, int x, int y)
	{
		if(y < l || x > r) return 0;
		if(x <= l && y >= r) return info[p].sum;
		int mid = l + r >> 1;
		return query(info[p].ls, l, mid, x, y) + query(info[p].rs, mid + 1, r, x, y);
	}

	int query(int p, int x, int y)
	{
		return query(p, 1, n, x, y);
	}
};

struct Info
{
	int pa;
	int ls = 0, rs = 0;
	int sum = 0;
};

void solve()
{
	int n, m;
	cin >> n >> m;
	Segmentree<Info> tr(n);
	vector<int> root(26);
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	for(int i = 1; i <= 25; i ++)
	{
		tr.build(root[i], a, i);
	}

	int q;
	cin >> q;
	while(q --)
	{
		int op;
		cin >> op;
		int l, r;
		cin >> l >> r;
		if(op == 1)
		{
			int x, y;
			cin >> x >> y;
			tr.modify(root[x], root[y], l, r);
		}
		else
		{
			int k;
			cin >> k;
			cout << tr.query(root[k], l, r) << '\n';
		}
	}
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