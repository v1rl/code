#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
题目需要知道树上所有路径的mex求和，暴力的复杂度在平方级别，于是，我们考虑寻找一个能一次解决大范围数据的数学变换
自然的，联想到能否找到一个算法，可以将mex的值相等的所有路径一次性处理完
考虑条件，树的节点编号为一个排列，且若mex的值为k，则0~k-1的所有点都需要出现在路径上
注意到：树上mex值为k的核心路径是唯一的，我们可以通过维护路径的两个端点xy来维护恰好覆盖该核心路径的点集，也就是将集合区间化
注意到：从mex为k的集合到mex为k+1的集合，这个过程的点集是严格继承并拓展的
于是，对集合的进一步递推只需考虑点k+1与现有点集的关系，也就是现有端点xy与k+1三点中，需要存在一个"当前点在其他两点的路径中"的点
在这个过程中更新xy即可完成对核心路径的维护
随后，我们需要进行包含核心路径的树上路径计数
注意到：树上路径的拐点是唯一的
于是，我们需要对单点路径、有拐点路径和无拐点路径执行不同策略的计数方案
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
    // 而初始xy两个节点相等时的"单点路径"，要做类似C(n, 2)的多集合两两配对处理，此时对配对方案的计算即为如下的前缀式相乘
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
            // 需要注意，对于无拐点路径，深度较浅的点贡献的计数集合是除开路径所在子树的所有点
            ans += 1ll * (n - siz[jump(y, x)]) * siz[y];
        } else if(p == y) {
            ans += 1ll * (n - siz[jump(x, y)]) * siz[x];
        } else {
            // 对于有拐点路径，直接子树相乘
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
