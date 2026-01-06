#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://www.luogu.com.cn/problem/P8769

#define int long long

/*
价格从小到大排序

5 5 2 2 3
*/

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
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(m);
    for(int i = 0; i < m; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = {x, y, z};
    }

    sort(a.begin(), a.end());
    vector<int> st(n + 1);
    Fenwick<int> tr(n + 1);

    i64 ans = 0;
    int mx = n;

    for(auto [p, d, c] : a) {
        if(d > mx) {
            ans += 1ll * min(n, c) * p;
            n -= min(n, c);
            tr.add(mx, min(n, c));
            continue;
        }
        if(tr.sum(d) >= d) {
            // cout << tr.sum(d) << ' ' << d << '\n';
            continue;
        }
        int sel = min({c, n, d - tr.sum(d)});
        // cout << sel << ' ' << d << ' ' << p << '\n';
        ans += 1ll * p * sel;
        n -= sel;
        tr.add(d, sel);
    }

    if(n > 0) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}