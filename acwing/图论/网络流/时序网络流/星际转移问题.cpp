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


struct DSU
{
    vector<int> p, siz;

    DSU(int n) 
    {
        init(n);
    }

    void init(int n)
    {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        siz.assign(n + 1, 1);
    }

    int find(int x)
    {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    bool same(int x, int y)
    {
        if(find(x) == find(y)) return true;
        return false;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(x == y) return false;
        p[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
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
    cin >> n >> m >> k;
    int mx = (n + 2) * (n + 2) * k * (n + 2);
    // int mx = 10000;
    MaxFlow<int> mf(mx + 2);
    int stt = mx + 1, edd = mx + 2;

    DSU dsu(n + 2);
    struct Node
    {
        int w;
        vector<int> p;
    };
    vector<Node> bus(m);
    for(int i = 0; i < m; i ++)
    {
        int w, k;
        cin >> w >> k;
        bus[i].w = w;
        bus[i].p.reserve(k);
        for(int j = 0; j < k; j ++)
        {
            int id;
            cin >> id;
            if(id == -1) id = n + 1;
            bus[i].p.emplace_back(id);
            if(j != 0) dsu.merge(bus[i].p[0], id);
        }
    }


    if(!dsu.same(0, n + 1)) cout << 0 << '\n';
    else
    {
        mf.addEdge(stt, get(0, 0), inf);
        mf.addEdge(get(0, n + 1), edd, inf);
        int ans = 0;

        int day = 1;
        while(1)
        {
            for(int i = 0; i < n + 1; i ++)
            {
                mf.addEdge(get(day - 1, i), get(day, i), inf);
            }
            mf.addEdge(get(day, n + 1), edd, inf);
            for(auto &[w, p] : bus)
            {
                mf.addEdge(get(day - 1, p[(day - 1) % p.size()]),       //从0开始才方便取模
                    get(day, p[day % p.size()]), w);
            }
            ans += mf.flow(stt, edd);
            if(ans >= k) break;
            day ++;
        }

        cout << day << '\n';
    }
    return 0;
}