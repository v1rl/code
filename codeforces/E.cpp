#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<i64, int> PII;
constexpr i64 inf = 1e18;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n, m, h;
        cin >> n >> m >> h;
        vector<vector<PII>> adj(2 * n + 1);

        for(int i = 0; i < h; i ++)
        {
            int x; 
            cin >> x;
            adj[x].emplace_back(n + x, 0);
        }

        for(int i = 0; i < m; i ++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            adj[x].emplace_back(y, w);
            adj[y].emplace_back(x, w);
            adj[x + n].emplace_back(y + n, w / 2);
            adj[y + n].emplace_back(x + n, w / 2);
        }

        auto dijkstra = [&](int s)
        {
            vector<i64> dist(2 * n + 1, inf);
            priority_queue<PII, vector<PII>, greater<PII>> heap;
            heap.push({0, s});
            while(heap.size())
            {
                auto [d, x] = heap.top();
                heap.pop();

                if(dist[x] != inf) continue;
                dist[x] = d;

                for(auto [y, w] : adj[x])
                {
                    if(dist[y] > dist[x] + w)
                    {
                        heap.push({dist[x] + w, y});
                    }
                }
            }

            vector<i64> d(n + 1, inf);
            for(int i = 1; i <= n; i ++)
                d[i] = min(dist[i], dist[i + n]);

            return d;
        };

        auto d1 = dijkstra(1);
        auto dn = dijkstra(n);

        i64 ans = inf;
        for(int i = 1; i <= n; i ++)
            ans = min(ans, max(d1[i], dn[i]));

        if(ans == inf) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}