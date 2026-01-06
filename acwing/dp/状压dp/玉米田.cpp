#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 13, M = (1 << 12) + 10, mod = 1e8;
vector<int> state;
vector<vector<int>> head(M);
int f[N][M];
int n, m;
int g[N];

bool check1(int x)
{
	return !(x & x >> 1);
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	state.reserve(M);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j < m; j++)
		{
			int x;
			cin >> x;
			g[i] += x << j;
		}

	for(int i = 0; i < 1 << m; i ++) 
		if(check1(i)) state.emplace_back(i);

	for(auto a : state)
		for(auto b : state)
		{
			if((a & b) == 0) head[a].emplace_back(b);
		}

	f[0][0] = 1;
	for(int i = 1; i <= n; i ++)
		for(auto a : state)
			if((g[i] | a) == g[i])
				for(auto b : head[a])
				{
					if((g[i - 1] | b) == g[i - 1]) 
						f[i][a] = (f[i][a] + f[i - 1][b]) % mod;
				}

	int res = 0;
	for(auto a : state) res = (res + f[n][a]) % mod;
	cout << res << '\n';
	return 0;
}