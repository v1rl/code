#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int inf = 2e9;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i ++) cin >> a[i];
        sort(a.begin(), a.end());

        int h = n / 2;
        int ml = a[h / 2], mr = a[h / 2 + h];
        i64 ans = 1e18;
        for(auto xl : {ml, ml - 1})             //ml + 1在中间相等时可能横跨到右半部分，即便是正常情况下也与ml - 1等价因此不予考虑
        {
            for(auto xr : {mr, mr + 1})
            {
                if(xl == xr) continue;
                i64 res = 0;
                for(int i = 0; i < h; i ++)
                {
                    res += abs(a[i] - xl);
                    res += abs(a[i + h] - xr);
                }
                ans = min(res, ans);
            }
        }
        cout << ans << '\n';

    }
}