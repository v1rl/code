#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	vector<int> w(n + 1);
	for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

	vector<int> f(m + 1);
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			if(j - v[i] >= 0) f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}

	cout << f[m] << '\n';
}