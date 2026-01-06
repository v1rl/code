#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int C[N][N];

int k, b;

int dp(int n)
{
    if(!n) return 0;

    vector<int> nums;
    while(n)
    {
        nums.emplace_back(n % k);
        n /= k;
    }
    int res = 0;
    int sel = 0;
    for(int i = nums.size() - 1; i >= 0; i --)
    {
        int x = nums[i];
        if(x)
        {
            res += C[i][b - sel];
            if(x > 1)
            {
                if(b - 1 - sel >= 0) res += C[i][b - 1 - sel];
                return res;
            }
            else
            {
                sel ++;
            }
            if(sel > b) return res;
        }
        if(!i && sel == b) res ++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int l, r;
    cin >> l >> r;
    cin >> k >> b;
    for(int i = 0; i <= 30; i ++)
        for(int j = 0; j <= i; j ++)
        {
            if(!j) C[i][j] = 1;
            else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }

    cout << dp(r) - dp(l - 1);
}