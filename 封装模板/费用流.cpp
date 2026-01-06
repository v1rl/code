#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
const int inf = 2e9;

/*
常规时间复杂度——flow * mlogn
单位容量边时间复杂度——n * mlogn
*/

template<class T>
struct MinCostFlow {
    struct Edge {
        int y;
        T cap;
        T cost;
        Edge(int y_, T cap_, T cost_) : y(y_), cap(cap_), cost(cost_) {};
    };

    int n;
    vector<vector<int>> g;
    vector<Edge> e;
    vector<T> h, dist;
    // 存通向当前点的边的编号
    vector<int> pre;
    MinCostFlow(int n_) : n(n_), g(n + 1) {};

    void addEdge(int x, int y, T cap, T cost) {
        g[x].emplace_back(e.size());
        e.emplace_back(y, cap, cost);
        g[y].emplace_back(e.size());
        e.emplace_back(x, 0, -cost);
    }

    // 寻找单位费用最小的增广路
    bool dijkstra(int stt, int edd) {
        dist.assign(n + 1, numeric_limits<T>::max());
        dist[stt] = 0;
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> heap;
        heap.push({dist[stt], stt});
        while(heap.size()) {
            auto [d, x] = heap.top();
            heap.pop();
            if(d != dist[x]) continue;

            for(auto j : g[x]) {
                auto [y, cap, cost] = e[j];
                if(cap > 0 && dist[y] > dist[x] + cost + h[x] - h[y]) {
                    dist[y] = dist[x] + cost + h[x] - h[y];
                    pre[y] = j;
                    heap.push({dist[y], y});
                }
            }
        }
        return dist[edd] != numeric_limits<T>::max();
    }

    pair<T, T> flow(int stt, int edd) {
        //因为初始反边没有流量, 所以第一次执行dij时负权边不会进行增广
        h.assign(n + 1, 0);
        pre.resize(n + 1);
        T flow = 0;
        T cost = 0;
        while(dijkstra(stt, edd))   {
            for(int i = 0; i <= n; i ++) 
                h[i] += dist[i];
            T aug = numeric_limits<T>::max();
            for(int i = edd; i != stt; i = e[pre[i] ^ 1].y) {
                aug = min(aug, e[pre[i]].cap);
            }
            for(int i = edd; i != stt; i = e[pre[i] ^ 1].y) {
                e[pre[i]].cap -= aug;
                e[pre[i] ^ 1].cap += aug;
            }
            flow += aug;
            cost += aug * h[edd];
        }
        return {flow, cost};
    }

    struct _Edge {
        int x;
        int y;
        T cap;
        T flow;
        T cost;
    };

    vector<_Edge> edges() {
        vector<_Edge> res;
        for(int i = 0; i < e.size(); i += 2) {
            res.push_back({e[i + 1].y, e[i].y, e[i].cap + e[i + 1].cap, e[i + 1].cap, e[i].cost});
        }
        return res;
    }
};

void solve() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m, stt, edd;
    cin >> n >> m >> stt >> edd;
    MinCostFlow<int> mf(n);
    for(int i = 1; i <= m; i ++) {
        int x, y, cap, cost;
        cin >> x >> y >> cap >> cost;
        mf.addEdge(x, y, cap, cost);
    }
    auto [flow, cost] = mf.flow(stt, edd);
    cout << flow << ' ' << cost << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --) {
        solve();
    }
    return 0;
}