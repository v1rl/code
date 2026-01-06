#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i ++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<int> dep(n + 1);
    vector<array<int, 18>> f(n + 1);
    queue<int> q;
    q.push(1);
    dep[1] = 1;
    while(q.size())
    {
        int x = q.front();
        q.pop();

        for(auto y : adj[x])
        {
            if(dep[y]) continue;
            dep[y] = dep[x] + 1;
            f[y][0] = x;
            for(int i = 1; i <= 17; i ++)
                f[y][i] = f[f[y][i - 1]][i - 1];
            q.push(y);
        }
    }
    
    auto lca = [&](int x, int y)->int
    {
        if(dep[x] > dep[y]) swap(x, y);
        for(int i = 17; i >= 0; i --)
            if(dep[f[y][i]] >= dep[x])
                y = f[y][i];
        if(x == y) return x;
        for(int i = 17; i >= 0; i --)
            if(f[y][i] != f[x][i])
                x = f[x][i], y = f[y][i];
        
        return f[x][0];
    };
    
    i64 res = 0;
    auto dfs = [&](auto &&self, int x, int p)->int
    {
        int s = 1;
        for(auto y : adj[x])
        {
            if(y == p) continue;
            int t = self(self, y, x);
            res += 1ll * (n - t) * t;
            s += t;
        }
        return s;
    };
    
    dfs(dfs, 1, -1);
    for(int i = 1; i <= n; i ++)
        for(int j = i + 1; i * j < n; j ++)
        {
            int p = lca(i, j);
            int d = dep[i] + dep[j] - 2 * dep[p];
            if(i * j < d)
                res -= max(0, d - i * j);
        }
    
    cout << res * 2 << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}

