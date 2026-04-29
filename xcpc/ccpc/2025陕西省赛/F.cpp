#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

template<class Info>
struct SegmentTree {
    int n;
    vector<Info> info;

    SegmentTree(vector<Info> &a) {
        init(a);
    }

    void init(vector<Info> &a) {
        n = a.size() - 1;
        info.assign(4 << __lg(n), Info());
        function <void(int, int, int)> build = [&](int p, int l, int r) {
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
        assert(p < (4 << __lg(n)));
        if(l == r) {
            info[p].cnt += v;
            info[p].sum += v * info[p].val;
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

    i64 query(int p, int l, int r, int cnt) {
        // if(cnt <= 0) {
        //     return 0;
        // }
        if(info[p].cnt <= cnt) {
            return info[p].sum;
        }
        if(l == r) {
            return cnt * info[p].val;
        }
        int mid = l + r >> 1;
        if(info[p << 1 | 1].cnt >= cnt) {
            return query(p << 1 | 1, mid + 1, r, cnt);
        } else {
            return query(p << 1 | 1, mid + 1, r, cnt) + query(p << 1, l, mid, cnt - info[p << 1 | 1].cnt);
        }
    }

    i64 query(int cnt) {
        return query(1, 1, n, cnt);
    }
};

struct Info {
    int cnt = 0;
    i64 val = 0;
    i64 sum = 0;
};

Info operator+(Info a, Info b) {
    Info c;
    c.cnt = a.cnt + b.cnt;
    c.sum = a.sum + b.sum;
    return c;
}

void solve() {
    int n;
    cin >> n;
    vector<int> kth;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> v[i];
        kth.emplace_back(v[i]);
    }

    sort(kth.begin(), kth.end());
    kth.erase(unique(kth.begin(), kth.end()), kth.end());
    int N = kth.size();
    kth.insert(kth.begin(), 0);

    auto rank = [&](int x) {
        return lower_bound(kth.begin() + 1, kth.end(), x) - kth.begin();
    };

    vector<Info> a(N + 1);
    vector<int> rk(n + 1);
    for(int i = 1; i <= n; i ++) {
        rk[i] = rank(v[i]);
        int id = rk[i];
        a[id].val = v[i];
        a[id].cnt ++;
        a[id].sum += v[i];
    }

    SegmentTree<Info> tr(a);

    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<vector<int>> nadj(n + 1);
    auto idfs = [&](auto &&self, int x, int p) -> void {
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            nadj[x].emplace_back(y);
            self(self, y, x);
        }
        sort(nadj[x].begin(), nadj[x].end(), 
            [&](auto &a, auto b) {
                if(v[a] != v[b]) {
                    return v[a] > v[b];
                }
                return a < b;
            });
    };


    idfs(idfs, 1, -1);
    adj = move(nadj);

    i64 ans = v[1];
    auto dfs = [&](auto &&self, int x, i64 dsum, i64 tsum, int rem) -> void {
        rem ++;
        int m = adj[x].size();
        if(rem >= m) {
            i64 res = 0;
            for(auto y : adj[x]) {
                tr.modify(rk[y], -1);
                res += v[y];
            }
            ans = max(ans, dsum + res + tr.query(rem - m) - tsum);

            for(auto y : adj[x]) {
                tr.modify(rk[y], 1);
            }
        }

        i64 sel = 0;
        for(int i = 0; i < m; i ++) {
            int y = adj[x][i];

            if(rem >= i) {
                tr.modify(rk[y], -1);
                self(self, y, dsum + sel, tsum + v[y], rem - i);
                // tr.modify(rk[y], 1);
                // tr.modify(rk[y], -1);
                sel += v[y];
            } else {
                break;
            }
        }

        for(int i = 0; i < min(m, rem + 1); i ++) {
            int y = adj[x][i];
            tr.modify(rk[y], 1);
        }
    };

    tr.modify(rk[1], -1);
    dfs(dfs, 1, 0, v[1], 1);
    cout << ans << '\n';
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
