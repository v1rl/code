#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    int len = __lg(n);
    vector<vector<int>> f(n + 2, vector<int>(len + 1));
    for(int i = 1; i <= n; i ++) cin >> a[i];
    int l = 1, r = 1, sum = 0;
    while(l <= n)
    {
        while(r <= n && sum + a[r] <= k)
        {
            sum += a[r];
            r ++;
        }
        f[l][0] = r;
        sum -= a[l];
        l ++;
    }
    for(int i = 0; i <= len; i ++) f[n + 1][i] = n + 1;

    for(int i = n; i >= 0; i --)
        for(int j = 1; j <= len; j ++)
            f[i][j] = f[f[i][j - 1]][j - 1];

    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        int num = m, res = 0, t = i;
        for(int j = len; j >= 0; j --)
        {
            if(num - (1 << j) >= 0)
            {
                num -= (1 << j);
                res += f[t][j] - t;
                t = f[t][j];
            }
        }
        ans = max(ans, res);
    }
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
