#include <bits/stdc++.h>
using namespace std;
//https://www.acwing.com/problem/content/348/
const int N = 6010;
struct Node
{
	int x, y, w;
	bool operator < (const Node &W) const
	{
		return w < W.w;
	}
};
int p[N], siz[N];


int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void solve()
{
	int n;
	cin >> n;
	vector<Node> edge;
	for(int i = 0; i < n - 1; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		edge.push_back({x, y, w});
	}

	sort(edge.begin(), edge.end());

	for(int i = 1; i <= n; i ++) p[i] = i, siz[i] = 1;

	int res = 0;
	for(auto [x, y, w] : edge)
	{
		x = find(x), y = find(y);
		if(x == y) continue;
		p[x] = y;
		res += (siz[x] * siz[y] - 1) * (w + 1);
		siz[y] += siz[x];
	}
	cout << res << "\n";
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T --)
	{
		solve();
	}
}