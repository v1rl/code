#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

// https://codeforces.com/gym/105158

// 很难证明局部最优是全局最优，且结果证明局部最优的贪心是错误的
// ----考虑动态规划
// ----将绝对更劣的可能直接排除，优化dp的时间复杂度

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(m + 1);
	vector<i64> f(m + 1, inf);
	for(int i = 1; i <= m; i ++)
		cin >> a[i];

	f[0] = 0;
	for(int i = 1; i <= m; i ++)
	{
		for(int j = i - 1; j >= max(0, i - 40); j --)
		{
			f[i] = min(f[i], f[j] + (i64)pow(i - j, 4) + a[i]);	
		}
	}

	cout << f[m] << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int t = 1;
	// cin >> t;

	while(t --)
	{
		solve();
	}
	return 0;
}