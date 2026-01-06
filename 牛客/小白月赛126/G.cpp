#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
区间增变成了一个递增 / 递减排列
考虑给区间存储排列的起点
全部都是单点查询，我们没有pushup/down的必要
将路径上所有区间的答案统计上即可

区间如何累计
初始值为0
存储相对值，用位置-相对值累计答案
*/

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;

    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_ + 1, v_);
    }

    LazySegmentTree(vector<Info> a) {
        init(a);
    }

    void init(int n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }

    void init(vector<Info> a) {
        n = a.size();
        info.assign(4 << __lg(n) + 1, Info());
        tag.assign(4 << __lg(n) + 1, Tag());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if(l == r) {
                info[p] = a[l];
                return;
            }
            int mid = l + r >> 1;
            build(p << 1, l, mid);
            build(p << 1 | 1, mid + 1, r);
        };
        build(1, 1, n);
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &t) {
        if(l > y || r < x) return;
        if(l >= x && r <= y) {
            // cout << l << ' ' << r << '\n';
            info[p].apply(l, r, t);
            return;
        }
        int mid = l + r >> 1;
        rangeApply(p << 1, l, mid, x, y, t);
        rangeApply(p << 1 | 1, mid + 1, r, x, y, t);
    }

    void rangeApply(int x, int y, const Tag &t) {
        if(x > y) {
            return;
        }
        rangeApply(1, 1, n, x, y, t);
    }

    void query(int p, int l, int r, int x, i64 &res) {
        res += info[p].sum(l, r, x);
        if(l == r) {
            return;
        }
        int mid = l + r >> 1;
        if(x <= mid) {
            query(p << 1, l, mid, x, res);
        } else {
            query(p << 1 | 1, mid + 1, r, x, res);
        }
    }

    i64 query(int x) {
        i64 res = 0;
        query(1, 1, n, x, res);
        return res;
    }
};
constexpr i64 inf = 1e18;

struct Tag {
    int x;
    int op;
};

struct Info {
    i64 L = 0;
    i64 R = 0;
    int lt = 0;
    int rt = 0;

    void apply(int l, int r, const Tag &t) {
        auto [x, op] = t;
        if(op == 0) {
            L += l - x;
            lt ++;
        } else {
            R += x - r;
            rt ++;
        }
    }

    i64 sum(int l, int r, int pos) {
        i64 res = 0;
        res += L + 1ll * (pos - l) * lt;
        res += R + 1ll * (r - pos) * rt;
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    LazySegmentTree<Info, Tag> tr(n);
    for(int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        tr.rangeApply(1, l - 1, {l - 1, 1});
        tr.rangeApply(r + 1, n, {r + 1, 0});
        int mid = l + r >> 1;
        tr.rangeApply(l + 1, mid, {l + 1, 0});
        tr.rangeApply(mid + 1, r - 1, {r - 1, 1});            
    }

    while(q --) {
        int x;
        cin >> x;
        cout << tr.query(x) << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
