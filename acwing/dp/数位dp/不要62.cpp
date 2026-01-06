#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int f[35][10];

int dp(int n)
{
    if(!n) return 1;
    vector<int> nums;
    while(n) nums.emplace_back(n % 10), n /= 10;

    int res = 0;
    int last = 0;
    for(int i = nums.size() - 1; i >= 0; i --)
    {
        int x = nums[i];
        for(int j = 0; j <= x - 1; j ++)
        {
            if(j == 4 || (last == 6 && j == 2)) continue;
            res += f[i + 1][j];
        }
        if(x == 4 || (last == 6 && x == 2)) return res;
        last = x;
        if(!i) res ++; 
    }
    return res;

}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    for(int i = 0; i <= 9; i ++)
    {
        if(i == 4) continue;
        f[1][i] = 1;
    }
    for(int i = 2; i <= 30; i ++)
    {
        for(int j = 0; j <= 9; j ++)
        {
            if(j == 4) continue;
            for(int k = 0; k <= 9; k ++)
            {
                if(k == 4) continue;
                if(j == 6 && k == 2) continue;
                f[i][j] += f[i - 1][k];
            }
        }
    }

    int l, r;
    while(cin >> l >> r, l)
    {
        cout << dp(r) - dp(l - 1) << '\n';
    }
}