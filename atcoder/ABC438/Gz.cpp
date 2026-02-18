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

template<class Info>
struct PresidentTree {
    int n;
    int idx = 0;
    vector<Info> info;
    PresidentTree(int n_, int cnt_) : n(n_), info(cnt_ * (__lg(n) + 2) + 1) {};
    
    void modify(int p, int &q, int l, int r, const int &v, const int &add) {
        q = ++ idx;
        info[q] = info[p];
        info[q].act ++;
        info[q].sum += add;
        if(l == r) return;
        int mid = l + r >> 1;
        if(v <= mid) modify(info[p].l, info[q].l, l, mid, v, add);
        else modify(info[p].r, info[q].r, mid + 1, r, v, add);
    }

    void modify(int p, int &q, const int &v, const int &add) {
        modify(p, q, 1, n, v, add);
    }

    int kth(int p, int q, int l, int r, int k) {
        if(l == r) return l;
        int mid = l + r >> 1;
        int sum = info[info[q].l].act - info[info[p].l].act;
        if(k <= sum) return kth(info[p].l, info[q].l, l, mid, k);
        else return kth(info[p].r, info[q].r, mid + 1, r, k - sum);
    }

    int kth(int p, int q, int k) {
        return kth(p, q, 1, n, k);
    }

    int queryC(int p, int q, int l, int r, int x, int y) {
        if(l > y || r < x) return 0;
        if(l >= x && r <= y) return info[q].act - info[p].act;
        int mid = l + r >> 1;
        return queryC(info[p].l, info[q].l, l, mid, x, y) + queryC(info[p].r, info[q].r, mid + 1, r, x, y);
    }

    int queryC(int p, int q, int x, int y) {
        return queryC(p, q, 1, n, x, y);
    }

    i64 queryS(int p, int q, int l, int r, int x, int y) {
        if(l > y || r < x) return 0;
        if(l >= x && r <= y) return info[q].sum - info[p].sum;
        int mid = l + r >> 1;
        return queryS(info[p].l, info[q].l, l, mid, x, y) + queryS(info[p].r, info[q].r, mid + 1, r, x, y);
    }

    i64 queryS(int p, int q, int x, int y) {
        return queryS(p, q, 1, n, x, y);
    }
};

struct Info {
    int l, r;
    int act = 0;
    i64 sum = 0;
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

    PresidentTree<Info> tr(S, m);
    vector<int> root(m + 1);
    for(int i = 1; i <= m; i ++) {
        tr.modify(root[i - 1], root[i], seq[i - 1], kth[seq[i - 1] - 1]);
    }

    int ans = 0;
    for(auto [l, r, v, c] : query) {
        l ++;
        int upc = tr.queryC(root[l - 1], root[r], v, S);
        i64 los = tr.queryS(root[l - 1], root[r], 1, v - 1);
        ans += (1ll * upc * kth[v - 1] + los) % mod * c % mod;
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
