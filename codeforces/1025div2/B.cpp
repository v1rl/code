#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

// 3 5	3 3		2 3		1 3		1 2 	1 1

int work(int x)
{
	int num = 0;
	while(x > 1)
	{
		x = (x + 1) / 2;
		num ++;
	}
	return num;
}

void solve()
{
	int n, m, a, b;
	cin >> n >> m >> a >> b;

	int r = min(n - a + 1, a), c = min(m - b + 1, b);

	int ans = min(work(r) + work(m), work(n) + work(c));
	cout << ans + 1 << '\n';
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