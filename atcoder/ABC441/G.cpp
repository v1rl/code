#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
题目显然可以用懒标记线段树维护
考虑节点和标记分别需要维护哪些信息
求最大值，且只有向上的部分可以执行加，操作包括上下翻转，考虑维护mx，actUp，actDown
需要知道翻转的次数和加的和，考虑维护flip，add
然后考虑节点信息怎么合并，标记信息怎么叠加，标记信息怎么应用即可

另外，本题还可以区间求向上的章鱼烧个数
*/

constexpr i64 inf = 1e18;

template<class Info, class Tag>
struct LazySegmentree {
    int n;
    vector<Info> info;
    vector<Tag> tag;

    LazySegmentree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }


    LazySegmentree(const vector<Info> &a) {
        init(a);
    }

    void init(int n_, Info v_) {
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

    void pushdown(int p) {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag();
    }

    void apply(int p, const Tag &t) {
        info[p].apply(t);
        tag[p].apply(t);
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &t) {
        if(l > y || r < x) {
            return;
        }
        if(l >= x && r <= y) {
            apply(p, t);
            return;
        }
        int mid = l + r >> 1;
        pushdown(p);
        rangeApply(p << 1, l, mid, x, y, t);
        rangeApply(p << 1 | 1, mid + 1, r, x, y, t);
        pushup(p);
    }

    void rangeApply(int x, int y, const Tag &t) {
        rangeApply(1, 1, n, x, y, t);
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
    int flip = 0;
    i64 add = 0;

    void apply(const Tag &t) {
        if(t.flip) {
            flip += t.flip;
            add = t.add;
        } else {
            add += t.add;
        }
    }
};

struct Info {
    int actU = 0;
    int actD = 0;
    i64 mx = 0;

    void apply(const Tag &t) {
        if(t.flip % 2 == 1) {
            swap(actU, actD);
        }
        if(actU == 0) {
            mx = 0;
        } else {
            if(t.flip) {
                mx = t.add;
            } else {
                mx += t.add;
            }            
        }
    }
};

Info operator+(Info a, Info b) {
    Info c;
    c.mx = max(a.mx, b.mx);
    c.actU = a.actU + b.actU;
    c.actD = a.actD + b.actD;
    return c;
}


void solve() {
    int n, m;
    cin >> n >> m;
    LazySegmentree<Info, Tag> tr(n, {1, 0, 0});
    for(int i = 0; i < m; i ++) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1) {
            int x;
            cin >> x;
            tr.rangeApply(l, r, {0, x});
        } else if(op == 2) {
            tr.rangeApply(l, r, {1, 0});
        } else {
            cout << tr.query(l, r).mx << '\n';
        }
        // for(int i = 1; i <= n; i ++) {
        //     cout << tr.query(i, i).mx << " \n"[i == n];
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