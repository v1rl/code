#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int mod = 1e9 + 7;

i64 qmi(i64 a, i64 b)
{
    i64 res = 1;
    while(b)
    {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

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

    vector<i64> f(n + 1);
    auto dfs = [&](auto &&self, int x, int p)->void
    {
        f[x] = 1;
        int num = adj[x].size() - 1;
        if(x == 1) num ++;
        i64 ny = qmi(num, mod - 2);
        for(auto y : adj[x])
        {
            if(y == p) continue;
            self(self, y, x);
            f[x] = (f[x] + f[y] * ny % mod) % mod;
        }
    };
    dfs(dfs, 1, -1);
    cout << f[1] << '\n';
}