#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
const int inf = 1e9;

template<class T>
struct MaxFlow
{
    struct Edge
    {
        int y;
        T cap;
        Edge(int y_, T cap_) : y(y_), cap(cap_) {};
    };

    int n;
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> cur, d;
    MaxFlow(int n_) : n(n_), g(n + 1) {};

    void addEdge(int x, int y, int cap)
    {
        g[x].emplace_back(e.size());
        e.emplace_back(y, cap);
        g[y].emplace_back(e.size());
        e.emplace_back(x, 0);
    }

    bool bfs(int stt, int edd)
    {
        d.assign(n + 1, -1);
        d[stt] = 0;
        queue<int> q;
        q.push(stt);
        while(q.size())
        {
            int x = q.front();
            q.pop();

            for(auto j : g[x])
            {
                auto [y, cap] = e[j];
                if(cap == 0 || d[y] != -1) continue;
                d[y] = d[x] + 1;
                if(y == edd) return true;
                q.push(y);
            }
        }
        return false;
    }

    T dfs(int x, int edd, T limit)      //总共可以流出的流-还可以流出的流->已经流出的流
    {
        if(x == edd) return limit;
        T flow = limit;
        for(int &i = cur[x]; i < g[x].size(); i ++)
        {
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

    T flow(int stt, int edd)
    {
        T flow = 0; 
        while(bfs(stt, edd))
        {
            cur.assign(n + 1, 0);
            flow += dfs(stt, edd, numeric_limits<T>::max()) ;
        }
        return flow;
    }

    struct _Edge
    {
        int x;
        int y;
        T cap;
        T flow;
    };

    vector<_Edge> edges()           //仅限单向边
    {
        vector<_Edge> res;
        for(int i = 0; i < e.size(); i += 2)
        {
            res.push_back({e[i + 1].y, e[i].y, e[i + 1].cap + e[i].cap, e[i + 1].cap});
        }
        return res;
    }

    void reset()
    {
        for(int i = 0; i < e.size(); i += 2)
        {
            e[i].cap += e[i + 1].cap;
            e[i + 1].cap = 0;
        }
    }

    void update(int num, int x1, int x2, int stt, int edd)
    {
        for(int i = 0; i < e.size(); i += 2)
        {
            int x = e[i + 1].y, y = e[i].y;
            if(x == x1 && y == x1 + num) e[i].cap = inf;
            if(x == x2 && y == x2 + num) e[i].cap = inf; 
            if(x == stt && y == x1) e[i].cap = inf;
            if(x == x2 + num && y == edd) e[i].cap = inf;
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    int mx = 1;
    vector<int> f(n + 1, 1);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j < i; j ++)
            if(a[j] <= a[i])
            {
                f[i] = max(f[i], f[j] + 1);
                mx = max(mx, f[i]);
            }

    cout << mx << '\n';
    int stt = 0, edd = n * 2 + 1;
    MaxFlow<int> mf(n * 2 + 1);
    for(int i = 1; i <= n; i ++)
    {
        if(f[i] == 1) mf.addEdge(stt, i, 1);
        if(f[i] == mx) mf.addEdge(n + i, edd, 1);
        mf.addEdge(i, i + n, 1);
    }

    for(int i = 2; i <= n; i ++)
        for(int j = 1; j < i; j ++)
            if(a[j] <= a[i] && f[i] == f[j] + 1)
                mf.addEdge(n + j, i, 1);

    int flow = mf.flow(stt, edd);
    cout << flow << '\n';
    if(n != 1) mf.update(n, 1, n, stt, edd);
    cout << flow + mf.flow(stt, edd) << '\n';
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