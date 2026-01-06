#include <bits/stdc++.h>
using namespace std;
//https://www.acwing.com/problem/content/354/
const int N = 1e5 + 10;
vector<vector<int>> adj(N);
int dep[N];
int f[N][17];
int d[N];
int ans = 0;

void bfs()
{
    dep[1] = 1;
    queue<int> q;
    q.push(1);
    while(q.size())
    {
        int x = q.front();
        q.pop();

        for(auto y : adj[x])
        {
            if(dep[y]) continue;
            dep[y] = dep[x] + 1;
            f[y][0] = x;
            for(int i = 1; i <= 16; i ++) f[y][i] = f[f[y][i - 1]][i - 1];
            q.push(y);
        }
    }
}

int lca(int x, int y)
{
    if(dep[x] > dep[y]) swap(x, y);
    for(int i = 16; i >= 0; i --)
    {
        if(dep[f[y][i]] >= dep[x])
        {
            y = f[y][i];
        }
    }
    if(x == y) return x;
    for(int i = 16; i >= 0; i --)
    {
        if(f[y][i] != f[x][i])
        {
            y = f[y][i];
            x = f[x][i];
        }
    }
    return f[x][0];
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i < n; i ++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bfs();

    for(int i = 1; i <= m; i ++)
    {
        int x, y;
        cin >> x >> y;
        int t = lca(x, y);
        d[x]++, d[y]++, d[t] -= 2;
    }

    auto dfs = [&](auto && self, int x,int pa)->int
    {
        int res = d[x];
        for(auto y : adj[x])
        {
            if(y == pa) continue;
            int t = self(self, y, x);
            if(t == 0) ans += m;
            if(t == 1) ans ++;
            res += t;
        }
        return res;
    };

    dfs(dfs, 1, -1);

    cout << ans << endl;
}