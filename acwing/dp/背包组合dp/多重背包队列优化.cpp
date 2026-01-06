#include <bits/stdc++.h>
using namespace std;
const int N = 20010;
int q[N];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	vector<int> w(n + 1);
	vector<int> s(n + 1);
	for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i] >> s[i];

	vector<vector<int>> f(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i ++)
	{
		for(int k = 0; k < v[i]; k ++)
		{
			int l = 1, r = 0;
			for(int j = k; j <= m; j += v[i])
			{
				while(l <= r && f[i - 1][q[r]] + (j - q[r]) / v[i] * w[i] < f[i - 1][j]) r --;
				q[++ r] = j;
				while(l <= r && j - q[l] > s[i] * v[i]) l ++;
				f[i][j] = f[i - 1][q[l]] + (j - q[l]) / v[i] * w[i];
			}
		}
	}

	cout << f[n][m] << '\n';
	return 0;
}