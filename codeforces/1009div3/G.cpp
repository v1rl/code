#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    vector f(n + 1, vector(n + 1, 0ll));
    for(int r = 3; r <= n; r ++)
        for(int l = r - 2; l; l --)
        {
            for(int i = l + 1; i <= r - 1; i ++)
            {
                f[l][r] = max(f[l][r], f[l + 1][i - 1] + f[i + 1][r - 1] + 1ll * a[l] * a[r] * a[i]);
            }
            for(int i = l; i <= r - 1; i ++)
            {
                f[l][r] = max(f[l][r], f[l][i] + f[i + 1][r]);
            }
        }
    cout << f[1][n] << '\n';
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