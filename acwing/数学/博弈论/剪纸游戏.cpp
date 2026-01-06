#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 210;
int f[N][N];

// https://www.acwing.com/problem/content/description/221/

void solve()
{
	int n, m;
	memset(f, -1, sizeof f);
	while(cin >> n >> m, n || m)
	{
		auto sg = [&](auto && self, int x, int y)->int
		{
		    if(x > y) swap(x, y);
			if(f[x][y] != -1) return f[x][y];
            bool st[N];
			memset(st, false, sizeof st);
			for(int i = 2; i < x - 1; i ++)
			{
				st[self(self, i, y) ^ self(self, x - i, y)] = true;
			}
			for(int i = 2; i < y - 1; i ++)
			{
				st[self(self, x, i) ^ self(self, x, y - i)] = true;
			}

			for(int i = 0; ; i ++)
			{
				if(!st[i]) return f[x][y] = f[y][x] = i;
			}
			return 114514;
		};

		f[2][2] = f[2][3] = f[3][2] = 0;
		cout << (sg(sg, n, m) ? "WIN" : "LOSE") << '\n';
	}
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --)
    {
    	solve();
    }
}