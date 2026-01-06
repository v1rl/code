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
    int n, m;
    while(cin >> n >> m)
    {
        int stt = 0, edd = n + m + 1;
        int nstt = n + m + 2, nedd = n + m + 3;
        vector<int> A(n + m + 2);
        MaxFlow<int> mf(n + m + 3);
        for(int i = 0; i < m; i ++)
        {
            int w;
            cin >> w;
            mf.addEdge(i + 1 + n, edd, inf);
            A[i + 1 + n] -= w, A[edd] += w;
        }
        for(int i = 0; i < n; i ++)
        {
            int k, nw;
            cin >> k >> nw;
            mf.addEdge(stt, i + 1, nw);
            for(int j = 0; j < k; j ++)
            {
                int id, l, r;
                cin >> id >> l >> r;
                mf.addEdge(i + 1, id + 1 + n, r - l);
                A[i + 1] -= l;
                A[id + 1 + n] += l;
            }
        }
        
        
        int tot = 0;
        for(int i = 0; i <= n + m + 1; i ++)
        {
            if(A[i] > 0) tot += A[i], mf.addEdge(nstt, i, A[i]);
            else if(A[i] < 0) mf.addEdge(i, nedd, -A[i]);
        }
        
        mf.addEdge(edd, stt, inf);
        int flow = mf.flow(nstt, nedd);
        if(flow == tot)
        {
            int flow1 = mf.e.back().w;
            mf.e.pop_back();
            mf.e.pop_back();
            mf.g[stt].pop_back();
            mf.g[edd].pop_back();
            int flow2 = mf.flow(stt, edd);
            cout << flow1 + flow2 << '\n';
        }
        else cout << "-1" << '\n';
        cout << '\n';
    }
    return 0;
}