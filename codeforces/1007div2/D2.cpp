#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	i64 n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n + 1);
	vector<int> pre(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
	}

	if(n % 2 == 0)
	{
		a.emplace_back(pre[n / 2]);
		pre.emplace_back(pre[n] ^ a[n + 1]);
		n ++;
	}

	i64 ans = 0;
	for(i64 i = l; i <= min(n, r); i ++)
	{
		ans += a[i];
	}

	auto get = [&](i64 x)
	{
		if(x <= n) return a[x];
		i64 i = x / 2;
		int res = 0;
		while(i % 2 == 0 && i > n)
		{
			res ^= pre[n];
			i /= 2;
		}
		res ^= pre[min(i, n)];
		return res;
	};

	if(r > n)
	{
		l = max(n + 1, l);
		if(l <= r && l % 2)
		{
			ans += get(l);
			l ++;
		}
		if(l <= r && r % 2 == 0)
		{
			ans += get(r);
			r --;
		}

		if(l <= r)
		{
			l /= 2;
			r /= 2;
			for(i64 x = 1; (n / 2 + 1) * x <= r; x *= 2)
			{
				int t = __builtin_ctzll(x) & pre[n];
				for(i64 i = (n / 2) + 1; i <= n && i * x <= r; i ++)
				{
					if(i * x >= l)
					{
						ans += 2 * (t ^ pre[i]);		//从n的一半到n的数尾接t个0，且在l~r的范围之间，则计数
					}
				}
				i64 R = r / x;
				i64 L = max(n + 1, (l + x - 1) / x);		//为保证[l, r]的左闭右闭，左端点排开后面的x个0后上取整
				if(L <= R)		//不取1~n这一部分值，小于n/2部分已经被之前其大于n/2的形式使用过了因此不计算，大于n/2部分上面单独计算过了
				{
					ans += 2 * ((R - L + 1) / 2 + (L % 2) * (R % 2)) * (t ^ pre[n]);		//后缀x个0且上一位为1的数的个数
				}
			}
		}
	}

	cout << ans << '\n';
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
}