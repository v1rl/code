#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        adj[y].emplace_back(x);
    }

    int t;
    cin >> t;
    queue<int> q;
    vector<int> dist(n + 1, -1);
    while(t --) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            if(dist[x] != -1) {
                continue;
            }
            q.push(x);
            dist[x] = 0;
            while(q.size()) {
                int x = q.front();
                q.pop();

                for(auto y : adj[x]) {
                    if(dist[y] != -1) {
                        continue;
                    }
                    dist[y] = dist[x] + 1;
                    q.push(y);
                }
            }
        } else {
            cout << (dist[x] == -1 ? "No" : "Yes") << '\n';
        }
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
