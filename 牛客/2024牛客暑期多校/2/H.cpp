#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;

	vector<array<int, 2>> a(n + 1);
	for(int i = 0; i < n; i ++)
	{
		a[i + 1] = a[i];
		if(s[i] == 'W') a[i + 1][1] ++;
		else if(s[i] == 'S') a[i + 1][1] --;
		else if(s[i] == 'A') a[i + 1][0] --;
		else a[i + 1][0] ++;
	}

	i64 ans = 0;
	map<array<int, 2>, int> idx;
	for(int i = n; i >= 0; i --)
	{
		idx[a[i]] = i;
		if(idx.count({a[i][0] + x, a[i][1] + y}))
		{
			int j = idx[{a[i][0] + x, a[i][1] + y}];
			j = max(j, i + 1);
			ans += n - j + 1;
		}
	}
	cout << ans << "\n";

	return 0;
}