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
    vector<int> b = a;
    sort(b.begin() + 1, b.end());
    unordered_map<int, int> mp;
    vector<int> val(n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(!mp.count(b[i])) mp[b[i]] = ++ cnt;
        val[cnt] = b[i];
    }
    PresidentTree<Info> tr(n, n);
    vector<int> root(n + 1);
    root[0] = tr.build(1, cnt);
    for(int i = 1; i <= n; i ++)
    {
        tr.modify(root[i - 1], root[i], mp[a[i]]);
    }

    for(int i = 1; i <= n; i ++)
    {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }


    auto work1 = [&](int x)
    {
        i64 res = 0;
        for(int i = 1; i <= n; i ++)
        {
            auto [l, r] = range[i];
            int ll = 1, rr = r - l + 1;
            while(ll < rr)
            {
                int mid = (ll + rr + 1) >> 1;
                if(a[i] + val[tr.query(root[l - 1], root[r], mid)] <= x) ll = mid;
                else rr = mid - 1;
            }
            res += r - l + 1 - ll;
            if(a[i] + val[tr.query(root[l - 1], root[r], ll)] > x) res ++; 
        }
        return res;
    };

    auto work2 = [&](int x)
    {
        i64 res = 0;
        for(int i = 1; i <= n; i ++)
        {
            auto [l, r] = range[i];
            int ll = 1, rr = r - l + 1;
            while(ll < rr)
            {
                int mid = ll + rr >> 1;
                if(a[i] + val[tr.query(root[l - 1], root[r], mid)] >= x) rr = mid;
                else ll = mid + 1;
            }
            res += (r - l + 1 - ll + 1);
            if(a[i] + val[tr.query(root[l - 1], root[r], rr)] < x) res --;
        }
        return res;
    };


    auto check = [&](int x)
    {
        return work1(x) - work2(mod) + work1(x + mod);
    };

    int l = -1, r = mod - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid) <= k - 1) r = mid;
        else l = mid + 1;
    }

    int tag = l;

    vector<int> ans;
    for(int i = 1; i <= n; i ++)
    {
        auto [l, r] = range[i];
        int ll = 1, rr = r - l + 1;
        while(ll < rr)
        {
            int mid = (ll + rr + 1) >> 1;
            if(a[i] + val[tr.query(root[l - 1], root[r], mid)] <= tag) ll = mid;
            else rr = mid - 1;
        }
        int pos1 = ll;

        ll = 1, rr = r - l + 1;
        while(ll < rr)
        {
            int mid = (ll + rr + 1) >> 1;
            if(a[i] + val[tr.query(root[l - 1], root[r], mid)] <= tag + mod) ll = mid;
            else rr = mid - 1;
        }
        int pos2 = ll;

        if(a[i] + val[tr.query(root[l - 1], root[r], pos1)] > tag && a[i] + val[tr.query(root[l - 1], root[r], pos1)] < mod) 
            ans.emplace_back((a[i] + val[tr.query(root[l - 1], root[r], pos1)]) % mod);
        for(int j = pos1 + 1; j <= r - l + 1; j ++)
        {
            int t = a[i] + val[tr.query(root[l - 1], root[r], j)];
            if(t >= mod) break;
            ans.emplace_back(t);
        }        

        if(a[i] + val[tr.query(root[l - 1], root[r], pos2)] > tag + mod) 
            ans.emplace_back((a[i] + val[tr.query(root[l - 1], root[r], pos2)]) % mod);
        for(int j = pos2 + 1; j <= r - l + 1; j ++)
        {
            ans.emplace_back((a[i] + val[tr.query(root[l - 1], root[r], j)]) % mod);
        }
    }

    sort(ans.begin(), ans.end(), greater<int>());
    while(ans.size() < k) ans.emplace_back(tag);
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