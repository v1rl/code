#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> w(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin >> w[i][j];

    int q;
    cin >> q;
    while(q --)
    {
        int x, y, t;
        cin >> x >> y >> t;
        if(x + y - 2 >= t) 
            w[x][y] = -1;
    }

    vector<vector<int>> f(n + 1, vector<int>(m + 1, -1e9));
    f[1][1] = w[1][1];
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(w[i - 1][j] != -1) f[i][j] = max(f[i][j], f[i - 1][j] + w[i][j]);
            if(w[i][j - 1] != -1) f[i][j] = max(f[i][j], f[i][j - 1] + w[i][j]);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            // cout << w[i][j] << " \n"[j == m];
            if(w[i][j] != -1)
                ans = max(ans, f[i][j]);
        }
    }    
    cout << ans << '\n';
}