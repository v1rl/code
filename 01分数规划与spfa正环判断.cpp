#include <bits/stdc++.h>
using namespace std;
//https://www.acwing.com/problem/content/363/
const int N = 1100;
const double eps = 1e-3;
int n, m;
double f[N];
typedef pair<int,int> PII;
vector<vector<PII>> adj(N);
bool st[N];
double dist[N];
int cnt[N];

bool check(double mid)
{
	queue<int> q;
	memset(dist, 0, sizeof dist);
	memset(st, false, sizeof st);
	memset(cnt, 0, sizeof cnt);
	for(int i = 1; i <= n; i ++)
	{
		q.push(i);
		st[i] = true;
	}
	while(q.size())
	{
		int x = q.front();
		q.pop();
		st[x] = false;

		for(auto [y, t] : adj[x])
		{
			if(dist[x] + f[x] - mid * t > dist[y])
			{
				dist[y] = dist[x] + f[x] - mid * t;
				cnt[y] = cnt[x] + 1;
				if(cnt[y] >= n) return true;
				if(!st[y])
				{
					q.push(y);
					st[y] = true;
				}
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> f[i];
	for(int i = 1; i <= m; i ++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		adj[x].emplace_back(y, t);
	}

	double l = 0.0, r = 1000.0;
	while(r - l > eps)
	{
		double mid = (l + r) / 2;
		if(!check(mid)) r = mid;
		else l = mid;
	}

	printf("%.2lf", l);
}