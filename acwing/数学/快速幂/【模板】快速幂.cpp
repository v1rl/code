#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 qmi(i64 a, i64 b, i64 mod)
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
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int a, b, mod;
    cin >> a >> b >> mod;
    printf("%d^%d mod %d=%d", a, b, mod, qmi(a, b, mod));
}