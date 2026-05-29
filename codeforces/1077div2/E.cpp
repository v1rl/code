#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> fa(n + 1);
    for(int i = 1; i < n; i ++) {
        fa[i] = i + 1;
    }
    for(int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        fa[x] = max(fa[x], y);
    }

    vector<int> dep(n + 1);
    for(int i = n - 1; i >= 1; i --) {
        dep[i] = dep[fa[i]] + 1;
    }

    i64 ans = 0;
    vector t = dep;
    sort(t.begin() + 1, t.end());
    for(int l = 1, r = 1; l <= n; l = r) {
        while(r <= n && t[l] == t[r]) {
            r ++;
        }
        // int c = r - l;
        // int g = n - r + 1;
        // ans += 1ll * c * g + 1ll * c * (c - 1);
        ans += 1ll * t[l] * (r - l) * (n - l);
    }

    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i ++) {
        adj[fa[i]].emplace_back(i);
    }

    vector<int> siz(n + 1, 1);
    auto dfs = [&](auto &&self, int x) -> void {
        for(auto &y : adj[x]) {
            self(self, y);
            siz[x] += siz[y];
            if(siz[y] > siz[adj[x][0]]) {
                swap(y, adj[x][0]);
            }
        }
    };

    dfs(dfs, n);

    i64 res = 0;
    vector<int> in(n + 1), out(n + 1), ord(n + 1);
    vector<int> cnt(n + 1);
    int tsp = 0;
    auto work = [&](auto && self, int x) -> void {
        in[x] = ++ tsp;
        ord[tsp] = x;

        for(auto y : adj[x]) {
            if(y == adj[x][0]) {
                continue;
            }
            self(self, y);
            for(int i = in[y]; i <= out[y]; i ++) {
                cnt[dep[ord[i]]] --;
            }
        }

        int pre = 1;
        if(adj[x].size()) {
            self(self, adj[x][0]);
            res += 1ll * siz[adj[x][0]] * pre * dep[x];
            pre += siz[adj[x][0]];
        }
        // res += cnt[dep[x]];
        cnt[dep[x]] ++;

        for(auto y : adj[x]) {
            if(y == adj[x][0]) {
                continue;
            }
            res += 1ll * pre * siz[y] * dep[x];
            pre += siz[y];
            for(int i = in[y]; i <= out[y]; i ++) {
                res += 1ll * dep[x] * cnt[dep[ord[i]]];
            }
            for(int i = in[y]; i <= out[y]; i ++) {
                cnt[dep[ord[i]]] ++;
            }
        }
        out[x] = tsp;
    };

    work(work, n);
    cout << ans - res << '\n';
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