#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    vector<int> b = a;
    sort(b.begin() + 1, b.end());
    unordered_map<int, int> mp;
    vector<int> val(n + 1);
    int tt = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(!mp.count(b[i])) mp[b[i]] = ++ tt;
        val[tt] = b[i];
    }

    vector<vector<int>> f(n + 1, vector<int>(tt + 1, 1e9));
    for(int i = 1; i <= tt; i ++)
        f[0][i] = 0;

    for(int i = 1; i <= n; i ++)
    {
        int mn = 1e9;
        for(int j = 1; j <= tt; j ++)
        {
            mn = min(mn, f[i - 1][j]);
            f[i][j] = min(f[i][j], mn + abs(val[j] - a[i]));
        }
    }

    int ans1 = 1e9;
    for(int i = 1; i <= tt; i ++)
        ans1 = min(ans1, f[n][i]);

    for(int i = 1; i <= n; i ++) f[i].assign(tt + 1, 1e9); 
    for(int i = 1; i <= tt; i ++)
        f[0][i] = 0;

    for(int i = 1; i <= n; i ++)
    {
        int mn = 1e9;
        for(int j = tt; j >= 1; j --)
        {
            mn = min(mn, f[i - 1][j]);
            f[i][j] = min(f[i][j], mn + abs(val[j] - a[i]));
        }
    }
    int ans2 = 1e9;
    for(int i = 1; i <= tt; i ++)
        ans2 = min(ans2, f[n][i]);

    cout << min(ans1, ans2) << '\n';

    return 0;
}