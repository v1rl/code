#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m + 1);
    for(int i = 1; i <= m; i ++) cin >> b[i];
    a[0] = b[0] = -1;

    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    vector<vector<int>> pre(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i ++)
    {
        int val = f[i - 1][0];
        int pos = 0;
        for(int j = 1; j <= m; j ++)
        {
            if(a[i] == b[j])
            {
                f[i][j] = val + 1;
                pre[i][j] = pos;
            }
            else f[i][j] = f[i - 1][j];
            if(b[j] < a[i]) 
            {
                if(val < f[i - 1][j])
                {
                    val = f[i - 1][j];
                    pos = j;
                }
            }
        }
    }

    int res = 0;
    int final = 0;
    for(int i = 1; i <= m; i ++)
    {
        if(f[n][i] > res)
        {
            res = f[n][i];
            final = i;
        }
    }
    m = final;

    vector<int> ans;
    ans.reserve(res);
    while(f[n][m])
    {
        if(a[n] == b[m]) 
        {
            ans.emplace_back(a[n]);
            m = pre[n][m];
            n --;
        }
        else n --;
    }

    cout << res << '\n';
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < res; i ++) cout << ans[i] << ' ';

    return 0;
}