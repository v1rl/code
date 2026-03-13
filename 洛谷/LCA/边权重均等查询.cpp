#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

// https://leetcode.cn/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/description/

const int N = 18;

void solve() {
    int n;
    cin >> n;
    vector<vector<array<int, 2>>> adj(n + 1);
    for(int i = 1; i < n; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    queue<int> q;
    q.push(1);
    vector<int> dep(n + 1);
    dep[1] = 1;
    
    vector<array<int, 27>> cnt(n + 1);
    vector<array<int, N>> f(n + 1);

    while(q.size()) {
        int x = q.front();
        q.pop();

        for(auto [y, w] : adj[x]) {
            if(dep[y]) {
                continue;
            }
            dep[y] = dep[x] + 1;
            f[y][0] = x;
            for(int i = 1; i < N; i ++) {
                f[y][i] = f[f[y][i - 1]][i - 1];
            }
            cnt[y] = cnt[x];
            cnt[y][w] ++;
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
                x = f[x][i], y = f[y][i];
            }
        }
        return f[x][0];
    };

    int qy;
    cin >> qy;
    while(qy --) {
        int x, y;
        cin >> x >> y;
        int p = lca(x, y);
        int s = 0;
        int mx = 0;
        for(int i = 1; i <= 26; i ++) {
            int cur = cnt[x][i] + cnt[y][i] - 2 * cnt[p][i];
            s += cur;
            mx = max(mx, cur);
        }
        cout << s - mx << '\n';
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