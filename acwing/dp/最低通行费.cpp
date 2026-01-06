#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int g[N][N];
int f[N][N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            cin >> g[i][j];
    
    for(int i = 0; i <= n; i ++) f[i][0] = f[0][i] = 0x3f3f3f3f;

    f[0][1] = f[1][0] = 0;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            f[i][j] = min(f[i - 1][j] + g[i][j], f[i][j - 1] + g[i][j]);
        }
    }

    cout << f[n][n] << '\n';
    return 0;
}
