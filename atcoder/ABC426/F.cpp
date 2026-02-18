#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
如果没有库存有限的设定就是简单的区间修线段树
发生库存不足时，需要单独处理库存不足的点，如果每次都要处理所有点在时间上肯定是做不到的
注意到：一个点只会发生一次需要特殊处理的库存不足，之后将其移除考虑即可
因此只需要对库存不足的点单独判断并处理，时间复杂度是可行的
*/

constexpr i64 inf = 1e18;

template<class Info, class Tag>
struct LazySegmentree {
    int n;
    vector<Info> info;
    vector<Tag> tag;

    LazySegmentree(const vector<Info> &a) {
        init(a);
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

    void pushdown(int p) {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag();
    }

    void apply(int p, const Tag &t) {
        info[p].apply(t);
        tag[p].apply(t);
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &t) {
        if(l > y || r < x) {
            return;
        }
        if(l >= x && r <= y) {
            apply(p, t);
            return;
        }
        int mid = l + r >> 1;
        pushdown(p);
        rangeApply(p << 1, l, mid, x, y, t);
        rangeApply(p << 1 | 1, mid + 1, r, x, y, t);
        pushup(p);
    }

    void rangeApply(int x, int y, const Tag &t) {
        rangeApply(1, 1, n, x, y, t);
    }

    Info query(int p, int l, int r, int x, int y) {
        if(l > y || r < x) {
            return Info();
        }
        if(l >= x && r <= y) {
            return info[p];
        }
        pushdown(p);
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid + 1, r, x, y);
    }

    Info query(int x, int y) {
        return query(1, 1, n, x, y);
    }

    int queryMin(int p, int l, int r, int x, int y) {
        if(l > y || r < x) {
            return 0;
        }
        if(info[p].mn >= 0) {
            return 0;
        }
        if(l == r) {
            int val = info[p].mn;
            apply(p, {-1, inf});
            return val;
        }
        pushdown(p);
        int mid = l + r >> 1;
        int res = queryMin(p << 1, l, mid, x, y);
        if(res == 0) {
            res = queryMin(p << 1 | 1, mid + 1, r, x, y);
        }
        pushup(p);
        return res;
    }

    int queryMin(int x, int y) {
        return queryMin(1, 1, n, x, y);
    }
};

struct Tag {
    int act = 0;
    i64 val = 0;

    void apply(const Tag &t) {
        act += t.act;
        val += t.val;
    }
};

struct Info {
    int act = 0;
    i64 mn = inf;

    void apply(const Tag &t) {
        act += t.act;
        mn += t.val;
    }
};

Info operator+(Info a, Info b) {
    Info c;
    c.mn = min(a.mn, b.mn);
    c.act = a.act + b.act;
    return c;
}

/*
*/

void solve() {
    int n;
    cin >> n;
    vector<Info> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        a[i].act = 1;
        cin >> a[i].mn;
    }
    LazySegmentree<Info, Tag> tr(a);

    int q;
    cin >> q;
    while(q --) {
        int l, r, d;
        cin >> l >> r >> d;
        i64 ans = 1ll * tr.query(l, r).act * d;
        tr.rangeApply(l, r, {0, -d});
        while(1) {
            int val = tr.queryMin(l, r);
            if(!val) {
                break;
            }
            ans += val;
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}