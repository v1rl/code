#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 100003;

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
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    i64 n, m;
    cin >> m >> n;
    cout << (qmi(m, n) - m * qmi(m - 1, n - 1) % mod + mod) % mod;
}