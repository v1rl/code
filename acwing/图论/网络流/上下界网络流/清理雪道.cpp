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
    
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    int stt = 0, edd = n + 1;
    int nstt = n + 2, nedd = n + 3;
    MaxFlow<int> mf(n + 3);
    vector<int> A(n + 2);

    for(int i = 1; i <= n; i ++)
    {
        mf.addEdge(stt, i, inf);
    }
    
    for(int i = 1; i <= n; i ++)
    {
        mf.addEdge(i, edd, inf);
    }

    for(int i = 1; i <= n; i ++)
    {
        int t;
        cin >> t;
        while(t --)
        {
            int y;
            cin >> y;
            mf.addEdge(i, y, inf);
            A[i] -= 1, A[y] += 1;
        }
    }

    int tot = 0;
    for(int i = 0; i <= n + 1; i ++)
    {
        if(A[i] > 0) tot += A[i], mf.addEdge(nstt, i, A[i]);
        else if(A[i] < 0) mf.addEdge(i, nedd, -A[i]);
    }

    mf.addEdge(edd, stt, inf);
    int flow = mf.flow(nstt, nedd);
    if(tot == flow)
    {
        int flow1 = mf.e.back().w;
        mf.e.pop_back();
        mf.e.pop_back();
        mf.g[stt].pop_back();
        mf.g[edd].pop_back();
        int flow2 = mf.flow(edd, stt);
        cout << flow1 - flow2 << '\n';
    }
    else cout << "-1" << '\n';
    return 0;
}