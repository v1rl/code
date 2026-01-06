#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
//https://www.luogu.com.cn/problem/U298750
int f[N][4];
int w[N];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> w[i];

	f[0][1] = -1e9, f[0][2] = 0, f[0][3] = 0;
	for(int i = 1; i <= n; i ++)
	{
		f[i][1] = max(f[i - 1][1], f[i - 1][3] - w[i]);
		f[i][2] = f[i - 1][1] + w[i];
		f[i][3] = max(f[i - 1][3], f[i - 1][2]);
	}

	cout << max(f[n][2], f[n][3]) << '\n';
}