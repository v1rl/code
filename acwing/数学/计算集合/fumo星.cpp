#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve()
{
	int n;
	cin >> n;
	vector<array<int, 2>> p(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int x, y;
		cin >> x >> y;
		p[i] = {x, y};
	}

	set<array<i64, 3>> S;
	for(int i = 1; i <= n; i ++)
	{
		auto [x1, y1] = p[i];
		for(int j = i + 1; j <= n; j ++)
		{
			auto [x2, y2] = p[j];
			int dx = x2 - x1, dy = y2 - y1;
			int g = __gcd(dx, dy);
			if(g == 0)
			{
				cout << "inf" << '\n';
				return;
			}
			dx /= g, dy /= g;
			if(dx < 0) dx = -dx, dy = -dy;

			i64 b = 1ll * dy * x1 - 1ll * dx * y1;
			S.insert({dx, dy, b});
		}
	}

	cout << S.size() << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}

