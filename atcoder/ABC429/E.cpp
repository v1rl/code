#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    string s;
    cin >> s;
    s = "#" + s;

    vector<int> st(n + 1);
    queue<int> q;
    vector<array<int, 2>> dist(n + 1, {inf, inf});
    for(int i = 1; i <= n; i ++) {
        if(s[i] == 'S') {
            dist[i] = {0, inf};
            q.push(i);
            st[i] = true;
        }
    }

    vector<int> pre(n + 1);

    while(q.size()) {
        // cerr << 'h';
        int x = q.front();
        q.pop();
        st[x] = false;

        for(auto y : adj[x]) {
            bool f = false;
            if(dist[y][0] == inf) {
                dist[y][0] = dist[x][0] + 1;
                pre[y] = x;
                dist[y][1] = min(dist[x][1] + 1, dist[y][1]);
                f = true;
            } else {
                if(pre[y] != x) {
                    if(dist[y][1] > dist[x][0] + 1) {
                        dist[y][1] = dist[x][0] + 1;
                        f = true;
                    }
                } else {
                    if(dist[y][1] > dist[x][1] + 1) {
                        dist[y][1] = dist[x][1] + 1;
                        f = true;
                    }
                }
            }
            if(!st[y] && f) {
                q.push(y);
                st[y] = true;
            }
        }
    }

    for(int i = 1; i <= n; i ++) {
        if(s[i] == 'D') {
            assert(dist[i][1] != inf);
            cout << min(dist[i][0] * 2 + 2, dist[i][0] + dist[i][1]) << '\n';
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
