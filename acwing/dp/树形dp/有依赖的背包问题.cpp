#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 110;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    vector<vector<int>> adj(n + 1);
    vector<int> v(n + 1), w(n + 1);
    int root;
    for(int i = 1; i <= n; i ++)
    {
        int op;
        cin >> v[i] >> w[i] >> op;
        if(op == -1) root = i;
        else adj[op].emplace_back(i);
    }

    auto dfs = [&](auto &&self, int x, int p)->void
    {
        for(int j = v[x]; j <= m; j ++) f[x][j] = w[x];
        for(auto y : adj[x])
        {
            self(self, y, x);
            for(int j = m; j >= v[x]; j --)
            {
                for(int k = v[y]; k <= j - v[x]; k ++)
                {
                    f[x][j] = max(f[x][j], f[x][j - k] + f[y][k]);
                }
            }
        }
    };

    dfs(dfs, root, 0);
    cout << f[root][m] << '\n';
}