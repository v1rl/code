#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

template<class Info>
struct PresidentTree
{
    int n;
    int idx = 0;
    vector<Info> info;
    PresidentTree(int n_, int q) : n(n_), info(n * 4 + q * (__lg(n) + 1) + 1) {};

    int build(vector<int> &a, int l, int r)
    {
        int p = ++ idx;
        if(l == r) 
        {
            info[p].val = a[l];
            return p;
        }
        int mid = l + r >> 1;
        info[p] = {build(a, l, mid), build(a, mid + 1, r)};
        return p;
    }

    void modify(int p, int &q, int l, int r, const int &pos, const int &v)
    {
        q = ++ idx;
        info[q] = info[p];
        if(l == r) 
        {
            info[q].val = v;
            return;
        }
        int mid = l + r >> 1;
        if(pos <= mid) modify(info[p].l, info[q].l, l, mid, pos, v);
        else modify(info[p].r, info[q].r, mid + 1, r, pos, v);
    }

    void modify(int p, int &q, const int &pos, const int &v)
    {
        modify(p, q, 1, n, pos, v);
    }

    int query(int p, int l, int r, const int &pos)
    {
        if(l == r) return info[p].val;
        int mid = l + r >> 1;
        if(pos <= mid) return query(info[p].l, l, mid, pos);
        else return query(info[p].r, mid + 1, r, pos);
    }

    int query(int p, const int &pos)
    {
        return query(p, 1, n, pos);
    }
};

struct Info
{
    int l, r;
    int val;
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    PresidentTree<Info> tr(n, q);
    vector<int> root(q + 1);
    root[0] = tr.build(a, 1, n);
    for(int i = 1; i <= q; i ++)
    {
        int p, op, pos;
        cin >> p >> op >> pos;
        if(op == 1)
        {
            int v;
            cin >> v;
            tr.modify(root[p], root[i], pos, v);
        }
        else
        {
            root[i] = root[p];
            cout << tr.query(root[p], pos) << '\n';
        }
    }
}