#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

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
	int n, m;
	cin >> n >> m;
	MinCostFlow<i64> mcf(n + m + 2);
	int stt = 0, edd = n + m + 1;
	string s;
	cin >> s;
	s = "#" + s;
	i64 sum = 0;
	vector<int> w(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> w[i];
		sum += w[i];
	}

	vector<int> st(n + 1);
	for(int i = 1; i <= m; i ++) {
		int x, y, z;
		cin >> x >> y >> z;
		st[x] = st[y] = st[z] = true;
		if(s[x] == '(') {			
			mcf.addEdge(stt, n + i, 1, 0);
			mcf.addEdge(n + i, x, 1, -w[x]);
			mcf.addEdge(n + i, y, 1, -w[y]);
			mcf.addEdge(n + i, z, 1, -w[z]);
		} else {
			mcf.addEdge(n + i, edd, 1, 0);
			mcf.addEdge(x, n + i, 1, -w[x]);
			mcf.addEdge(y, n + i, 1, -w[y]);
			mcf.addEdge(z, n + i, 1, -w[z]);
		}
	}

	for(int i = 1; i <= n; i ++) {
		if(st[i]) {
			continue;
		}
		if(s[i] == '(') {
			mcf.addEdge(stt, i, 1, -w[i]);
		} else {
			mcf.addEdge(i, edd, 1, -w[i]);
		}
	}

	for(int i = 1; i < n; i ++) {
		mcf.addEdge(i, i + 1, inf, 0);
	}

	auto [flow, cost] = mcf.flow(stt, edd);
	if(flow * 2 == n - 2 * m) {
		cout << "Yes" << '\n';
		cout << sum + cost;
	} else {
		cout << "No" << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}
