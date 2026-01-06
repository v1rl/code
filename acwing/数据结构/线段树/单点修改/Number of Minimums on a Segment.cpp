#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
template<class Info>
struct Segmentree
{
    int n;
    vector<Info> info;

    Segmentree(int n_) : n(n_), info(4 * n + 1) {};
    Segmentree(vector<Info> &a) : Segmentree(a.size() - 1)
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

    void modify(int p, int l, int r, int pos, int x)
    {
        if(l == r)
        {
            info[p].apply(x);
            return;
        }
        int mid = l + r >> 1;
        if(pos <= mid) modify(p << 1, l, mid, pos, x);
        else modify(p << 1 | 1, mid + 1, r, pos, x);
        pushup(p);
    }

    void modify(int pos, int x)
    {
        modify(1, 1, n, pos, x);
    }

    Info query(int p, int l, int r, int x, int y)
    {
        if(r < x || l > y) return Info();
        if(x <= l && r <= y) return info[p];
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid + 1, r, x, y);
    }

    Info query(int x, int y)
    {
        return query(1, 1, n, x, y);
    }
};

struct Info
{
    int mn = 1e9;
    int num = 0;

    void apply(int x)
    {
        mn = x;
    }
};

Info operator+(Info a, Info b)
{
    Info c;
    c.mn = min(a.mn, b.mn);
    if(a.mn == c.mn) c.num += a.num;
    if(b.mn == c.mn) c.num += b.num;
    return c;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Info> a(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        a[i] = {x, 1};
    }
    Segmentree<Info> tr(a);

    while(m --)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int pos, x;
            cin >> pos >> x;
            pos ++;
            tr.modify(pos, x);
        }
        else if(op == 2)
        {
            int l, r;
            cin >> l >> r;
            l ++;
            auto t = tr.query(l, r);
            cout << t.mn << ' ' << t.num << '\n';
        }
    }
    return 0;
}