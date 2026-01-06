#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 2e9;
#define int long long

const int maxh = 30;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> adj(n + 1);

    for(int i = 1; i <= n; i ++) {
        int l, r;
        cin >> l >> r;
        adj[i] = {l, r};
    }

    vector<int> h(n + 1);
    vector<int> siz(n + 1, 1);
    h[1] = 1;
    auto idfs = [&](auto && self, int x) -> void {
        bool f = true;
        for(int i = 0; i < 2; i ++) {
            int y = adj[x][i];
            if(y) {
                h[y] = h[x] + 1;
                self(self, y);
                siz[x] += siz[y];
                f = false;
            }
        }
    };
    idfs(idfs, 1);

    vector<array<int, maxh + 1>> f(n + 1);
    for(auto &c : f) {
        c.fill(inf);
    }

    f[0][0] = 0, f[0][1] = 1;
    for(int i = 2; i <= maxh; i ++) {
        f[0][i] = f[0][i - 1] + f[0][i - 2] + 1;
    }

    auto dfs = [&](auto &&self, int x) -> void {
        f[x][0] = siz[x];
        f[x][1] = f[x][0] - 1;
        for(int i = 0; i < 2; i ++) {
            int y = adj[x][i];
            if(y) {
                self(self, y);
            }
        }
        int l = adj[x][0], r = adj[x][1];
        for(int i = 2; i <= maxh; i ++) {
            f[x][i] = min({f[l][i - 1] + f[r][i - 1], f[l][i - 2] + f[r][i - 1], f[l][i - 1] + f[r][i - 2]});
        }
    };

    dfs(dfs, 1);

    // for(int i = 1; i <= maxh; i ++) {
    //     cout << i << ' ' << f[1][i] << '\n';
    // }

    cout << *min_element(f[1].begin(), f[1].end()) << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;  
    cin >> t;
    while(t --) {
        solve();
    }
}