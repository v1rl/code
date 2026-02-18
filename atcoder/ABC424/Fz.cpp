#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

/*
考虑将直觉上的交叉或整体左右关系转换为数学上的区间关系
于是，题意可转换为新加入的区间[l, r]内部区间与它的关系只能是包含
注意到：这样的关系可以转换为区间[l, r]之间只能存在成对的区间端点
也就代表着内部的所有左端点对应的右端点需要在区间内，右端点对应的所有左端点需要在区间内
显然不可能全部遍历，这只是判定问题，可用最值代替全体，得到左端点的最大右端点和右端点的最小左端点，然后判断是否在范围内即可
于是转为区间最值问题，可用线段树维护
*/

const int inf = 1e9;

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

struct Info {
    int mx = 0;
    int mn = inf;
    void apply(const int &v) {
        mx = mn = v;
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
    SegmentTree<Info> trL(n), trR(n);
    while(q --) {
        int x, y;
        cin >> x >> y;
        if(trL.query(x, y).mn < x || trR.query(x, y).mx > y) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
            trL.modify(y, x);
            trR.modify(x, y);
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