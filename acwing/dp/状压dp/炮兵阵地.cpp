#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 101, M = (1 << 10) + 10;
vector<int> state;
vector<int> head[M];
int f[2][M][M];
int g[N];
int cnt[M];
int n, m;

bool check(int x)
{
	return !((x & x >> 1) | (x & x >> 2));
}

int Count(int x)
{
	int res = 0;
	for(int i = 0; i < m; i ++) res += (x >> i & 1);
	return res;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	state.reserve(M);
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j < m; j ++)
		{
			char c;
			cin >> c;
			if(c == 'P') g[i] += 1 << j;
		}

	for(int i = 0; i < 1 << m; i ++)
	{
		if(check(i)) 
			state.emplace_back(i);
		cnt[i] = Count(i);
	}

	for(auto a : state)
		for(auto b : state)
		{
			if(!(a & b)) head[a].emplace_back(b);
		}

	for(int i = 1; i <= n; i ++)
	{
		for(auto a : state)
		{
			if((g[i] | a) == g[i])
			{
				for(auto b : head[a])
				{
					if((g[i - 1] | b) > g[i - 1]) continue;
					for(auto c : head[b])
					{
						if((g[i - 2] | c) > g[i - 2]) continue;
						if(!(a & c))
							f[i & 1][a][b] = max(f[i & 1][a][b], f[1 - i & 1][b][c] + cnt[a]);
					}
				}
			}
		}
	}

	int ans = 0;
	for(auto a : state)
		for(auto b : head[a])
			ans = max(ans, f[n & 1][a][b]);

	cout << ans << '\n';
}