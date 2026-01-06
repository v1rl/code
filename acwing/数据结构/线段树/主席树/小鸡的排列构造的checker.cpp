#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

template<class Info>
struct PresidentTree
{
    int n;
    int idx = 0;
    vector<Info> info;
    PresidentTree(int n_, int q) : n(n_), info(n * 4 + q * (__lg(n) + 2) + 1) {};

    int build(int l, int r)
    {
        int p = ++ idx;
        if(l == r) return p;
        int mid = l + r >> 1;
        info[p] = {build(l, mid), build(mid + 1, r)};
        return p;
    }

    void modify(int p, int &q, int l, int r, const int &v)
    {
        q = ++ idx;
        info[q] = info[p];
        info[q].act ++;
        if(l == r) return;
        int mid = l + r >> 1;
        if(v <= mid) modify(info[p].l, info[q].l, l, mid, v);
        else modify(info[p].r, info[q].r, mid + 1, r, v);
    }

    void modify(int p, int &q, const int &v)
    {
        modify(p, q, 1, n, v);
    }

    int query(int p, int q, int l, int r, int x, int y)
    {
        if(x <= l && r <= y) return info[q].act - info[p].act;
        if(r < x || l > y) return 0;
        int mid = l + r >> 1;
        return query(info[p].l, info[q].l, l, mid, x, y) + query(info[p].r, info[q].r, mid + 1, r, x, y);
    }

    int query(int p, int q, int x, int y)
    {
        return query(p, q, 1, n, x, y);
    }
};

struct Info
{
    int l, r;
    int act = 0;
};

void solve()
{
    int n, q;
    cin >> n >> q;
    PresidentTree<Info> tr(n, n);
    vector<int> root(n + 1);
    root[0] = tr.build(1, n);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        tr.modify(root[i - 1], root[i], a[i]);
    }
    while(q --)
    {
        int l, r, pos;
        cin >> l >> r >> pos;
        int x = a[pos];
        int t = tr.query(root[l - 1], root[r], 1, x - 1);
        cout << l + t << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
}
