#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n, k, m;
	cin >> n >> k >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	sort(a.begin() + 1, a.end());
	vector<array<int, 2>> p;
	p.reserve(n);

	int l = 1, r = 2;
	while(r <= n)
	{
		if(a[r] - a[r - 1] > k)
		{
			if(r - l == 1)
			{
			 	if(l == 1) p.push_back({a[l], a[l]});
			}
			else p.push_back({a[l + 1] - k, a[r - 2] + k});
			l = r;
		}
		r ++;
	}
	if(l == n) p.push_back({a[l], a[l]});
	else p.push_back({a[l + 1] - k, a[r - 2] + k});

	int L = 1e9;
	int res = 0;
	for(int i = 0; i < p.size(); i ++)
	{
		if(L < p[i][0]) res += (p[i][0] - L + k - 1) / k;
		L = p[i][1];
	}
	if(res <= m)  cout << "Yes" << '\n';
	else cout << "No" << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	// t = 1;
	while(t --)
	{
		solve();
	}
}