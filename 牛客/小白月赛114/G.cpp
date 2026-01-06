#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://ac.nowcoder.com/acm/contest/106250/G

// map<col, map<name, int>> pd;
// map<name, map<col, int>> sp;

// 遍历S，在pd中对应col，遍历name，并记录当前个数num。在sp中对应name，遍历sp的tcol，考虑将tcol改为col。
// 此时需要满足sp[name][tcol] - 1后sp[name][col] + 1 <= num 且 sp[name][col] + 1 != m。

void solve()
{
	int n, m, q;
	cin >> n >> m >> q;
	unordered_map<string, unordered_map<string, int>> pd;
	for(int i = 1; i <= n; i ++)
	{
		string col, name;
		cin >> col >> name;
		pd[col][name] ++;
	}

	unordered_map<string, unordered_map<string, int>> sp;
	for(int i = 1; i <= m; i ++)
	{
		string col, name;
		cin >> col >> name;
		sp[name][col] ++;
	}

	vector<string> S;
	S.reserve(q);
	for(int i = 1; i <= q; i ++)
	{
		string col;
		cin >> col;
		S.emplace_back(col);
	}

	for(auto col : S)
	{
		for(auto [name, num] : pd[col])
		{
			for(auto [tcol, tnum] : sp[name])
			{
				sp[name][tcol] --;
				if(sp[name][col] + 1 <= num && sp[name][col] + 1 != m)
				{
					cout << "Yes" << '\n';
					cout << tcol << ' ' << name << '\n';
					cout << col << ' ' << name << '\n';
					return;
				}
				sp[name][tcol] ++;
			}
		}
	}
	cout << "No" << '\n';
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
	return 0;
}