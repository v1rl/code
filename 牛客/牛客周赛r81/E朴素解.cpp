#include<bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int N = 1e6 + 10;
const int mod = 1e8 + 7;
typedef pair<int, int> PII;
PII last[55][N];

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

    vector<vector<int>> f(n + 1, vector<int>(k + 1, 0));
    f[0][0] = 1;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 0; j <= k; j ++)
        {
            f[i][j] = f[i - 1][j];
            if(f[i - 1][j] > 0) last[i][j] = {i - 1, j};
            if(j >= v[i]) 
            {
                f[i][j] += f[i][j - v[i]];
                f[i][j] %= mod;
                if(f[i][j - v[i]] > 0 && last[i][j] == (PII){0, 0}) last[i][j] = {i, j - v[i]};
            }
        }
    }

    if(f[n][k] == 0)
    {
        cout << -1 << '\n';
        return;
    }

    vector<int> ans(n + 1);
    int x = n, y = k;
    while(x >= 1)
    {
        auto [nx, ny] = last[x][y];
        if(nx == x) ans[nx] += (y - ny) / v[x];
        x = nx, y = ny;
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