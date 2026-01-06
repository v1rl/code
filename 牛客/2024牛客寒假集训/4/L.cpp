#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7, N = 3e5 + 10;
int bita[N][32][2], bitb[N][32][2];

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		cin >> b[i];

	for(int i = 1; i <= n; i ++)
	{
		for(int j = 30; j >= 0; j --)
		{
			int cha = a[i] >> j & 1, chb = b[i] >> j & 1;
			bita[i][j][0] = bita[i - 1][j][0] + (cha == 0);
			bita[i][j][1] = bita[i - 1][j][1] + (cha == 1);
			bitb[i][j][0] = bitb[i - 1][j][0] + (chb == 0);
			bitb[i][j][1] = bitb[i - 1][j][1] + (chb == 1);
		}
	}

	vector<int> pre(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int res = 0;
		for(int j = 30; j >= 0; j --)
		{
			int ch = a[i] >> j & 1;
			res += (1ll << j) * (bitb[n][j][ch ^ 1] - bitb[i - 1][j][ch ^ 1]) % mod;
			res %= mod;
		}
		pre[i] = pre[i - 1] + res;
		pre[i] %= mod;
	}

	while(q --)
	{
		int l, r;
		cin >> l >> r;
		int ans = pre[r] - pre[l - 1];
		for(int j = 30; j >= 0; j --)
		{
			int a0 = bita[r][j][0] - bita[l - 1][j][0];
			int a1 = bita[r][j][1] - bita[l - 1][j][1];
			int b0 = bitb[n][j][0] - bitb[r][j][0];
			int b1 = bitb[n][j][1] - bitb[r][j][1];
			int num = (1ll * a0 * b1 + 1ll * a1 * b0) % mod;
			int res = (1ll << j) * num % mod;
			ans -= res;
			ans %= mod;
		}
		cout << (ans % mod + mod) % mod << '\n';
	}
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
}