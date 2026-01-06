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
    vector<int> sk(k);
    for(int i = 0; i < k; i ++)
    {
        cin >> sk[i];
    }
    for(int i = 0; i < m; i ++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
    }
    for(int i = 0; i < k; i ++)
    {
        int x = sk[i];
        for(int j = i + 1; j < k; j ++)
        {
            int y = sk[j];
            adj[x].emplace_back(y, 0);
            adj[y].emplace_back(x, 0);  
        }
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
    vector<int> dist = dijkstra(stt);

    cout << dist[edd] << '\n';
    return 0;
}
