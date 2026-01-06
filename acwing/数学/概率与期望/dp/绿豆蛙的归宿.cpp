#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;

int main()  
{  
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> adj(n + 1);
    for(int i = 0; i < m; i ++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }

    vector<double> f(n + 1);
    auto dfs = [&](auto &&self, int x)->void
    {
        if(f[x] > 0) return;
        double num = 1.0 / adj[x].size();
        for(auto [y, w] : adj[x])
        {
            self(self, y);
            f[x] += num * (w + f[y]);
        }
    };

    dfs(dfs, 1);
    printf("%.2lf", f[1]);
    return 0;
}  