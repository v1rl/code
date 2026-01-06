#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://codeforces.com/gym/105158

// 将关系具象为图

// ----将可行关系抽象为一条有向边
// ----将存在双向边的两个节点视作等价节点，用并查集维护等价节点，将等价节点缩为一个点得到有向无环图
// ----有向无环图的起点即为目标点

struct DSU
{
	vector<int> p;
	vector<int> siz;

	DSU(int n) 
	{
		init(n);
	}

	void init(int n)
	{
		siz.assign(n + 1, 1);
		p.resize(n + 1);
		iota(p.begin(), p.end(), 0);
	}

	int find(int x)
	{
		if(x != p[x]) p[x] = find(p[x]);
		return p[x];
	}

	bool merge(int x, int y)
	{
		x = find(x), y = find(y);
		if(x == y) return false;
		p[y] = x;
		siz[x] += siz[y];
		return true;
	}
};

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	DSU dsu(n);

	vector<array<int, 2>> edges;
	edges.reserve(n);
	for(int i = 1; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		if(2 * a[x] >= a[y] && 2 * a[y] >= a[x])
			dsu.merge(x, y);
		else if(2 * a[y] >= a[x])
			edges.push_back({x, y});
		else 
			edges.push_back({y, x});
	}

	vector<int> din(n + 1);
	for(auto [x, y] : edges)
	{
		x = dsu.find(x), y = dsu.find(y);
		din[y] ++;		
	}

	int num = 0;
	int root = 1;
	for(int i = 1; i <= n; i ++)
	{
		if(!din[i] && dsu.find(i) == i)
		{
			root = i;
			num ++;
		}
	}
	cout << (num == 1 ? dsu.siz[root] : 0) << '\n';
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