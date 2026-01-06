#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int m;
	cin >> m;
	vector<int> v{0, 10, 20, 50, 100};
	vector<int> f(m + 1);
	f[0] = 1;
	for(int i = 1; i <= 4; i ++)
	{
		for(int j = v[i]; j <= m; j ++)
		{
			f[j] = f[j] + f[j - v[i]];
		}
	}
	cout << f[m] << '\n';
}