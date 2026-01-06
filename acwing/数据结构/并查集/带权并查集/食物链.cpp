#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct DSU
{
    vector<int> p;
    vector<int> d;

    DSU(int n = 0)
    {
        init(n);
    }

    void init(int n)
    {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
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

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y, int op)
    {
        int px = find(x), py = find(y);
        if(px == py)
        {
            if((d[x] - d[y] - op) % 3) return true;
        }
        else 
        {
            p[py] = px;
            d[py] = d[x] - d[y] - op;
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    int ans = 0;
    while(q --)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if(x > n || y > n)
        {
            ans ++;
            continue;
        }
        int t;
        if(op == 1) t = 0;
        else t = 1;

        if(dsu.merge(x, y, t)) ans ++;
    }
    cout << ans << '\n';
    return 0;
}