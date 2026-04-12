#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P3367

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
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    DSU dsu(n);
    for(int i = 0; i < n; i += 2) {
        dsu.merge(a[i] / 2, a[i + 1] / 2);
    }
    int ans = n;
    for(int i = 0; i < n; i ++) {
        if(dsu.find(i) == i) {
            ans --;
        }
    }
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
