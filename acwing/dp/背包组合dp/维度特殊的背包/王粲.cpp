#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://ac.nowcoder.com/acm/contest/106250/F

const int N = 110;
const int inf = 1e9;
int w[N][15];
int v[N][15];

void solve()
{
	// 前i个，体积恰等于j，体积上限为k
	int n, w1, v1;
	cin >> n >> w1 >> v1;
	vector<int> s(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >> s[i];
		s[i] ++;
		v[i][1] = v1, w[i][1] = w1;
		for(int j = 2; j <= s[i]; j ++)
			cin >> w[i][j];
		for(int j = 2; j <= s[i]; j ++)
			cin >> v[i][j];
	}

	vector f(n + 1, vector(n + 1, vector(n + 1, -inf)));
	f[0][0][0] = 0;

	int mx = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 0; j <= n; j ++)
		{
			for(int k = 0; k <= i; k ++)
			{
				if(k > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1]);
				for(int x = 1; x <= s[i]; x ++)
				{
					if(j >= v[i][x]) f[i][j][k] = max(f[i][j][k], f[i - 1][j - v[i][x]][k] + w[i][x]);
				}
				if(i == n && j <= k) mx = max(mx, f[i][j][k]);
			}
		}
	}
	cout << mx << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --)
	{
		solve();
	}
	return 0;
}