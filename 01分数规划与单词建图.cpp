#include <bits/stdc++.h>
using namespace std;
//https://www.spoj.com/problems/WORDRING/
int n;
const int N = 26 * 26 + 10;
typedef pair<int,int> PII;
int cnt[N];
double dist[N];
bool st[N];


int get(char a, char b)
{
	int p = (a - 'a') * 26 + (b - 'a');
	return p;
}

bool check(double mid, vector<vector<PII>> adj)
{
	memset(cnt, 0, sizeof cnt);
	memset(st, true, sizeof st);
	queue<int> q;										//用栈优化
	for(int i = 1; i <= 676; i ++) q.push(i);

	int Count = 0;
	while(q.size())
	{
		int x = q.front();
		q.pop();
		st[x] = false;

		for(auto [y, w] : adj[x])
		{
			if(dist[x] + w - mid > dist[y])
			{
				dist[y] = dist[x] + w - mid;
				cnt[y] = cnt[x] + 1;
				if(++ Count > 2 * n) return true;		//经验trick, 理想地认为访问超过总边数的两倍则存在环
				if(cnt[y] >= N) return true;
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

void solve()
{
	vector<string> str;
	for(int i = 1; i <= n; i ++)
	{
		string s;
		cin >> s;
		str.push_back(s);
	}

	vector<vector<PII>> adj(N);
	for(auto s : str)
	{
		int w = s.size();
		if(w >= 2)
		{
			int x = get(s[0], s[1]);
			int y = get(s[w - 2], s[w - 1]);
			adj[x].emplace_back(y, w);
		}
	}

	if(!check(0, adj)) cout << "No solution." << "\n";
	else
	{
		double l = 0.0, r = 1000.0;
		while(r - l > 1e-4)
		{
			double mid = (l + r) / 2;
			if(!check(mid, adj)) r = mid;
			else l = mid;
		}

		printf("%.2lf\n", l);	
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	while(cin >> n, n != 0)
	{
		solve();
	}
}