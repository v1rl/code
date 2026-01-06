#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inv2 = 5e8 + 4, mod = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for(int i = s.size() - 1; i >= 1; i --)
	{
		if(s[i] == '0') ans = 1ll * ans * inv2 % mod;
		else ans = (1ll * (1 - ans) * inv2 % mod + ans) % mod;
	}
	cout << ((n - 1 + ans) + mod) % mod << '\n';
	// cout << ((1ll * ans * n % mod + 1ll * (1 - ans) * (n - 1) % mod) % mod + mod) % mod << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t --)
	{
		solve();
	}
}