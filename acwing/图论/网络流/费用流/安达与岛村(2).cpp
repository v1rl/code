#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 2e9;

// https://ac.nowcoder.com/acm/contest/104870/J

template<class T>
struct MinCostFlow
{
    struct Edge
    {
        int y;
        T cap;
        T cost;
        Edge(int y_, T cap_, T cost_) : y(y_), cap(cap_), cost(cost_) {};
    };

    int n;
    vector<vector<int>> g;
    vector<Edge> e;
    vector<T> h, dist;
    vector<int> pre;
    MinCostFlow(int n_) : n(n_), g(n + 1) {};

    void addEdge(int x, int y, T cap, T cost)
    {
        g[x].emplace_back(e.size());
        e.emplace_back(y, cap, cost);
        g[y].emplace_back(e.size());
        e.emplace_back(x, 0, -cost);
    }

    bool dijkstra(int stt, int edd)
    {
        dist.assign(n + 1, numeric_limits<T>::max());
        pre.assign(n + 1, -1);
        dist[stt] = 0;
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> heap;
        heap.push({dist[stt], stt});
        while(heap.size())
        {
            auto [d, x] = heap.top();
            heap.pop();
            if(d != dist[x]) continue;

            for(auto j : g[x])
            {
                auto [y, cap, cost] = e[j];
                if(cap > 0 && dist[y] > dist[x] + cost + h[x] - h[y])
                {
                    dist[y] = dist[x] + cost + h[x] - h[y];
                    pre[y] = j;
                    heap.push({dist[y], y});
                }
            }
        }
        return dist[edd] != numeric_limits<T>::max();
    }

    pair<T, T> flow(int stt, int edd)
    {
        h.assign(n + 1, 0);             //因为初始反边没有流量所以不会进行增广
        T flow = 0;
        T cost = 0;
        while(dijkstra(stt, edd))  
        {
            for(int i = 0; i <= n; i ++) 
                h[i] += dist[i];
            T aug = numeric_limits<T>::max();
            for(int i = edd; i != stt; i = e[pre[i] ^ 1].y) 
                aug = min(aug, e[pre[i]].cap);
            for(int i = edd; i != stt; i = e[pre[i] ^ 1].y)
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
        T cap;
        T flow;
        T cost;
    };

    vector<_Edge> edges()
    {
        vector<_Edge> res;
        for(int i = 0; i < e.size(); i += 2)
        {
            res.push_back({e[i + 1].y, e[i].y, e[i].cap + e[i + 1].cap, e[i + 1].cap, e[i].cost});
        }
        return res;
    }
};

void solve()
{
	int n, m;
	cin >> n >> m;

	int tstt = 0;
	int stt = n * 2 + 1;
	int edd = n * 2 + 2;
	MinCostFlow<int> mf(n * 2 + 3);

	int x;
	int sum = 0;
	cin >> x;
	m -= x;

	mf.addEdge(tstt, stt, m, 0);
	for(int i = 2; i <= n; i ++)
	{
		int x;
		cin >> x;
		sum += x;
		mf.addEdge(stt, i, inf, 0);
		mf.addEdge(i, n + i, x, -1);
		mf.addEdge(n + i, edd, inf, 0);
		for(int j = 2; j < i; j ++)
		{
			if(gcd(i, j) != 1)
			{
				mf.addEdge(n + i, j, inf, 0);
			}
		}
	}

	auto [flow, cost] = mf.flow(tstt, edd);
	// cout << flow << ' ' << cost << '\n';
	if(-cost == sum) cout << "Adachi" << '\n';
	else cout << "Shimamura" << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --)
	{
		solve();
	}
	return 0;
}