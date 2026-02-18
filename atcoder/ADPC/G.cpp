#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
在有向图的拓扑序上跑dp
*/

const i64 inf = 1e18 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> din(n + 1);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        din[y] ++;
    }
    queue<int> q;
    vector<int> f(n + 1);
    for(int i = 1; i <= n; i ++) {
        if(!din[i]) {
            q.push(i);
            f[i] = 0;
        }
    }

    while(q.size()) {
        int x = q.front();
        q.pop();
        for(auto y : adj[x]) {
            f[y] = f[x] + 1;
            if(--din[y] == 0) {
                q.push(y);
            }
        }
    }

    cout << *max_element(f.begin(), f.end()) << '\n';

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