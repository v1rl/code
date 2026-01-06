#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
const int inf = 1e9 + 7;

// https://ac.nowcoder.com/acm/contest/104637/E

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) 
		cin >> a[i];
	sort(a.begin() + 1, a.end());

	vector<bitset<200>> f(3);			//bool类型可考虑用bitset优化
	f[0][0] = 1;
	int ans = inf;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 200; j >= 0; j --)			//j维度在题意条件下最大有效值为200
		{
			for(int k = 1; k <= 2; k ++)
			{
				if(k == 2 && f[k][j] && j > a[i])			//当前累加个数大于等于2都符合题意，是等价的，因此把大于等于2的个数都压缩到2上
				{
					ans = min(ans, j + a[i]);
				}
				if(j >= a[i])
				{
					if(f[k - 1][j - a[i]]) f[k][j] = true;
					if(k == 2 && f[k][j - a[i]]) f[k][j] = true;
				}
			}
		}
	}

	// bitset<205> f;
	// f[0] = 1;
	// int ans = inf;
	// for(int i = 1; i <= n; i ++)
	// {
	//     for(int j = 200; j > a[i]; j --)		//第一轮没有数，第二轮只有第一个数，它不可能大于任何后面的数，第三轮及以后已经符合题意
	//     {
	//         if(f[j])
	//             ans = min(ans, j + a[i]);
	//     }
	//     f |= f << a[i];		//左移是往大了移
	// }

	cout << (ans == inf ? -1 : ans) << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}