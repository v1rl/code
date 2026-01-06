#include<bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int inf = 1e9 + 10;

void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++)
    {
        k -= i * i;
    }
    if(k < 0)
    {
        cout << -1 << '\n';
        return;
    }

    vector<int> v(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        v[i] = (i + n) * (n - i + 1) / 2;
    }

    vector<vector<int>> f(n + 2, vector<int>(k + 1, -1));
    f[n + 1][0] = 0;
    f[0][0] = 0;
    for(int i = n; i; i --)
    {
        for(int j = 0; j <= k; j ++)
            if(f[i + 1][j] != -1)
                f[i][j] = 0;

        for(int j = v[i]; j <= k; j ++)
            if(f[i][j - v[i]] != -1)
                f[i][j] = f[i][j - v[i]] + 1;
    }

    if(f[1][k] == -1)
    {
        cout << -1 << '\n';
        return;
    }

    vector<int> ans(n + 1);
    int cur = k;
    for(int i = 1; i <= n; i ++)
    {
        ans[i] = f[i][cur];
        cur -= v[i] * f[i][cur];
    }

    for(int i = 1; i <= n; i ++)
    {
        ans[i] += ans[i - 1];
        cout << ans[i] + i << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}