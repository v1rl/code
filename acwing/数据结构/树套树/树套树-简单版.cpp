#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9 + 10;

template<class Info>
struct Segmentree
{
	int n;
	vector<Info> info;

	Segmentree(int n_) : n(n_), info(4 * n + 1) {};
	Segmentree(vector<int> &a) : Segmentree(a.size() - 1)
	{
		function<void(int, int, int)> build = [&](int p, int l, int r)
		{
			for(int i = l; i <= r; i ++)
			{
				info[p].s.insert(a[i]);
			}
			if(l == r) return;
            int mid = l + r >> 1;
            build(p << 1, l, mid);
            build(p << 1 | 1, mid + 1, r);
		};
		build(1, 1, n);
	}

	void modify(int p, int l, int r, int pos, int x, int y)
	{
		info[p].s.extract(x);
		info[p].s.insert(y);
		if(l == r) return;
		int mid = l + r >> 1;
		if(pos <= mid) modify(p << 1, l, mid, pos, x, y);
		else modify(p << 1 | 1, mid + 1, r, pos, x, y);
	}

	void modify(int pos, int x, int y)
	{
		modify(1, 1, n, pos, x, y);
	}

	int query(int p, int l, int r, int x, int y, int t)
	{
		if(r < x || l > y) return -inf;
		if(x <= l && r <= y)
		{
			auto pos = info[p].s.lower_bound(t);
			if(pos != info[p].s.begin()) return *(--pos);
			return -inf;
		}
		int mid = l + r >> 1;
		return max(query(p << 1, l, mid, x, y, t), query(p << 1 | 1, mid + 1, r, x, y, t));
	}

	int query(int x, int y, int t)
	{
		return query(1, 1, n, x, y, t);
	}
};

struct Info
{
	int act = 0;
	multiset<int> s;
};

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		a[i] = x;
	}
	Segmentree<Info> tr(a);

	while(m --)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int pos, x;
			cin >> pos >> x;
			tr.modify(pos, a[pos], x);
			a[pos] = x;
		}
		else
		{
			int l, r, x;
			cin >> l >> r >> x;
			cout << tr.query(l, r, x) << '\n';
		}
	}
	return 0;
}