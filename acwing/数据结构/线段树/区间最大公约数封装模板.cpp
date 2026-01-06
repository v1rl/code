#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 gcd(i64 a, i64 b)
{
    return b ? gcd(b, a % b) : a;
}

template<class Info>
struct SegmentTree
{
    int n;
    vector<Info *> info;
    SegmentTree(int n_) : n(n_), info(4 * n) {};
    SegmentTree(vector<i64> a) : SegmentTree(a.size() - 1)
    {
        function<void(int, int, int)> build = [&](int u, int l, int r)
        {
            if(l == r)
            {
                (*info[u]).apply(a[l]);
                return;
            }
            int mid = l + r >> 1;
            if(info[u << 1] == NULL) info[u << 1] = new Info();
            if(info[u << 1 | 1] == NULL) info[u << 1 | 1] = new Info();
            build(u << 1, l, mid);
            build(u << 1 | 1, mid + 1, r);
            pushup(u);
        };
        info[1] = new Info();
        build(1, 1, n);
    }

    void pushup(int u)
    {
        *info[u] = *info[u << 1] + *info[u << 1 | 1];
    }

    void modify(int x, const i64 &v)
    {
        modify(1, 1, n, x, v);
    }

    void modify(int u, int l, int r, int x, const i64 &v)
    {
        if(l == r)
        {
            (*info[u]).apply(v);
            return;
        }
        int mid = l + r >> 1;
        if(x <= mid) modify(u << 1, l, mid, x, v);
        else modify(u << 1 | 1, mid + 1, r, x, v);
        pushup(u);
    }

    Info query(int x, int y)
    {
        return query(1, 1, n, x, y);
    }

    Info query(int u, int l, int r, int x, int y)
    {
        if(r < x || l > y) return Info();
        if(x <= l && r <= y) return *info[u];
        int mid = l + r >> 1;
        return query(u << 1, l, mid, x, y) + query(u << 1 | 1, mid + 1, r, x, y);
    }
};

struct Info
{
    i64 sgcd = 0;
    i64 sum = 0;

    Info(i64 x = 0) : sgcd(x), sum(x){};

    void apply(i64 x)
    {
        sgcd += x;
        sum += x;
    }
};

Info operator+(Info a, Info b)
{
    Info c;
    c.sgcd = gcd(a.sgcd, b.sgcd);
    c.sum = a.sum + b.sum;
    return c;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<i64> a(n + 2);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = n; i >= 1; i --) a[i] -= a[i - 1]; 
    SegmentTree<Info> tr(a);
    while(m --)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if(c == 'Q')
        {
            Info t1 = tr.query(l + 1, r);
            Info t2 = tr.query(1, l);
            cout << abs(gcd(t1.sgcd, t2.sum)) << '\n';
        }
        else
        {
            i64 add;
            cin >> add;
            tr.modify(l, add);
            tr.modify(r + 1, -add);
        }
    }
    return 0;
}