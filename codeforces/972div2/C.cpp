#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i ++) cin >> s[i];

    array<int, 5> dp;
    dp.fill(-inf);
    dp[0] = 0;

    string t = "narek";
    for(int i = 0; i < n; i ++)
    {
        auto ndp = dp;
        for(int x = 0; x < 5; x ++)
        {
            int y = x;
            int res = 0;
            for(auto c : s[i])
            {
                if(c == t[y])
                {
                    y ++;
                    if(y == 5)
                    {
                        res += 5;
                        y = 0;
                    }
                }
                else if(t.find(c) != -1) res --;
            }
            ndp[y] = max(ndp[y], dp[x] + res);
        }
        dp = ndp;
    }

    int ans = 0;
    for(int i = 0; i < 5; i ++) 
        ans = max(ans, dp[i] - i);

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
}