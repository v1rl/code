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

void solve()
{
    int n;
    cin >> n;
    DSU dsu(2 * n);
    vector<PII> query;
    unordered_map<int, int> mp;
    int idx = 0;
    for(int i = 1; i <= n; i ++)
    {
        int x, y, op;
        cin >> x >> y >> op;
        if(!mp.count(x)) mp[x] = ++ idx;
        if(!mp.count(y)) mp[y] = ++ idx;
        x = mp[x], y = mp[y];
        if(op)
        {
            dsu.merge(x, y);
        }
        else
        {
            query.emplace_back(x, y);
        }
    }

    for(auto [x, y] : query)
    {
        if(dsu.same(x, y))
        {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
}