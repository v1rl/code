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
        T w;
        Edge(int y_, T w_) : y(y_), w(w_) {};
    };

    int n;
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> cur, d;
    MaxFlow(int n_) : n(n_), g(n + 1) {};

    void addEdge(int x, int y, int w)
    {
        g[x].emplace_back(e.size());
        e.emplace_back(y, w);
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
                auto [y, w] = e[j];
                if(w == 0 || d[y] != -1) continue;
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
            auto [y, w] = e[j];

            if(d[y] != d[x] + 1 || w == 0) continue;
            T t = dfs(y, edd, min(flow, w));
            e[j].w -= t;
            e[j ^ 1].w += t;
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
            res.push_back({e[i + 1].y, e[i].y, e[i + 1].w + e[i].w, e[i + 1].w});
        }
        return res;
    }

    void reset()
    {
        for(int i = 0; i < e.size(); i += 2)
        {
            e[i].w += e[i + 1].w;
            e[i + 1].w = 0;
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    double d;
    cin >> d;
    MaxFlow<int> mf(n * 2);
    int stt = 0;
    vector<array<int, 2>> p(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i ++)
    {
        int x, y, num, w;
        cin >> x >> y >> num >> w;
        p[i] = {x, y};
        mf.addEdge(stt, i, num);
        mf.addEdge(i, n + i, w);
        sum += num;
    }

    auto check = [&](int i, int j)
    {
        int dx = p[i][0] - p[j][0], dy = p[i][1] - p[j][1];
        return dx * dx + dy * dy <= d * d;
    };

    for(int i = 1; i <= n; i ++)
        for(int j = i + 1; j <= n; j ++)
            if(check(i, j))
            {
                mf.addEdge(i + n, j, inf);
                mf.addEdge(j + n, i, inf);
            }

    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        mf.reset();
        if(mf.flow(stt, i) == sum) ans ++, cout << i - 1 << ' ';
    }
    if(ans == 0) cout << -1;
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}