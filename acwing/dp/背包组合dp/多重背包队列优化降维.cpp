#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e4 + 10;
int q[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), w(n + 1), s(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> v[i] >> w[i] >> s[i];
    }

    vector<int> f(m + 1);
    vector<int> g(m + 1);
    for(int i = 1; i <= n; i ++)
    {
        for(int k = 0; k < v[i]; k ++)
        {
            int l = 1, r = 0;
            for(int j = k; j <= m; j += v[i])
            {
                while(l <= r && g[q[r]] + (j - q[r]) / v[i] * w[i] < g[j]) r --;
                q[++ r] = j;
                while(l <= r && (j - q[l]) / v[i] > s[i]) l ++;
                f[j] = g[q[l]] + (j - q[l]) / v[i] * w[i];
            }
        }
        g = f;
    }

    cout << f[m] << '\n';
}