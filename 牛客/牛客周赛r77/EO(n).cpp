#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 2);
	vector<i64> pre(n + 1);
	int cnt = 1;
	a[0] = 2;
	vector<int> lst(n + 1), ne(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		char c;
		cin >> c;
		a[i] = c - '0';
		pre[i] += pre[i - 1];
		if(a[i] == 0) pre[i] += cnt ++;
		else cnt = 1;

		lst[i] = lst[i - 1];
		if(a[i] != a[i - 1]) lst[i] = i;
	}

	a[n + 1] = 2;
	for(int i = n; i; i --)
	{
		ne[i] = ne[i + 1];
		if(a[i] != a[i + 1]) ne[i] = i;
	}

	int q;
	cin >> q;
	while(q --)
	{
		int l, r;
		cin >> l >> r;
		i64 m = r - l + 1;
		i64 ans = m * (m + 1) / 2;
		if(a[l] == 1) ans -= pre[r] - pre[l - 1];
		else
		{
			int nei = ne[l];
			ans -= pre[r] - pre[min(r, nei)];
			i64 m = min(r, nei) - l + 1;
			ans -= m * (m + 1) / 2;
		}
		cout << ans << '\n';
	}
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