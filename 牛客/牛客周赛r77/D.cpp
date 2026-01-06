#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

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
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        DSU dsu(n);
        vector<int> st(65);
        for(int i = 1; i <= n; i ++)
        {
            i64 x;
            cin >> x;
            for(int j = 63; j >= 0; j --)
            {
                int t = (x >> j) & 1;
                if(t)
                {
                    if(st[j])
                    {
                        dsu.merge(i, st[j]);    
                    }
                    st[j] = i;
                }
            }
        }
        int mx = 0;
        for(int i = 0; i <= 63; i ++) 
        {
            mx = max(mx, dsu.size(st[i]));
        }
        cout << mx << '\n';
    }
}