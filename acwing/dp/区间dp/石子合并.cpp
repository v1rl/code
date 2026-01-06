#include<bits/stdc++.h>
using namespace std;
const int N = 310;
int a[N];
int s[N];
int f[N][N];

int dp(int l, int r)
{
	if(l == r) return 0;
	if(f[l][r] != 0x3f3f3f3f) return f[l][r];
	for(int i = l; i < r; i ++)
		f[l][r] = min(f[l][r], dp(l, i) + dp(i + 1, r) + s[r] - s[l - 1]);
	return f[l][r];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	memset(f, 0x3f, sizeof f);
	cout << dp(1, n) << '\n';
	return 0;
/*
	// 递推
	memset(f, 0x3f, sizeof f);
	for(int i = 1; i <= n; i ++) f[i][i] = 0;
	for(int len = 2; len <= n; len ++)
		for(int l = 1; l + len - 1 <= n; l ++)
		{
			int r = l + len - 1;
			for(int k = l; k < r; k ++)
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
		}

	cout << f[1][n] << '\n';
	return 0;
*/
}
