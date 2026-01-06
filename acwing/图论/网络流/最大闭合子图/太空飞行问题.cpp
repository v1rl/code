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
    
    vector<int> get(int stt)
    {
        vector<int> st(n);
        auto dfs = [&](auto &&self, int u)->void
        {
            st[u] = true;
            for(auto j : g[u])
            {
                auto [y, w] = e[j];
                // cout << u << ' ' << y << ' ' << w << '\n';
                if(!st[y] && w > 0)
                    self(self, y);
            }
        };
        dfs(dfs, stt);
        return st;
    }
    
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    string t;
    getline(cin, t);            //关同步流则用getline来输入回车
//  getchar();
    MaxFlow<int> mf(n + m + 1);
    int stt = 0, edd = n + m + 1;
    int tot = 0;
    for(int i = 1; i <= n; i ++)
    {
        string line;
        getline(cin, line);
        stringstream ssin(line);
        int w, id;
        ssin >> w;
        tot += w;
        mf.addEdge(stt, i, w);
        while(ssin >> id)
        {
            mf.addEdge(i, n + id, inf);
        }
    }
    for(int i = 1; i <= m; i ++)
    {
        int w;
        cin >> w;
        mf.addEdge(n + i, edd, w);
    }
    
    int flow = mf.flow(stt, edd);
    vector<int> ans1, ans2;
    vector<int> st = mf.get(stt);
    
    for(int i = 1; i <= n; i ++)
        if(st[i])
            cout << i << ' ';
    cout << '\n';
    for(int i = n + 1; i <= n + m; i ++)
        if(st[i])
            cout << i - n << ' ';
    cout << '\n';
    
    cout << tot - flow << '\n';
    return 0;
}
