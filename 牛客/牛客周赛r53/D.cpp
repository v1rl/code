#include<bits/stdc++.h>
using namespace std;            //正解为dp

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin(), a[i].end());
    }

    int tar;
    cin >> tar;

    int ans = 10000;
    bool f = false;
    auto dfs = [&](auto && self, int u, int res)->void
    {
        if(ans == 0) return;
        if(u == n)
        {
            if(tar > res) f = true;
            ans = min(ans, abs(tar - res));
            return;
        }
        for(int i = 0; i < m; i ++)
        {
            self(self, u + 1, res + a[u][i]);
            if(f) return;
        }
    };
    dfs(dfs, 0, 0);

    cout << ans << '\n';
    return 0;
}