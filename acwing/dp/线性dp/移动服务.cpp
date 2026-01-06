#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int f[1010][N][N];
int w[N][N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= m; j ++)
            cin >> w[i][j];

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    a[0] = 3;
    memset(f, 0x3f, sizeof f);
    f[0][1][2] = 0;
    for(int i = 0; i < n; i ++)
    {
        for(int x = 1; x <= m; x ++)
        {
            for(int y = 1; y <= m; y ++)
            {
                int z = a[i];
                if(x == y || y == z || x == z) continue;
                int t = a[i + 1];
                if(t != y && t != z) f[i + 1][z][y] = min(f[i + 1][z][y], f[i][x][y] + w[x][t]);
                if(t != x && t != z) f[i + 1][x][z] = min(f[i + 1][x][z], f[i][x][y] + w[y][t]);
                if(t != x && t != y) f[i + 1][x][y] = min(f[i + 1][x][y], f[i][x][y] + w[z][t]);
            }
        }
    }

    int mn = 1e9;
    for(int x = 1; x <= m; x ++)
        for(int y = 1; y <= m; y ++)
            mn = min(mn, f[n][x][y]);
        
    cout << mn << '\n';
    return 0;
}