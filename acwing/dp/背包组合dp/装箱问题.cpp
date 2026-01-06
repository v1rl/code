#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> m >> n;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i ++) cin >> v[i];
	vector<int> f(m + 1);
	for(int i = 1; i <= n; i ++)
	{
		for(int j = m; j; j --)
		{
			if(j >= v[i]) f[j] = max(f[j], f[j - v[i]] + v[i]);
		}
	}
	cout << m - f[m] << '\n';
	return 0;
}