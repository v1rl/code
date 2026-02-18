#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
k的数据范围极大，于是，我们考虑寻找一个能一次解决大范围数据的数学变换
不难联想到对固定的A[i], 寻找与之配对的B的规律
显然，这样的配对规律并非无迹可寻的随机，而是遵循某种规律的循环
注意到：两两配对，下标取模，无限增长情况下，A[i]在B中的配对顺序是一个顺序循环的集合
注意到：集合的选取以取模意义下A的长度n为跨度，存在g = gcd(n, m)个这样的集合；各个集合相互独立，互不干扰；集合的长度len为m/g
于是，我们考虑找一个能一次处理A[i]对应的B集合的方法
注意到：我们将B按照"相同循环集合的元素聚合"的规则重排为seq，便可以通过连续区间查询的方式处理B
注意到：令seq中一个下标为x，我们可以通过x/len得到当前元素属于哪个集合，通过x%len得到当前元素在集合中的位置
另外，存储B到seq的映射，就可以得到B所处集合及其位置，从而连续处理
遍历A，处理每个A在B中的匹配集合即可得到答案

不难得到，我们需要的处理方式是查询下标区间中大于x数的个数和小于x数的总和
这点可以用主席树在线处理，或是树状数组+莫队离线处理
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
