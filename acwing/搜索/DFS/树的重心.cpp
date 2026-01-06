#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < n - 1; i ++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    int t = -1;
    int mn = 1e9;
    auto dfs = [&](auto &&self, int x, int p)->int
    {
        int res = 0;
        int sum = 1;
        for(auto y : adj[x])
        {
            if(y == p) continue;
            int num = self(self, y, x);
            res = max(res, num);
            sum += num;
        }
        res = max(res, n - sum);
        if(res < mn)
        {
            mn = res;
            t = x;
        }
        return sum;
    };

    dfs(dfs, 1, -1);
    cout << mn << '\n';
    return 0;
}