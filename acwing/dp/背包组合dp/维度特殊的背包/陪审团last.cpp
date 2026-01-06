#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
array<int, 3> last[2010][21][810];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    int T = 0;
    while(cin >> n >> m, n)
    {
        vector<int> a(n + 1), b(n + 1);
        for(int i = 1; i <= n; i ++)
            cin >> a[i] >> b[i];

        vector f(m + 1, vector(m * 20 * 2 + 1, -inf));
        int base = m * 20;
        f[0][base] = 0;

        for(int i = 1; i <= n; i ++)
        {
            int c = a[i] - b[i];
            for(int j = min(m, i); j >= 1; j --)
            {
                for(int k = max(0, c); k <= min(base * 2, base * 2 + c); k ++)
                {
                    last[i][j][k] = {i - 1, j, k};
                    if(f[j][k] < f[j - 1][k - c] + a[i] + b[i])
                    {
                        f[j][k] = f[j - 1][k - c] + a[i] + b[i];
                        last[i][j][k] = {i - 1, j - 1, k - c};
                    }
                }
            }
        }

        int z = 0;
        for(int i = 0; i <= base; i ++)
        {
            if(f[m][i + base] < 0 && f[m][base - i] < 0) continue;
            if(f[m][i + base] > f[m][base - i]) z = base + i;
            else z = base - i;
            break;
        }

        int x = n, y = m;
        vector<int> ans;
        while(y > 0)
        {
            auto [nx, ny, nz] = last[x][y][z];
            if(ny < y) ans.emplace_back(x);
            x = nx, y = ny, z = nz;
        }
        reverse(ans.begin(), ans.end());

        int d = 0, p = 0;
        for(auto x : ans)
        {
            d += a[x];
            p += b[x];
        }
        printf("Jury #%d\n", ++ T);
        printf("Best jury has value %d for prosecution and value %d for defence:\n", d, p);
        for(auto x : ans)
            printf(" %d", x);
        printf("\n\n");
    }
}