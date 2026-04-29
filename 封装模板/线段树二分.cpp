#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9 + 10;

template<class Info>
struct SegemenTree {
    int n;
    vector<Info> info;

    SegemenTree(int n_) {
        init(vector(n_ + 1, Info()));
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

    void modify(int p, int l, int r, int pos, int v) {
        if(l == r) {
            info[p].mx = v;
            return;
        }
        int mid = l + r >> 1;
        if(pos <= mid) {
            modify(p << 1, l, mid, pos, v);
        } else {
            modify(p << 1 | 1, mid + 1, r, pos, v);
        }
        pushup(p);
    }

    void modify(int pos, int v) {
        modify(1, 1, n, pos, v);
    }

    int queryL(int p, int l, int r, int x, int y, int v) {
        if(l > y || r < x) {
            return 0;
        }
        if(info[p].mx < v) {
            return 0;
        }
        if(l == r) {
            return l;
        }
        int mid = l + r >> 1;
        int res = queryL(p << 1 | 1, mid + 1, r, x, y, v);
        if(res == 0) {
            res = queryL(p << 1, l, mid, x, y, v);
        }
        return res;
    }

    int queryL(int x, int y, int v) {
        return queryL(1, 1, n, x, y, v);
    }

    int queryR(int p, int l, int r, int x, int y, int v) {
        if(l > y || r < x) {
            return n + 1;
        }
        if(info[p].mx < v) {
            return n + 1;
        }
        if(l == r) {
            return l;
        }
        int mid = l + r >> 1;
        int res = queryR(p << 1, l, mid, x, y, v);
        if(res == n + 1) {
            res = queryR(p << 1 | 1, mid + 1, r, x, y, v);
        }
        return res;
    }

    int queryR(int x, int y, int v) {
        return queryR(1, 1, n, x, y, v);
    }
};

struct Info {
    int mx = -1;
};

Info operator+(Info a, Info b) {
    Info c;
    c.mx = max(a.mx, b.mx);
    return c;
}

struct Node {
    int x, y, id;
};

template<class T>
struct Fenwick {
    int n;
    vector<T> a;

    Fenwick(int n_) : n(n_), a(n + 1) {};

    void add(int x, const T &v) {
        for(int i = x; i <= n; i += i & -i) {
            a[i] += v;
        }
    }

    T sum(int x) {
        T res{};
        for(int i = x; i; i -= i & -i) {
            res += a[i];
        }
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<Node> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].x;
        a[i].id = i + 1;
    }      
    for(int i = 0; i < n; i ++) {
        cin >> a[i].y;
    }

    vector<int> L(n + 1, 0), R(n + 1, n + 1);
    SegemenTree<Info> trL(n);
    sort(a.begin(), a.end(), 
        [&](auto &x, auto &y) {
            if(x.x != y.x) {
                return x.x > y.x;
            }
            if(x.y != y.y) {
                return x.y > y.y;
            }
            return x.id < y.id;
        });

    for(auto [_, y, id] : a) {
        L[id] = trL.queryL(1, id - 1, y);
        trL.modify(id, y);
    }

    SegemenTree<Info> trR(n);
    sort(a.begin(), a.end(), 
        [&](auto &x, auto &y) {
            if(x.x != y.x) {
                return x.x > y.x;
            }
            if(x.y != y.y) {
                return x.y > y.y;
            }
            return x.id > y.id;
        });

    for(auto [_, y, id] : a) {
        R[id] = trR.queryR(id + 1, n, y);
        trR.modify(id, y);
    }

    vector<vector<array<int, 2>>> add(n + 1);
    vector<vector<array<int, 2>>> sub(n + 1);
    vector<vector<array<int, 2>>> query(n + 1);
    vector<int> ans(q);
    for(int i = 0; i < q; i ++) {
        int l, r;
        cin >> l >> r;
        query[l].push_back({r, i});
    }

    for(int i = 1; i <= n; i ++) {
        add[i].push_back({i, R[i] - 1});
        sub[L[i]].push_back({i, R[i] - 1});
    }

    Fenwick<int> tr(n);
    for(int i = n; i >= 1; i --) {
        for(auto [l, r] : add[i]) {
            tr.add(l, 1);
            tr.add(r + 1, -1);
        }
        for(auto [l, r] : sub[i]) {
            tr.add(l, -1);
            tr.add(r + 1, 1);
        }
        for(auto [x, id] : query[i]) {
            ans[id] = tr.sum(x);
        }
    }

    for(int i = 0; i < q; i ++) {
        cout << ans[i] << '\n';
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
