#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://codeforces.com/problemset/problem/708/C

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<int> siz(n + 1, 1);
    vector<int> mx1(n + 1, 0);
    vector<int> mx2(n + 1, 0);
    vector<int> chose(n + 1);
    vector<int> fa(n + 1, -1);

    auto dfs1 = [&](auto &&self, int x) -> void {
        for(auto y : adj[x]) {
            if(y == fa[x]) {
                continue;
            }
            fa[y] = x;
            self(self, y);
            siz[x] += siz[y];

            int val = siz[y] <= n / 2 ? siz[y] : mx1[y];
            if(val > mx1[x]) {
                mx2[x] = mx1[x];
                mx1[x] = val;
                chose[x] = y;
            } else if(val > mx2[x]) {
                mx2[x] = val;
            }
        }
    };

    dfs1(dfs1, 1);

    vector<int> out(n + 1);
    out[1] = 0;
    auto dfs2 = [&](auto &&self, int x) -> void {
        for(auto y : adj[x]) {
            if(y == fa[x]) {
                continue;
            }
            fa[y] = x;

            if(n - siz[y] <= n / 2) {
                out[y] = n - siz[y];
            } else if(chose[x] == y) {
                out[y] = max(out[x], mx2[x]);
            } else {
                out[y] = max(out[x], mx1[x]);
            }

            self(self, y);
        }
    };

    dfs2(dfs2, 1);

    auto check = [&](int x) {
        for(auto y : adj[x]) {
            if(y == fa[x]) {
                continue;
            }
            if(siz[y] > n / 2) {
                return siz[y] - mx1[y] <= n / 2;
            }
        }

        if(n - siz[x] > n / 2) {
            return n - siz[x] - out[x] <= n / 2;
        }
        return true;
    };

    for(int i = 1; i <= n; i ++) {
        cout << check(i) << ' ';
    }
    cout << '\n';
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