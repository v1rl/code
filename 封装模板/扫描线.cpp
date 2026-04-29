#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

template<class Info>
struct LazySegmentTree {
    int n;
    vector<Info> info;

    LazySegmentTree(int n_, Info v_ = Info()) {
        init(vector(n_ + 1, v_));
    }

    LazySegmentTree(vector<Info> a) {
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

    // pushup时若当前节点存在需要保持不变的信息，最好不用operator重写
    void pushup(int p) {
        info[p].x = info[p << 1].x + info[p << 1 | 1].x;
        info[p].v = (info[p].act ? info[p].x : info[p << 1].v + info[p << 1 | 1].v);
    }

    void rangeApply(int p, int l, int r, int x, int y, const int &op) {
        if(l > y || r < x) return;
        if(l >= x && r <= y) {
            info[p].apply(op);
            if(l != r) pushup(p);
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

    i64 query() {
        return info[1].v;
    }
};

struct Info {
    i64 x = 0;
    i64 v = 0;
    int act = 0;

    void apply(const int &op) {
        act += op;
        v = (act ? x : 0);
    }
};

struct Node {
    i64 x, y1, y2;
    int op;

    bool operator < (const Node &W) const {
        return x < W.x;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Node> dat;
    vector<int> kth;
    dat.reserve(2 * n);
    kth.reserve(2 * n + 1);
    kth.emplace_back(0);

    for(int i = 0; i < n; i ++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        dat.push_back({x1, y1, y2, 1});
        dat.push_back({x2, y1, y2, -1});
        kth.emplace_back(y1);
        kth.emplace_back(y2);
    }
    sort(dat.begin(), dat.end());

    sort(kth.begin(), kth.end());
    kth.erase(unique(kth.begin() + 1, kth.end()), kth.end());
    int M = kth.size();
    kth.insert(kth.begin(), -1);
    auto rank = [&](int x) {
        return lower_bound(kth.begin() + 1, kth.end(), x) - kth.begin();
    };

    vector<Info> a(M);
    for(int i = 1; i < M; i ++) {
        a[i] = {kth[i + 1] - kth[i]};
    }
    LazySegmentTree<Info> tr(a);

    int last = -1;
    i64 ans = 0;
    for(auto &[x, y1, y2, op] : dat) {
        if(last != -1) {
            ans += tr.query() * (x - last);
        }
        int l = rank(y1), r = rank(y2);
        tr.rangeApply(l, r - 1, op);
        last = x;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}