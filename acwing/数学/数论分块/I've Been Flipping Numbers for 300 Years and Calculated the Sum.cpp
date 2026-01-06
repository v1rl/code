#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
const int mod = 1e9 + 7;

// 以根号为分界点，根号前暴力，根号后数论分治
// 根号后部分的p进制长度都为2，反转后的值为 (n mod p) * p + (n / p) -> (n - (n / p) * p) * p + (n / p);
// https://codeforces.com/contest/2072/problem/G

void solve()
{
	int n;
	i64 k;
	cin >> n >> k;
	int res = 0;

	if(k > n)
	{
		i128 t = k - n;
		res += t * n % mod;
		k = n;
	}

	auto getsum = [&](int l, int r)
	{
		return 1ll * (l + r) * (r - l + 1) / 2;
	};

	auto getsquare = [&](int x)
	{
		return 1ll * x * (x + 1) * (2 * x + 1) / 6;
	};

	for(int l = 2, r; l <= k; l = r + 1)
	{
		if(1ll * l * l <= n)
		{
			r = l;
			vector<int> nums;
			for(int x = n; x; x /= l)
				nums.emplace_back(x % l);
			i64 x = 0;
			for(auto d : nums)
				x = (x * l % mod + d) % mod;
			res += x;
			res %= mod;
		}
		else
		{
			r = n / (n / l);
			if(r > k) r = k;
			i64 w = n / l;
			res += getsum(l, r) * n % mod;
			res %= mod;
			res += (r - l + 1) * w % mod;
			res %= mod;
			res -= (getsquare(r) - getsquare(l - 1)) * w % mod;
			res %= mod;
		}
	}

	cout << (res + mod) % mod << '\n';
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