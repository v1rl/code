#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;
constexpr int N = 1e6, mod = 1e9 + 7;
vector<int> fact(N + 1), infact(N + 1);

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

i64 C(i64 n, i64 m)
{
    return 1ll * fact[n] * infact[n - m] % mod * infact[m] % mod;
}
  
int main()  
{  
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    fact[0] = infact[0] = 1;
    for(int i = 1; i <= N; i ++)
    {
        fact[i] = 1ll * fact[i - 1] * i % mod;
        infact[i] = 1ll * infact[i - 1] * qmi(i, mod - 2) % mod;
    }
    while(t --)
    {
        int n, m;
        cin >> n >> m;
        cout << C(n - 2, m - 1) << '\n';
    }
    return 0;
}  
