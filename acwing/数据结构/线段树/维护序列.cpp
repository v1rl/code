#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
const i64 inf = 1e18;
int mod;

template<class Info, class Tag>
struct LazySegmentTree
{
    int n;
    vector<Info> info;
    vector<Tag> tag;

    LazySegmentTree(int n_) : n(n_), info(n * 4 + 1), tag(n * 4 + 1) {};
    LazySegmentTree(vector<Info> a) : LazySegmentTree(a.size() - 1)
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

    void apply(int p, const Tag &t)
    {
        info[p].apply(t);
        tag[p].apply(t);
    }

    void pushdown(int p)
    {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag();
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &t)
    {
        if(y < l || x > r) return;
        if(x <= l && r <= y)
        {
            apply(p, t);
            return;
        }
        int mid = l + r >> 1;
        pushdown(p);
        rangeApply(p << 1, l, mid, x, y, t);
        rangeApply(p << 1 | 1, mid + 1, r, x, y, t);
        pushup(p);
    }

    void rangeApply(int x, int y, const Tag &t)
    {
        rangeApply(1, 1, n, x, y, t);
    }

    Info query(int p, int l, int r, int x, int y)
    {
        if(y < l || x > r) return Info();
        if(x <= l && r <= y) return info[p];
        int mid = l + r >> 1;
        pushdown(p);
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid + 1, r, x, y);
    }

    Info query(int x, int y)
    {
        return query(1, 1, n, x, y);
    }
};

struct Tag
{
    i64 add = 0;
    i64 mul = 1;

    void apply(const Tag &t)
    {
        add = (add * t.mul % mod + t.add) % mod;
        mul = mul * t.mul % mod;
    }
};

struct Info
{
    i64 sum = 0;
    i64 act = 0;

    void apply(const Tag &t)
    {
        sum = (sum * t.mul % mod + t.add * act % mod) % mod;
    }
};

Info operator+(Info a, Info b)
{
    Info c;
    c.act = a.act + b.act;
    c.sum = (a.sum + b.sum) % mod;
    return c;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n >> mod;
    vector<Info> a(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        a[i] = {x, 1};
    }
    LazySegmentTree<Info, Tag> tr(a);
    int q;
    cin >> q;
    while(q --)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            Tag t = {0, x};
            tr.rangeApply(l, r, t);
        }
        else if(op == 2)
        {
            int l, r, x;
            cin >> l >> r >> x;
            Tag t = {x, 1};
            tr.rangeApply(l, r, t);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << tr.query(l, r).sum << '\n';
        }
    }
}