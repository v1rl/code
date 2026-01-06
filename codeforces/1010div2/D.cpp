#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 2e9;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	int res = 0;
	int l = -1, r = -1;
	for(int i = 1; i < n; i ++)
	{
		if(a[i] > a[i + 1])
		{
			if(l == -1) l = i;
			r = i + 1;
			res ++;
		}
	}
	if(res & 1) cout << (res + 1) / 2 << '\n';
	else 
	{
		if(a[r] - a[l] >= r - l) cout << res / 2 << '\n';
		else cout << res / 2 + 1 << '\n';
	}
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
}