#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> col(n + 1), dg(2 * n), udg(2 * n);
    int ans = 0;
    vector<int> stk(n + 1);
    int r = 0;
    auto dfs = [&](auto &&self, int u)->void
    {
        if(u == n)
        {
            ans ++;
            if(ans <= 3)
            {
                for(int i = 0; i < u; i ++)
                {
                    cout << stk[i] << ' ';
                } 
                cout << '\n';
            }
            return;
        }

        for(int i = 1; i <= n; i ++)
        {
            int r = u + 1;
            if(!col[i] && !udg[r + i - 1] && !dg[n - r + i])
            {
                col[i] = udg[r + i - 1] = dg[n - r + i] = true;
                stk[u] = i;
                self(self, u + 1);
                col[i] = udg[r + i - 1] = dg[n - r + i] = false;
            }
        }
    };

    dfs(dfs, 0);
    cout << ans << '\n';
    return 0;
}
