#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int f[35][10];
int nums[35];

int dp(int pos, int last, int op)
{
    if(!pos) return 1;
    if(!op && f[pos][last] != -1) return f[pos][last];
    int res = 0, mx = op ? nums[pos] : 9;
    for(int i = 0; i <= mx; i ++)  
    {
        if(abs(last - i) < 2) continue;
        res += dp(pos - 1, last == -2 && !i ? -2 : i, op && i == nums[pos]);
    }
    return op || last == -2 ? res : f[pos][last] = res;
}

int calc(int n)
{
    int tt = 0;
    memset(f, -1, sizeof f);
    while(n) nums[++ tt] = n % 10, n /= 10;
    return dp(tt, -2, 1);
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << '\n';
}