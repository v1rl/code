#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/find-all-people-with-secret/description/

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
    int n, fst;
    cin >> n >> fst;
    DSU dsu(n);
    dsu.merge(0, fst);

    int m;
    cin >> m;
    vector<array<int, 3>> a(m);
    for(int i = 0; i < m; i ++) {
        int x, y, t;
        cin >> x >> y >> t;
        a[i] = {x, y, t};
    }

    sort(a.begin(), a.end(), 
        [&](auto &x, auto &y) {
            return x[2] < y[2];
        });

    for(int i = 0; i < m; i ++) {
        auto [x, y, t] = a[i];
        vector<array<int, 2>> pr;
        pr.push_back({x, y});
        while(i + 1 < m && a[i + 1][2] == t) {
            pr.push_back({a[i + 1][0], a[i + 1][1]});
            i ++;
        }

        for(auto [cx, cy] : pr) {
            dsu.merge(cx, cy);
        }
        for(auto [cx, cy] : pr) {
            if(!dsu.same(cx, 0)) {
                dsu.set(cx, cx);
            }
            if(!dsu.same(cy, 0)) {
                dsu.set(cy, cy);
            }
        }
    }

    for(int i = 0; i < n; i ++) {
        if(dsu.same(i, 0)) {
            cout << i << ' ';
        }
    }
    cout << '\n';
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
