#include <bits/stdc++.h>
using namespace std;
const int N = 55, mod = 1e9 + 7;
int ne[N];
int n, m;
int f[N][N];

void scan(string s)
{
	for(int i = 2, j = 0; i <= m; i ++)
	{
		while(j && s[i] != s[j + 1]) j = ne[j];
		if(s[i] == s[j + 1]) j ++;
		ne[i] = j;
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	string s;
	cin >> s;
	s = "#" + s;

	scan(s);
	f[0][0] = 1;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < m; j ++)
		{
			for(char k = 'a'; k <= 'z'; k ++)
			{
				int u = j;
				while(u && s[u + 1] != k) u = ne[u];
				if(s[u + 1] == k) u ++;
				if(u != m)
				{
					f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod;
				// 	cout << i + 1 << ' ' << u  << ' ' << f[i + 1][j] << '\n';
				}
			}
		}
	}
	int res = 0;
	for(int i = 0; i < m; i ++)
	{
		res = (res + f[n][i]) % mod;
	}
	cout << res << '\n';
}