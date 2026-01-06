#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6 + 10;
int f[55][N];
typedef pair<int, int> PII;
PII lst[55][N];

// https://ac.nowcoder.com/acm/contest/101921/E

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++)
        k -= i * i;
    if(k < 0)
    {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        v[i] = (i + n) * (n - i + 1) / 2;
    }

    f[0][0] = 1;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 0; j <= k; j ++)
        {
            f[i][j] = f[i - 1][j];
            if(f[i - 1][j] > 0) lst[i][j] = {i - 1, j};
            if(j >= v[i])
            {
                f[i][j] = max(f[i][j], f[i][j - v[i]]);
                if(f[i][j - v[i]] > 0 && lst[i][j] == PII{0, 0}) lst[i][j] = {i, j - v[i]};
            }
        }
    }

    if(f[n][k] == 0)
    {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> ans(n + 1);

    // int x = n, y = k;
    // while(x >= 1)
    // {
    //     auto [nx, ny] = lst[x][y];
    //     if(x == nx) ans[x] += (y - ny) / v[x];
    //     x = nx, y = ny;
    // }
    
    int x = n, y = k;
    while(x >= 1)
    {
        if(y >= v[x] && f[x][y - v[x]])
        {
            ans[x] ++;
            y -= v[x];
        }
        else x --;
    }
    for(int i = 1; i <= n; i ++)
    {
        ans[i] += ans[i - 1];
        cout << ans[i] + i << ' ';
    }
    return 0;
}