#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;

    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    LazySegmentTree(const vector<Info> &a) {
        init(a);
    }

    void init(int n_, Info v_ = Info()) {
        init(vector(n_ + 1, v_));
    }

    void init(const vector<Info> &a) {
        n = a.size() - 1;
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if(l == r) {
                info[p] = a[l];
                return;
            }
            int mid = l + r >> 1;
            build(p << 1, l, mid);
            build(p << 1 | 1, mid + 1, r);
            pushup(p);
        };
        build(1, 1, n);
    }

    void pushup(int p) {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }

    void apply(int p, const Tag &t) {
        info[p].apply(t);
        tag[p].apply(t);
    }

    void pushdown(int p) {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag();
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &t) {
        if(l > y || r < x) return;
        if(l >= x && r <= y) {
            apply(p, t);
            return;
        }
        pushdown(p);
        int mid = l + r >> 1;
        rangeApply(p << 1, l, mid, x, y, t);
        rangeApply(p << 1 | 1, mid + 1, r, x, y, t);
        pushup(p);
    }

    void rangeApply(int x, int y, const Tag &t) {
        rangeApply(1, 1, n, x, y, t);
    }

    Info query(int p, int l, int r, int x, int y) {
        if(l > y || r < x) return Info();
        if(l >= x && r <= y) return info[p];
        pushdown(p);
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid + 1, r, x, y);
    }

    Info query(int x, int y) {
        return query(1, 1, n, x, y);
    }
};

constexpr i64 inf = 1e18;

struct Tag {
    i64 add = 0;

    void apply(const Tag &t) {
        add += t.add;
    }
};

struct Info {
    i64 min = inf;
    i64 max = -inf;
    i64 sum = 0;
    i64 act = 0;

    void apply(const Tag &t) {
        min += t.add;
        max += t.add;
        sum += act * t.add;
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.min = min(a.min, b.min);
    c.max = max(a.max, b.max);
    c.sum = a.sum + b.sum;
    c.act = a.act + b.act; 
    return c;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Info> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        a[i] = {x, x, x, 1};
    }

    LazySegmentTree<Info, Tag> tr(a);

    while(m --) {
        int op;
        cin >> op;
        if(op == 2) {
            int l, r;
            cin >> l >> r;
            cout << tr.query(l, r).sum << '\n';
        } else {
            int l, r;
            i64 k;
            cin >> l >> r >> k;
            tr.rangeApply(l, r, {k});
        }
    }
    return 0;
}