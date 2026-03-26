#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

template<typename T>
struct Fenwick {
    int n;
    vector<T> a;

    Fenwick(int n_) : n(n_), a(n + 1) {};

    void add(int x, const T &v) {
        for(int i = x; i <= n; i += i & -i)
            a[i] += v;
    }

    T sum(int x) {
        T res{};
        for(int i = x; i; i -= i & -i)
            res += a[i];
        return res;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Fenwick<i64> tr(n);

    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        tr.add(i, x);
    }

    vector<array<i64, 3>> stk;
    i64 t = 0;
    while(m --) {
        int op;
        cin >> op;
        if(op == 1) {
            i64 l, r, k;
            cin >> l >> r >> k;
            stk.push_back({l, r, t});
            t += k;
            tr.add(l, r);
        } else if(op == 2) {
            i64 k;
            cin >> k;
            t -= k;
            while(stk.size() && stk.back()[2] > t) {
                auto [l, r, _] = stk.back();
                stk.pop_back();
                tr.add(l, -r);
            }
        } else if(op == 3) {
            int l, r;
            cin >> l >> r;
            cout << tr.rangeSum(l, r) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }


    return 0;
}
