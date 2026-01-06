#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://ac.nowcoder.com/acm/contest/104870/K

void solve()
{
	int n;
	cin >> n;
	i64 ans = 0;
	for(int i = 0; i < n - 1; i ++)
	{
		int l, r;
		cin >> l >> r;
		ans += l * r;
	}
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --)
	{
		solve();
	}
	return 0;
}