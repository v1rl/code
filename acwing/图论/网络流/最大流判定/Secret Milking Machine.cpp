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
        e.emplace_back(x, w);
        // e.emplace_back(x, 0);
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
    int n, m, k;
    cin >> n >> m >> k;
    int stt = 1, edd = n;
    vector<array<int, 3>> e;
    for(int i = 0; i < m; i ++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        e.push_back({x, y, w});
    }

    auto check = [&](int mid)
    {
        MaxFlow<int> mf(n + 1);
        for(auto &[x, y, w] : e)
        {
            if(w <= mid)
            {
                mf.addEdge(x, y, 1);        //合并
                // mf.addEdge(y, x, 1);
            }
        }
        if(mf.flow(stt, edd) >= k) return true;
        return false;
    };

    int l = 0, r = 1000000;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
    return 0;
}