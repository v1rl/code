#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;    
    vector<array<int, 2>> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i][0];
    for(int i = 1; i <= n; i ++) cin >> a[i][1];

    vector<vector<int>> f(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            if(a[i][0] == a[j][1]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }

    cout << f[n][n] << '\n';
}