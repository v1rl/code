#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

struct DSU
{
    vector<int> p;
    vector<int> siz;

    DSU(int n)
    {
        init(n);
    }

    int find(int x)
    {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    void init(int n)
    {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        siz.assign(n + 1, 1);
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
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    unordered_map<int, int> mp;
    int cnt = 0;
    DSU dsu(n);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        if(!mp.count(a[i])) 
            mp[a[i]] = ++cnt;
        int x = mp[a[i]];
        int y = mp[a[i] + k];
        int z = mp[a[i] - k];
        if(y) dsu.merge(x, y);
        if(z) dsu.merge(x, z);
    }
    vector<int> b = a;
    sort(b.begin() + 1, b.end());

    for(int i = 1; i <= min(n, k); i ++)
    {
        vector<int> p, q;
        for(int j = i; j <= n; j += k)
        {
            p.emplace_back(dsu.find(mp[a[j]]));
            q.emplace_back(dsu.find(mp[b[j]]));
        }
        sort(q.begin(), q.end());
        sort(p.begin(), p.end());
        for(int i = 0; i < q.size(); i ++)
        {
            if(p[i] != q[i])
            {
                cout << "No" << '\n';
                return;
            }
        }
    }
    cout << "Yes" << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    t = 1;
    // cin >> t;
    while(t --)
    {
        solve();
    }
}