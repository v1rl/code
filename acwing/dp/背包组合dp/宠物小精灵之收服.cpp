#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int num, h, n;
	cin >> num >> h >> n;
	vector<int> v(n + 1);
	vector<int> d(n + 1);
	for(int i = 1;i <= n; i ++) cin >> v[i] >> d[i];

	vector<vector<int>> f(num + 1, vector<int>(h + 1));
	for(int i = 1; i <= n; i ++)
	{
		for(int j = num; j; j --)
		{
			for(int k = h; k; k --)
			{
				if(j >= v[i] && k >= d[i]) f[j][k] = max(f[j][k], f[j - v[i]][k - d[i]] + 1);
			}
		}
	}

	int ans = f[num][h];
	int min_h;
	for(int i = h; i >= 0; i --) 
		if(f[num][i] == ans) 
			min_h = i;
	cout << ans << ' ' << h - min_h << '\n';
	return 0;
}