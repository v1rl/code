#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int inf = 1e9;
template<class Info>
struct SegmentTree
{
    int n;
    vector<Info> info;

    SegmentTree(int n_) : n(n_), info(4 * n) {};
    SegmentTree(vector<Info> a) : SegmentTree(a.size() - 1) 
    {
        function<void(int, int, int)> build = [&](int u, int l, int r)
        {
            if(l == r)
            {
                info[u] = a[l];
                return;
            }
            int mid = l + r >> 1;
            build(u << 1, l, mid);
            build(u << 1 | 1, mid + 1, r);
            pushup(u);
        };
        build(1, 1, n);
    }

    void pushup(int u)
    {
        info[u] = info[u << 1] + info[u << 1 | 1];
    }

    void modify(int u, int l, int r, int x, const int &v)
    {
        if(l == r)
        {
            info[u].apply(v);
            return;
        }
        int mid = l + r >> 1;
        if(x <= mid) modify(u << 1, l, mid, x, v);
        else modify(u << 1 | 1, mid + 1, r, x ,v);
        pushup(u);
    }

    void modify(int x, const int &v)
    {
        modify(1, 1, n, x, v);
    }

    Info query(int u, int l, int r, int x, int y)
    {
        if(r < x || l > y) return Info();
        if(x <= l && r <= y) return info[u];
        int mid = l + r >> 1;
        return query(u << 1, l, mid, x, y) + query(u << 1 | 1, mid + 1, r, x, y);
    }

    Info query(int x, int y)
    {
        return query(1, 1, n, x, y);
    }
};

struct Info
{
    int lsum = -inf;
    int rsum = -inf;
    int tsum = 0;
    int val = -inf;

    void apply(const int &v)
    {
        lsum = v;
        rsum = v;
        tsum = v;
        val = v;
    }
};

Info operator+(Info a, Info b)
{
    Info c;
    c.lsum = max(a.lsum, a.tsum + b.lsum);
    c.rsum = max(b.rsum, b.tsum + a.rsum);
    c.tsum = a.tsum + b.tsum;
    c.val = max(max(a.val, b.val), a.rsum + b.lsum);
    return c;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<Info> a(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        a[i] = {x, x, x, x};
    }
    SegmentTree<Info> tr(a);
    int m;
    cin >> m;
    while(m --)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1)
        {
            Info t = tr.query(l, r).tsum;
        }
        else
        {
            tr.modify(l, r);
        }
    }
    return 0;
}