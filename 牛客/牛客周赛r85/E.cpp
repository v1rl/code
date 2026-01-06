#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7, inv2 = 5e8 + 4;

void solve()
{
	int n;
	cin >> n;
	vector<array<int, 3>> range(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int l, r;
		cin >> l >> r;
		range[i] = {l, r, i};
	}

	sort(range.begin() + 1, range.end(), 
		[&](array<int, 3> i, array<int, 3> j)
		{
			return i[0] < j[0];
		});

	int r1 = -1, r2 = -1;
	vector<int> res;
	for(int i = 1; i <= n; i ++)
	{
		auto [l, r, id] = range[i];
		if(l <= r1)
		{
			if(l <= r2)
			{
				cout << -1 << '\n';
				return;
			}
			res.emplace_back(id);
			r2 = r;
		}
		else r1 = r;
	}
	if(res.size() == 0)
	{
		cout << 1 << '\n' << 1 << '\n';
		return;
	}
	cout << res.size() << '\n';
	for(auto x : res) 
		cout << x << ' ';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --)
	{
		solve();
	}
}