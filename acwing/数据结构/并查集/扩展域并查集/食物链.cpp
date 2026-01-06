#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
typedef pair<int, int> PII;

struct DSU
{
    vector<int> p, siz;

    DSU(int n = 0)
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
        return find(x) == find(y);
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

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, q;
    cin >> n >> q;
    DSU dsu(n * 3);
    const int base = n;
    int res = 0;
    while(q --)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if(x > n || y > n)
        {
            res ++;
            continue;
        }
        if(op == 1)
        {
            if(dsu.same(x, y + base) || dsu.same(x + base, y)) res ++;
            else
            {
                dsu.merge(x, y);
                dsu.merge(x + base, y + base);
                dsu.merge(x + base * 2, y + base * 2);
            }
        }
        else
        {
            if(dsu.same(x, y) || dsu.same(x + base, y)) res ++;
            else
            {
                dsu.merge(x, y + base);
                dsu.merge(x + base, y + base * 2);
                dsu.merge(x + base * 2, y);
            }
        }
    }
    cout << res << '\n';
    return 0;
}