#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// ----推式子让目标式更具体
// ----坐标旋转偏移，转换为找到最陡的直线
// ----注意到，目标直线一定出现在相邻点构成的直线中

void solve()
{
	int n;
	cin >> n;
	vector<array<int, 2>> a(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i][0] >> a[i][1];
	}

	sort(a.begin() + 1, a.end(),
		[&](auto p, auto q)
		{
			return p[0] + p[1] < q[0] + q[1];
		});

	auto get = [&](array<int, 2> p, array<int, 2> q)->double
	{
		i64 d1 = p[0] - q[0], d2 = p[1] - q[1]; 
		return (abs(d1) + abs(d2)) / sqrt(d1 * d1 + d2 * d2);
	};

	double ans = 1;
	for(int i = 2; i <= n; i ++)
	{
		ans = max(ans, get(a[i - 1], a[i]));
	}

	sort(a.begin() + 1, a.end(),
		[&](auto p, auto q)
		{
			return p[0] - p[1] < q[0] - q[1];
		});

	for(int i = 2; i <= n; i ++)
	{
		ans = max(ans, get(a[i - 1], a[i]));
	}

	cout << fixed << setprecision(15);
	cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --)
    {
        solve();
    }
    return 0;
}