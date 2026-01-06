#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> adj(n + 1);
    int mx = 0;
    for(int i = 1; i <= m; i ++)
    {
        int x, y, w;
        cin >> x >> y >> w;  
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
        mx = max(mx, w);
    }

    vector<int> color(n + 1);
    auto dfs = [&](auto &&self, int x, int mid)->bool
    {
        for(auto [y, w] : adj[x])
        {
            if(w <= mid) continue;
            if(color[y] && color[y] == color[x]) return false;
            if(!color[y])
            {
                color[y] = 3 - color[x];
                if(!self(self, y, mid)) return false;
            }
        }
        return true;
    };

    auto check = [&](int mid)->bool
    {
        color.assign(n + 1, 0);
        for(int i = 1; i <= n; i ++)
        {
            if(!color[i])
            {
                color[i] = 1;
                if(!dfs(dfs, i, mid)) return false;
            } 
        }
        return true;
    };

    int l = 0, r = mx;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
    return 0;
}