#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
const int inf = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) 
		cin >> a[i];
	sort(a.begin() + 1, a.end());

	// f(前i个，和为j，用了k条边，最值为p)的可达性

	bitset<205> f;
	f[0] = 1;
	int ans = inf;
	for(int i = 1; i <= n; i ++)
	{
		/*
		for(int j = 200; j >= 0; j --)
		{
			if(f[j] && j > a[i])
				ans = min(ans, j + a[i]);
			if(j >= a[i] && f[j - a[i]]) f[j] = true;
		}
		*/

		for(int j = 200; j > a[i]; j --)
		{
			if(f[j])
				ans = min(ans, j + a[i]);
		}
		f |= f << a[i];
	}
	cout << (ans == inf ? -1 : ans) << '\n';
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
    return 0;
}