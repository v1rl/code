#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

// 离线做法，提前将需要的数全部离散化

template<typename T>
struct Fenwick
{
    int n;
    vector<T> a;

    Fenwick(int n_) : n(n_), a(n + 1) {};

    void add(int x, const T &v)
    {
        for(int i = x; i <= n; i += i & -i)
            a[i] += v;
    }

    T sum(int x)
    {
        T res{};
        for(int i = x; i; i -= i & -i)
            res += a[i];
        return res;
    }

    T rangeSum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    int kth(int k)                //针对权值树状数组
    {
        int pos = 0;
        T cur{};
        for(int i = 1 << __lg(n); i; i >>= 1)
        {
            if(pos + i <= n && cur + a[pos + i] < k)    //第k - 1大数
            {
                pos += i;
                cur += a[pos];
            }
        }
        return pos + 1;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<i64> a(n + 1);
    vector<i64> kth;
    kth.reserve(n + q + 1);
    kth.emplace_back(0);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        kth.emplace_back(a[i]);
    }
    vector<i64> b = a;

    vector<array<int, 2>> query;
    query.reserve(q);
    while(q --) {
        int x, y;
        cin >> x >> y;
        query.push_back({x, y});
        b[x] += y;
        kth.emplace_back(b[x]);
    }

    sort(kth.begin() + 1, kth.end());
    kth.erase(unique(kth.begin() + 1, kth.end()), kth.end());

    auto rank = [&](i64 x) {
        return lower_bound(kth.begin() + 1, kth.end(), x) - kth.begin();
    };

    Fenwick<int> tr(kth.size());
    for(int i = 1; i <= n; i ++) {
        tr.add(rank(a[i]), 1);
    }

    for(auto [x, y] : query)
    {
        tr.add(rank(a[x]), -1);
        a[x] += y;
        tr.add(rank(a[x]), 1);

        int pos = (n + 1) / 2;
        int md = tr.kth(pos);
        int t = tr.kth(pos + 1);
        if(md != t) {
            cout << pos << '\n';
        } else {
            int l = 1, r = pos;
            while(l < r) {
                int mid = l + r >> 1;
                if(tr.kth(mid) == md) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            cout << l - 1 << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t --) {
        solve();
    }
}