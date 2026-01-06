#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
离散化
扫描线
*/

template<class Info>
struct SegmenTree {
    int n;
    vector<Info> info;

    SegmenTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    SegmenTree(vector<Info> a) {
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
        if(info[p].cnt) {
            info[p].res = info[p].len;
        } else {
            info[p] = info[p << 1] + info[p << 1 | 1];
        }
    }

    void rangeApply(int p, int l, int r, int x, int y, const int &op) {
        if(l > y || r < x) {
            return;
        }
        if(l >= x && r <= y) {
            info[p].apply(op);
            if(l != r) {
                pushup(p);
            }
            return;
        }
        int mid = l + r >> 1;
        rangeApply(p << 1, l, mid, x, y, op);
        rangeApply(p << 1 | 1, mid + 1, r, x, y, op);
        pushup(p);
    }

    void rangeApply(int x, int y, const int &op) {
        rangeApply(1, 1, n, x, y, op);
    }

    int query() {
        return info[1].res;
    }
};

struct Info {
    int len = 0;
    int cnt = 0;
    int res = 0;

    void apply(int op) {
        cnt += op;
        res = (cnt ? len : 0);
    }
};

Info operator +(Info a, Info b) {
    Info c;
    c.len = a.len + b.len;
    c.res = a.res + b.res;
    return c;
}

void solve() {
    int m, n;
    cin >> m >> n;
    vector<array<int, 2>> query(n);
    vector<int> kth;
    kth.reserve(n * 2);
    for(int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        kth.emplace_back(l);
        kth.emplace_back(r + 1);
        query[i] = {l, r + 1};
    }

    sort(kth.begin(), kth.end());
    kth.erase(unique(kth.begin(), kth.end()), kth.end());
    auto rank = [&](int x) {
        return lower_bound(kth.begin(), kth.end(), x) - kth.begin() + 1;
    };

    int S = kth.size();
    vector<Info> a(S);
    for(int i = 1; i <= S - 1; i ++) {
        a[i] = {kth[i] - kth[i - 1], 0, 0};
    }

    SegmenTree<Info> tr(a);
    for(auto [l, r] : query) {
        l = rank(l), r = rank(r);
        tr.rangeApply(l, r - 1, 1);
        cout << m - tr.query() << '\n';
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
