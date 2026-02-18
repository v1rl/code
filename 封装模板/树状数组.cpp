
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

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

    int upper_bound(const T &k) {          //针对普通前缀和树状数组
        int pos = 0;
        T cur{};
        for(int i = 1 << __lg(n); i; i >>= 1) {      //前缀和小于等于 k 的最大下标位置
            if(pos + i <= n && cur + a[pos + i] <= k) {
                pos += i;
                cur += a[pos];
            }
        }
        return pos + 1;
    }

    int kth(int k) {                //针对权值树状数组 
        int pos = 0;
        T cur{};
        for(int i = 1 << __lg(n); i; i >>= 1) {
            if(pos + i <= n && cur + a[pos + i] < k) {   // 第k - 1大数
                pos += i;
                cur += a[pos];
            }
        }
        return pos + 1;
    }

    int pre(int x) {
        int cnt = sum(x - 1);
        if(cnt == 0) {
            return -1;
        }
        return kth(cnt);
    }

    int suf(int x) {
        int cnt = sum(x);
        int tot = sum(n);
        if(cnt == tot) {
            return -1;
        }
        return kth(cnt + 1);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    Fenwick<int> tr(n);
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        tr.add(i, x);
        // tr.add(x, 1);
    }
    cout << tr.rangeSum(1, 5) << '\n';
    cout << tr.upper_bound(6) << '\n';
    // cout << tr.kth(5) << '\n';
}