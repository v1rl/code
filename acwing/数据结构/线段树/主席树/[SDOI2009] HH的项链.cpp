#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6 + 10;

template<class Info>
struct PresidentTree
{
    int n;
    int idx = 0;
    vector<Info> info;
    PresidentTree(int n_) : n(n_), info(n * (__lg(n) + 2) + 1) {};

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
        if(r < x || l > y) return 0;
        if(x <= l && r <= y) return info[q].act - info[p].act;
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

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> root(n + 1);
    vector<int> lst(N);
    PresidentTree<Info> tr(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        tr.modify(root[i - 1], root[i], lst[x] + 1);
        lst[x] = i;
    }


    int m;
    cin >> m;
    while(m --)
    {
        int l, r;
        cin >> l >> r;
        cout << tr.query(root[l - 1], root[r], 1, l) << '\n';
    }
    return 0;
}