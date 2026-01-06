#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector a(n, vector(m, 0));
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> a[i][j];

    vector<int> p(n + 1);
    for(int i = 0; i < n; i ++)
    {
        sort(a[i].begin(), a[i].end());
        for(int j = 0; j < m; j ++)
        {
            if(j == 0)
            {
                if(a[i][j] < n) p[a[i][j] + 1] = i + 1;
                else
                {
                    cout << -1 << '\n';
                    return;
                }
            }
            else
            {
                if(a[i][j] != a[i][j - 1] + n)
                {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++) 
        cout << p[i] << ' ';
    cout << '\n';
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