#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 310;
int f[8][N][N];

void solve()
{
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> a(l + 1);
    for(int i = 1; i <= l; i ++) cin >> a[i];
    vector<int> st(8);
    for(int i = 1; i <= l; i ++)
    {
        if(st[a[i]])
        {
            l = i - 1;
            break;
        }
        st[a[i]] = 1;
    }
    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++) 
            cin >> b[i][j];

    memset(f, 0, sizeof f);
    for(int k = l; k >= 1; k --)
        for(int i = n; i >= 1; i --)
            for(int j = m; j >= 1; j --)
            {
                // f[k][i][j] = max(f[k][i - 1][j], f[k][i][j - 1]);
                if(b[i][j] == a[k] && (i == n || j == m || k == l || !f[k + 1][i + 1][j + 1]))
                {
                    f[k][i][j] = 1;
                }
                if(f[k][i][j]) f[k][i - 1][j] = f[k][i][j - 1] = f[k][i][j];
            }

    if(f[1][1][1]) cout << 'T' << '\n';
    else cout << 'N' << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
}