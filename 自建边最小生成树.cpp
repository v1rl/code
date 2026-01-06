#include <bits/stdc++.h>
using namespace std;
//https://www.dotcpp.com/oj/problem3128.html
const int N = 1010, M = N * N;
int p[M];
int n, m;
struct Node
{
	int x, y, w;
};
vector<Node> adj;							//从小打大建边可无需排序

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void get()
{
	int dx[4] = {-1, 0, 1, 0}, dy[4]={0, -1, 0, 1}, dw[4] = {1, 2, 1, 2};
	for(int z = 0; z < 2; z ++)
		for(int x = 1; x <= n; x ++)
			for(int y = 1; y <= m; y ++)
				for(int i = 0; i < 4; i ++)
				{
					if(i % 2 == z)
					{
						int wx = x + dx[i], wy = y + dy[i];
						if(wx > 0 && wx <= n && wy > 0 && wy <=m)
						{
							int a = (x - 1) * m + y, b = (wx - 1) * m + wy;
							if(a > b) adj.push_back({a, b, dw[i]});
						}
					}
				}

}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;

	for(int i = 1; i <= M; i++)	p[i] = i;

	int x1, y1, x2, y2;
	while(cin >> x1 >> y1 >> x2 >> y2)
	{
		int a = (x1 - 1) * m + y1, b = (x2 - 1) * m + y2;
		a = find(a), b = find(b);
		p[a] = b;
	}

	get();

	int ans = 0;
	for(auto [x, y, w] : adj)
	{
		int a = find(x), b = find(y);
		if(a != b) p[a] = b, ans += w;
	}
	cout << ans << "\n";
	return 0;
}