#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int f[N][N];


int dp(int n)
{
    if(!n) return 0;        //根据下方的计算决定0是否纳入参考范围，根据题目描述决定0是否算入答案

    vector<int> nums;
    while(n)
    {
        nums.emplace_back(n % 10);
        n /= 10;
    }

    int res = 0;
    int last = -2;

    // 前导0没有限制，特判
    for(int i = nums.size() - 1; i >= 1; i --)
        for(int j = 1; j <= 9; j ++)
            res += f[i][j];

    for(int i = nums.size() - 1; i >= 0; i --)
    {
        int x = nums[i];
        for(int j = i == nums.size() - 1; j <= x - 1; j ++)
        {
            if(abs(last - j) >= 2)
                res += f[i + 1][j];
        }
        if(abs(x - last) < 2) return res;
        last = x;
        if(!i) res ++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int l, r;
    cin >> l >> r;
    for(int i = 0; i <= 9; i ++)
        f[1][i] = 1;
    for(int i = 2; i <= 30; i ++)
    {
        for(int j = 0; j <= 9; j ++)
        {
            for(int k = 0; k <= 9; k ++)
            {
                if(abs(j - k) >= 2)
                {
                    f[i][j] += f[i - 1][k];
                }
            }
        }
    }


    cout << dp(r) - dp(l - 1) << '\n';
}