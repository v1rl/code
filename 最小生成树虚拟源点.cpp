#include <bits/stdc++.h>
using namespace std;
//https://www.dotcpp.com/oj/problem2397.html
const int N = 310,M = N * N;
int w[N][N];
int dist[M];
bool st[M];
int n;

int prim()
{
	memset(dist, 0x3f, sizeof dist);
	dist[0] = 0;
	int res = 0;

	for(int i = 0; i < n + 1; i ++)
	{
		int t = -1;
		for(int j = 0; j <= n; j ++)
			if(!st[j] && (t == -1 || dist[j] < dist[t]))
				t = j;

		st[t] = true;
		res += dist[t];

		for(int j = 0; j <= n; j ++) dist[j] = min(dist[j], w[t][j]);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> w[0][i];
		w[i][0] = w[0][i];
	}

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cin >> w[i][j];

	cout << prim() << "\n";
	return 0;
}