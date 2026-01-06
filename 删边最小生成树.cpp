#include <bits/stdc++.h>
using namespace std;
//https://www.luogu.com.cn/problem/P1991
const int N = 510, M = N * N;
typedef pair<int, int> PII;
PII a[N];
int p[M];
struct Node
{
	int x, y;
	double w;
	bool operator < (const Node &W) const
	{
		return w < W.w;
	} 
};
vector<Node> adj;

double get(PII a, PII b)
{
	int dx = a.first - b.first, dy=a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int k, n;
	cin >> k >> n;
 
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
		{
			adj.push_back({i, j, get(a[i], a[j])});
		}

	sort(adj.begin(), adj.end());
	int m = adj.size();
	for(int i = 1; i <= m; i++) p[i] = i;

	int cnt = n;
    double ans = 0;
	for(auto [x, y, w] : adj)
	{
		x = find(x), y = find(y);
		if(x == y) continue;
		p[x] = y;
		cnt--;
		ans = w;
		if(cnt == k) break;
	}
	printf("%.2lf", ans);	
	return 0;
}