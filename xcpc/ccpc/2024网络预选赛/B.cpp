#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

i64 qmi(i64 a, int b)
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

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    i64 ny = qmi(9, mod - 2);
    while(t --)
    {
        int m;
        cin >> m;
        vector<int> nums(10);
        for(int i = 0; i <= 9; i ++) cin >> nums[i];

        if(m == 1 && nums[0])
        {
            cout << 0 << '\n';
            continue;
        }
        i64 ans = 0;
        for(int i = 1; i <= 9; i ++)
        {
            if(nums[i])
            {
                ans = i, nums[i] --, m --;
                break;
            }
        }

        for(int i = 0; i <= 9; i ++)
        {
            if(nums[i])
            {
                int c = min(nums[i], m);
                m -= c;
                int z = qmi(10, c);
                ans = ans * z % mod;
                ans = (ans + ((z - 1) * ny % mod * i)) % mod;
            }
            if(m == 0) break;
        }
        cout << ans << '\n';
    }
    return 0;
}
