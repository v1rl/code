#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;

template<class T>
struct MinCostFlow
{
    struct Edge
    {
        int v;
        T cap;
        T cost;
        Edge(int v_, T cap_, T cost_) : v(v_), cap(cap_), cost(cost_) {};
    };
    int n;
    vector<Edge> e;
    vector<vector<int>> g;
    vector<T> h, dist;
    vector<int> pre;
    MinCostFlow(int n_) : n(n_ + 1), g(n) {};

    void addEdge(int x, int y, T cap, T cost)
    {
        g[x].emplace_back(e.size());
        e.emplace_back(y, cap, cost);
        g[y].emplace_back(e.size());
        e.emplace_back(x, 0, -cost);
    }

    bool dijkstra(int stt, int edd)
    {
        dist.assign(n, numeric_limits<T>::max());
        pre.assign(n, -1);
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> heap;
        dist[stt] = 0;
        heap.push({0, stt});
        while(heap.size())
        {
            auto [d, x] = heap.top();
            heap.pop();
            if(d != dist[x]) continue;
            for(auto j : g[x])
            {
                auto [y, cap, cost] = e[j];
                if(cap > 0 && dist[y] > d + h[x] - h[y] + cost)
                {
                    dist[y] = d + h[x] - h[y] + cost;
                    pre[y] = j;
                    heap.push({dist[y], y});
                }
            }
        }
        return dist[edd] != numeric_limits<T>::max();
    }

    pair<T, T> flow(int stt, int edd)
    {
        T flow = 0;
        T cost = 0;
        h.assign(n, 0);
        while(dijkstra(stt,edd))
        {
            for(int i = 0; i < n; i ++) h[i] += dist[i];
            T aug = numeric_limits<T>::max();
            for(int i = edd; i != stt; i = e[pre[i] ^ 1].v) aug = min(aug, e[pre[i]].cap);
            for(int i = edd; i != stt; i = e[pre[i] ^ 1].v)
            {
                e[pre[i]].cap -= aug;
                e[pre[i] ^ 1].cap += aug;
            }
            flow += aug;
            cost += aug * h[edd];
        }
        return {flow, cost};
    }

    struct _Edge
    {
        int x;
        int y;
        int cap;
        int flow;
        int cost;
    };

    vector<_Edge> edges()
    {
        vector<_Edge> a;
        for(int i = 0; i < e.size(); i += 2)
        {
            _Edge x = {e[i + 1].v, e[i].v, e[i + 1].cap + e[i].cap, e[i + 1].cap, e[i].cost};
            a.emplace_back(x);
        }
        return a;
    }

    void init(int n_)
    {
        n = n_ + 1;
        e.clear();
        g.assign(n, {});
    }
};

int a[30][110];
int n, m;

int get(int x, int y)
{
    return (n + n + x - 2) * (x - 1) / 2 + y;    
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= m; i ++)
    {
        for(int j = 1; j < n + i; j ++)
        {
            cnt ++;
            cin >> a[i][j];
        }
    }
    MinCostFlow<int> mcf(2 * cnt + 1);
    int stt = 0, edd = 2 * cnt + 1;
    for(int i = 1; i <= n; i ++) mcf.addEdge(stt, get(1, i), 1, -a[1][i]);
    for(int i = 1; i < m; i ++)
    {
        for(int j = 1; j < n + i; j ++)
        {
            mcf.addEdge(cnt + get(i, j), get(i + 1, j), 1, -a[i + 1][j]);
            mcf.addEdge(cnt + get(i, j), get(i + 1, j + 1), 1, -a[i + 1][j + 1]);
        }
    }
    for(int i = 1; i < n + m; i ++)
    {
        mcf.addEdge(cnt + get(m, i), edd, 1, 0);
    }
    for(int i = 1; i <= cnt; i ++)
    {
        mcf.addEdge(i, cnt + i, 1, 0);
    }
    auto t = mcf.flow(stt, edd);
    cout << -t.second << '\n';


    mcf.init(cnt + 1);
    stt = 0, edd = cnt + 1;
    for(int i = 1; i <= n; i ++) mcf.addEdge(stt, get(1, i), 1, -a[1][i]);
    for(int i = 1; i < m; i ++)
    {
        for(int j = 1; j < n + i; j ++)
        {
            mcf.addEdge(get(i, j), get(i + 1, j), 1, -a[i + 1][j]);
            mcf.addEdge(get(i, j), get(i + 1, j + 1), 1, -a[i + 1][j + 1]);
        }
    }
    for(int i = 1; i < n + m; i ++)
    {
        mcf.addEdge(get(m, i), edd, 2, 0);
    }
    t = mcf.flow(stt, edd);
    cout << -t.second << '\n';


    mcf.init(cnt + 1);
    for(int i = 1; i <= n; i ++) mcf.addEdge(stt, get(1, i), 1, -a[1][i]);
    for(int i = 1; i < m; i ++)
    {
        for(int j = 1; j < n + i; j ++)
        {
            mcf.addEdge(get(i, j), get(i + 1, j), inf, -a[i + 1][j]);
            mcf.addEdge(get(i, j), get(i + 1, j + 1), inf, -a[i + 1][j + 1]);
        }
    }
    for(int i = 1; i < n + m; i ++)
    {
        mcf.addEdge(get(m, i), edd, inf, 0);
    }
    t = mcf.flow(stt, edd);
    cout << -t.second << '\n';
}
  