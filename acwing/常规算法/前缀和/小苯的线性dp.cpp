#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
const int inf = 1e9 + 7;

// https://ac.nowcoder.com/acm/contest/104637

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	vector<i64> s(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		s[i] += s[i - 1] + a[i];
	}

	for(int k = 1; k <= n - 2; k ++)
	{
		vector<i64> pre(n + 1), suf(n + 2);
		for(int i = 1; i <= n; i ++)
		{
			i64 t = s[i] - s[max(0, i - k)];
			pre[i] = max(pre[i - 1], t);
		}

		for(int i = n; i >= 1; i --)
		{
			i64 t = s[min(i + k - 1, n)] - s[i - 1];
			suf[i] = max(suf[i + 1], t);
		}

		i64 mx = 0;
		for(int i = 1; i <= n; i ++)
		{
			mx = max(mx, max(pre[i - 1], suf[i + 1]) - a[i]);
		}

		cout << mx << ' ';
	}
	if(n != 1) cout << max(s[n] - 2 * a[1], s[n - 1] - a[n]) << ' ';
	cout << 0 << '\n';
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