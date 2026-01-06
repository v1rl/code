#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// 注意到：回字形最优

void solve()
{
    int n;
    cin >> n;

    int u, d, l, r;
    u = d = l = r = (n - 1) / 2;
    vector g(n, vector(n, 0));

    int idx = 0;
    for(int k = 1; k <= n - 1; k ++)
    {
        if(k & 1)
        {
            r ++;
            for(int i = u; i <= d; i ++)
                g[i][r] = ++ idx;
            d ++;
            for(int i = r; i >= l; i --)
                g[d][i] = ++ idx;
        }
        else
        {
            l --;
            for(int i = d; i >= u; i --)
                g[i][l] = ++ idx;
            u --;
            for(int i = l; i <= r; i ++)
                g[u][i] = ++ idx;
        }
    }

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            cout << g[i][j] << " \n"[j == n - 1];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --)
    {
        solve();
    }
    return 0;
}