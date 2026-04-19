#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

template<class Info, class Tag>
struct SegmenTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;

    SegmenTree(vector<Info> &a) {
        init(a);
    }

    void init(vector<Info> &a) {
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
        auto &l = info[p << 1];
        auto &r = info[p << 1 | 1];
        if(l.mx >= r.mx) {
            info[p].mx = l.mx;
            info[p].k = l.k;
        } else {
            info[p].mx = r.mx;
            info[p].k = r.k;
        }
    }

    void apply(int p, const Tag &t) {
        info[p].apply(t);
        tag[p].apply(t);
    }

    void pushdonw(int p) {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag();
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &t) {
        if(r < x || l > y) {
            return;
        }
        if(l >= x && r <= y) {
            apply(p, t);
            return;
        }
        int mid = l + r >> 1;
        pushdonw(p);
        rangeApply(p << 1, l, mid, x, y, t);
        rangeApply(p << 1 | 1, mid + 1, r, x, y, t);
        pushup(p);
    }

    void rangeApply(int x, int y, const Tag &t) {
        rangeApply(1, 1, n, x, y, t);
    }

    Info queryMax() {
        return info[1];
    }
};

struct Tag {
    int add = 0;

    void apply(const Tag &t) {
        add += t.add;
    }
};

struct Info {
    int mx = 0;
    int k = 0;

    void apply(const Tag &t) {
        mx += t.add;
    }
};

struct Node {
    int l, r;
    int v;

    bool operator <(const Node &ano) const {
        return l < ano.l;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Info> a(n * 2 + 1);
    set<Node> odt;

    for(int i = 1; i <= n * 2; i ++) {
        a[i] = {0, i};
    }
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        odt.insert({i, i + 1, x});
        a[x].mx ++;
    }

    SegmenTree<Info, Tag> tr(a);
    auto [mx, k] = tr.queryMax();
    cout << k << ' ' << mx << '\n';

    auto split = [&](int x) {
        auto it = odt.lower_bound({x, 0, 0});
        if(it != odt.end() && it->l == x) {
            return it;
        }  
        it --;
        auto [l, r, v] = *it;
        odt.erase(it);
        odt.insert({l, x, v});
        return odt.insert({x, r, v + (x - l)}).first;
    };

    auto assign = [&](int l, int r, int v) {
        auto itr = split(r + 1);
        auto itl = split(l);
        for(auto it = itl; it != itr; it ++) {
            auto [cl, cr, cv] = *it;
            tr.rangeApply(cv, cv + cr - cl - 1, {-1});
        }
        odt.erase(itl, itr);
        odt.insert({l, r + 1, v});
        tr.rangeApply(v, v + r - l, {1});
    };

    while(m --) {
        int l, r, v;
        cin >> l >> r >> v;
        assign(l, r, v);
        auto [mx, k] = tr.queryMax();
        cout << k << ' ' << mx << '\n';
    }
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
