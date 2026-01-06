#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 210;
int g[N][N], dist[N][N]; 

void solve()
{
	int n, m, e, d;
	cin >> n >> m >> e >> d;
	int day = 0;
	// vector<vector<int>> adj(m + 1);
	vector<array<int, 2>> dat;
	dat.reserve(n);
	int mpos, res;
	cin >> mpos >> res;
	int total = res;
	for(int i = 0; i < n - 1; i ++)
	{
		int pos, w;
		cin >> pos >> w;
		dat.push_back({w, pos});
		total += w;
	}
	memset(dist, 0x3f, sizeof dist);
	memset(g, 0x3f, sizeof g);
	for(int i = 1; i <= e; i ++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		dist[x][y] = dist[y][x] = c;
		g[x][y] = g[y][x] = 1;
	}
	for(int i = 0; i < m; i ++) 
		dist[i][i] = g[i][i] = 0;

	for(int i = 0; i < m; i ++)
		for(int j = 0; j < m; j ++)
			for(int k = 0; k < m; k ++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}

	while(!dat.empty())
	{
		int cw = -1, ct = -1, cd = 1e9, cr = 1e9;
		for(auto [w, pos] : dat)
		{
			if(w <= res && w > cw)
			{
				cw = w;
				ct = pos;
				cd = dist[mpos][ct];
				cr = g[mpos][ct];
			}
			if(w == cw)
			{
				if(dist[mpos][pos] < cd)
				{
					ct = pos;
					cd = dist[mpos][ct];
					cr = g[mpos][ct];
				}
				else if(dist[mpos][pos] == cd && g[mpos][pos] < cr)
				{
					ct = pos;
					cr = g[mpos][ct];
				}
				else if(dist[mpos][pos] == cd && g[mpos][pos] == cr)
				{
					ct = min(ct, pos);
				}
			}
		}

		if(cw == -1)
		{
			printf("Lose on day %d with %d.", day + 1, res);
			break;
		}

		day += cd;
		if(day > d)
		{
			printf("Game over with %d.", res);
			break;
		}
		if(mpos != ct) printf("Move from %d to %d.\n", mpos, ct);

		day ++;
		if(day > d)
		{
			printf("Game over with %d.", res);
			break;
		}
		// cerr << day << '\n;
		printf("Get %d at %d on day %d.\n", cw, ct, day);
		res += cw;
		mpos = ct;


		vector<array<int, 2>> ndat;
		ndat.reserve(n);
		int sum = 0;
		for(auto [w, pos] : dat)
		{
			if(pos == ct)
			{
				sum += w;
			}
			else ndat.push_back({w, pos});
		}

		sum -= cw;
		if(sum != 0)
		{
			if(res >= sum)
			{
				day ++;
				if(day > d)
				{
					printf("Game over with %d.", res);
					break;
				}
				res += sum;
				printf("Get %d at %d on day %d.\n", sum, ct, day);
			}
			else 
			{
				ndat.push_back({sum, ct});
			}
		}

		dat = ndat;
	}
	if(res == total) printf("WIN on day %d with %d!", day, res);
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