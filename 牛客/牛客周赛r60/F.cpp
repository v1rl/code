#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;
constexpr int mod = 1e9 + 7;
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
    vector<int> b(n + 1);
    for(int i = 1; i < n; i ++) cin >> a[i];
    for(int i = 1; i < n; i ++) cin >> b[i];

    vector<int> p(n + 1);
    vector<int> q(n + 1);
    p[1] = 1, q[1] = (a[1] + b[1]) * qmi(a[1], mod - 2) % mod;

    for(int i = 2; i < n; i ++)
    {
        int t = qmi((1ll * a[i] * a[i] % mod + 1ll * (1 - p[i - 1]) * b[i] * b[i] % mod) % mod, mod - 2);
        p[i] = 1ll * a[i] * a[i] % mod * t % mod;
        q[i] = (1ll * b[i] * b[i]  % mod * q[i - 1] % mod + (1ll * a[i] + b[i]) * (a[i] + b[i]) % mod) % mod * t % mod;
    }

    vector<int> f(n + 1);
    f[n] = 1;
    for(int i = n - 1; i; i --)
    {
        f[i] = (1ll * p[i] * f[i + 1] % mod + q[i]) % mod;
    }
    cout << f[1] << '\n';
}  
