#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e7 + 5e6;

struct Tag
{
	i64 add = 0;

	void apply(const Tag &t)
	{
		add += t.add;
	}
}tag[N];

struct Info
{
	int l, r;
	i64 sum = 0;
	int add = 0;

	void apply(const Tag &t, int l, int r)
	{
		sum += 1ll * (r - l + 1) * t.add;
	}
}info[N];

struct Segmentree
{
	int n;
	int idx = 0;

	Segmentree(int n_) : n(n_) {};

	void apply(int p, const Tag &t, int l, int r)	//懒标记的应用与l，r有关，作为参数传递
	{
		info[p].apply(t, l, r);
		tag[p].apply(t);
	}

	void pushdown(int p, int l, int r)
	{
		int mid = l + r >> 1;
		if(!info[p].l) 						//pushdown过程可能会遇到没有开的点，需要先开点在传递
			info[p].l = ++ idx;
		apply(info[p].l, tag[p], l, mid);
		if(!info[p].r) 
			info[p].r = ++ idx;
		apply(info[p].r, tag[p], mid + 1, r);
		tag[p] = Tag{};
	}

	void modify(int &p, int l, int r, int x, int y)
	{
		if(r < x || l > y) return;
		if(!p) p = ++ idx;
		if(x <= l && r <= y) 
		{
			apply(p, {1}, l, r);
			return;
		}
		info[p].sum += min(r, y) - max(l, x) + 1;
		int mid = l + r >> 1;
		modify(info[p].l, l, mid, x, y);
		modify(info[p].r, mid + 1, r, x, y);
	}

	void modify(int &p, int x, int y)
	{
		modify(p, 1, n, x, y);
	}

	i64 query(int p, int l, int r, int x, int y)
	{
		if(r < x || l > y) return 0ll;
		if(!p) return 0ll;
		if(x <= l && r <= y) return info[p].sum;
		pushdown(p, l, r);
		int mid = l + r >> 1;
		return query(info[p].l, l, mid, x, y) + query(info[p].r, mid + 1, r, x, y);
	}

	i64 query(int p, int x, int y)
	{
		return query(p, 1, n, x, y);
	}
};

struct wSegmentree
{
	int n, m;
	vector<int> root;
	Segmentree tr;

	wSegmentree(int n_, int m) : n(n_), root(4 * n), tr(m) {};

	void modify(int p, int l, int r, int pos, int x, int y)
	{
		tr.modify(root[p], x, y);
		if(l == r) return;
		int mid = l + r >> 1;
		if(pos <= mid) modify(p << 1, l, mid, pos, x, y);
		else modify(p << 1 | 1, mid + 1, r, pos, x, y);
	}

	void modify(int pos, int x, int y)
	{
		modify(1, 1, n, pos, x, y);
	}

	int query(int p, int l, int r, int x, int y, i64 k)
	{
		if(l == r) return l;
		i64 sum = tr.query(root[p << 1 | 1], x, y);
		int mid = l + r >> 1;
		if(k <= sum) return query(p << 1 | 1, mid + 1, r, x, y, k);
		else return query(p << 1, l, mid, x, y, k - sum);
	}

	int query(int x, int y, i64 k)
	{
		return query(1, 1, n, x, y, k);
	}
};

struct dat
{
	int op, l, r;
	i64 c;
};

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> b;
	b.reserve(m);
	vector<dat> query;
	query.reserve(m);
	for(int i = 1; i <= m; i ++)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int l, r, c;
			cin >> l >> r >> c;
			b.emplace_back(c);
			query.push_back({op, l, r, c});
		}
		else
		{
			int l, r;
			cin >> l >> r;
			i64 c;
			cin >> c;
			query.push_back({op, l, r, c});
		}
	}
	sort(b.begin(), b.end());
	unordered_map<int, int> mp;
	int cnt = 0;
	vector<int> val(m + 1);
	for(auto x : b)
	{
		if(!mp.count(x)) mp[x] = ++cnt;
		val[cnt] = x;
	}
	wSegmentree tr(cnt, n);
	for(auto &[op, l, r, c] : query)
	{
		if(op == 1)
		{
			tr.modify(mp[c], l, r);
		}
		else
		{
			int t = tr.query(l, r, c);
			cout << val[t] << '\n';
		}
	}
}