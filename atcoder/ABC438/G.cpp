#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
离散化
将B拆分成g个独立的环，重排B以支持区间查询，维护从原下标到重拍后下标的映射数组
遍历A，处理每个A对B的匹配，存储需要的查询
按莫队重排查询
处理查询，输出结果
*/

const int mod = 998244353;

template<class T>
struct Fenwick {
    int n;
    vector<T> a;

    Fenwick(int n_) : n(n_), a(n + 1) {};

    void add(int x, T v) {
        for(int i = x; i <= n; i += i & -i) {
            a[i] += v;
        }
    }

    T sum(int x) {
        T res{};
        for(int i = x; i; i -= i & -i) {
            res += a[i];
        }
        return res;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

void solve() {
    int n, m;
    i64 k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    vector<int> kth;
    kth.reserve(n + m);

    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        kth.emplace_back(a[i]);
    }
    for(int i = 0; i < m; i ++) {
        cin >> b[i];
        kth.emplace_back(b[i]);
    }

    sort(kth.begin(), kth.end());
    kth.erase(unique(kth.begin(), kth.end()), kth.end());
    auto rank = [&](int x) {
        return lower_bound(kth.begin(), kth.end(), x) - kth.begin() + 1;
    };

    for(int i = 0; i < n; i ++) {
        a[i] = rank(a[i]);
    }
    for(int i = 0; i < m; i ++) {
        b[i] = rank(b[i]);
    }


    int S = kth.size();

    int g = gcd(n, m);
    vector<int> pos(m, -1), seq;
    for(int i = 0; i < g; i ++) {
        for(int j = i; pos[j] == -1; j = (j + n) % m) {
            pos[j] = seq.size();
            seq.emplace_back(b[j]);
        }
    }

    int len = m / g;

    vector<array<int, 4>> query;
    for(int i = 0; i < min<i64>(n, k); i ++) {
        i64 c = (k - i - 1) / n + 1;
        int p = pos[i % m];
        int l = p / len * len, r = l + len;

        i64 full = c / len;
        int rem = c % len;

        if(full) {
            query.push_back({l, r, a[i], full % mod});
        }
        if(rem) {
            if(p + rem < r) {
                query.push_back({p, p + rem, a[i], 1});
            } else {
                query.push_back({p, r, a[i], 1});
                query.push_back({l, l + rem - (r - p), a[i], 1});
            }
        }
    }

    const int B = 400;

    sort(query.begin(), query.end(), 
        [&](auto a, auto b) {
            if(a[0] / B != b[0] / B) {
                return a[0] / B < b[0] / B;
            }
            return a[1] < b[1];
        });

    Fenwick<int> trc(S + 10);
    Fenwick<i64> trs(S + 10);

    auto add = [&](int x) {
        trc.add(seq[x], 1);
        trs.add(seq[x], kth[seq[x] - 1]);
    };

    auto del = [&](int x) {
        trc.add(seq[x], -1);
        trs.add(seq[x], -kth[seq[x] - 1]);
    };

    auto work = [&](int v) {
        int upc = trc.rangeSum(v, S);
        i64 los = trs.rangeSum(1, v - 1);
        return (1ll * upc * kth[v - 1] % mod + los % mod) % mod;
    };

    int l = 0, r = -1;
    i64 ans = 0;
    for(auto [x, y, v, c] : query) {
        y -= 1;
        while(l > x) {
            add(-- l);
        }
        while(r < y) {
            add(++ r);
        }
        while(l < x) {
            del(l ++);
        }
        while(r > y) {
            del(r --);
        }
        ans += work(v) * c % mod;
        ans %= mod;
    }

    cout << ans << '\n';
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
