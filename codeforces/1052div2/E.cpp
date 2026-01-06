#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
选的数越多mex越大，但相应地可能得到的答案就越少
我们需要在这之中有所权衡
经过一番考虑，本题并没有这样权衡的贪心策略
于是，我们考虑暴力，这会是O(n^2log(n))的复杂度，显然不可接受
我们考虑暴力的优化，题目要求所有for i in [1, n]中所有[1~i]的w，这天然提示我们边维护边求解
但在这之前，我们需要转换一下题意
考虑反向求解：先求出MEX再找最大的w很困难，那么先假定MEX已知，并取其中最大值呢
于是注意到转换：序列中大于MEX的数的个数->对于序列中不存在的数x，令大于x数的个数为w，取其中最大的w
在for i in [1, n]遍历过程中，对于当前的a[i], 我们让所有[0, a[i] - 1]]的 w 增加 1 --> 前缀区间内大于x数的个数
随后，清空a[i]的w --> 前缀区间内，在x不出现于区间内的情况下，大于x数的个数
*/

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;

    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    void init(int n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }

    void init(vector<Info> a) {
        n = a.size();
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if(r - l == 1) {
                info[p] = a[l];
                return;
            }
            int mid = l + r >> 1;
            build(p << 1, l, mid);
            build(p << 1 | 1, mid, r);
            pushup(p);
        };
        build(1, 0, n);
    }

    void pushup(int p) {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }

    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }

    void pushdown(int p) {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag();
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if(l >= y || r <= x) return;
        if(l >= x && r <= y) {
            apply(p, v);
            return;
        }
        pushdown(p);
        int mid = l + r >> 1;
        rangeApply(p << 1, l, mid, x, y, v);
        rangeApply(p << 1 | 1, mid, r, x, y, v);
        pushup(p);
    }

    void rangeApply(int x, int y, const Tag &v) {
        rangeApply(1, 0, n, x, y, v);
    }

    void modify(int p, int l, int r, int x, const Info &v) {
        if(r - l == 1) {
            info[p] = v;
            return;
        }
        pushdown(p);
        int mid = l + r >> 1;
        if(x < mid) {
            modify(p << 1, l, mid, x, v);
        } else {
            modify(p << 1 | 1, mid, r, x, v);
        }
        pushup(p);
    }

    void modify(int x, const Info &v) {
        modify(1, 0, n, x, v);
    }

    Info query(int p, int l, int r, int x, int y) {
        if(l >= y || r <= x) return Info();
        if(l >= x && r <= y) return info[p];
        pushdown(p);
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid, r, x, y);
    }

    Info query(int x, int y) {
        return query(1, 0, n, x, y);
    }
};
constexpr int inf = 1e9;

struct Tag {
    int add = 0;
    void apply(const Tag &t) {
        add += t.add;
    }
};

struct Info {
    int max = 0;
    void apply(const Tag &t) {
        max += t.add;
    }
};

Info operator+(Info a, Info b) {
    Info c;
    c.max = max(a.max, b.max);
    return c;
}

void solve() {
    int n;
    cin >> n;
    LazySegmentTree<Info, Tag> tr(n + 1);
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        tr.rangeApply(0, x, {1});
        tr.modify(x, {0});
        cout << tr.query(0, n + 1).max << ' ';
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