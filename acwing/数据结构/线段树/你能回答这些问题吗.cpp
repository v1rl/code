#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
const i64 inf = 1e18;

template<class Info>
struct SegementTree
{
    int n;
    vector<Info> info;

    SegementTree(int n_) : n(n_), info(4 * n + 1) {};
    SegementTree(vector<Info> a) : SegementTree(a.size() - 1)
    {
        function<void(int, int, int)> build = [&](int p, int l, int r)
        {
            if(l == r)
            {
                info[p] = a[l];
                return;
            }
            int mid = l + r >> 1;
            build(p << 1, l, mid);
            build(p << 1 | 1, mid + 1, r);
            pushup(p);
        };
        build(1, 1, n);
    }

    void pushup(int p)
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }

    void modify(int p, int l, int r, int x, const int &v)
    {
        if(l == r)
        {
            info[p].apply(v);
            return;
        }
        int mid = l + r >> 1;
        if(x <= mid) modify(p << 1, l, mid, x, v);
        else modify(p << 1 | 1, mid + 1, r, x, v);
        pushup(p);
    }

    void modify(int x, const int &v)
    {
        modify(1, 1, n, x, v);
    }

    Info query(int p, int l, int r, int x, int y)
    {
        if(x <= l && r <= y) return info[p];
        if(y < l || x > r) return Info();
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid + 1, r, x, y);
    }

    Info query(int l, int r)
    {
        return query(1, 1, n, l, r);
    }
};

struct Info
{
    i64 lmax = -inf;
    i64 rmax = -inf;
    i64 total = 0;
    i64 tmax = -inf;
    void apply(const int &v)
    {
        lmax = v;
        rmax = v;
        total = v;
        tmax = v;
    }
};

Info operator+(Info a, Info b)
{
    Info c;
    c.lmax = max(a.lmax, a.total + b.lmax);
    c.rmax = max(b.rmax, b.total + a.rmax);
    c.total = a.total + b.total;
    c.tmax = max({a.tmax, b.tmax, a.rmax + b.lmax});
    return c;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<Info> a(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        a[i].apply(x);
    }
    SegementTree<Info> tr(a);
    while(q --)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int l, r;
            cin >> l >> r;
            if(l > r) swap(l, r);
            cout << tr.query(l, r).tmax << '\n';
        }
        else
        {
            int x, v;
            cin >> x >> v;
            tr.modify(x, v);
        }
    }
    return 0;
}