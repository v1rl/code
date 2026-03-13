#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

const int N = 18;
const int inf = 1e9;

struct DSU {
    vector<int> p;

    DSU(int n) {
        init(n);
    }

    int find(int x) {
        if(x != p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    void init(int n) {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) {
            return false;
        }
        p[y] = x;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> e;
    e.reserve(n);
    for(int i = 1; i <= m; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        e.push_back({z, x, y});
    }

    sort(e.begin(), e.end(), greater());

    DSU dsu(n);

    // 贪心：图->最大生成树
    vector<vector<array<int, 2>>> adj(n + 1);
    for(auto [w, x, y] : e) {
        if(dsu.merge(x, y)) {
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
    }

    queue<int> q;
    vector<int> dep(n + 1);
    vector<array<int, N>> f(n + 1);
    vector<array<int, N>> g(n + 1);
    for(int i = 1; i <= n; i ++) {
        g[i].fill(inf);
    }

    auto build = [&](int r) {
        q.push(r);
        dep[r] = 1;

        while(q.size()) {
            int x = q.front();
            q.pop();

            for(auto [y, w] : adj[x]) {
                if(dep[y]) {
                    continue;
                }
                dep[y] = dep[x] + 1;
                f[y][0] = x;
                g[y][0] = w;
                for(int i = 1; i < N; i ++) {
                    f[y][i] = f[f[y][i - 1]][i - 1];
                    g[y][i] = min(g[y][i - 1], g[f[y][i - 1]][i - 1]);
                }
                q.push(y);
            }
        }
    };

    for(int i = 1; i <= n; i ++) {
        if(!dep[i]) {
            build(i);
        }
    }


    auto lca = [&](int x, int y) {
        int res = inf;
        if(dep[y] > dep[x]) {
            swap(x, y);
        }
        for(int i = N - 1; i >= 0; i --) {
            if(dep[f[x][i]] >= dep[y]) {
                res = min(res, g[x][i]);
                x = f[x][i];
            }
        }

        if(x == y) {
            return res;
        }

        for(int i = N - 1; i >= 0; i --) {
            if(f[x][i] != f[y][i]) {
                res = min({res, g[x][i], g[y][i]});
                x = f[x][i];
                y = f[y][i];
            }
        }

        res = min({res, g[x][0], g[y][0]});
        return res;
    };

    int qy;
    cin >> qy;
    while(qy --) {
        int x, y;
        cin >> x >> y;
        if(!dsu.same(x, y)) {
            cout << -1 << '\n';
        } else {
            cout << lca(x, y) << '\n';
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