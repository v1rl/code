#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), w(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> v[i] >> w[i];
    }
    vector<vector<int>> f(n + 2, vector<int>(m + 1));
    for(int i = n; i >= 1; i --)
    {
        for(int j = 1; j <= m; j ++)
        {
            f[i][j] = f[i + 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        }
    }

    vector<int> ans;
    int x = 1, y = m;
    while(x <= n)
    {
        if(y >= v[x] && f[x][y] == f[x + 1][y - v[x]] + w[x])
        {
            ans.emplace_back(x);
            y -= v[x];
            x ++;
        }
        else x ++;
    }

    for(auto x : ans) cout << x << ' ';
}