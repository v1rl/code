#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

int floor(int n, int m) {
    if(n >= 0) {
        return n / m;
    }
    return (n - m + 1) / m;
}

constexpr int inf = 2e9;

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

    void rangeApplyAdd(int p, int l, int r, int x, int y, const Tag &t) {
        if(l > y || r < x) {
            return;
        }
        if(l >= x && r <= y) {
            apply(p, t);
            return;
        }
        int mid = l + r >> 1;
        pushdown(p);
        rangeApplyAdd(p << 1, l, mid, x, y, t);
        rangeApplyAdd(p << 1 | 1, mid + 1, r, x, y, t);
        pushup(p);
    }

    void rangeApplyAdd(int x, int y, const Tag &t) {
        rangeApplyAdd(1, 1, n, x, y, t);
    }

    void rangeApplyD(int p, int l, int r, int x, int y, const int &d) {
        if(l > y || r < x) {
            return;
        }
        if(l >= x && r <= y) {
            int mx = info[p].mx, mn = info[p].mn;
            int a = mx - floor(mx, d), b = mn - floor(mn, d);
            if(a == b) {
                apply(p, {-a});
                return;
            }
        }
        if(l == r) {
            int x = info[p].sum;
            info[p].apply(floor(info[p].sum, d));
            return;
        }
        int mid = l + r >> 1;
        pushdown(p);
        rangeApplyD(p << 1, l, mid, x, y, d);
        rangeApplyD(p << 1 | 1, mid + 1, r, x, y, d);
        pushup(p);
    }

    void rangeApplyD(int x, int y, const int &d) {
        rangeApplyD(1, 1, n, x, y, d);
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
};

struct Tag {
    int val = 0;

    void apply(const Tag &t) {
        val += t.val;
    }
};

struct Info {
    int act = 0;
    int mx = -inf;
    int mn = inf;
    i64 sum = 0;


    void apply(const Tag &t) {
        mn += t.val;
        mx += t.val;
        sum += 1ll * act * t.val;
    }

    void apply(const int &d) {
        mn = mx = sum = d;
    }
};

Info operator+(Info a, Info b) {
    Info c;
    c.act = a.act + b.act;
    c.sum = a.sum + b.sum;
    c.mx = max(a.mx, b.mx);
    c.mn = min(a.mn, b.mn);
    return c;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<Info> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        a[i] = {1, x, x, x};
    }

    LazySegmentree<Info, Tag> tr(a);

    while(q --) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r, add;
            cin >> l >> r >> add;
            l ++, r ++;
            tr.rangeApplyAdd(l, r, {add});
        } else if(op == 2) {
            int l, r, d;
            cin >> l >> r >> d;
            l ++, r ++;
            tr.rangeApplyD(l, r, d);
        } else if(op == 3) {
            int l, r;
            cin >> l >> r;
            l ++, r ++;
            cout << tr.query(l, r).mn << '\n';
        } else {
            int l, r;
            cin >> l >> r;
            l ++, r ++;
            cout << tr.query(l, r).sum << '\n';
        }
        // for(int i = 1; i <= n; i ++) {
        //     cout << tr.query(i, i).sum << " \n"[i == n];
        // }
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