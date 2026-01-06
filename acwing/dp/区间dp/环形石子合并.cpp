#include<bits/stdc++.h>
using namespace std;
const int N = 410;
int a[N];
int s[N];
int f[N][N];
int g[N][N];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = n + 1; i <= n * 2; i ++) a[i] = a[i - n];
	for(int i = 1; i <= n * 2; i ++) s[i] = s[i - 1] + a[i]; 

	memset(f, 0x3f, sizeof f);
	for(int i = 1; i <= n * 2; i ++) f[i][i] = 0;

	for(int len = 2; len <= n; len ++)
		for(int l = 1; l + len - 1 <= n * 2; l ++)
		{
			int r = l + len - 1;
			for(int k = l; k < r; k ++)
			{
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
				g[l][r] = max(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
			}
		}

	int Max = 0, Min = 1e9;
	for(int i = 1; i <= n; i ++) 
	{
		Min = min(Min, f[i][i + n - 1]);
		Max = max(Max, g[i][i + n - 1]);
	}
	
	cout << Min << '\n' << Max << '\n';
}
