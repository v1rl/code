#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9 + 10;
const int mod = 1e9 + 7;

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

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    i64 res = 0;
    for(int i = 2; i <= n; i ++)
    {
        res = (res + (1ll * a[i] * (i - 1) - a[i - 1]) % mod) % mod;
        a[i] = (a[i] + a[i - 1]) % mod;
    }
    res *= 2;
    res *= (n - 1);
    res %= mod;

    vector<int> fact(n + 1), infact(n + 1);
    fact[0] = infact[0] = 1;
    for(int i = 1; i <= n; i ++)
    {
        fact[i] = (1ll * fact[i - 1] * i) % mod;
        infact[i] = (1ll * infact[i - 1] * qmi(i, mod - 2)) % mod;
    }

    i64 ans = ((res * fact[n - 2]) % mod * infact[n]) % mod;
    cout << (ans + mod) % mod << '\n';
}