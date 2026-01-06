#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	i64 k, l, r;
	cin >> k >> l >> r;
	int n = 9 * 9 * 18;

	auto get = [&](i64 x)
	{
		int res = 0;
		while(x)
		{
			int t = x % 10;
			res += t * t;
			x /= 10;
		}
		return res;
	};

	auto find = [&](i64 x)
	{
		int res = 0;
		for(int i = 1; i <= n && k * i <= x; i ++)
		{
			if(get(k * i) == i)
				res ++;
		}
		return res;
	};

	cout << find(r) - find(l - 1) << '\n';
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