#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

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

    int kth(int p, int q, int l, int r, int k)
    {
        if(l == r) return l;
        int mid = l + r >> 1;
        int sum = info[info[q].l].act - info[info[p].l].act;
        if(k <= sum) return kth(info[p].l, info[q].l, l, mid, k);
        else return kth(info[p].r, info[q].r, mid + 1, r, k - sum);
    }

    int kth(int p, int q, int k)
    {
        return kth(p, q, 1, n, k);
    }

    int query(int p, int q, int l, int r, int x, int y)
    {
        if(r < x || l > y) return 0;
        if(x <= l && y >= r) return info[q].act - info[p].act;
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
    ios::sync_with_stdio(false), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    vector<int> kth = a;
    sort(kth.begin() + 1, kth.end());
    kth.erase(unique(kth.begin() + 1, kth.end()), kth.end());
    // int cnt = kth.size() - 1;
    auto rank = [&](int x)
    {
        return lower_bound(kth.begin() + 1, kth.end(), x) - kth.begin();
    };

    PresidentTree<Info> tr(n);
    vector<int> root(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        tr.modify(root[i - 1], root[i], rank(a[i]));
    }
    while(q --)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << kth[tr.kth(root[l - 1], root[r], k)] << '\n';
        // cout << tr.query(root[l - 1], root[r], mp[1], mp[3]) << '\n';
    }
}