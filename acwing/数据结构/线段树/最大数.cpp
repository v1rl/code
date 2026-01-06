#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

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
    int mx = 0;
    void apply(const int &v)
    {
        mx = v;
    }
};

Info operator+(Info a, Info b)
{
    Info c;
    c.mx = max(a.mx, b.mx);
    return c;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, mod;
    cin >> n >> mod;
    int cnt = 0;
    SegementTree<Info> tr(n);
    int last = 0;
    for(int i = 1; i <= n; i ++)
    {
        char op;
        cin >> op;
        if(op == 'A')
        {
            int x;
            cin >> x;
            int v = (x + last) % mod;
            tr.modify(++cnt, v);
        }
        else
        {
            int len;
            cin >> len;
            last = tr.query(cnt - len + 1, cnt).mx;
            cout << last << '\n';
        }
    }
    return 0;
}