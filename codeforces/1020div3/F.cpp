#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://codeforces.com/contest/2106/problem/F
// 找规律+贪心
// 对首个节点单独初始化时，维护的变量也应该随首个节点初始化
// 注意联通失败时的重新初始化

void solve()
{
	int n;
	string s;
	cin >> n >> s;
	s = '#' + s;
	vector<i64> up(n + 1), dp(n + 1);

	if(s[1] == '0') dp[1] = n - 1;
	else dp[1] = 1;
	i64 mx = dp[1];
	
	for(int i = 2; i <= n; i ++)
	{
		if(s[i] == '0')
		{
			if(s[i - 1] == '0') 
			{
				up[i] = up[i - 1] + (i - 1);
				dp[i] = dp[i - 1] + (n - i);
			}
			else
			{
				up[i] = dp[i - 1] + (i - 1);
				dp[i] = n - i;
			}
		}
		if(s[i] == '1')
		{
			if(s[i - 1] == '0')
			{
				dp[i] = dp[i - 1] + 1;
			}
			else
			{
				dp[i] = 1;
			}
		}
		mx = max({mx, up[i], dp[i]});
	}
	cout << mx << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
    	solve();
    }
}