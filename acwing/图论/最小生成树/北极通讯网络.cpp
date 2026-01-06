#include<bits/stdc++.h>
using namespace std;
const int N = 510;
int p[N];

struct Node
{
	double w;
	int x, y;
	bool operator < (const Node &W) const
	{
		return w < W.w;
	}
};

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) p[i] = i;

	vector<array<int, 2>> dat(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int x, y;
		cin >> x >> y;
		dat[i] = {x, y};
	}

	vector<Node> edges;
	edges.reserve(n * (n + 1) / 2);
	for(int i = 1; i <= n; i ++)
		for(int j = i + 1; j <= n; j ++)
		{
			int x = dat[i][0] - dat[j][0], y = dat[i][1] - dat[j][1];
			double w = sqrt(x * x + y * y);
			edges.push_back({w, i, j});
		}

	sort(edges.begin(), edges.end());
	double res = 0;
	for(auto [w, x, y] : edges)
	{
		x = find(x), y = find(y);
		if(x == y) continue;
		p[x] = y;
		n --;
		res = w;
		if(n == k) break;
	}

	printf("%.2lf", res);
	return 0;
}