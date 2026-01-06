#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 4e5 + 5;

// 把小数优先拿走

vector<int> minp, primes;
void sieve(int n)
{
    minp.assign(n + 1, 0);
    for(int i = 2; i <= n; i ++)
    {
        if(minp[i] == 0)
        {
            minp[i] = i;
            primes.emplace_back(i);
            if(primes.size() == N) break;
        }
        for(auto p : primes)
        {
            if(i * p > n) break;
            minp[i * p] = p;
            if(p == minp[i]) break;
        }
    }
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	int k = 0;
	i64 num = 0;
	sort(a.begin() + 1, a.end());
	int ans = 0;
	for(int i = n; i >= 1; i --)
	{
		num += a[i] - primes[k];
		k ++;
		if(num < 0)
		{
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
	sieve(1e7);
	// cout << primes.size() << '\n';

    while(t --)
    {
        solve();
    }
    return 0;
}