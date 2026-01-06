#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		cin >> b[i];
	vector<vector<int>> c(n + 1);

	int num = 0, pos = -1;
	for(int i = 1; i <= n; i ++)
	{
		c[a[i]].emplace_back(i);
		c[b[i]].emplace_back(i);
		if(a[i] == b[i]) num ++, pos = i;
	}
	vector<array<int, 2>> res;
	if(n & 1)
	{
		if(num != 1)
		{
			cout << -1 << '\n';
			return;
		}
		if(pos != n / 2 + 1)
		{
			int cur = n / 2 + 1;
			res.push_back({cur, pos});
			int t = c[a[cur]][1] == cur;
			c[a[cur]][t] = pos;
			c[b[cur]][t] = pos;
			swap(a[cur], a[pos]);
			swap(b[cur], b[pos]);
		}
	}


	for(int i = 1, j = n; i <= j; i ++, j --)
	{
		if(i == j)
		{
			if(a[i] != b[i])
			{
				cout << -1 << '\n';
				return;
			}
		}
		else
		{
			if(a[i] == b[j] && a[j] == b[i]) continue;
			bool f = false;
			for(auto k : c[b[j]])
			{
				if(k == j) continue;
				if(b[k] != a[j])
				{
					cout << -1 << '\n';
					return;
				}
				f = true;
				res.push_back({k, i});
				int t = c[a[i]][1] == i;
				c[a[i]][t] = k;
				c[b[i]][t] = k;
				swap(a[k], a[i]);
				swap(b[k], b[i]);
			}
			if(!f)
			{
				cout << -1 << '\n';
				return;
			}
		}
	}

	cout << res.size() << '\n';
	for(auto [l, r] : res)
	{
		cout << l << ' ' << r << '\n';
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
	return 0;
}