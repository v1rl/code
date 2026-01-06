#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;

i64 qmi(i64 a, i64 b)
{
	i64 res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;	
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a;
	vector<int> b(2 * n + 1);
	for(int i = 1; i <= 2 * n; i ++)
	{
		cin >> b[i];
		if(b[i] != -1) 
			a.emplace_back(b[i]);
	}

	sort(a.begin(), a.end());
	vector<int> st(n + 1);
	int sum = 0;
	int k = 0;
	i64 ans = 1;
	for(int i = 1; i <= 2 * n; i ++)
	{
		if(b[i] != -1)
			st[b[i]] ++, sum ++;
		else
		{
			ans *= st[a[k]];
			ans %= mod;
			ans *= qmi(sum, mod - 2);
			ans %= mod;

			sum --;
			st[a[k]] --;
			k ++;
			
			if(ans == 0)
			{
				cout << 0 << '\n';
				return;
			}
		}
	}
	cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --)
    {
        solve();
    }
    return 0;
}