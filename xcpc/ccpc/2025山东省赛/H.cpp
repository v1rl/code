#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;


struct DSU {
    vector<int> p, siz;

    DSU(int n) {
        init(n);
    }

    void init(int n) {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        siz.assign(n + 1, 1);
    }

    int find(int x) {
        if(x != p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) {
            return false;
        }
        p[y] = x;
        siz[x] += siz[y];
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return siz[find(x)];
    }

    void set(int x, int y) {
        p[x] = y;
    }
};

void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<array<int, 4>> edges(m);
    for(int i = 0; i < m; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges[i] = {x, y, w, i + 1};
    }

    sort(edges.begin(), edges.end(), 
        [&](auto &x, auto &y) {
            return x[2] < y[2];
        });

    DSU dsu(n);

    vector<array<int, 4>> sel;
    i64 res = 0;
    for(auto [x, y, w, id] : edges) {
        if(dsu.same(x, y)) {
            continue;
        }
        sel.push_back({x, y, w, id});
        res += w;
        dsu.merge(x, y);
    }

    dsu.init(n);
    vector<int> ans;
    vector<array<int, 2>> add;
    sort(sel.begin(), sel.end(), 
        [&](auto &x, auto &y) {
            return x[2] > y[2];
        });

    for(int i = 0; i < sel.size(); i ++, c --) {
        auto [x, y, w, id] = sel[i];
        if(c > 0 && w > 0) {
            res -= w;
        } else {
            dsu.merge(x, y);
            ans.emplace_back(id);
        }
    }

    for(int i = 2; i <= n; i ++) {
        if(!dsu.same(i, i - 1)) {
            dsu.merge(i, i - 1);
            res ++;
            ans.emplace_back(add.size() + m + 1);
            add.push_back({i, i - 1});
        }
    }

    cout << add.size() << '\n';
    for(auto [x, y] : add) {
        cout << x << ' ' << y << '\n';
    }
    cout << res << '\n';
    for(auto c : ans) {
        cout << c << ' ';
    }
    cout << '\n';
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
