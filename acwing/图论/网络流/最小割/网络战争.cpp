#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
//https://www.acwing.com/file_system/file/content/whole/index/content/7372040/
// 01分数规划

template<class T>
struct MaxFlow
{
    struct Edge
    {
        int v;
        T w;
        T gw;                   //初始权值gw与实际流w
        Edge(int v, T w, T gw) : v(v), w(w), gw(gw){};
    };

    int n;
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> cur, h;
    MaxFlow(int n_) : n(n_ + 1), g(n) {};

    void addEdge(int x, int y, T w)     //双向边       怎么求flow和cap，怎么重新初始化
    {
        g[x].emplace_back(e.size());
        e.push_back({y, w, w});
        g[y].emplace_back(e.size());
        e.push_back({x, w, w});
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
                auto [y, w, _] = e[j];
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
            auto [y, w, _] = e[j];
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

    T flow(int stt, int edd, T mid)
    {
        T ans = 0;
        for(int i = 0; i < e.size(); i += 2)
        {
            e[i].w = e[i + 1].w = e[i].gw - mid;
            if(e[i].w < 0) 
            {
                ans += e[i].w;
                e[i].w = e[i + 1].w = 0;
            }
        }

        T res = 0;
        while(bfs(stt, edd))
        {
            cur.assign(n, 0);
            res += dfs(stt, edd, numeric_limits<T>::max());
        }
        return ans + res;
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
    int n, m, stt, edd;
    cin >> n >> m >> stt >> edd;
    MaxFlow<double> mf(n);
    for(int i = 0; i < m; i ++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        mf.addEdge(x, y, w);
    }

    double l = 0, r = 1e7;
    int cnt = 0;
    while(r - l > eps)
    {
        double mid = (l + r) / 2;
        if(mf.flow(stt, edd, mid) < 0) r = mid;
        else l = mid;
    }

    printf("%.2lf", r);
    return 0;
}