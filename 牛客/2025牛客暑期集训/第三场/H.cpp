#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// 不会回头，向一个方向一直走
// lca点往上的路径可以共享    X
// dfs？上一个有标记的点，看当前点是否可以承接上一个点，返回min(递归后的结果 - 1，inf / min(上一个有标记的点 + 距离, 当前点右端点））

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for(int i = 2; i <= n; i ++) {
        int y = i;
        int x;
        cin >> x;
        adj[x].emplace_back(y);
    }

    vector<array<int, 2>> range(n + 1);
    for(int i = 1; i <= k; i ++) {
        int x, l, r;
        cin >> x >> l >> r;
        range[x] = {l, r};
    }

    auto dfs = [&]()

}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    sieve(5000000);
    while(t --)
    {
        solve();
    }
}