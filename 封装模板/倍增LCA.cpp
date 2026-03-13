#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
向上倍增取祖先节点时，超过根节点的部分全部修正为0
在0是根节点本身时代码依然是正确的
*/

const int N = 20;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<int> dep(n + 1);
    vector<array<int, N>> f(n + 1);
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
            for(int i = 1; i < N; i ++) {
                f[y][i] = f[f[y][i - 1]][i - 1];
            }
            q.push(y);
        }
    }
    
    auto lca = [&](int x, int y) -> int {
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
            if(f[y][i] != f[x][i]) {
                x = f[x][i], y = f[y][i];
            }
        }
        return f[x][0];
    };

    auto dist = [&](int x, int y) {
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    };

    auto on = [&](int x, int y, int z) {
        return dist(x, z) + dist(y, z) == dist(x, y);
    };

    auto jump = [&](int x, int y) -> int {
        for(int i = N - 1; i >= 0; i --) {
            if(dep[f[x][i]] > dep[y]) {
                x = f[x][i];
            }
        }
        return x;
    };

    cout << dist(4, 5);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}

