#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 200907;

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

void solve()
{
    int flag = 0;
    i64 a, b, c, n;
    cin >> a >> b >> c >> n;
    if(c - b == b - a) flag = 1;
    else flag = 2;
    if(flag == 1) cout << (a + (b - a) * (n - 1) % mod) % mod << '\n';
    else cout << (a * qmi(b / a, n - 1)) % mod << '\n';
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
}