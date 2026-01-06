#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

template<class T>
struct MaxFlow{
	struct Edge {
		int y;
		T cap;
		Edge(int y_, T cap_) : y(y_), cap(cap_) {};
	};

	int n;
	vector<Edge> e;
	vector<vector<int>> g;
	vector<int> cur, d;
	MaxFlow(int n_) : n(n_), g(n + 1) {};

	void addEdge(int x, int y, int cap) {
		g[x].emplace_back(e.size());
		e.emplace_back(y, cap);
		g[y].emplace_back(e.size());
		e.emplace_back(x, 0);
	}

	bool bfs(int stt, int edd) {
		d.assign(n + 1, -1);
		d[stt] = 0;
		queue<int> q;
		q.push(stt);

		while(q.size()) {
			int x = q.front();
			q.pop();

			for(auto j : g[x]) {
				auto [y, cap] = e[j];
				if(cap == 0 || d[y] != -1) continue;
				d[y] = d[x] + 1;
				if(y == edd) return true;
				q.push(y);
			}
		}
		return false;
	}

	T dfs(int x, int edd, T limit) {
		if(x == edd) return limit;
		T flow = limit;
		for(int &i = cur[x]; i < g[x].size(); i ++) {
			int j = g[x][i];
			auto [y, cap] = e[j];

			if(d[y] != d[x] + 1 || cap == 0) continue;
			T t = dfs(y, edd, min(flow, cap));
			e[j].cap -= t;
			e[j ^ 1].cap += t;
			flow -= t;
			if(flow == 0) return limit;
		}
		return limit - flow;
	}

	T flow(int stt, int edd) {
		T flow = 0;
		while(bfs(stt, edd)) {
			cur.assign(n + 1, 0);
			flow += dfs(stt, edd, numeric_limits<T>::max());
		}
		return flow;
	}
};

void solve() {
	int s;
	cin >> s;
	vector<int> a(8);
	for(int i = 1; i <= 7; i ++) {
		cin >> a[i];
	}
	swap(a[3], a[4]);

	auto check = [&](int mid) {
		MaxFlow<int> mf(8);
		int stt = 0, edd = 8;
		mf.addEdge(stt, 1, a[1]);
		mf.addEdge(stt, 2, a[2]);
		mf.addEdge(stt, 3, a[3]);

		mf.addEdge(stt, 4, a[4]);
		mf.addEdge(4, 1, a[4]);
		mf.addEdge(4, 2, a[4]);

		mf.addEdge(stt, 5, a[5]);
		mf.addEdge(5, 1, a[5]);
		mf.addEdge(5, 3, a[5]);

		mf.addEdge(stt, 6, a[6]);
		mf.addEdge(6, 2, a[6]);
		mf.addEdge(6, 3, a[6]);

		mf.addEdge(stt, 7, a[7]);
		mf.addEdge(7, 1, a[7]);
		mf.addEdge(7, 2, a[7]);
		mf.addEdge(7, 3, a[7]);

		mf.addEdge(1, edd, mid);
		mf.addEdge(2, edd, mid);
		mf.addEdge(3, edd, mid);

		int flow = mf.flow(stt, edd);
		return flow == mid * 3;
	};

	int l = 0, r = (s / 3) + 1;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}

	cout << l << '\n';
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}