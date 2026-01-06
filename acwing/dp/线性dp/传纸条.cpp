#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 51;
int f[N * 2][N][N];
int w[N][N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin >> w[i][j];

    for(int k = 2; k <= n + m; k ++)
    {
        for(int x1 = 1; x1 <= min(n, k - 1); x1 ++)
        {
            int y1 = k - x1;
            for(int x2 = 1; x2 <= min(n, k - 1); x2 ++)
            {
                int y2 = k - x2;
                int t = w[x1][y1];
                if(x1 != x2) t += w[x2][y2];
                f[k][x1][x2] = max({f[k - 1][x1 - 1][x2 - 1], f[k - 1][x1][x2], f[k - 1][x1][x2 - 1], f[k - 1][x1 - 1][x2]}) + t;
            }
        }
    }

    cout << f[n + m][n][n] << '\n';
    return 0;
}