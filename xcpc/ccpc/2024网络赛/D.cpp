#include<bits/stdc++.h>
using namespace std;
const int N = 110, mod = 998244353;
int f[N][N][N];
using i64 = long long;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
    string S, T;
    cin >> S >> T;
    int n = S.size(), m = T.size();
    S = ' ' + S;
    T = ' ' + T;
    for(int i = 0; i <= n; i ++)
        for(int l = 0; l <= m; l ++)
            f[i][l + 1][l] = 1;

    // for(int i = 0; i <= n; i++)
    //     for(int j = 1; j <= m+1; j++)
    //         for(int t = 0; t < j; t++)
    //             f[i][j][t] = 1;    

    for(int i = 1; i <= n; i ++)
        for(int len = 1; len <= m; len ++)
            for(int l = 1; l + len - 1 <= m; l ++)
            {
                int r = l + len - 1;
                for(int k = l - 1; k <= r; k ++)
                {
                    f[i][l][r] = (f[i][l][r] + (i64)f[i - 1][l][k] * f[i - 1][k + 1][r]) % mod;
                }
                for(int k = l; k <= r; k ++)
                {
                    if(S[i] == T[k])
                        f[i][l][r] = (f[i][l][r] + (i64)f[i - 1][l][k - 1] * f[i - 1][k + 1][r]) % mod;
                }
            }

    cout << f[n][1][m] << '\n';
    return 0;
}   
