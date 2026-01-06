#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a.begin() + 1, a.end(), greater<int>());

    vector f(n + 1, vector(m + 1, 0));
    f[0][0] = 1;
    for(int i = 1; i <= n; i ++)
        for(int j = 0; j <= m; j ++)
        {
            f[i][j] |= f[i - 1][j];
            if(j >= a[i]) f[i][j] |= f[i - 1][j - a[i]];
        }


    if(!f[n][m]) cout << "No Solution" << '\n';
    else
    {
        vector<int> res;
        int x = n, y = m;
        while(x >= 1)
        {
            if(y - a[x] >= 0 && f[x][y] == f[x - 1][y - a[x]])
            {
                res.emplace_back(a[x]);
                y -= a[x];
                x --;
            }
            else
            {
                x --;
            }
        }
        for(int i = 0; i < res.size(); i ++)
        {
            cout << res[i];
            if(i != res.size() - 1) cout << ' ';
        }
    }
}