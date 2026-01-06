#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
typedef pair<int, int> PII;
const int inf = 2e9;

//https://ac.nowcoder.com/acm/contest/104421/E

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<PII>> adj(n + 1 + k + k);
    vector<int> bel(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        bel[i] = x + n;
    }
    for(int i = 1; i <= m; i ++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].emplace_back(y, w);
    }
    int tp;
    cin >> tp;
    for(int i = 1; i <= tp; i ++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x + n].emplace_back(y + n + k, w);
    }
    for(int i = 1; i <= n; i ++)
    {
        int w;
        cin >> w;
        adj[i].emplace_back(bel[i], 0);
        adj[bel[i] + k].emplace_back(i, w);
    }

    auto dijk = [&](int stt)
    {
        vector<int> dist(n + k + k + 1, inf);
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        heap.push({0, stt});
        while(heap.size())
        {
            auto [d, x] = heap.top();
            heap.pop();
            if(dist[x] != inf) continue;
            dist[x] = d;
            for(auto [y, w] : adj[x])
            {
                if(dist[y] > dist[x] + w)
                    heap.push({dist[x] + w, y});
            }
        }
        return dist[n];
    };

    int ans = dijk(1);
    cout << (ans == inf ? -1 : ans) << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
        solve();
}