#include<bits/stdc++.h>
using namespace std;
//https://ac.nowcoder.com/acm/contest/84888
#define int long long
const int inf = 1e9;

struct Node
{
	int x, y;
};

signed main()
{
	int n, m;
	cin >> n >> m;
	vector<Node> l;
	for(int i = 1; i <= n; i ++)
	{
		int x, y;
		cin >> x >> y;
		l.push_back({x, y});
	}

	int ma1 = -inf, ma2 = -inf, ma3 = -inf, ma4 = -inf;
	int x1, x2, x3, x4, y1, y2, y3, y4;

	for(int i = 1; i <= m; i ++)
	{
		int x, y;
		cin >> x >> y;
		if(x + y > ma1)
		{
			ma1 = x + y;
			x1 = x;
			y1 = y;
		}
		if(x - y > ma2)
		{
			ma2 = x - y;
			x2 = x;
			y2 = y;
		}
		if(-x + y > ma3)
		{
			ma3 = -x + y;
			x3 = x;
			y3 = y;
		}
		if(-x - y > ma4)
		{
			ma4 = -x - y;
			x4 = x;
			y4 = y;
		}		
	}

	int ans = 0;
	for(auto [x, y] : l)
	{
		if(x1 >= x && y1 >= y) ans = max(ans, ma1 - x - y);
		if(x2 >= x && y2 <= y) ans = max(ans, ma2 - x + y);
		if(x3 <= x && y3 >= y) ans = max(ans, ma3 + x - y);
		if(x4 <= x && y4 <= y) ans = max(ans, ma4 + x + y);
	}
	cout << ans << "\n";
}