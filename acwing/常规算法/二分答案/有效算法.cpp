#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

// https://codeforces.com/gym/105158

// 答案具有两点单调性，且只要已知答案就可以验证答案的正确性
// 显然的二分答案

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> b(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		cin >> b[i];

	auto check = [&](int mid)
	{
		i64 L = -1e18, R = 1e18;
		for(int i = 1; i <= n; i ++)
		{
			L = max(L, a[i] - 1ll * mid * b[i]);
			R = min(R, a[i] + 1ll * mid * b[i]);
		}
		if(R >= L) return true;
		return false;
	};

	int l = 0, r = inf;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << l << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int t = 1;
	cin >> t;

	while(t --)
	{
		solve();
	}
	return 0;
}