#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 110;
int f[35][10][N];
int mod;

int get(int cur, int ls)
{
    return ((cur - ls) % mod + mod) % mod;
}

int dp(int n)
{
    if(!n) return 1;

    vector<int> nums;
    while(n)
    {
        nums.emplace_back(n % 10);
        n /= 10;
    }

    int res = 0;
    int last = 0;
    for(int i = nums.size() - 1; i >= 0; i --)
    {
        int x = nums[i];
        for(int j = 0; j <= x - 1; j ++)
        {
            res += f[i + 1][j][get(mod, last)];
        }
        last += x;
        if(!i && last % mod == 0) res ++;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int l, r;
    cin >> l >> r >> mod;

    for(int i = 0; i <= 9; i ++)
    {
        f[1][i][i % mod] ++;
    }
    for(int i = 2; i <= 30; i ++)
    {
        for(int j = 0; j <= 9; j ++)
        {
            for(int k = 0; k < mod; k ++)
            {
                for(int ls = 0; ls <= 9; ls ++)
                {
                    f[i][j][k] += f[i - 1][ls][get(k, j)];
                }
            }
        }
    }

    cout << dp(r) - dp(l - 1) << '\n';
}