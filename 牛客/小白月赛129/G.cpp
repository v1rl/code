#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 7;
const int N = 30;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<int> dep(n + 1);
    vector<array<int, 20>> f(n + 1);
    dep[1] = 1;
    queue<int> q;
    q.push(1);
    while(q.size()) {
        int x = q.front();
        q.pop();

        for(auto y : adj[x]) {
            if(dep[y]) continue;
            dep[y] = dep[x] + 1;
            f[y][0] = x;
            for(int i = 1; i < 20; i ++) {
                f[y][i] = f[f[y][i - 1]][i - 1];
            }
            q.push(y);
        }
    }

    vector<int> siz(n + 1, 1);
    auto dfs = [&](auto &&self, int x, int p) -> void {
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            self(self, y, x);
            siz[x] += siz[y];
        }
    };

    dfs(dfs, 1, -1);
    
    auto lca = [&](int x, int y) -> int {
        if(dep[x] > dep[y]) swap(x, y);
        for(int i = 19; i >= 0; i --)
            if(dep[f[y][i]] >= dep[x])
                y = f[y][i];
        if(x == y) return x;
        for(int i = 19; i >= 0; i --)
            if(f[y][i] != f[x][i])
                x = f[x][i], y = f[y][i];
        
        return f[x][0];
    };

    auto dist = [&](int x, int y) {
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    };

    while(m --) {
        int x, y;
        cin >> x >> y;
        int d = dist(x, y);
        int p = lca(x, y);

        if((siz[y] > 1 && p == x && n - siz[x] + d + 1 + siz[y] - 1 == n) || (siz[x] > 1 && p == y && n - siz[y] + d + 1 + siz[x] - 1 == n) || d + 1 + siz[x] + siz[y] - 2 == n) {
            cout << d * 2 + 4 << '\n';
        } else if(d + 1 == n) {
            cout << -1 << '\n';
        } else {
            cout << d * 2 + 2 << '\n';
        }
    }
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