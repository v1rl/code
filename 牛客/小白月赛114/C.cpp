#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

void solve()
{
	auto get = [&](int l, int len)->i64
	{
		return 1ll * (l + l + len - 1) * len / 2;
	};

	int n, k;
	cin >> n >> k;

	int l = 0, r = n + 1;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(get(-1, mid) >= k) r = mid;
		else l = mid + 1;
	}
	int m = l - 1;

	vector<int> a(n * 2 + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}
	vector<i64> pre(n * 2 + 1);
	for(int i = 1; i <= n * 2; i ++)
	{
		pre[i] = pre[i - 1] + a[i];
	}

	vector<i64> f(n * 2 + 1);
	vector<int> q(n * 2 + 1);
	l = 1, r = 1;
	i64 mx = 0;
	for(int i = 1; i <= n * 2; i ++)
	{
		if(i <= n)
		{
			while(l < r && pre[q[r - 1]] >= pre[i]) r --;
			q[r ++] = i;
		}
		while(l < r && i - q[l] > m) l ++;
		if(l == r) break;
		f[i] = pre[i] - pre[q[l]];
		if(i >= n) mx = max(mx, f[i]);
	}

	cout << mx << '\n';

}

signed main()
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