#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://www.luogu.com.cn/problem/P1297

void solve()
{
	int n, A, B, C, D;
	cin >> n >> A >> B >> C >> D;
	vector<int> a(n + 1); 
	a[1] = D;
	for(int i = 2; i <= n; i ++)
		a[i] = (1ll * a[i - 1] * A + B) % 100000001;
	for(int i = 1; i <= n; i ++)
		a[i] = a[i] % C + 1;

	// for(int i = 1; i <= n; i ++)
	// {
	// 	cout << a[i] << ' ';
	// }
	if(n == 1)
	{
		printf("1.000");
		return;
	}
	double ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(i == n) ans += 1.0 / max(a[1], a[n]);
		else ans += 1.0 / max(a[i], a[i + 1]);
	}
	printf("%.3lf", ans);
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
}