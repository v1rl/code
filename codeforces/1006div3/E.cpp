#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int sum[501];

void solve()
{
	int n;
	cin >> n;
	vector<int> res;
	for(int i = 499; i >= 2; i --)
	{
		if(n >= sum[i])
		{
			res.emplace_back(i);
			n -= sum[i];
		}
	}
	vector<int> pls;
	while(n > 0)
	{
		pls.emplace_back(2);
		n -= 1;
	}
	int ans = 0;
	for(int i = 0; i < res.size(); i ++)
	{
		ans += res[i];
		if(i != 0) ans --;
	}
	cout << ans + pls.size() * 2 << '\n';
	int col = 0, row = 1;
	for(int i = 0; i < res.size(); i ++)
	{
		if(i == 0)
		{
			for(int j = 0; j < res[i]; j ++)
			{
				cout << 0 << ' ' << j << '\n';
			}
		}
		else
		{
			for(int j = 1; j < res[i]; j ++)
			{
				cout << row ++ << ' ' << col << '\n';
			}
			col ++;
		}
	}
	int l = 114514, r = 1919810;
	for(auto _ : pls)
	{
		cout << l << ' ' << r << '\n';
		cout << l << ' ' << r + 1 << '\n';
		l += 10, r += 10;
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i <= 499; i ++)
	{
		sum[i + 1] = sum[i] + i;
	}
	while(t --)
	{
		solve();
	}
	return 0;
}