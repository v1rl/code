#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    queue<int> q;
    int cnt = 0;
    vector<int> vis(n + 1);
    for(int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        if(x == 0 && y == 0) {
            cnt ++;
            vis[i] = true;
            q.push(i);
        } else {
            adj[x].emplace_back(i);
            adj[y].emplace_back(i);
        }
    }
    while(q.size()) {
        int x = q.front();
        q.pop();

        for(auto y : adj[x]) {
            if(!vis[y]) {
                cnt ++;
                vis[y] = true;
                q.push(y);
            }
        }
    }

    cout << cnt << '\n';
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