#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
注意到，题目的依赖关系是一个树型结构
注意到，局部的排序就是对依赖同一个点的所有点排序，亦即对一个点所有子节点的排序
而局部有序统一为整体有序的过程就是树中序遍历的过程
如此，我们对所有点执行局部排序后中序遍历输出节点即为答案
但是，我们需要额外对y相等的情况做出判断
显然，题目条件下，所有相等的y应为同一个子节点
我们需要判断是否已经存在值为y的节点，并将所有值为y的节点统一映射到第一个值为y的节点，并在处理节点时，先执行映射
因为还需要存第一个值为y的节点，所以我们用map而不是set
*/

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> res(n + 1);
    vector<int> w(n + 1);

    map<int, int> mp[n + 1];
    vector<int> pa(n + 1);

    for(int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        int fa = (pa[x] ? pa[x] : x);
        if(mp[fa].count(y)) {
            pa[i] = mp[fa][y];
            res[pa[i]].emplace_back(i);
        } else {
            adj[fa].emplace_back(i);
            mp[fa][y] = i;
        }
        w[i] = y;
    }

    for(int i = 0; i <= n; i ++) {
        sort(adj[i].begin(), adj[i].end(),
            [&](auto x, auto y) {
                if(w[x] != w[y]) {
                    return w[x] < w[y];
                }
                return x < y;
            });
    }

    auto dfs = [&](auto &&self, int x) -> void {
        if(x != 0) {
            cout << x << ' ';
            for(auto c : res[x]) {
                cout << c << ' ';
            }
        }
        for(auto y : adj[x]) {
            self(self, y);
        }
    };

    dfs(dfs, 0);
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
