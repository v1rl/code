#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<i64> pre(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}

	i64 ans = 1e18;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = i; j <= n; j ++)
		{
			i64 res = pre[j] - pre[i - 1];
			i64 sum = 0;
			int l, r;
			l = r = j + 1;
			while(r <= n)
			{
				sum += a[r];
				ans = min(ans, abs(sum - res));
				while(l < r && sum > res)
				{
					sum -= a[l ++];
					ans = min(ans, abs(sum - res));
				}
				r ++;
			}
		}
	}

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
	return 0;
}