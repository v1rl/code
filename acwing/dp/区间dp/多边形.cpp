#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

struct Info
{
    char op;
    int x;
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<Info> a(n * 2 + 1);
    for(int i = 1; i <= n; i ++)
    {
        char op;
        int x;
        cin >> op >> x;
        a[i] = {op, x};
    }
    for(int i = n + 1; i <= n * 2; i ++)
        a[i] = a[i - n];

    vector f(n * 2 + 1, vector(n * 2 + 1, array<int, 2>{inf, -inf}));
    for(int i = 1; i <= n * 2; i ++)
    {
        f[i][i] = {a[i].x, a[i].x};
    }
    for(int r = 2; r <= 2 * n; r ++)
        for(int l = r - 1; l; l --)
        {
            for(int i = l; i < r; i ++)
            {
                auto [op, _] = a[i + 1];
                if(op == 't')
                {
                    f[l][r][0] = min(f[l][r][0], f[l][i][0] + f[i + 1][r][0]);
                    f[l][r][1] = max(f[l][r][1], f[l][i][1] + f[i + 1][r][1]);
                }
                else
                {
                    f[l][r][0] = min({f[l][r][0], f[l][i][0] * f[i + 1][r][0], f[l][i][1] * f[i + 1][r][1], f[l][i][0] * f[i + 1][r][1], f[l][i][1] * f[i + 1][r][0]});
                    f[l][r][1] = max({f[l][r][1], f[l][i][0] * f[i + 1][r][0], f[l][i][1] * f[i + 1][r][1], f[l][i][0] * f[i + 1][r][1], f[l][i][1] * f[i + 1][r][0]});
                }
            }
        }

    int mx = 0;
    vector<int> res;
    for(int l = 1; l <= n; l ++)
    {
        if(f[l][l + n - 1][1] > mx)
        {
            mx = f[l][l + n - 1][1];
            res.clear();
            res.emplace_back(l);
        }
        else if(f[l][l + n - 1][1] == mx)
            res.emplace_back(l);
    }
    cout << mx << '\n';
    for(auto x : res)
        cout << x << ' ';
}