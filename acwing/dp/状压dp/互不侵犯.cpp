#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 11, M = (1 << 9) + 10;
vector<int> state;
vector<vector<int>> head(M);
int cnt[M];
i64 f[N][90][M];
int n, m;

bool check(int x)
{
	return !(x & x >> 1);
}

int Count(int x)
{
	int res = 0;
	for(int i = 0; i < n; i ++) res += (x >> i & 1);
	return res;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	state.reserve(M);
	cin >> n >> m;
	for(int i = 0; i < 1 << n; i ++)
	{
		if(check(i))
		{
			state.emplace_back(i);
			cnt[i] = Count(i);
		}
	}

	for(auto a : state)
	{
		for(auto b : state)
		{
			if(check(a | b) && (a & b) == 0)
				head[a].emplace_back(b);		
		}
	}

	f[0][0][0] = 1;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 0; j <= m; j ++)
		{
			for(auto a : state)
			{
				for(auto b : head[a])
				{
					int c = cnt[a];
					if(j >= c)
					{
						f[i][j][a] += f[i - 1][j - c][b];
					}
				}
			}
		}
	}

	i64 res = 0;
	for(auto a : state) res += f[n][m][a];
	cout << res << '\n';
}