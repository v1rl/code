#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/number-of-good-paths/description/

struct DSU {
    vector<int> p, cnt;
    vector<int> mx;

    DSU(int n) {
        init(n);
    }

    void init(int n) {
        p.resize(n + 1);
        mx.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        cnt.assign(n + 1, 1);
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
        int cmx = max(mx[x], mx[y]);
        int ccnt = 0;
        if(mx[x] == cmx) {
            ccnt += cnt[x];
        }
        if(mx[y] == cmx) {
            ccnt += cnt[y];
        }
        mx[x] = cmx;
        cnt[x] = ccnt;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int val(int x, int y) {
        x = find(x), y = find(y);
        if(mx[x] == mx[y]) {
            return cnt[x] * cnt[y];
        }
        return 0;
    }
};

void solve() {
    int n;
    cin >> n;
    DSU dsu(n);
    vector<int> v(n);
    for(int i = 0; i < n; i ++) {
        cin >> v[i];
    }

    for(int i = 0; i < n; i ++) {
        dsu.mx[i] = v[i];
    }

    vector<array<int, 2>> edges(n - 1);
    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        edges[i] = {x, y};
    }

    sort(edges.begin(), edges.end(), 
        [&](auto x, auto y) {
            return max(v[x[0]], v[x[1]]) < max(v[y[0]], v[y[1]]);
        });

    int ans = 0;
    for(auto [x, y] : edges) {
        ans += dsu.val(x, y);
        dsu.merge(x, y);
    }

    cout << ans + n << '\n';
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
