#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using PII = pair<int, int>;
const int inf = 1e9;

/*
每个点要么是左括号，要么是右括号
对左括号有个数约束
对左右括号匹配有匹配约束

可以将对特定颜色左括号个数的下界约束，转换为对特定颜色右括号个数的上界约束，
将从前往后左括号的下界个数约束，转换为从后往前对左括号的上界个数约束，
从而直接使用普通费用流，避免使用上下界网络流

Trick：数据量较小，约束较多的情况都可以考虑网络流建边处理约束
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
	int n, m;
	cin >> n >> m;
	n *= 2;
	vector<int> num(m + 1);
	for(int i = 1; i <= m; i ++) {
		cin >> num[i];
		num[i] = -num[i];
	}
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		num[a[i]] ++;
	}
	i64 sum = 0;
	vector<int> w(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> w[i];
		sum += w[i];
	}

	for(int i = 1; i <= m; i ++) {
		if(num[i] < 0) {
			cout << -1 << '\n';
			return;
		}  
	}

	MinCostFlow<i64> mcf(n + m + 1);
	int stt = 0, edd = n + m + 1;
	// 设置局部汇点处理约束，将对应颜色的点连向它的局部汇点
	for(int i = 1; i <= n; i ++) {
		mcf.addEdge(i, n + a[i], 1, w[i]);
	}
	for(int i = 1; i <= m; i ++) {
		mcf.addEdge(n + i, edd, num[i], 0);
	}
	// 从后往前连成一条线并设置最大流量约束解决括号匹配问题
	mcf.addEdge(stt, n, n / 2, 0);
	for(int i = n; i >= 2; i --) {
		mcf.addEdge(i, i - 1, (i - 1) / 2, 0);
	}

	auto [flow, cost] = mcf.flow(stt, edd);
	if(flow != n / 2) {
		cout << -1 << '\n';
	} else {
		cout << sum - cost << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}