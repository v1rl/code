#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<int> siz(n, 1);
    vector<int> p(n + 1);
    p[0] = -1;
    auto dfs = [&](auto &&self, int x) -> void {
        for(auto y : adj[x]) {
            if(y == p[x]) {
                continue;
            }
            p[y] = x;
            self(self, y);
            siz[x] += siz[y];
        }
    };

    dfs(dfs, 0);

    int l = 0, r = 0;
    i64 ans = 1;
    i64 pre = 1;
    for(auto y : adj[0]) {
        ans += siz[y] * pre;
        pre += siz[y];
    }

    int v0;
    vector<int> vis(n + 1);
    vis[0] = true;
    for(int i = 1; i < n; i ++) {
        bool f = false;
        int x = i;

        if(vis[x]) {
            f = true;
        } else {
            while(x >= 1 && !vis[x]) {
                vis[x] = true;

                if(p[x] == 0) {
                    v0 = x;
                }

                x = p[x];
                if(x == l) {
                    f = true;
                    l = i;
                } else if(x == r) {
                    f = true;
                    r = i;
                }
            }            
        }

        if(f) {
            if(l == 0) {
                ans += 1ll * (siz[l] - siz[v0]) * siz[r];
            } else if(r == 0) {
                ans += 1ll * (siz[r] - siz[v0]) * siz[l];
            } else {
                ans += 1ll * siz[l] * siz[r];
            }
        } else {
            break;
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
