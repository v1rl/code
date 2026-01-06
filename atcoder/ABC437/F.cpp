#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

template <typename Info>
struct SegmentTree {
    int n;
    vector<Info> info;

    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    SegmentTree(vector<Info> a) {
        init(a);
    }

    void init(int n_, Info v_ = Info()) {
        init(vector(n_ + 1, v_));
    }

    void init(vector<Info> a) {
        n = a.size();
        info.assign(4 << __lg(n), Info());
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

    void modify(int p, int l, int r, int x, const int &v) {
        if(l == r) {
            info[p].apply(v);
            return;
        }
        int mid = l + r >> 1;
        if(x <= mid) {
            modify(p << 1, l, mid, x, v);
        } else {
            modify(p << 1 | 1, mid + 1, r, x, v);
        }
        pushup(p);
    }

    void modify(int x, const int &v) {
        modify(1, 1, n, x, v);
    }

    Info query(int p, int l, int r, int x, int y) {
        if(l > y || r < x) {
            return Info();
        } 
        if(l >= x && r <= y) {
            return info[p];
        }
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid + 1, r, x, y);
    }

    Info query(int x, int y) {
        return query(1, 1, n, x, y);
    }
};

const int inf = 2e9;

struct Info {
    int mx = -inf;
    int mn = inf;
    void apply(const int &v) {
        mx = v;
        mn = v;
    }
};

Info operator+(Info a, Info b) {
    Info c;
    c.mx = max(a.mx, b.mx);
    c.mn = min(a.mn, b.mn);
    return c;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<Info> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x + y, x + y};
        b[i] = {x - y, x - y};
    }

    SegmentTree<Info> tr1(a);
    SegmentTree<Info> tr2(b);

    while(q --) {
        int op;
        cin >> op;
        if(op == 1) {
            int t, x, y;
            cin >> t >> x >> y;
            tr1.modify(t, {x + y});
            tr2.modify(t, {x - y});
        } else {
            int l, r, x, y;
            cin >> l >> r >> x >> y;
            i64 b1 = x + y;
            i64 b2 = x - y;

            i64 mx1 = tr1.query(l, r).mx;
            i64 mn1 = tr1.query(l, r).mn;
            i64 mx2 = tr2.query(l, r).mx;
            i64 mn2 = tr2.query(l, r).mn;

            cout << max({b1 - mn1, -(b1 - mx1), b2 - mn2, -(b2 - mx2)}) << '\n';
        }
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
