#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 0x3f3f3f3f;

template<class T>
struct MaxFlow
{
    struct Edge
    {
        int v;
        T w;
        Edge(int v, T w) : v(v), w(w) {};
    };

    int n;
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> cur, h;
    MaxFlow(int n_) : n(n_ + 1), g(n) {};

    void addEdge(int x, int y, T w)
    {
        g[x].emplace_back(e.size());
        e.emplace_back(y, w);
        g[y].emplace_back(e.size());
        e.emplace_back(x, 0);
    }

    bool bfs(int stt, int edd)
    {
        h.assign(n, -1);
        h[stt] = 0;
        queue<int> q;
        q.push(stt);
        while(q.size())
        {
            int x = q.front();
            q.pop();
            for(auto j : g[x])
            {
                auto [y, w] = e[j];
                if(w > 0 && h[y] == -1)
                {
                    h[y] = h[x] + 1;
                    if(y == edd) return true;
                    q.push(y);
                }
            }
        }
        return false;
    }

    T dfs(int x, int edd, T limit)
    {
        if(x == edd) return limit;
        T flow = limit;
        for(int &i = cur[x]; i < g[x].size(); i ++)
        {
            int j = g[x][i];
            auto [y, w] = e[j];
            if(w > 0 && h[y] == h[x] + 1)
            {
                T t = dfs(y, edd, min(w, flow));
                e[j].w -= t;
                e[j ^ 1].w += t;
                flow -= t;
                if(flow == 0) return limit;
            }
        }
        return limit - flow;
    }

    T flow(int stt, int edd)
    {
        T ans = 0;
        while(bfs(stt, edd))
        {
            cur.assign(n, 0);
            ans += dfs(stt, edd, numeric_limits<T>::max());
        }
        return ans;
    }

    struct _Edge
    {
        int u;
        int v;
        T cap;
        T flow;
    };

    vector<_Edge> edges()
    {
        vector<_Edge> a;
        for(int i = 0; i < e.size(); i += 2)
        {
            _Edge x = {e[i + 1].v, e[i].v, e[i + 1].w + e[i].w, e[i + 1].w};
            a.emplace_back(x);
        }
        return a;
    }

    void update(int num, int x1, int x2, int stt, int edd)
    {
        for(int i = 0; i < e.size(); i += 2)
        {
            if(e[i + 1].v == x1 && e[i].v == num + x1) e[i].w = inf;
            if(e[i + 1].v == x2 && e[i].v == num + x2) e[i].w = inf;
            if(e[i + 1].v == stt && e[i].v == x1) e[i].w = inf;
            if(e[i + 1].v == x2 + num && e[i].v == edd) e[i].w = inf;
        }
    }

};

int n, m, k;
int get(int day, int id)
{
    return day * (n + 2) + id;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> f(n + 1, 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 2; i <= n; i ++)
        for(int j = 1; j < i; j ++)
            if(a[j] <= a[i])
                f[i] = max(f[i], f[j] + 1);

    int mx = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(f[i] > mx) mx = f[i];
    }
    cout << mx << '\n';

    MaxFlow<int> mf(n * 2 + 1);
    int stt = 0, edd = n * 2 + 1;
    for(int i = 1; i <= n; i ++)
    {
        if(f[i] == 1) mf.addEdge(stt, i, 1);
        if(f[i] == mx) mf.addEdge(n + i, edd, 1);
        mf.addEdge(i, n + i, 1);
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