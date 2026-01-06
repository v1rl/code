#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	s = '#' + s;
	int mx = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = i; j <= n; j ++)
		{
			string cur = s;
			for(int k = 1; k <= n; k ++)
			{
				if(cur[k] == '?')
				{
					if(k >= i && k <= j) cur[k] = 'v';
					else cur[k] = 'o';
				}
			}
			vector<int> pre(n + 1), suf(n + 2);
			for(int k = 1; k <= n; k ++)
			{
				pre[k] = pre[k - 1] + (cur[k] == 'o');
			}
			for(int k = n; k >= 1; k --)
			{
				suf[k] = suf[k + 1] + (cur[k] == 'o');
			}
			int res = 0;
			for(int k = 1; k <= n; k ++)
			{
				if(cur[k] == 'v')
					res += pre[k - 1] * suf[k + 1];
			}
			mx = max(mx, res);
		}
	cout << mx << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	// t = 1;
	while(t --)
	{
		solve();
	}
	return 0;
}