#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Info
{
    int l, r;
    int act = 0;
}info[30000000];

// 带修主席树

template<class Info>
struct wSegmentree
{
    int n;
    int idx = 0;
    wSegmentree(int n_) : n(n_) {};
    
    void modify(int &p, int l, int r, int x, int d)
    {
        if(!p) p = ++ idx;
        info[p].act += d;
        if(l == r) return;
        int mid = l + r >> 1;
        if(x <= mid) modify(info[p].l, l, mid, x, d);
        else modify(info[p].r, mid + 1, r, x, d);
    }

    void modify(int &p, int x, int d)
    {
        modify(p, 1, n, x, d);
    }

    int query(vector<int> &p, vector<int> &q, int l, int r, int k)
    {
        if(l == r) return l;
        int mid = l + r >> 1;

        int sum = 0;
        for(auto root : p)
            sum -= info[info[root].l].act;
        for(auto root : q)
            sum += info[info[root].l].act;

        if(k <= sum)
        {
            for(auto &root : p)
                root = info[root].l;
            for(auto &root : q)
                root = info[root].l;
            return query(p, q, l, mid, k);
        }
        else
        {
            for(auto &root : p)
                root = info[root].r;
            for(auto &root : q)
                root = info[root].r;
            return query(p, q, mid + 1, r, k - sum);
        }
    }

    int query(vector<int> &p, vector<int> &q, int k)
    {
        return query(p, q, 1, n, k);
    }
};

struct Fenwick
{
    int n;
    vector<int> root;
    wSegmentree<Info> tr;

    Fenwick(int n_, int q) : n(n_), root(n + 1), tr(n + q) {};

    void add(int id, int x, int op)
    {
        for(int i = id; i <= n; i += i & -i)
        {
            tr.modify(root[i], x, op);
        }
    }

    int kth(int l, int r, int k)
    {
        vector<int> rtl, rtr;
        rtl.reserve(__lg(n) + 1);
        for(int i = l - 1; i; i -= i & -i)
            rtl.emplace_back(root[i]);
        for(int i = r; i; i -= i & -i)
            rtr.emplace_back(root[i]);

        return tr.query(rtl, rtr, k);
    }
};

struct dat
{
    char op;
    int l, r, k = 0;
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> b;
    b.reserve(n + q);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        b.emplace_back(a[i]);
    }

    vector<dat> query;
    query.reserve(q);
    for(int i = 1; i <= q; i ++)
    {
        char op;
        cin >> op;
        if(op == 'Q')
        {
            int l, r, k;
            cin >> l >> r >> k;
            query.push_back({op, l, r, k});
        }
        else
        {
            int x, y;
            cin >> x >> y;
            query.push_back({op, x, y});
            b.emplace_back(y);
        }        
    }

    sort(b.begin(), b.end());
    unordered_map<int, int> mp;
    int cnt = 0;
    vector<int> val(n + q + 1);
    for(auto x : b)
    {
        if(!mp.count(x)) mp[x] = ++cnt;
        val[cnt] = x;
    }

    Fenwick tr(n, cnt);
    for(int i = 1; i <= n; i ++)
    {
        tr.add(i, mp[a[i]], 1);
    }

    for(auto &[op, l, r, k] : query)
    {
        if(op == 'Q')
        {
            cout << val[tr.kth(l, r, k)] << '\n';
        }
        else
        {
            tr.add(l, mp[a[l]], -1);
            tr.add(l, mp[r], 1);
            a[l] = r;
        }
    }
}