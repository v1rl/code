#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i ++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    int k;
    cin >> k;
    vector<int> st(n + 1);
    for(int i = 1; i <= k; i ++)
    {
        int x;
        cin >> x;
        st[x] = 1;
    }

    vector<i64> ans(n + 1);
    vector<int> sum(n + 1);
    auto dfs = [&](auto &&self, int x, int p)->i64
    {
        i64 t = 0;
        for(auto y : adj[x]) 
        {
            if(y == p) continue;
            t += self(self, y, x);
            sum[x] += sum[y];
        }
        if(st[x]) sum[x] ++;
        ans[x] = 1ll * sum[x] * sum[x] - t;
        return ans[x] + t;
    };

    dfs(dfs, 1, -1);
    for(int i = 1; i <= n; i ++) cout << ans[i] << ' ';
    return 0;
}