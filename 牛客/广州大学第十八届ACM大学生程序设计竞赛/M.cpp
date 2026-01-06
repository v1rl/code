#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve()
{
	int n;
	cin >> n;
	vector<array<int, 3>> p(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int x, y;
		cin >> x >> y;
		p[i] = {x, y, i};
	} 
	
	sort(p.begin() + 1, p.end(),
	[&](auto i, auto j)
	{
		if(i[0] != j[0]) return i[0] < j[0];
		return i[1] < j[1];	
	});
	
	cout << n / 2 << '\n';
	for(int i = 2; i <= n; i += 2)
	{
		cout << p[i - 1][2] << ' ' << p[i][2] << '\n';
	}
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    // cin >> t;
    t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}
