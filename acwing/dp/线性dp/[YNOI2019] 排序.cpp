#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	vector<int> f(n + 1);
	int mx = -1e9;
	for(int i = 1; i <= n; i ++)
	{
		f[i] = a[i];
		for(int j = 1; j < i; j ++)
		{
			if(a[j] <= a[i]) f[i] = max(f[i], f[j] + a[i]);
		}
		mx = max(mx, f[i]);
	}

	int sum = accumulate(a.begin() + 1, a.end(), 0);
	cout << sum - mx;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	// t = 1;
	while(t --)
	{
		solve();
	}
}