#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 2e9 + 10;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> d(n + 1), cnt(n + 1);
    for(int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        d[x] ++, d[y] ++;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    for(int i = 1; i <= n; i ++) {
        cnt[d[i]] ++;
    }

    vector<int> dist(n + 1, inf), ans(n + 1, inf);
    queue<int> q;

    auto bfs = [&](int U) {
        while(q.size()) {
            int x = q.front();
            q.pop();

            for(auto y : adj[x]) {
                if(d[y] >= U) {
                    continue;
                }
                if(ans[y] > dist[x] + 1) {
                    ans[y] = dist[y] = dist[x] + 1;
                    q.push(y);
                }
            }
        }
    };

    for(int i = n; i >= 1; i --) {
        if(!cnt[i]) {
            continue; 
        }

        for(int x = 1; x <= n; x ++) {
            if(d[x] == i) {
                dist[x] = 0;
                q.push(x);
            }
        }

        bfs(i);
    }

    for(int i = 1; i <= n; i ++) {
        cout << (ans[i] == inf ? -1 : ans[i]) << ' ';
    }
    cout << '\n';
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