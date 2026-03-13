#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 7;
const int N = 30;

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
        n = a.size() - 1;
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

    void modify(int p, int l, int r, int x, int y) {
        if(l > y || r < x) {
            return;
        }

        if(l >= x && r <= y) {
            if(info[p].act == 0) {
                return;
            }
        }

        if(l == r) {
            info[p].apply(l - x + 2);
            return;
        }

        int mid = l + r >> 1;
        modify(p << 1, l, mid, x, y);
        modify(p << 1 | 1, mid + 1, r, x, y);
        pushup(p);
    }

    void modify(int x, int y) {
        modify(1, 1, n, x, y);
    }

    int query() {
        return info[1].v;
    }
};

struct Info {
    int v = 0;
    int act = 0;
    void apply(const int &div) {
        v /= div;
        if(v == 0) {
            act = 0;
        }
    }
};

Info operator+(Info a, Info b) {
    Info c;
    c.v = a.v ^ b.v;
    c.act = a.act + b.act;
    return c;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Info> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        a[i] = {x, 1};
    }

    SegmentTree<Info> tr(a);

    while(m --) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r;
            cin >> l >> r;
            tr.modify(l + 1, r);
        } else {
            cout << tr.query() << '\n';
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