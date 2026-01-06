#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= m; i ++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<int> color(n + 1);
    auto dfs = [&](auto &&self, int x)->bool
    {
        for(auto y : adj[x])
        {
            if(color[y] && color[y] == color[x]) return false;
            if(!color[y]) 
            {
                color[y] = 3 - color[x];
                if(!self(self, y)) return false;
            }
        }
        return true;
    };

    bool f = true;
    for(int i = 1; i <= n; i ++)
    {
        if(!color[i])
        {
            color[i] = 1;
            f = dfs(dfs, i);
            if(!f) break;
        }
    }
    if(f) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}