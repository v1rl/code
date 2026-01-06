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

    void modify(int p, int l, int r, int x, const i64 &v)
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

    void modify(int x, const i64 &v)
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
    i64 sum = 0;
    i64 gcd = 0;
    void apply(const i64 &v)
    {
        sum += v;
        gcd += v;
    }
};

Info operator+(Info a, Info b)
{
    Info c;
    c.sum = a.sum + b.sum;
    c.gcd = __gcd(a.gcd, b.gcd);
    return c;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<i64> b(n + 2);
    vector<Info> a(n + 2);
    for(int i = 1; i <= n; i ++)
    {
        cin >> b[i];
        a[i].apply(b[i] - b[i - 1]);
    }
    SegementTree<Info> tr(a);
    while(q --)
    {
        char op;
        cin >> op;
        if(op == 'Q')
        {
            int l, r;
            cin >> l >> r;
            Info t1 = tr.query(1, l);
            Info t2 = tr.query(l + 1, r);
            cout << abs(__gcd(t1.sum, t2.gcd)) << '\n';
        }
        else
        {
            int l, r;
            i64 v;
            cin >> l >> r >> v;
            tr.modify(l, v);
            tr.modify(r + 1, -v);
        }
    }
    return 0;
}