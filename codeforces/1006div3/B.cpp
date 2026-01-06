#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int ceil(int n, int m)
{
	return (n + m - 1) / m;
}

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = 0, b = 0;
	for(auto c : s)
	{
		if(c == '-') a ++;
		else b ++;
	}
	i64 ans = 1ll * b * (a / 2) * ceil(a, 2);
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
	return 0;
}