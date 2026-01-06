#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	i64 n, m;
	cin >> n >> m;
	vector<i64> v(n + 1);
	for(int i = 1; i <= n; i ++) cin >> v[i];

	vector<i64> f(m + 1);
	f[0] = 1;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			if(j >= v[i]) f[j] += f[j - v[i]];
		}
	}

	cout << f[m] << '\n';
	return 0;
}