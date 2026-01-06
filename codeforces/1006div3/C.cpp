#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve()
{
	int n, x;
	cin >> n >> x;
	int t = x;
	int pos = 30;
	for(int i = 0; i < 30; i ++)
	{
		if(!(t >> i & 1))
		{
			pos = i;
			break;
		}
	}
	int mx = (1 << pos) - 1;

	int num = min(mx, n - 2);
	for(int i = 0; i <= num; i ++)
		cout << i << ' ';
	if(mx == x)
	{
		if(__lg(num + 1) + 1 == pos) cout << num + 1;
		else cout << x << ' ';
	}
	else cout << x << ' ';
	for(int i = 1; i <= n - num - 2; i ++)
		cout << 0 << ' ';
	cout << '\n';
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