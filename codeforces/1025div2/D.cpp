#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 2e9 + 10;

// 不存在环的情况下，可达当且仅当可行的求和为大于等于深度的同奇偶数
// 求和，减去一个最小的奇数/偶数后是否满足大于

// 存在环的情况下，奇偶可以改变，尽可能花费最小代价
// 求改变奇偶的最小代价是多少？

// bfs，哪些点可以改变奇偶，离目标点的距离是多少

void solve()
{
	int n, m, l;
	cin >> n >> m >> l;
	int modd = inf;
	int sum = 0;
	for(int i = 1; i <= l; i ++)
	{
		int x;
		cin >> x;
		if(x & 1) modd = min(modd, x);
		sum += x;
	}

	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= m; i ++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	queue<array<int, 2>> q;
	q.push({1, 0});
	vector<array<int, 2>> dep(n + 1, {inf, inf});
	dep[1] = {0, inf};

	while(q.size())
	{
		auto [x, op] = q.front();
		q.pop();

		for(auto y : adj[x])
		{
			if(y == x) continue;
			if(dep[y][op ^ 1] != inf) continue;

			int t = dep[x][op] + 1;
			dep[y][op ^ 1] = t;

			q.push({y, op ^ 1});
		}
	}

	int mxodd, mxeven;
	if(sum & 1)
	{
		mxodd = sum;
		mxeven = sum - modd;
	}
	else
	{
		mxeven = sum;
		mxodd = sum - modd;
	}

	cout << 1;
	for(int i = 2; i <= n; i ++)
	{
		// cout << i << ' ' << dep[i][1] << ' ' << dep[i][0] << '\n';
		if(dep[i][0] <= mxeven || dep[i][1] <= mxodd) cout << 1;
		else cout << 0;
	}
	cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --)
    {
        solve();
    }
    return 0;
}