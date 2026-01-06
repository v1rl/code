#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;
const int N = 1e6 + 10;

// 注意到偶数和5结尾的情况都是合数
// 或者使用全排列暴力

bool st[N];

vector<int> minp, primes;
void sieve(int n)
{
	minp.assign(n + 1, 0);
	for(int i = 2; i <= n; i ++)
	{
		if(!minp[i])
		{
			minp[i] = i;
			primes.emplace_back(i);
		}
		for(auto p : primes)
		{
			if(p * i > n) break;
			minp[p * i] = p;
			if(minp[i] == p) break;
		}
	}
}

void solve()
{
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	do
	{
		if(s[0] != '0')
		{
			int x = stoi(s);
			if(!st[x]) 
			{
				cout << x << '\n';
				return;
			}
		}
	}while(next_permutation(s.begin(), s.end()));
	cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    sieve(1e6);
    for(auto p : primes)
    	st[p] = true;

    while(t --)
    {
        solve();
    }
    return 0;
}