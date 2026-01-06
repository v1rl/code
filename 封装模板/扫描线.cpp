#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

template<class Info>
struct LazySegmentTree {
    int n;
    vector<Info> info;

    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    LazySegmentTree(vector<Info> a) {
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
        if(info[p].cnt) info[p].res = info[p].len; 
        else info[p] = info[p << 1] + info[p << 1 | 1];
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
        return info[1].res;
    }
};

struct Info {
    i64 len = 0;
    i64 res = 0;
    int cnt = 0;

    void apply(const int &op) {
        cnt += op;
        res = (cnt ? len : 0);
    }
};

Info operator+(Info a, Info b) {
    Info c;
    c.len = a.len + b.len;
    c.res = a.res + b.res;
    return c;
}

struct Node {
    i64 x, y1, y2;
    int op;

    bool operator < (const Node &W) const {
        return x < W.x;
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<Node> dat;
    vector<int> kth;
    dat.reserve(2 * n);
    kth.reserve(2 * n);
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
    sort(kth.begin() + 1, kth.end());
    kth.erase(unique(kth.begin() + 1, kth.end()), kth.end());
    int cnt = kth.size() - 1;
    auto krank = [&](int x) {
        return lower_bound(kth.begin() + 1, kth.end(), x) - kth.begin();
    };

    vector<Info> a(cnt + 1);
    for(int i = 1; i < cnt; i ++) {
        a[i] = {kth[i + 1] - kth[i]};
    }
    LazySegmentTree<Info> tr(a);

    int last = -1;
    i64 ans = 0;
    for(auto &[x, y1, y2, op] : dat)
    {
        if(last != -1) {
            ans += tr.query() * (x - last);
        }
        int l = krank(y1), r = krank(y2);
        tr.rangeApply(l, r - 1, op);
        last = x;
    }
    cout << ans << '\n';
}