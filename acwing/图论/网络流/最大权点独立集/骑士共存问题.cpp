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
    
    vector<_Edge> edges()           //仅限单向边
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

int n, m;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[] = {-1, -2, -2, -1, 1, 2, 2, 1,};
int get(int x, int y)
{
    return (x - 1) * n + y;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 1));
    for(int i = 0; i < m; i ++)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = 0;
    }
    MaxFlow<int> mf(n * n + 1);
    int stt = 0, edd = n * n + 1;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            if(!g[i][j]) continue;
            int x = get(i, j);
            if(i + j & 1)
            {
                mf.addEdge(stt, x, 1);
                for(int k = 0; k < 8; k ++)
                {
                    int ni = i + dx[k], nj = j + dy[k];
                    if(ni < 1 || ni > n || nj < 1 || nj > n) continue;
                    int y = get(ni, nj);
                    mf.addEdge(x, y, inf);
                }
            }
            else mf.addEdge(x, edd, 1);
        }

    cout << n * n - m - mf.flow(stt, edd) << '\n';
}
