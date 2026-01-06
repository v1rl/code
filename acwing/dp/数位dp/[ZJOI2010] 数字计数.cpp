#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;
int nums[20];
i64 f[20][20];

i64 dp(int pos, int x, int s, int zero, int op)
{
	if(!pos) return s;
	if(!op && !zero && f[pos][s] != -1) return f[pos][s];

	i64 res = 0, mx = op ? nums[pos] : 9;
	for(int i = 0; i <= mx; i ++)
	{
		res += dp(pos - 1, x, s + ((x == 0 && x == i && !zero) || (x != 0 && x == i)), zero && i == 0, op && i == nums[pos]);
	}
	return op || zero ? res : f[pos][s] = res;
}

i64 calc(i64 n, int x)
{
	int tt = 0;
	while(n)
	{
		nums[++ tt] = n % 10;
		n /= 10;
	}
	return dp(tt, x, 0, 1, 1);
}

void solve()
{
	i64 l, r;
	cin >> l >> r;
	memset(f, -1, sizeof f);
	for(int i = 0; i <= 9; i ++)
	{
		cout << calc(r, i) - calc(l - 1, i) << ' ';
	}
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