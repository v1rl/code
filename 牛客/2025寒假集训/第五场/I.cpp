#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<i64, i64> PII;

/*
*/

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
        if(x > y) {
            return;
        }
        rangeApply(1, 1, n, x, y, t);
    }

    bool query(int p, int l, int r, i64 &s, i64 h) {
        if(l == r) {
            s += info[p].sum;
            if(s > h) {
                return true;
            }
            return false;

        }
        pushdown(p);
        int mid = l + r >> 1;
        if(query(p << 1, l, mid, s, h)) {
            return true;
        }
        if(query(p << 1 | 1, mid + 1, r, s, h)) {
            return true;
        }
        return false;
    }

    bool query(i64 &s, i64 h) {
        return query(1, 1, n, s, h);
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
    i64 sum = 0;
    i64 act = 0;

    void apply(const Tag &t) {
        sum += act * t.add;
    }
};

Info operator+(Info a, Info b) {
    Info c;
    c.sum = a.sum + b.sum;
    c.act = a.act + b.act; 
    return c;
}

void solve() {
    int n, m;
    i64 h;
    cin >> n >> m >> h;

    vector<array<int, 2>> ops(m + 1);
    for(int i = 1; i <= m; i ++) {
        cin >> ops[i][0] >> ops[i][1];
    }

    LazySegmentTree<Info, Tag> tr(n + 1, {0, 1});

    auto check = [&](int mid) {
        i64 s = 0;
        return tr.query(s, h);
    };

    int l = 1, r = m + 1;
    bool dir = 1;
    while(l < r) {
        int mid = l + r >> 1;

        if(dir) {
            for(int i = l; i <= mid; i ++) {
                auto [pos, f] = ops[i];
                i64 L = pos - f + 1, R = pos + f;
                if(L <= 0) {
                    tr.rangeApply(1, 1, {f - (pos - 1)});
                    tr.rangeApply(2, pos, {1});
                } else {
                    tr.rangeApply(L, pos, {1});
                }
                tr.rangeApply(pos + 1, min<int>(R, n), {-1});
            }
        } else {
            for(int i = r; i > mid; i --) {
                auto [pos, f] = ops[i];
                i64 L = pos - f + 1, R = pos + f;
                if(L <= 0) {
                    tr.rangeApply(1, 1, {-(f - (pos - 1))});
                    tr.rangeApply(2, pos, {-1});
                } else {
                    tr.rangeApply(L, pos, {-1});
                }
                tr.rangeApply(pos + 1, min<int>(R, n), {1});
            }
        }

        if(check(mid)) {
            r = mid;
            dir = 0;
        } else {
            l = mid + 1;
            dir = 1;
        }

    }

    if(l <= m) {
        cout << "Yes" << '\n' << l << '\n';
    } else {
        cout << "No" << '\n';
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
