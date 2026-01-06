#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int q[N];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	vector<int> w(n + 1);
	vector<int> s(n + 1);
	for(int i = 1; i <= n;i ++) cin >> v[i] >> w[i] >> s[i];

	vector<int> f(m + 1);
	vector<int> g(m + 1);

	for(int i = 1; i <= n; i ++)
	{
		g = f;
		if(s[i] == -1)
		{
			for(int j = m; j >= v[i]; j --)
			{
				f[j] = max(g[j], g[j - v[i]] + w[i]);
			}
		}
		else if(s[i] == 0)
		{
			for(int j = v[i]; j <= m; j ++)
			{
				f[j] = max(g[j], f[j - v[i]] + w[i]);
			}
		}
		else
		{
			for(int k = 0; k < v[i]; k ++)
			{
				int l = 0, r = -1;
				for(int j = k; j <= m; j += v[i])
				{
					while(l <= r && g[q[r]] + (j - q[r]) / v[i] * w[i] <= g[j]) r --;
					q[++ r] = j;
					while(l <= r && (j - q[l]) > v[i] * s[i]) l ++;
					f[j] = g[q[l]] + (j - q[l]) / v[i] * w[i];
				}
			}
		}
	}

	cout << f[m] << '\n';
	return 0;
}