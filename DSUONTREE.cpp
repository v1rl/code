#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    // 邻接表存图
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 读入颜色
    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    // 读入查询（虽然这题是子树查询，通常DSU on tree会求出所有点的答案，最后按需输出）
    int m;
    cin >> m;
    vector<int> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    // 预处理部分：计算子树大小(siz)、重儿子(son)、DFS序(dfn)
    // dfn序的作用是将子树映射为一段连续的区间，方便后续直接循环处理
    vector<int> siz(n + 1), son(n + 1);
    vector<int> dfn(n + 1), seq(n + 1); // seq是dfn的反向映射
    int timer = 0;

    auto dfs1 = [&](auto &&self, int u, int p) -> void {
        siz[u] = 1;
        dfn[u] = ++timer;
        seq[timer] = u; // 记录dfs序第timer个节点是谁
        
        for (auto v : adj[u]) {
            if (v == p) continue;
            self(self, v, u);
            siz[u] += siz[v];
            if (siz[v] > siz[son[u]]) {
                son[u] = v;
            }
        }
    };
    dfs1(dfs1, 1, 0);

    // 核心 DSU on Tree 部分
    vector<int> cnt(n + 1); // 全局颜色计数桶 (假设颜色值域 <= n，如果很大需要离散化)
    int tot_color = 0;      // 当前子树中不同颜色的数量
    vector<int> ans(n + 1);

    // 修改函数的 Lambda 写法
    auto add = [&](int u) {
        if (cnt[color[u]] == 0) {
            tot_color++;
        }
        cnt[color[u]]++;
    };

    auto del = [&](int u) {
        cnt[color[u]]--;
        if (cnt[color[u]] == 0) {
            tot_color--;
        }
    };

    // dsu 递归函数: u当前节点, p父节点, keep是否保留当前子树信息
    auto dfs2 = [&](auto &&self, int u, int p, bool keep) -> void {
        // 1. 先遍历轻儿子，keep=false (算完就清空)
        for (auto v : adj[u]) {
            if (v != p && v != son[u]) {
                self(self, v, u, false);
            }
        }

        // 2. 再遍历重儿子，keep=true (算完保留，不传回去)
        if (son[u]) {
            self(self, son[u], u, true);
        }

        // 3. 暴力统计树的信息，合并到当前轻儿子子数据中
        // 利用DFS序，轻儿子的子树在 seq 数组中是连续的一段 [dfn[v], dfn[v] + siz[v] - 1]
        for (auto v : adj[u]) {
            if (v != p && v != son[u]) {
                // 遍历轻子树的所有节点
                for (int i = dfn[v]; i < dfn[v] + siz[v]; i++) {
                    add(seq[i]);
                }
            }
        }

        // 4. 加入当前节点 u 自己的贡献
        add(u);

        // 5. 记录答案
        ans[u] = tot_color;

        // 6. 如果当前不是重儿子（keep=false），则清空整个子树的信息
        // 此时子树也是一段连续区间，直接循环删除
        if (!keep) {
            for (int i = dfn[u]; i < dfn[u] + siz[u]; i++) {
                del(seq[i]);
            }
        }
    };

    // 从根节点开始，保留数据(true/false均可，因为根最后不用清空)
    dfs2(dfs2, 1, 0, false);

    // 输出查询结果
    for (int i = 0; i < m; i++) {
        cout << ans[queries[i]] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}