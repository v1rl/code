#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

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

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;

    Comb comb(10000, 1e9 + 7);
    while(t --)
    {
        int a, b;
        cin >> a >> b;
        cout << comb.C(a, b) << '\n';
    }
}