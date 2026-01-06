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

    vector<array<int, 20>> f(n);
    vector<int> dep(n);

    queue<int> q;
    q.push(0);
    dep[0] = 1;
    while(q.size()) {
        int x = q.front();
        q.pop();

        for(auto y : adj[x]) {
            if(dep[y]) {
                continue;
            }
            dep[y] = dep[x] + 1;
            f[y][0] = x;
            for(int i = 1; i < 20; i ++) {
                f[y][i] = f[f[y][i - 1]][i - 1];
            }
            q.push(y);
        }
    }

    vector<int> siz(n, 1);
    auto dfs = [&](auto &&self, int x, int p) -> void {
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            self(self, y, x);
            siz[x] += siz[y];
        }
    };

    dfs(dfs, 0, -1);

    auto lca = [&](int x, int y) -> int {
        if(dep[x] > dep[y]) {
            swap(x, y);
        }
        for(int i = 19; i >= 0; i --) {
            if(dep[f[y][i]] >= dep[x]) {
                y = f[y][i];
            }
        }
        if(x == y) {
            return x;
        }
        for(int i = 19; i >= 0; i --) {
            if(f[x][i] != f[y][i]) {
                x = f[x][i], y = f[y][i];
            }
        }
        return f[x][0];
    };

    auto dist = [&](int x, int y) -> int {
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    };

    auto on = [&](int x, int y, int z) {
        return dist(x, z) + dist(y, z) == dist(x, y);
    };

    auto jump = [&](int x, int y) -> int {
        for(int i = 19; i >= 0; i --) {
            if(dep[f[x][i]] >= dep[y] + 1) {
                x = f[x][i];
            }
        }
        return x;
    };

    // 需要注意，一般情况为只存在两个集合的双集合两两配对处理，此时对配对方案的计算即为类似笛卡尔积简单相乘
    // 而初始xy两个节点相等时，要做类似C(n, 2)的多集合两两配对处理，此时对配对方案的计算即为如下的前缀式相乘
    // 另外，此时的根节点0是单独的一个配对集合，所以我们让pre初始为1；两点都为0是一个单独的特殊配对，所以我们让ans初始为1
    int x = 0, y = 0;
    i64 ans = 1;
    i64 pre = 1;
    for(auto y : adj[0]) {
        ans += siz[y] * pre;
        pre += siz[y];
    }

    for(int i = 1; i < n; i ++) {
        int z = i;
        if(on(x, y, z)) {
            ;
        } else if(on(x, z, y)) {
            y = z;
        } else if(on(y, z, x)) {
            x = z;
        } else {
            // cout << z << '\n';
            break;
        }

        int p = lca(x, y);
        if(p == x) {
            // 需要注意，当xy的lca与其中某一点重合时，"lca重合点"端的点集为抛开"非lca重合点"所在子树外的所有点
            ans += 1ll * (n - siz[jump(y, x)]) * siz[y];
        } else if(p == y) {
            ans += 1ll * (n - siz[jump(x, y)]) * siz[x];
        } else {
            ans += 1ll * siz[y] * siz[x];
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
