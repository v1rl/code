#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353, N = 1e5 + 10;
int mi26[N];

i64 qmi(i64 a, i64 b)
{
    i64 res = 1;
    while(b)
    {
        if(b & 1) res = res * a % mod;
        a = (i64)a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;

    mi26[0] = 1;
    for(int i = 1; i < N; i ++)
        mi26[i] = (i64)mi26[i - 1] * 26 % mod;
    i64 inv26 = qmi(26, mod - 2);

    i64 res = 1;
    i64 tep = 26;
    for(int i = 1; i <= m; i ++)
    {
        if(tep < n)
        {
            res = (res + tep) % mod;
            tep *= 26;
        }
        else res = (res + n) % mod;
    }

    i64 ans = 1;
    for(int i = 1; i <= m; i ++)
    {
        ans = (ans + (1 - qmi(1 - qmi(inv26, i), n)) * mi26[i] % mod) % mod;
        // ans = (ans + (1 - qmi(1 - qmi(mi26[i], mod - 2), n)) * mi26[i] % mod) % mod;
    }
    cout << res << ' ' << (ans + mod) % mod << '\n';
}   