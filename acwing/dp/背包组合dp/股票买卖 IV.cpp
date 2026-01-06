#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int f[N][110][2];
int w[N];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) cin >> w[i];

	memset(f, -0x3f, sizeof f);
	f[0][0][0] = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 0; j <= k; j ++)
		{
			f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]);
			f[i][j][1] = f[i - 1][j][1];
			if(j >= 1) f[i][j][1] = max(f[i][j][1], f[i - 1][j - 1][0] - w[i]);
		}
	}

	int res = 0;
	for(int i = 0; i <= k; i ++) res = max(res, f[n][i][0]);
	cout << res << '\n';
}