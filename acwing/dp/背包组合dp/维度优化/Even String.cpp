#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
const int mod = 998244353;

// https://codeforces.com/contest/2086/problem/D

struct Comb
{
    int n, mod;
    vector<int> fact, infact;

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

    Comb(int n_, int m_) : n(n_ + 1), mod(m_), fact(n), infact(n)
    {
        fact[0] = infact[0] = 1;
        for(int i = 1; i <= n; i ++)
        {
            fact[i] = 1ll * fact[i - 1] * i % mod;
            infact[i] = 1ll * infact[i - 1] * qmi(i, mod - 2) % mod;
        }
    };

    i64 C(int a, int b)
    {
        if(a < 0 || b < 0 || a < b) return 0;
        return 1ll * fact[a] * infact[b] % mod * infact[a - b] % mod;
    }

    i64 A(int a, int b)
    {
        return C(a, b) * fact[b] % mod;
    }
};

Comb comb(500010, mod);			//多测中多次初始化会莫名RE

void solve()
{
	i64 sum = 0;
	vector<int> a(27);
	for(int i = 1; i <= 26; i ++)
	{
		cin >> a[i];
		sum += a[i];
	}

	int s1 = sum / 2, s2 = (sum + 1) / 2;
	int u = 0;
	vector f(27, vector(s1 + 1, 0));
	f[0][s1] = 1;
	for(int i = 1; i <= 26; i ++)
	{
		if(a[i] == 0)		//因此对a[i]==0特判，直接继承
		{
			f[i] = f[i - 1];
			continue;
		}
		for(int j = 0; j <= s1; j ++)
		{
			if(j >= a[i]) f[i][j - a[i]] += f[i - 1][j] * comb.C(j, a[i]) % mod, f[i][j - a[i]] %= mod;		
			int k = s2 - (u - (s1 - j));
			if(k <= s2 && k >= a[i]) f[i][j] += f[i - 1][j] * comb.C(k, a[i]) % mod, f[i][j] %= mod;		//a[i]==0时会继承两次上一轮的值
		}
		u += a[i];
	}
	cout << f[26][0] << '\n';
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