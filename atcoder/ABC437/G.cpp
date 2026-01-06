#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
题目的数据范围表明，这需要一个至少O(n^2)的算法
注意到：每个点需要变化的次数固定为该点的度——那么,只要我们在条件约束下，能够对该点执行度的大小次变化，就能够让该点符合题意
那么，判定点在一定条件约束下能否达到目标次数，以及复杂度O(n^2)，不难联想到网络流
显然，两个点的颜色不同才能执行变化的约束，可以通过网络流拆点建边完成
注意到：点在某一颜色下的变化次数也是固定的
那么，点变化后颜色发生变化的约束，可以通过拆点后设置边的容量完成
于是，我们通过网络流完成了题目的所有约束，只要最大流为n-1，该流网络就可以达成条件

但是，题目需要的不止是判定，还要构造出合法的删边次序
需要注意到，本题支持O(n^2)的复杂度，所以我们可以发散思路找一个暴力一些的做法
先存储下来所有有流量的边，最后维护每个点当前的颜色，若边两端的点符合颜色不同的约束则可以直接删除
多次暴力遍历所有边，直到所有边都被删除
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> c(n + 1);
    for(int i = 0; i < n; i ++) {
        if(s[i] == 'R') {
            c[i + 1] = 0;
        } else if(s[i] == 'G') {
            c[i + 1] = 1;
        } else {
            c[i + 1] = 2;
        }
    }

    MaxFlow<int> mf(n * 3 + 2);
    int stt = 0, edd = n * 3 + 1;
    vector<vector<int>> adj(n + 1);
    vector<int> d(n + 1);

    map<array<int, 2>, int> mp;

    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
        mp[{x, y}] = i + 1;
        mp[{y, x}] = i + 1;
        d[x] ++, d[y] ++;
    }

    vector<int> pt(n + 1, -1);
    pt[1] = 0;

    vector<array<int, 3>> num(n + 1);

    for(int x = 1; x <= n; x ++) {
        int stt = c[x];
        for(int i = 0; i < d[x] % 3; i ++) {
            num[x][(stt + i) % 3] ++;
        }
        d[x] /= 3;
        for(int i = 0; i < 3; i ++) {
            num[x][i] += d[x];
        }
    }

    queue<int> q;
    q.push(1);
    while(q.size()) {
        auto x = q.front();
        q.pop();

        if(!pt[x]) {
            for(auto y : adj[x]) {
                for(int i = 0; i < 3; i ++) {
                    for(int j = 0; j < 3; j ++) {
                        if(i == j) continue;
                        mf.addEdge(n * i + x, n * j + y, 1);
                    }
                }
            }
            for(int i = 0; i < 3; i ++) {
                mf.addEdge(stt, n * i + x, num[x][i]);
            }
        } else {
            for(int i = 0; i < 3; i ++) {
                mf.addEdge(n * i + x, edd, num[x][i]);
            }
        }

        for(auto y : adj[x]) {
            if(pt[y] != -1) {
                continue;
            }
            pt[y] = pt[x] ^ 1;
            q.push(y);
        }
    }

    int flow = mf.flow(stt, edd);
    // cout << flow << '\n';
    if(flow != n - 1) {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';

    // cerr << 'h';

    vector<array<int, 4>> stk;
    stk.reserve(n - 1);
    auto edges = mf.edges();

    for(auto &[x, y, cap, flow] : edges) {
        if(x != 0 && y != n * 3 + 1 && flow == 1) {
            stk.push_back({(x - 1) % n + 1, (y - 1) % n + 1, (x - 1) / n, (y - 1) / n});
        }
    }

    vector<int> ans;
    vector<int> st(n);
    int cnt = 0;

    while(cnt < n - 1) {
        // cerr << 'h';
        for(int i = 0; i < stk.size(); i ++) {
            if(st[i]) {
                continue;
            }
            auto &[x, y, u, v] = stk[i];
            if(c[x] == u && c[y] == v) {
                ans.emplace_back(mp[{x, y}]);
                st[i] = true;
                cnt ++;
                c[x] ++, c[x] %= 3;
                c[y] ++, c[y] %= 3;
            }
        }
    }

    for(auto c : ans) {
        cout << c << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
