#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int f[N][N];


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

        if(x < last) return res;
        for(int j = last; j <= x - 1; j ++)
        {
            res += f[i + 1][j];
        }

        last = x;

        if(!i) res ++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i <= 9; i ++)
        f[1][i] = 1;
    for(int i = 2; i <= 30; i ++)
    {
        for(int j = 0; j <= 9; j ++)
        {
            for(int k = j; k <= 9; k ++)
            {
                f[i][j] += f[i - 1][k];
            }
        }
    }
    while(t --)
    {
        int l, r;
        cin >> l >> r;
        cout << dp(r) - dp(l - 1) << '\n';
    }

}