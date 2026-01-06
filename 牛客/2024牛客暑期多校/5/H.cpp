#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
bool st[41];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i ++)
    {
        int x, y;
        cin >> x >> y;
        x --, y --;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    int ans = 0;
    auto dfs = [&](auto && self, int x, int res)->void
    {
        vector<int> v;
        v.reserve(n);
        for(auto y : adj[x])
        {
            if(!st[y]) 
            {
                st[y] = true;
                v.emplace_back(y);
            }
        }
        for(auto y : v) self(self, y, res + 1);
        for(auto y : v) st[y] = false;
        ans = max(ans, res);
    };


    for(int i = 0; i < n; i ++)
    {
        st[i] = true;
        dfs(dfs, i, 1);
        st[i] = false;
    }
    cout << ans << '\n';
}