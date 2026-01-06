#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 80112002;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> res;
    vector<int> st(n + 1);
    vector<vector<int>> adj(n + 1);
    while(m --)
    {
        int x, y;
        cin >> y >> x;
        adj[x].emplace_back(y);
        st[y] = true;
    }
    for(int i = 1; i <= n; i ++)
        if(!st[i])
            res.emplace_back(i);


    vector<int> f(n + 1);
    auto dfs = [&](auto && self, int x, int p)
    {
        if(f[x]) return f[x];
        int res = 0;
        for(auto y : adj[x])
        {
            if(y == p) continue;
            res += self(self, y, x);
            res %= mod;
        }
        if(res == 0) res = 1;
        f[x] = res;
        return res;
    };

    int ans = 0;
    for(auto x : res)
    {
        ans += dfs(dfs, x, -1);
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}