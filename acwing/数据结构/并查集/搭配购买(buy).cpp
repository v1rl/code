#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

struct DSU
{
    vector<int> p, v, w;
    DSU(int n = 0)
    {
        init(n);
    }

    void init(int n)
    {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        v.resize(n + 1);
        w.resize(n + 1);
        for(int i = 1; i <= n; i ++)
        {
            cin >> v[i] >> w[i];
        }
    }

    int find(int x)
    {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    bool merge(int x, int y)
    {
        x = find(x), y = find(y);
        if(x == y) return false;
        p[y] = x;
        v[x] += v[y];
        w[x] += w[y];
        return true;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    int work(int n, int q, int m)
    {
        for(int i = 1; i <= q; i ++)
        {
            int x, y;
            cin >> x >> y;
            merge(x, y);
        }
        vector<int> f(m + 1);
        for(int i = 1; i <= n; i ++)
        {
            if(p[i] != i) continue;
            for(int j = m; j >= v[i]; j --)
            {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }
        return f[m];
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m, w;
    cin >> n >> m >> w;
    DSU dsu(n);
    cout << dsu.work(n, m, w) << '\n';
}