#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template <typename Info>
struct SegmentTree {
    int n;
    vector<Info> info;

    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    void init(int n_, Info v_ = Info()) {
        init(vector(n_ + 1, v_));
    }

    SegmentTree(vector<Info> a) {
        init(a);
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

struct Info {
    int sum = 0;
    void apply(const int &v) {
        sum += v;
    }
};

Info operator+(Info a, Info b) {
    Info c;
    c.sum = a.sum + b.sum;
    return c;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Info> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].sum;
    }
    SegmentTree<Info> tr(a);
    while(m --) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1) {
            tr.modify(l - 1, r);
        } else {
            cout << tr.query(l - 1, r).sum << '\n';
        }
    }
}