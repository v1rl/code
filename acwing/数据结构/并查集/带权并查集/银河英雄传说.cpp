#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
typedef pair<int, int> PII;

struct DSU
{
    vector<int> p, siz;
    vector<int> d;

    DSU(int n = 0)
    {
        init(n);
    }

    void init(int n)
    {
        p.resize(n + 1); 
        iota(p.begin(), p.end(), 0);
        siz.assign(n + 1, 1);
        d.assign(n + 1, 0);
    }

    int find(int x)
    {
        if(x != p[x])
        {
            int t = find(p[x]);
            d[x] += d[p[x]];
            p[x] = t;
        }
        return p[x];
    }

    int same(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if(px != py) return -1;
        return abs(d[x] - d[y]);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(x == y) return false;
        p[y] = x;
        d[y] = siz[x];
        siz[x] += siz[y];
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int q;
    cin >> q;
    DSU dsu(30000);
    while(q --)
    {
        char op;
        int x, y;
        cin >> op >> x >> y;
        if(op == 'M')
        {
            dsu.merge(y, x);
        }
        else
        {
            int t = dsu.same(x, y);
            if(t == -1) cout << -1 << '\n';
            else cout << max(0, t - 1) << '\n';
        }
    }

    return 0;
}