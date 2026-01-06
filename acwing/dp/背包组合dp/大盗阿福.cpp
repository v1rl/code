#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> T;
	while(T --)
	{
		int n;
		cin >> n;
		vector<int> w(n + 1);
		for(int i = 1; i <= n; i ++) cin >> w[i];

/*		
		// 序列dp
		vector<int> f(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			f[i] = max(f[max(0, i - 2)], f[max(0, i - 3)]) + w[i];
		}
		cout << max(f[n], f[n - 1]) << '\n';
*/


		// 状态机
		vector<array<int, 2>> f(n + 1);
		f[0][0] = 0, f[0][1] = -1e9;
		for(int i = 1; i <= n ;i ++)
		{
			f[i][0] = max(f[i - 1][0], f[i - 1][1]);
			f[i][1] = f[i - 1][0] + w[i];
		}
		cout << max(f[n][0], f[n][1]) << '\n';
	}

	return 0;
}