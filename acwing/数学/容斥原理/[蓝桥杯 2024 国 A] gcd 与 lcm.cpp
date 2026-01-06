#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;

// https://www.luogu.com.cn/problem/P10580

i64 qmi(i64 a, i64 b)
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
	int x, y, n;
	cin >> x >> y >> n;
	y /= x;
	vector<int> b;
	for(int i = 2; i * i <= y; i ++)
	{
		if(y % i == 0)
		{
			int cnt = 0;
			while(y % i == 0)
			{
				cnt ++;
				y /= i;
			}
			b.emplace_back(cnt);
		}
	}
	if(y > 1) b.emplace_back(1);

	int ans = 1;
	for(auto c : b)
	{
		i64 t = qmi(c + 1, n) - 2ll * qmi(c, n) + qmi(c - 1, n);
		t %= mod;
		ans = 1ll * ans * t % mod;
	}
	cout << (ans % mod + mod) % mod << '\n';
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
	return 0;
}