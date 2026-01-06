#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://ac.nowcoder.com/acm/contest/95335/G

void solve()
{
	int n, k;
	cin >> n >> k;

	auto check = [&](int mid)
	{
		int res = 0;
		for(int l = 1, r; l <= n; l = r + 1)
		{
			r = n / (n / l);
			int d = n / l;
			int mx = n - d * l;
			if(mid > mx) continue;

			res += min(r - l + 1, (mx - mid) / d + 1);
		}
		return res >= k;
	};

	int l = 0, r = n;
	while(l < r)
	{
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}

	auto getsum = [&](int fst, int d, int num)
	{
		return 1ll * (fst + fst - d * (num - 1)) * num / 2;
	};

	int tar = l + 1;
	i64 res = 0;
	int cnt = 0;
	for(int l = 1, r; l <= n; l = r + 1)
	{
		r = n / (n / l);
		int d = n / l;
		int mx = n - d * l;
		if(tar > mx) continue;

		int g = min(r - l + 1, (mx - tar) / d + 1);
		cnt += g;
		res += getsum(mx, d, g);
	}

	while(cnt < k)
	{
		res += tar - 1;
		cnt ++;
	}
	cout << res << '\n';
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
}