#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

constexpr int inf = 2e9 + 10;

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

    void modify(int p, int l, int r, int x, const Info &v) {
        if(l == r) {
            info[p] = v;
            return;
        }
        pushdown(p);
        int mid = l + r >> 1;
        if(x <= mid) {
            modify(p << 1, l, mid, x, v);
        } else {
            modify(p << 1 | 1, mid + 1, r, x, v);
        }
        pushup(p);
    }

    void modify(int x, const Info &v) {
        modify(1, 1, n, x, v);
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

    Info query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

struct Tag {
    int v = inf;

    void apply(const Tag &t) {
        v = min(v, t.v);
    }
};

struct Info {
    int mn = inf;
    int mnI;
    int v = inf;
    int vI;

    void apply(const Tag &t) {
        if(mn != inf && t.v != inf && v > t.v + mn) {
            v = t.v + mn;
            vI = mnI;
        }
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    if(a.mn < b.mn) {
        c.mn = a.mn;
        c.mnI = a.mnI;
    } else {
        c.mn = b.mn;
        c.mnI = b.mnI;
    }
    if(a.v < b.v) {
        c.v = a.v;
        c.vI = a.vI;
    } else {
        c.v = b.v;
        c.vI = b.vI;
    }
    return c;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    LazySegmentTree<Info, Tag> tr(n);

    for(int i = 1; i <= n; i ++) {
        tr.modify(i, {a[i], i, inf, -1});
    }


    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(int i = 1; i <= n; i ++) {
        adj[i].emplace_back(0);
        adj[i].emplace_back(n + 1);
        sort(adj[i].begin(), adj[i].end());
    }


    tr.modify(1, {a[1], 1, 0, 1});
    i64 ans = 0;
    for(int i = 0; i < n; i ++) {
        auto [_1, _2, v, x] = tr.query(1, n);
        if(v == inf) {
            cout << -1 << '\n';
            return;
        }
        ans += v;
        tr.modify(x, {inf, -1, inf, -1});

        for(int i = 1; i < adj[x].size(); i ++) {
            tr.rangeApply(adj[x][i - 1] + 1, adj[x][i] - 1, {a[x]});
        }
    }

    cout << ans << '\n';
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
