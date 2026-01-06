#include<bits/stdc++.h>
using namespace std;
const int N = 210;
int a[N];
int f[N][N];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) 
	{
		cin >> a[i];
		a[i + n] = a[i];
	}

	for(int len = 3; len <= n + 1; len ++)
		for(int l = 1; l + len - 1 <= n * 2; l ++)
		{
			int r = l + len - 1;
			for(int k = l + 1; k < r; k ++)
				f[l][r] = max(f[l][r], f[l][k] + f[k][r] + a[l] * a[r] * a[k]);
		}
	int res = 0;
	for(int i = 1; i <= n; i ++)
		res = max(res, f[i][i + n]);
	cout << res << '\n';
}
