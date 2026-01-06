#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

const i64 inf = 1e18;
typedef pair<i64, int> PII;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> mn(n + 1, 1e9);
    vector<vector<array<int, 2>>> adj(n + 1);
    for(int i = 0; i < m; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
        mn[x] = min(mn[x], w);
        mn[y] = min(mn[y], w);
    }
    for(int x = 1; x <= n; x ++) {
        for(auto &[y, w] : adj[x]) {
            w = min(w, mn[x] * 2);
        }
    }

    vector<i64> dist(n + 1, inf);
    vector<int> st(n + 1);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({dist[1], 1});
    while(heap.size()) {
        auto [_, x] = heap.top();
        heap.pop();
        if(st[x]) {
            continue;
        }
        st[x] = true;

        for(auto [y, w] : adj[x]) {
            if(dist[y] > dist[x] + w) {
                dist[y] = dist[x] + w;
                heap.push({dist[y], y});
            }
        }
    }

    cout << (dist[n] == inf ? -1 : dist[n]) << '\n';

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