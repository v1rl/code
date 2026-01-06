#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e9;

// https://codeforces.com/problemset/problem/623/C

void solve()
{
	int n;
	cin >> n;
	vector<array<int, 2>> a(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}

	vector<int> pmx(n + 1,-inf), pmn(n + 1, inf), smx(n + 2, -inf), smn(n + 2, inf);

	auto pow2 = [&](i64 x)->i64
	{
		return x * x;
	};

	auto dis = [&](array<i64, 2> p, array<i64, 2> q)->i64
	{
		return pow2(p[0] - q[0]) + pow2(p[1] - q[1]);
	};

	auto ck = [&](int l, int r, i64 mid)
	{
		int mx = max(pmx[l - 1], smx[r + 1]);
		int mn = min(pmn[l - 1], smn[r + 1]);
		if(mx == -inf && mn == inf) return true;			//特判另一个坐标轴上不存在点
		if(pow2(mx - mn) > mid) return false;

		i64 d = max({										//不用分类讨论，四种情况取最大即可
			dis({a[l][0], 0}, {0, mx}),
			dis({a[l][0], 0}, {0, mn}),
			dis({a[r][0], 0}, {0, mx}),
			dis({a[r][0], 0}, {0, mn})
		});

		return d <= mid;
	};

	auto check = [&](i64 mid)
	{
		for(int l = 1, r = 1; l <= n; l ++)
		{
			while(r <= n && pow2(a[r][0] - a[l][0]) <= mid) 
			{
				r ++;
				if(ck(l, r - 1, mid)) return true;			//l和r都是关键点，在选取区间时要把所有的左端点l和右端点r都选到
			}
		}
		return false;
	};

	auto init = [&]()
	{
		sort(a.begin() + 1, a.end());
		for(int i = 1; i <= n; i ++)
		{
			pmx[i] = max(pmx[i - 1], a[i][1]);
			pmn[i] = min(pmn[i - 1], a[i][1]);
		}
		for(int i = n; i >= 1; i --)
		{
			smx[i] = max(smx[i + 1], a[i][1]);
			smn[i] = min(smn[i + 1], a[i][1]);
		}
	};

	i64 ans;
	i64 l = 0, r = 1e18;
	init();
	while(l < r)
	{
		i64 mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	ans = l;


	for(int i = 1; i <= n; i ++) swap(a[i][0], a[i][1]);		//y轴方向同样需要筛选
	init();
	l = 0, r = 1e18;
	while(l < r)
	{
		i64 mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}

	ans = min(ans, l);
	cout << ans << '\n';
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
