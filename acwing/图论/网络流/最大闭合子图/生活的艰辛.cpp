#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const double eps = 1e-8;
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
        double res = 0;
        for(int &i = cur[x]; i < g[x].size(); i ++)
        {
            int j = g[x][i];
            auto [y, w] = e[j];
            if(w > 0 && h[y] == h[x] + 1)
            {
                T t = dfs(y, edd, min(w, flow));
                res += t;
                e[j].w -= t;
                e[j ^ 1].w += t;
                flow -= t;
                if(flow == 0) return limit;
            }
        }
        return res;
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

    vector<int> get(int &ans, int stt, int n, int m)
    {
        vector<int> st(n + m + 1);
        auto dfs = [&](auto && self, int u)->void
        {
            st[u] = true;
            if(u >= 1 && u <= n) ans ++;
            for(int i = 0; i < g[u].size(); i ++)
            {
                int j = g[u][i];
                auto [y, w] = e[j];
                if(w > 0 && !st[y])
                    self(self, y);
            }
        };
        dfs(dfs, stt);
        return st;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> edge(m);
    for(int i = 0; i < m; i ++)
    {
        int x, y;
        cin >> x >> y;
        edge[i] = {x, y};
    }

    int stt = 0, edd = m + n + 1;
    double l = 0, r = m;
    int ans = 0;
    while(r - l > eps)
    {
        double mid = (l + r) / 2;
        MaxFlow<double> mf(n + m + 1);
        int cnt = 1;
        for(auto [x, y] : edge)
        {
            mf.addEdge(stt, n + cnt, 1);
            mf.addEdge(n + cnt, x, inf);
            mf.addEdge(n + cnt, y, inf);
            cnt ++;
        }
        for(int i = 1; i <= n; i ++)
        {
            mf.addEdge(i, edd, mid);
        }
        double flow = mf.flow(stt, edd);
        if(m - flow > 0) l = mid;
        else r = mid;


        if(r - l <= eps)
        {
            vector<int> st = mf.get(ans, stt, n, m);
            cout << ans << '\n';
            for(int i = 1; i <= n; i ++)
                if(st[i])
                    cout << i << '\n';
        }
    }
    return 0;

}
