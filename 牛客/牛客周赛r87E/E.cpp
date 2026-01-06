#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

void solve()
{
	int n, x, y;
	cin >> n >> x >> y;

	for(int i = 30; i >= 0; i --)
	{
		int xi = x >> i & 1;
		int yi = y >> i & 1;
		if(xi == 0 && yi == 1)
		{
			cout << "NO" << '\n';
			return;
		}
	}

	if(n == 1 && x != y)
	{
		cout << "NO" << '\n';
		return;
	}

	if(x == y && n % 2 == 0)
	{
		if((x & -x) == x)
		{
			cout << "NO" << '\n';
		}
		else
		{
			cout << "YES" << '\n';
			for(int i = 1; i <= (n - 2); i ++)
				cout << x << ' ';
			cout << (x & -x) << ' ' << x - (x & -x) << '\n';
		}
		return;
	}

	cout << "YES" << '\n';
	for(int i = 1; i < n; i ++)
		cout << x << ' ';
	cout << ((n & 1) ? y : (y ^ x)) << '\n';
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