#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;

void solve()
{
	vector<int> a(15);
	for(int i = 1; i <= 9; i ++)
	{
		cin >> a[i];
	}
	int t = min(a[1], a[2]);
	a[2] -= t, a[1] -= t, a[3] += t;
	if(a[1])
	{
		a[3] += a[1] / 3;
		a[1] %= 3;
		a[2] += a[1] / 2;
		a[1] %= 2;
	}
	if(a[1])
	{
		for(int i = 2; i <= 9; i ++)
		{
			if(a[i])
			{
				a[i + 1] ++;
				a[i] --;
				a[1] --;
				break;
			}
		}
	}

	i64 ans = 1;
	for(int i = 2; i <= 10; i ++)
	{
		// cout << a[i] << ' ';
		while(a[i])
		{
			ans *= i;
			a[i] --;
			ans %= mod;
		}
	}
	// cout << '\n';

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