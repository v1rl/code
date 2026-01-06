#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 12;
int f[N * N][N][N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    int x, y, w;
    while(cin >> x >> y >> w, x)
    {
        g[x][y] = w;
    }

    for(int k = 2; k <= 2 * n; k ++)
    {
        for(int x1 = 1; x1 <= min(n, k - 1); x1 ++)
        {
            int y1 = k - x1;
            for(int x2 = 1; x2 <= min(n, k - 1); x2 ++)
            {
                int y2 = k - x2;
                int t = g[x1][y1];
                if(x1 != x2) t += g[x2][y2];
                f[k][x1][x2] = max({f[k - 1][x1 - 1][x2 - 1], f[k - 1][x1][x2], f[k - 1][x1][x2 - 1], f[k - 1][x1 - 1][x2]}) + t;
            }
        }
    }

    cout << f[2 * n][n][n] << '\n';
    return 0;
}