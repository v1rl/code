#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

// https://ac.nowcoder.com/acm/contest/105623/D

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	vector<i64> f(n + 1, 0);
	for(int i = 1; i <= n; i ++)
	{
		f[i] = f[i - 1] + a[i];
		if(i >= 2) f[i] = max(f[i], f[i - 2]);
		if(i >= 3) f[i] = max(f[i], f[i - 3]);
	}
	cout << f[n] << '\n';
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