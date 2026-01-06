#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const double eps = 1e-8;

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

    void addEdge(int x, int y, T w1, T w2)
    {
        g[x].emplace_back(e.size());
        e.emplace_back(y, w1);
        g[y].emplace_back(e.size());
        e.emplace_back(x, w2);
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
        // double res = 0;
        for(int &i = cur[x]; i < g[x].size(); i ++)
        {
            int j = g[x][i];
            auto [y, w] = e[j];
            if(w > 0 && h[y] == h[x] + 1)
            {
                T t = dfs(y, edd, min(w, flow));
                // res += t;
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
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1);
    vector<int> dg(n + 1);
    MaxFlow<int> mf(n + 1);
    int stt = 0, edd = n + 1;
    
    // for(int i = 1; i <= n; i ++) cin >> p[i];
    // while(m --)
    // {
    //     int x, y, w;
    //     cin >> x >> y >> w;
    //     mf.addEdge(x, y, w, w);
    //     dg[x] += w, dg[y] += w;
    // }

    // int U = 0;
    // for(int i = 1; i <= n; i ++) U = max(U, dg[i]);
    // for(int i = 1; i <= n; i ++)
    // {
    //     mf.addEdge(stt, i, U, 0);
    //     mf.addEdge(i, edd, U + p[i] * 2 - dg[i], 0);
    // }

    for(int i = 1; i <= n; i ++) cin >> p[i], p[i] *= -1;
    while(m --)
    {
        int x, y, w;
        cin >> x >> y >> w;
        mf.addEdge(x, y, w, w);
        dg[x] += w, dg[y] += w;
    }

    int U = 0;
    for(int i = 1; i <= n; i ++) U = max(U, p[i] * 2 + dg[i]);
    for(int i = 1; i <= n; i ++)
    {
        mf.addEdge(stt, i, U, 0);
        mf.addEdge(i, edd, U - p[i] * 2 - dg[i], 0);
    }

    cout << (U * n - mf.flow(stt, edd)) / 2 << '\n';
}
