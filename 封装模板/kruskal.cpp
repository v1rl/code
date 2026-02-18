#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

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
    DSU dsu(n);

    int sum = 0;
    vector<array<int, 3>> edges(m);
    for(int i = 0; i < m; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges[i] = {w, x, y};
        sum += w;
    }

    sort(edges.begin(), edges.end());

    int res = 0;
    for(auto [w, x, y] : edges) {   
        if(dsu.merge(x, y)) {
            res += w;
        }
    }

    cout << sum - res << '\n';
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