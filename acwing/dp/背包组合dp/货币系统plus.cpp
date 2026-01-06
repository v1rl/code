#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t --)
	{
		int n;
		cin >> n;
		vector<int> v(n + 1);
		for(int i = 1; i <= n; i ++) cin >> v[i];
		sort(v.begin() + 1, v.end());

		int m = v[n];
		vector<int> f(m + 1);
		f[0] = 1;
		int res = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(f[v[i]]) res ++;
			for(int j = v[i]; j <= m; j ++)
			{
				f[j] += f[j - v[i]];
			}
		}
		cout << n - res << '\n';
	}
	return 0;
}