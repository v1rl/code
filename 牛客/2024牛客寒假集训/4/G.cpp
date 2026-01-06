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
        // if(l == r)
        // {
        //     info[q].act ++;
        //     return;
        // }
        int mid = l + r >> 1;
        if(v <= mid) modify(info[p].l, info[q].l, l, mid, v);
        else modify(info[p].r, info[q].r, mid + 1, r, v);
        // info[q].act = info[info[q].l].act + info[info[q].r].act;
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

struct Node
{
    int val, id, l, r;
    bool operator <(const Node &W) const
    {
        return val < W.val;
    }
};

void solve()
{
    int n, mod, k;
    cin >> n >> mod >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        a[i] %= mod;
    }
    vector<array<int, 2>> range(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    vector<int> b = a;
    sort(b.begin() + 1, b.end());
    unordered_map<int, int> mp;
    vector<int> val(n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(!mp.count(b[i])) mp[b[i]] = ++cnt;
        val[cnt] = b[i];
    }
    PresidentTree<Info> tr(cnt, n);
    vector<int> root(n + 1);
    root[0] = tr.build(1, cnt);
    for(int i = 1; i <= n; i ++)
    {
        tr.modify(root[i - 1], root[i], mp[a[i]]);
    }

    priority_queue<Node, vector<Node>> heap;
    for(int i = 1; i <= n; i ++)
    {
        auto [l, r] = range[i];
        int ll = 1, rr = r - l + 1;
        while(ll < rr)
        {
            int mid = ll + rr >> 1;
            if(a[i] + val[tr.query(root[l - 1], root[r], mid)] >= mod) rr = mid;
            else ll = mid + 1;
        }
        int pos;
        if(a[i] + val[tr.query(root[l - 1], root[r], ll)] < mod)
        {
            pos = ll;
        }
        else
        {
            if(ll > 1) pos = ll - 1;
            else pos = 0;
        }
        if(pos > 0) 
        {
            heap.push({a[i] + val[tr.query(root[l - 1], root[r], pos)], i, 1, pos});
        }
        if(pos != r - l + 1)
        {
            heap.push({(a[i] + val[tr.query(root[l - 1], root[r], r - l + 1)]) % mod, i, pos + 1, r - l + 1});
        }
    }

    vector<int> ans;
    ans.reserve(k);
    while(ans.size() < k && !heap.empty())
    {
        auto [v, id, l, r] = heap.top();
        heap.pop();
        ans.emplace_back(v);
        if(r - 1 >= l)
        {
            heap.push({(a[id] + val[tr.query(root[range[id][0] - 1], root[range[id][1]], r - 1)]) % mod, id, l, r - 1});
        }
    }
    while(ans.size() < k) ans.emplace_back(-1);
    for(auto x : ans)
        cout << x << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}