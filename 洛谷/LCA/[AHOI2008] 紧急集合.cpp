#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;
const int N = 24;

const int inf = 1e9 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    queue<int> q;
    q.push(1);
    vector<int> dep(n + 1);
    dep[1] = 1;
    vector<array<int, N>> f(n + 1);
    while(q.size()) {
        int x = q.front();
        q.pop();

        for(auto y : adj[x]) {
            if(dep[y]) {
                continue;
            }
            dep[y] = dep[x] + 1;
            f[y][0] = x;
            for(int i = 1; i < N; i ++) {
                f[y][i] = f[f[y][i - 1]][i - 1];
            }
            q.push(y);
        }
    }


    auto lca = [&](int x, int y) {
        if(dep[y] > dep[x]) {
            swap(x, y);
        }
        for(int i = N - 1; i >= 0; i --) {
            if(dep[f[x][i]] >= dep[y]) {
                x = f[x][i];
            }
        }
        if(x == y) {
            return x;
        }
        for(int i = N - 1; i >= 0; i --) {
            if(f[x][i] != f[y][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }
        return f[x][0];
    };

    /*
    // 暴力
    auto dist = [&](int x, int y) {
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    };

    for(int i = 1; i <= m; i ++) {
        int x, y, z;
        cin >> x >> y >> z;

        vector<int> r{lca(x, y), lca(x, z), lca(y, z)};
        int id = -1, mn = inf;

        for(auto p : r) {
            int cur = dist(x, p) + dist(y, p) + dist(z, p);
            if(cur < mn) {
                mn = cur;
                id = p;
            }
        }

        cout << id << ' ' << mn << '\n';
    }
    */

    // 贪心
    for(int i = 1; i <= m; i ++) {
        int x, y, z;
        cin >> x >> y >> z;

        int hi, lo, t;
        hi = lca(x, y);
        t = lca(y, z);
        if(hi == t) {
            lo = lca(x, z);
        } else {
            lo = t;
        }

        if(dep[hi] > dep[lo]) {
            swap(hi, lo);
        }

        cout << lo << ' ' << dep[x] + dep[y] + dep[z] - dep[lo] - 2 * dep[hi] << '\n';
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