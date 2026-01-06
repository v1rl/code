#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template<class Info>
struct SegmentTree
{
	int n;
	vector<Info> info;
	
	SegmentTree(int n_) : n(n_), info(4 * n + 1) {};
	SegmentTree(vector<Info> a) : SegmentTree(a.size() - 1)
	{
		function<void(int, int, int)> build = [&](int p, int l, int r)
		{
			if(l == r)
			{
				info[p] = a[l];
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
	
	void rangeApply(int p, int l, int r, int x, int y)
	{
		if(r < x || l > y) return;
		if(x <= l && r <= y)
		{
			if(info[p].ok)
				return;
		}
		if(l == r)
		{
			info[p].apply();
			return;
		}
		int mid = l + r >> 1;
		rangeApply(p << 1, l, mid, x, y);
		rangeApply(p << 1 | 1, mid + 1, r, x, y);
		pushup(p);
	}
	
	void rangeApply(int x, int y)
	{
		rangeApply(1, 1, n, x, y);
	}
	
	Info query(int p, int l, int r, int x, int y)
	{
		if(r < x || l > y) return Info();
		if(x <= l && r <= y) return info[p];
		int mid = l + r >> 1;
		return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid + 1, r, x, y);
	}
	
	Info query(int x, int y)
	{
		return query(1, 1, n, x, y);
	}
};
constexpr i64 inf = 1e18;

struct Info
{
	i64 sum = 0;
	int act = 0;
	int ok = 0;
	
	void apply()
	{
		sum = sqrt(sum);
		if(sum == 0 || sum == 1) ok = 1;
	}
};

Info operator+(Info a, Info b)
{
	Info c;
	c.sum = a.sum + b.sum;
	c.act = a.act + b.act; 
	c.ok = (a.ok && b.ok);
	return c;
}

int main()
{
	int n;
	int t = 0;
	while(cin >> n, n)
	{
		printf("Case #%d:\n", ++ t);
		vector<Info> info(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			i64 x;
			scanf("%lld", &x);
			info[i] = {x, 1};
		}
		SegmentTree<Info> tr(info);
		int m;
		cin >> m;
		while(m --)
		{
			int op, l, r;
			scanf("%d%d%d", &op, &l, &r);
			if(l > r) swap(l, r);
			if(op == 1)
			{
				printf("%lld\n", tr.query(l, r).sum);
			}
			else 
			{
				// for(int i = 1; i <= n; i ++)
				// {
				//     cout << tr.query(i, i).sum << " \n"[i == n];
				// }
				tr.rangeApply(l, r);
			}
		}
		printf("\n");
	}
}

