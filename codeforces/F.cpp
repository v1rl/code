#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n, c;
        cin >> n >> c;
        vector<int> w(n + 1);
        for(int i = 1; i <= n; i ++)
        {
            int x;
            cin >> x;
            w[i] = x;
        }
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < n - 1; i ++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        i64 ans = 0;
        vector<array<i64, 2>> f(n + 1);
        auto dfs = [&](auto &&self, int x, int p)->void
        {
            f[x][0] = 0;
            f[x][1] = w[x];
            for(auto y : adj[x])
            {
                if(y == p) continue;
                self(self, y, x);
                f[x][0] += max(f[y][0], f[y][1]);
                f[x][1] += max(f[y][0], f[y][1] - 2 * c);
            }
        };
        dfs(dfs, 1, -1);

        cout << max(f[1][0], f[1][1]) << '\n';
    }
    return 0;
}