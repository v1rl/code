#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

template<class Info>
struct PresidentTree
{
    int n;
    int idx = 0;
    vector<Info> info;
    PresidentTree(int n_) : n(n_), info(n * 4 + n * (__lg(n) + 1) + 1) {};

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
        info[q] = info[p], info[q].act ++;
        if(l == r) return;
        int mid = l + r >> 1;
        if(v <= mid) modify(info[p].l, info[q].l, l, mid, v);
        else modify(info[p].r, info[q].r, mid + 1, r, v);
    }

    void modify(int p, int &q, const int &v)
    {
        modify(p, q, 1, n, v);
    }

    int query(int p, int q, int l, int r, int k)
    {
        if(l == r) return l;
        int mid = l + r >> 1;
        int sum = info[info[q].l].act - info[info[p].l].act;
        if(k <= sum) return query(info[p].l, info[q].l, l, mid, k);
        else return query(info[p].r, info[q].r, mid + 1, r, k - sum);
    }

    int query(int p, int q, int k)
    {
        return query(p, q, 1, n, k);
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
    vector<int> a(n);
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    unordered_map<int, int> mp;
    int cnt = 0;
    vector<int> val(n + 1);
    for(auto x : b)
    {
        if(!mp.count(x)) mp[x] = ++cnt;
        val[cnt] = x;
    }
    PresidentTree<Info> tr(n);
    vector<int> root(n + 1);
    root[0] = tr.build(1, cnt);
    for(int i = 0; i < n; i ++)
    {
        tr.modify(root[i], root[i + 1], mp[a[i]]);
    }
    while(q --)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << val[tr.query(root[l - 1], root[r], k)] << '\n';
    }
}