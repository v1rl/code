#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;

i64 phi(i64 n)
{
    i64 res = n;
    for(int i = 2; i <= n / i; i ++)
    {
        if(n % i == 0)
        {
            res = res / i * (i - 1);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) res = res / n * (n - 1);
    return res;
}

i64 qmul(i64 a, i64 b, i64 mod)
{
    i64 res = 0;
    while(b)
    {
        if(b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

i64 qmi(i64 a, i64 b, i64 mod)
{
    i64 res = 1;
    while(b)
    {
        if(b & 1) res = qmul(res, a, mod);
        a = qmul(a, a, mod);
        b >>= 1;
    }
    return res;
}

int main()  
{  
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    int id = 0;
    while(cin >> n, n)
    {
        id ++;
        i64 g = gcd(n, 8);
        i64 mod = 1ll * n * 9 / g;
        i64 p = phi(mod);
        // cout << mod << '\n';
        i64 res = 1e18;
        if(gcd(mod, 10) != 1) res = 0;
        for(i64 i = 1; i <= p / i; i ++)
        {
            if(p % i == 0)
            {
                if(qmi(10, i, mod) == 1) res = min(res, i);
                if(qmi(10, p / i, mod) == 1) res = min(res, p / i);
            }
        }
        printf("Case %d: %d\n", id, res);
    }
    return 0;
}  
