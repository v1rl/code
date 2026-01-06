#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
int f[N][N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    for(int i = 1; i <= n; i ++)
        cin >> b[i];

    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        int mx = 0;
        for(int j = 1; j <= n; j ++)
        {
            if(a[i] == b[j])
            {
                f[i][j] = mx + 1;
                ans = max(f[i][j], ans);
            }
            else f[i][j] = f[i - 1][j];
            if(b[j] < a[i])
            {
                mx = max(mx, f[i - 1][j]);
            }
        }
    }
    cout << ans << '\n';
}