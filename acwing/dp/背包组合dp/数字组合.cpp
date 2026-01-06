#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n ,m ;
	cin >> n >> m;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i ++) cin >> v[i];

	vector<int> f(m + 1);
	f[0] = 1;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = m; j >= v[i]; j --)
		{
			f[j] = f[j] + f[j - v[i]];
		}
	}

	cout << f[m] << '\n';
	return 0;
}