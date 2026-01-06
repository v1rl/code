#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<PII>> adj(n + 1);
    for(int i = 0; i < k; i ++)
    {
        int x;
        cin >> x;
        adj[0].emplace_back(x, 0);
    }
    for(int i = 0; i < m; i ++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
    }

    auto dijkstra = [&](int S)
    {
        vector<int> dist(n + 1, 1e9);
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        heap.push({0, S});
        while(heap.size())
        {
            auto [d, x] = heap.top();
            heap.pop();
            if(dist[x] != 1e9) continue;
            dist[x] = d;
            for(auto [y, w] : adj[x])
            {
                if(dist[x] + w < dist[y])
                    heap.push({dist[x] + w, y});
            }
        }
        return dist;
    };

    int stt, edd;
    cin >> stt >> edd;
    vector<int> dist1 = dijkstra(0);
    vector<int> dist2 = dijkstra(stt);

    cout << min(dist1[stt] + dist1[edd], dist2[edd]) << '\n';
    return 0;
}