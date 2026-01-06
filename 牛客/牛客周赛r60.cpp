#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
const int inf = 1e9;
const int N = 5010;
const int mod = 1e9 + 7;
int f[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;
    if(m - 1 == 0) cout << 1 << '\n';
    else cout << f[n - 2][m - 2] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i <= 5000; i ++) f[i][0] = i;
    for(int i = 1; i <= 5000; i ++)
    {
        for(int j = 1; j <= 5000; j ++)
        {
            f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod;
        }
    }

    // cout << f[3][2] << '\n';


    while(t --)
    {
        solve();
    }
}