#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/minimize-malware-spread-ii/description/

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
};

void solve() {
    int n;
    cin >> n;
    vector g(n, vector(n, 0));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> g[i][j];
        }
    }

    int m;
    cin >> m;
    vector<int> a(m);
    vector<int> vis(n);
    for(int i = 0; i < m; i ++) {
        cin >> a[i];
        vis[a[i]] = true;
    }

    DSU dsu(n);
    for(int i = 0; i < n; i ++) {
        if(vis[i]) {
            continue;
        }
        for(int j = 0; j < n; j ++) {
            if(vis[j]) {
                continue;
            }
            if(g[i][j]) {
                dsu.merge(i, j);
            }
        }
    }

    vector<int> from(n, -1);
    for(auto x : a) {
        for(int j = 0; j < n; j ++) {
            if(g[x][j] == 1) {
                int y = dsu.find(j);
                if(from[y] == -1 || from[y] == x) {
                    from[y] = x;
                } else {
                    from[y] = -2;
                }
            } 
        }
    }

    vector<int> cnt(n);
    for(int i = 0; i < n; i ++) {
        if(!vis[i] && i == dsu.find(i)) {
            if(from[i] >= 0) {
                cnt[from[i]] += dsu.size(i);
            }
        }
    }

    int mx = -1;
    int ans = -1;
    for(int i = 0; i < n; i ++) {
        if(vis[i]) {
            if(cnt[i] > mx) {
                mx = cnt[i];
                ans = i;
            }
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
