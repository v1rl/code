#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
关键词：dfs，子树大小，贪心

题目要求对每个节点作为根节点都做一次统计
一个节点能不能作为LCA存在，看此时（n - 根节点所在子树节点数）是否大于等于k
我们可以 dfs 比较容易的求到每个节点作为LCA存在的次数，求和即可得到答案
*/

const i64 inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    i64 ans = 0;
    vector<int> siz(n + 1, 1);
    auto dfs = [&](auto && self, int x, int p) -> void{
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            self(self, y, x);
            siz[x] += siz[y];
            if(n - siz[y] >= k) {
                ans += siz[y];
            }
        }
        if(siz[x] >= k) {
            ans += n - siz[x];
        }
        // 在统计总答案时，写下面这个也是对的。此时，某一结点的 某个子节点所在子树 作为根的统计在遍历到该子节点时进行
        // if(n - siz[x] >= k) {
        //     ans += siz[x];
        // }
    };
    dfs(dfs, 1, -1);
    cout << ans + n << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}