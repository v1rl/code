#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
一般网络--n^2 * m
*/

template<class T>
struct MaxFlow {
    struct Edge {
        int y;
        //剩余流量
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

    // 在原图基础上bfs得到层次图
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

    // 在层次图中dfs出阻塞流
    // limit最大入流，flow还可以流出的流量，limit - flow真实出流
    T dfs(int x, int edd, T limit) {
        if(x == edd) return limit;
        T flow = limit;
        for(int &i = cur[x]; i < g[x].size(); i ++) {
            int j = g[x][i];
            auto [y, cap] = e[j];

            if(d[y] != d[x] + 1 || cap == 0) continue;
            // 下一个点的最大入流等于min(当前点还可以流出的流量，当前边的剩余容量)
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

    struct _Edge {
        int x;
        int y;
        //最大容量
        T cap;
        T flow;
    };

    vector<_Edge> edges() {           //仅限单向边
        vector<_Edge> res;
        for(int i = 0; i < e.size(); i += 2) {
            res.emplace_back(e[i + 1].y, e[i].y, e[i].cap + e[i + 1].cap, e[i + 1].cap);
        }
        return res;
    }

    void reset() {
        for(int i = 0; i < e.size(); i += 2) {
            e[i].cap += e[i + 1].cap;
            e[i + 1].cap = 0;
        }
    }
};

void solve() {
    int n, m, stt, edd;
    cin >> n >> m >> stt >> edd;
    MaxFlow<i64> mf(n);
    for(int i = 1; i <= m; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        mf.addEdge(x, y, w);
    }
    cout << mf.flow(stt, edd) << '\n';
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