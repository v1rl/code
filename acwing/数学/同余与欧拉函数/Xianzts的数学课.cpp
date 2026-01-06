#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;
//https://ac.nowcoder.com/acm/contest/104421/H

int qmi(i64 a, i64 b, int mod)
{
	i64 res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

void solve()
{
	// int a, k;
	// cin >> a >> k;
	// for(int i = 1; i <= k; i ++)
	// {
	// 	int p = qmi(2, i, mod - 1);
	// 	int res = qmi(a, p, mod);
	// 	cout << i << ' ' <<  res << '\n';
	// }

	int n, k;
	cin >> n >> k;
	int ans = 0;
	if(k <= 46)
	{
		for(int i = 0; i <= k; i ++)
		{
			int p = qmi(2, i, mod - 1);
			int res = qmi(n, p, mod);
			ans += res;
			ans %= mod;
		}
		cout << ans << '\n';
	}
	else
	{
		vector<int> a(24);
		for(int i = 0; i <= 22; i ++)
		{
			int p = qmi(2, i, mod - 1);
			int res = qmi(n, p, mod);
			ans += res;
			ans %= mod;
		}
		for(int i = 23, j = 0; i <= 46; i ++, j ++)
		{
			int p = qmi(2, i, mod - 1);
			int res = qmi(n, p, mod);
			a[j] = res;
		}
		for(int i = k; i >= k - 24 + 1; i --)
		{
			ans = (ans + 1ll * ((i - 23) / 24 + 1) * a[(i - 23) % 24] % mod) % mod;
		}
		cout << ans << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	// t = 1;
	while(t --)
	{
		solve();
	}
}