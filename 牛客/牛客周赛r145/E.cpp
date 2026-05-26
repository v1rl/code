#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

struct DSU {
    vector<int> p, siz;

    DSU(int n = 0) {
        init(n);
    }

    void init(int n) {
        p.resize(n + 1); 
        iota(p.begin(), p.end(), 0);
        siz.assign(n + 1, 1);
    }

    int find(int x) {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        p[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> edges(3);
    for(int i = 1; i <= m; i ++) {
        int x, y, c;
        cin >> x >> y >> c;
        edges[c].push_back({x, y});
    }

    auto work = [&](int c1, int c2) {
        if(edges[c1].empty() || edges[c2].empty()) {
            return false;
        }
        DSU dsu(n);
        vector<array<int, 2>> ans;
        auto [x, y] = edges[c1][0];
        dsu.merge(x, y);
        ans.push_back({x, y});
        int cnt = 2;

        for(auto [x, y] : edges[c2]) {
            if(dsu.merge(x, y)) {
                ans.push_back({x, y});
                cnt ++;
            }
        }
        for(int i = 1; i < edges[c1].size(); i ++) {
            auto [x, y] = edges[c1][i];
            if(dsu.merge(x, y)) {
                ans.push_back({x, y});
                cnt ++;
            }
        }

        if(cnt != n) {
            return false;
        }

        for(auto [x, y] : ans) {
            cout << x << ' ' << y << '\n';
        }
        return true;
    };

    bool f = false;
    f = work(0, 1);
    if(!f) {
        f = work(0, 2);
    }
    if(!f) {
        f = work(1, 2);
    }
    if(!f) {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}