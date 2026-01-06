#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

template<class Info>
struct Segmentree
{
	int n;
	vector<Info> info;
	Segmentree(int n_) : n(n_), info(n * 4 + 1)
	{
		function<void(int, int, int)> build = [&](int p, int l, int r)
		{
			if(l == r)
			{
				info[p] = {-1, {-1, l}, {-1, l}};
				return;
			}
			int mid = l + r >> 1;
			build(p << 1, l, mid);
			build(p << 1 | 1, mid + 1, r);
			pushup(p);
		};
		build(1, 1, n);
	}

	void pushup(int p)
	{
		info[p] = info[p << 1] + info[p << 1 | 1];
	}

	void modify(int p, int l, int r, int pos, const int &x)
	{
		if(l == r)
		{
			info[p].apply(x);
			return;
		}
		int mid = l + r >> 1;
		if(pos <= mid) modify(p << 1, l, mid, pos, x);
		else modify(p << 1 | 1, mid + 1, r, pos, x);
		pushup(p);
	}

	void modify(int pos, const int &x)
	{
		modify(1, 1, n, pos, x);
	}

	Info query(int p, int l, int r, int x, int y)
	{
		if(r < x || l > y) return Info();
		if(x <= l && r <= y) return info[p];
		int mid = l + r >> 1;
		return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid + 1, r,  x, y);
	}

	Info query(int x, int y)
	{
		return query(1, 1, n, x, y);
	}
};

struct Info
{
	int sum = 0;
	array<int, 2> ls = {-inf, 0};
	array<int, 2> rs = {-inf, 0};

	void apply(const int &x)
	{
		sum = x;
		ls[0] = rs[0] = x;
	}
};

Info operator+(Info a, Info b)
{
	Info c;
	c.sum = a.sum + b.sum;
	c.ls = max(a.ls, {a.sum + b.ls[0], b.ls[1]});
	c.rs = max(b.rs, {b.sum + a.rs[0], a.rs[1]});
	return c;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	map<int, vector<int>> mp;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		mp[a[i]].emplace_back(i);
	}
	Segmentree<Info> tr(n);
	int l = 1, r = 1;
	int mx = 0;
	vector<int> last;
	for(auto [num, vec] : mp)
	{
		if(!last.empty())
		{
			for(auto x : last)
				tr.modify(x, 1);
			last.clear();
		}
		for(auto x : vec)
		{
			tr.modify(x, 0);
			last.emplace_back(x);
		}
		for(auto x : vec)
		{
			Info t = tr.query(x, n);
			if(t.ls[0] > mx)
			{
				mx = t.ls[0];
				l = x;
				r = t.ls[1];
			}
		}
	}
	cout << l << ' ' << r << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t --)
	{
		solve();
	}
	return 0;
}