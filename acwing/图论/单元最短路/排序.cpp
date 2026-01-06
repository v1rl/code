#include<bits/stdc++.h>
using namespace std;
int n, m;

int check(vector<vector<int>> &dist)
{
	for(int i = 0; i < n; i ++)
		for(int j = 0; j <= i; j ++)
				if(dist[i][j] && dist[j][i]) return 0;

	for(int i = 0; i < n; i ++)
		for(int j = 0; j < i; j ++)
			if(!dist[i][j] && !dist[j][i]) return 2;

	return 1;
}

char get_min(vector<vector<int>> &dist, vector<bool> &st)
{
	for(int i = 0; i < n; i ++)
	{
		if(st[i]) continue;
		bool f = true;
		for(int j = 0; j < n; j ++)
		{
			if(st[j] || j == i) continue;
			if(!dist[i][j]) f = false;
		}
		if(f)
		{
			st[i] = true;
			return i + 'A';
		}
	}
	return 'A';
}

void floyd(int x, vector<vector<int>> &dist)
{
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			dist[i][j] |= dist[i][x] && dist[x][j];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	while(cin >> n >> m, n || m)
	{
		vector<vector<int>> dist(n, vector<int>(n));
		vector<bool> st(n);
		bool f = false;
		for(int cnt = 0; cnt < m; cnt ++)
		{
			string s;
			cin >> s;
			if(f) continue;
			int a = s[0] - 'A', b = s[2] - 'A';
			dist[a][b] = 1;
			floyd(a, dist), floyd(b, dist);

			int t = check(dist);
			if(t == 0)
			{
				printf("Inconsistency found after %d relations.\n", cnt + 1);
				f = true;
			}
			else if(t == 1)
			{
				printf("Sorted sequence determined after %d relations: ", cnt + 1);
				for(int j = 0; j < n; j ++) printf("%c", get_min(dist, st));
				printf(".\n");
				f = true;
			}

		}
		if(!f) printf("Sorted sequence cannot be determined.\n");
	}
}