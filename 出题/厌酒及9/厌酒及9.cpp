#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7, N = 20;
int f[N][10][10];
int nums[N];

int dp(int pos, int val, int sum, int op)
{
    if(!pos)
    {
        if(val && sum) return 1;
        return 0;
    }
    if(!op && f[pos][val][sum] != -1) return f[pos][val][sum];
    int res = 0, mx = op ? nums[pos] : 9;
    for(int i = 0; i <= mx; i ++)
    {
        if(i == 9) continue;
        res = (res + dp(pos - 1, (val * 10 + i) % 9, (sum + i) % 9, op && i == nums[pos])) % mod;
    }
    return op ? res : f[pos][val][sum] = res;
}

int calc(i64 n)
{
    int tt = 0;
    while(n) nums[++ tt] = n % 10, n /= 10;
    return dp(tt, 0, 0, 1);
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    memset(f, -1, sizeof f);
    int n;
    cin >> n;
    while(n --)
    {
        i64 l, r;
        cin >> l >> r;
        cout << ((calc(r) - calc(l - 1)) % mod + mod) % mod << '\n';
    }    
}