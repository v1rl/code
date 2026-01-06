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
            int root = find(p[x]);
            d[x] ^= d[p[x]];
            p[x] = root;
        }
        return p[x];
    }

    int same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y, int op)
    {
        int px = find(x);
        int py = find(y);
        if(px == py) return false;
        p[py] = px;
        d[py] = d[y] ^ d[x] ^ op;
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
    int n;
    cin >> n;
    int q;
    cin >> q;
    DSU dsu(q * 2);
    int ans = q;
    unordered_map<int, int> mp;
    int idx = 0;
    bool f = false;
    for(int i = 1; i <= q; i ++)
    {
        int x, y;
        string s;
        cin >> x >> y >> s;
        x --;
        if(!mp.count(x)) mp[x] = ++idx;
        if(!mp.count(y)) mp[y] = ++idx;
        x = mp[x], y = mp[y];

        if(!f)
        {
            int t;
            if(s[0] == 'e') t = 0;
            else t = 1;
            if(!dsu.merge(x, y, t))
            {
                if((dsu.d[x] ^ dsu.d[y]) != t) 
                {
                    ans = i - 1;
                    f = true;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}