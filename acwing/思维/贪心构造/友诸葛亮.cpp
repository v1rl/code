#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://ac.nowcoder.com/acm/contest/106250/E

// “目标个数”更大的优先

void solve()
{
	int a[4];
	cin >> a[1] >> a[2] >> a[3];
	vector<int> st(4);

	auto get = [&](int x, int add)
	{
		return (x + add - 1) % 3 + 1;
	};

	int n = a[1] + a[2] + a[3];

	vector<int> b(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> b[i];

	vector<array<int, 4>> suf(n + 2);
	for(int i = n; i >= 1; i --)
	{
		suf[i][1] = suf[i + 1][1] + (b[i] == 1);
		suf[i][2] = suf[i + 1][2] + (b[i] == 2);
		suf[i][3] = suf[i + 1][3] + (b[i] == 3);
	}

	for(int i = 1; i <= n; i ++)
	{
		int c = get(b[i], 1), d = get(b[i], 2);
		if(min(suf[i + 1][c], a[c] - st[c]) < min(suf[i + 1][d], a[d] - st[d])) swap(c, d);
		if(st[c] < a[c])
		{
			cout << c << ' ';
			st[c] ++;
		}
		else if(st[d] < a[d])
		{
			cout << d << ' ';
			st[d] ++;
		}
		else
		{
			cout << b[i] << ' ';
			st[b[i]] ++;
		}
	}
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