#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;
int nums[110];
int f[110][1 << 10];

int dp(int pos, int s, int zero, int op)
{
	if(!pos)
	{
		int res = 0;
		for(int i = 0; i <= 9; i ++)
		{
			if(s & (1 << i))
				res ++;
		}
		return res;
	}
	if(!zero && !op && f[pos][s] != -1) return f[pos][s];
	int res = 0, mx = op ? nums[pos] : 9;
	for(int i = 0; i <= mx; i ++)
	{
		if(zero && i == 0)
			res += dp(pos - 1, s, true, op && i == nums[pos]), res %= mod;
		else
		{
			int ns = s;
			for(int j = i; j <= 9; j ++)
			{
				if(ns & (1 << j))
				{
					ns ^= (1 << j);
					break;
				}
			}
			ns |= (1 << i);
			res += dp(pos - 1, ns, false, op && i == nums[pos]);
			res %= mod;
		}
	}
	return zero || op ? res : f[pos][s] = res;
}

int calc(string s)
{
	memset(f, -1, sizeof f);
	int tt = 0;
	reverse(s.begin(), s.end());
	for(auto c : s)
	{
		int ch = c - '0';
		nums[++ tt] = ch;
	}
	return dp(tt, 0, 1, 1);
}

void solve()
{
	string s;
	cin >> s;
	cout << calc(s) % mod << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --)
	{
		solve();
	}
	return 0;
}