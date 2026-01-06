#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 20, mod = 1e9 + 7;
array<int, 3> f[N][10][10];
int nums[N];
int p[20];

array<int, 3> dp(int pos, int val, int sum, int op)
{
    if(!pos)
    {
        if(val && sum) return {1, 0, 0};
        return {0, 0, 0};
    }
    if(!op && f[pos][val][sum][0] != -1) return f[pos][val][sum];
    array<int, 3> res{};
    int mx = op ? nums[pos] : 9;
    for(int i = 0; i <= mx; i ++)
    {
        if(i == 7) continue;
        auto t = dp(pos - 1, (val * 10 + i) % 7, (sum + i) % 7, op && i == nums[pos]);
        int k = 1ll * i * p[pos - 1] % mod;
        t[2] = (t[2] + 1ll * k * k % mod * t[0]) % mod;         //存的不是单个二项式各项，存的是二项式各项的求和，因而还单独存了一位t[0]表示有几个这样的二项式
        t[2] = (t[2] + 2ll * k * t[1]) % mod;
        t[1] = (t[1] + 1ll * t[0] * k % mod) % mod;
        res[0] = (res[0] + t[0]) % mod;
        res[1] = (res[1] + t[1]) % mod;
        res[2] = (res[2] + t[2]) % mod;
    }
    return op ? res : f[pos][val][sum] = res;
}

int calc(i64 n)
{
    // memset(f, -1, sizeof f);
    int tt = 0;
    while(n) nums[++ tt] = n % 10, n /= 10;
    return dp(tt, 0, 0, 1)[2];
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    memset(f, -1, sizeof f);
    p[0] = 1;
    for(int i = 1; i < 20; i ++)
    {
        p[i] = 1ll * p[i - 1] * 10 % mod;
    }

    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        i64 l, r;
        cin >> l >> r;
        cout << ((calc(r) - calc(l - 1)) % mod + mod) % mod << '\n';
    }
    return 0;
}