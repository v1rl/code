#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<int> v(n + 1);
    vector<int> s(n + 1);
    m -= (n + 3) * n / 2;
    if(m < 0) cout << -1 << '\n';
    else
    {
/*
    // 多重背包
        for(int i = 1; i <= n; i ++) v[i] = i + 1, s[i] = m / (i + 1);

        vector<int> f(m + 1);
        vector<int> g(m + 1);
        f[0] = 1;
        for(int i = 1; i <= n; i ++)
        {
            g = f;
            for(int k = 0; k < v[i]; k ++)
            {
                vector<int> sum(m + 1, 0);
                int cnt = 0;
                for(int j = k; j <= m; j += v[i])
                {
                    sum[cnt + 1] = sum[cnt] + g[j];
                    f[j] = sum[cnt + 1] - sum[max(cnt - s[i], 0)];
                    cnt ++;
                }
            }
        }
        cout << f[m] << '\n';
*/
        for(int i = 1; i <= n; i ++) v[i] = i + 1;
        vector<int> f(m + 1);
        f[0] = 1;
        for(int i = 1; i <= n; i ++)
            for(int j = v[i]; j <= m; j ++)
                f[j] += f[j - v[i]];
        cout << f[m] << '\n';
    }
    return 0;
}