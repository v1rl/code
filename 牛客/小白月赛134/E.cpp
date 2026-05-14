#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

const int inf = 1e9 + 10;
const int M = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    int S = -1;
    vector<int> w(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> w[i];
        if(!w[i]) {
            S = i;
        }
    }

    vector<vector<PII>> adj(n + 1);
    vector<int> ans(m + 1, M);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y, i);
        adj[y].emplace_back(x, i);
    }

    if(S == -1) {
        cout << -1 << '\n';
        return;
    }

    vector<int> dist(n + 1, inf);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    dist[S] = 0;
    heap.push({dist[S], S});

    while(heap.size()) {
        auto [d, x] = heap.top();
        heap.pop();
        if(dist[x] != d) {
            continue;
        }

        for(auto [y, id] : adj[x]) {
            if(dist[y] == inf) {
                if(w[y] < w[x]) {
                    cout << -1 << '\n';
                    return;
                } else {
                    dist[y] = w[y];
                    ans[id] = w[y] - w[x];
                    heap.push({dist[y], y});
                }
            }
        }
    }

    for(int i = 1; i <= m; i ++) {
        cout << ans[i] << '\n';
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
