#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

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

    void pushup(int p) {
        info[p].v = info[p].act ? 1 : info[p << 1].v + info[p << 1 | 1].v;
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

    void modify(int p, int l, int r, int x, int y) {
        if(l > y || r < x) {
            return;
        }
        if(l >= x && r <= y) {
            info[p].act = 0;
            if(l != r) {
                pushup(p);
            }
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

    int query(int p, int l, int r, int x, int y) {
        if(l > y || r < x) {
            return 0;
        } 
        if(l >= x && r <= y) {
            return info[p].v;
        }
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid + 1, r, x, y) + info[p].act;
    }

    int query(int x, int y) {
        return query(1, 1, n, x, y);
    }
};

struct Info {
    int v = 0;
    int act = 1;
};

void solve() {
    int n;
    cin >> n;
    SegmentTree<Info> tr(n, {1, 1});
    for(int i = 0; i < n; i ++) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1) {
            tr.modify(l, r);
        } else {
            cout << tr.query(l, r) << '\n';
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