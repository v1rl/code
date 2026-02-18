#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

/*
考虑将直觉上的交叉或整体左右关系转换为数学上的区间关系
于是，题意可转换为新加入的区间[l, r]内部区间与它的关系只能是包含
注意到：这样的关系可以转换为区间[l, r]之间只能存在成对的区间端点
于是，对区间的两个端点做异或哈希，然后放到可以区间查询异或和的树状数组中即可
*/

template<class T>
struct Fenwick {
    int n;
    vector<T> a;

    Fenwick(int n_) : n(n_), a(n + 1) {};

    void add(int x, const T &v) {
        for(int i = x; i <= n; i += i & -i) {
            a[i] ^= v;
        }
    }

    T sum(int x) {
        T res{};
        for(int i = x; i; i -= i & -i) {
            res ^= a[i];
        }
        return res;
    }

    T rangeSum(int l, int r) {
        return sum(r) ^ sum(l - 1);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    Fenwick<u64> tr(n);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    while(q --) {
        int x, y;
        cin >> x >> y;
        if(!tr.rangeSum(x, y)) {
            cout << "Yes" << '\n';
            u64 r = rng();
            tr.add(x, r);
            tr.add(y, r);
        } else {
            cout << "No" << '\n';
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