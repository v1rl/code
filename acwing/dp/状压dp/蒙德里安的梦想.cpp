#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	while(cin >> n >> m, n || m)
	{
		vector<vector<i64>> f(m + 1, vector<i64>(1 << n));
		vector<bool> st(1 << n);
		for(int i = 0; i < 1 << n; i ++)
		{
			st[i] = true;
			int cnt = 0;
			for(int j = 0; j < n; j ++)
			{
				if(i >> j & 1)
				{
					if(cnt & 1) st[i] = false;
					cnt = 0;
				}
				else cnt ++;
			}
			if(cnt & 1) st[i] = false;
		}

		// 只占据前i列，第i列的接受情况/第i - 1列的支出情况 为j的方案数
		f[0][0] = 1;
		for(int i = 1; i <= m; i ++)
			for(int j = 0; j < 1 << n; j ++)
				for(int k = 0; k < 1 << n; k ++)
				{
					if(!(j & k) && st[k | j]) 
					{
						// if(f[i - 1][k] == 0) cout << 'h';
						f[i][j] += f[i - 1][k];
					}
				}

		i64 ans = 0;
		for(int i = 0; i < 1 << n; i ++) 
			if(st[i]) 
				ans += f[m - 1][i];
		cout << ans << '\n';
		
		// cout << f[m][0] << '\n';
	}
}