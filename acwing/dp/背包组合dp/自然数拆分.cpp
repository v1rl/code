#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 4010;
i64 f[N];
const i64 mod = 2147483648;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    f[0] = 1;
    for(int i = 1; i <= n; i ++)
        for(int j = i; j <= n; j ++)
            f[j] = (f[j] + f[j - i]) % mod;

    cout << ((f[n] - 1) % mod + mod) % mod << '\n';
}