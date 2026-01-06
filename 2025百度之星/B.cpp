#include<bits/stdc++.h> 
using namespace std;
using i64 = long long;

template<class T>
struct MinCostFlow {
	struct Edge {
		int y;
		T cap;
		T cost;
		Edge(int y_, T cap_, T cost_) : y(y_), cap(cap_), cost(cost_) {};
	};

	int n;
	vector<Edge> e;
	vector<vector<int>> g;
	vector<T> h, dist;
	vector<int> pre;

	MinCostFlow(int n_) : n(n_), g(n + 1) {};

	void addEdge(int x, int y, T cap, T cost) {
		g[x].emplace_back(e.size());
		e.emplace_back(y, cap, cost);
		g[y].emplace_back(e.size());
		e.emplace_back(x, 0, -cost);
	}

	bool dijkstra(int stt, int edd) {
		dist.assign(n + 1, numeric_limits<T>::max());
		pre.assign(n + 1, -1);
		dist[stt] = 0;
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> heap;
		heap.push({dist[stt], stt});
		while(heap.size()) {
			auto [d, x] = heap.top();
			heap.pop();
			if(d != dist[x]) {
				continue;
			}

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
		h.assign(n + 1, 0);
		T flow = 0;
		T cost = 0;
		while(dijkstra(stt, edd)) {
			for(int i = 0; i <= n; i ++) {
				h[i] += dist[i];
			}
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
};

void solve() {
	int n, m, nd, hs;
	cin >> n >> m >> nd >> hs;
	MinCostFlow<int> mf(n + 2);
	int stt = 0, edd = n + 1;
	vector<int> to(n + 1);
	for(int i = 0; i < nd; i ++) {
		int x;
		cin >> x;
		to[x] ++;
	}
	for(int i = 1; i <= n; i ++) {
		if(to[i]) {
		// cout << i << ' ' << edd << ' ' << to[i] << '\n';
			mf.addEdge(stt, i, to[i], 0);
		}
	}

	vector<int> fm(n + 1);
	for(int i = 0; i < hs; i ++) {
		int x;
		cin >> x;
		fm[x] ++;
	}
	for(int i = 1; i <= n; i ++) {
		if(fm[i]) {
			mf.addEdge(i, edd, fm[i], 0);
		}
	}


	for(int i = 0; i < m; i ++) {
		int c, a, b;
		cin >> c >> a >> b;
		vector<int> A(a), B(b);
		for(int i = 0; i < a; i ++) {
			cin >> A[i];
		}
		for(int i = 0; i < b; i ++) {
			cin >> B[i];
		}
		for(int i = 0; i < a; i ++) {
			for(int j = 0; j < b; j ++) {
				mf.addEdge(A[i], B[j], c, 1);
			}
		}
	}

	auto z = mf.flow(stt, edd);
	int flow = z.first;
	int cost = z.second;
	// cout << flow << '\n';
	if(flow != nd) {
		cout << -1 << '\n';
	} else {
		cout << cost << '\n';
	}
}

int main() {
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
    return 0;
}