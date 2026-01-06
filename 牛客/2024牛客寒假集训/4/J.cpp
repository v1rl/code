#include <bits/stdc++.h>
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
        if(x > y) swap(x, y);
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n + 1);
    DSU dsu(n);
    for(int i = 1; i <= m; i ++)
    {
        int x, y;
        cin >> x >> y;
        dsu.merge(x, y);
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<array<int, 2>> block;
    block.reserve(n);
    for(int i = 1; i <= n; i ++)
    {
        if(dsu.p[i] == i)
        {
            block.push_back({dsu.size(i), i});
        }
    }

    sort(block.begin(), block.end(), 
        [&](array<int, 2> a, array<int, 2> b)
        {
            if(a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });

    int num = k - block.size();

    i64 res = 0;
    vector<int> dat;
    for(int i = 0; i < k && i < block.size(); i ++)
    {
        auto [siz, id] = block[i];
        res += siz;
        dat.emplace_back(id);
    }

    auto bfs = [&]()
    {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> heap;
        vector<int> st(n + 1);
        int cnt = 0;
        for(auto x : dat)
        {
            heap.push(x);
            st[x] = true;
        }
        while(heap.size())
        {
            if(num > 0 && res.size() + 1 <= n && heap.top() != res.size() + 1)
            {
                heap.push(res.size() + 1);
                st[res.size() + 1] = true;
                num --;
            }
            int x = heap.top();
            heap.pop();
            res.emplace_back(x);
            for(auto y : adj[x])
            {
                if(st[y]) continue;
                st[y] = true;
                heap.push(y);
            }
        }
        return res;
    };

    vector<int> ans = bfs();

    cout << res << '\n';
    for(auto x : ans)
    {
        cout << x << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}