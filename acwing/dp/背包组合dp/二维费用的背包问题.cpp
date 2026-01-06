#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	vector<int> v1(n + 1);
	vector<int> v2(n + 1);
	vector<int> w(n + 1);
	for(int i = 1; i <= n; i ++) cin >> v1[i] >> v2[i] >> w[i];

	vector<vector<int>> f(m1 + 1, vector<int>(m2 + 1));
	for(int i = 1; i <= n; i ++)
	{
		for(int j = m1; j >= v1[i]; j --)
		{
			for(int k = m2; k >= v2[i]; k --)
			{
				f[j][k] = max(f[j][k], f[j - v1[i]][k - v2[i]] + w[i]);
			}
		}
	}
	cout << f[m1][m2] << '\n';
	return 0;
}