#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 110;
int v[N][N];
int w[N][N];
int s[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        cin >> s[i];
        for(int j = 1; j <= s[i]; j ++)
        {
            cin >> v[i][j] >> w[i][j];
        }
    }

    vector<int> f(m + 1);
    for(int i = 1; i <= n; i ++)
    {
        for(int j = m; j >= 0; j --)
        {
            for(int k = 1; k <= s[i]; k ++)
            {
                if(j >= v[i][k]) f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
            }
        }
    }

    cout << f[m] << '\n';
}