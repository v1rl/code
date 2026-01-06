#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
关键词：树的直径，贪心

求每个点与其他所有点中距离最远的点，且存在多个点满足条件时取值最大的那个点
考虑到树的直径性质：对于任意一个点，距离它最远的点一定在树的直径对应的两个点之中

但除此之外，我们还需要保证取到值最大的点
因此在两次bfs找树的直径时，每次我们都选择距离最远且值最大的点
*/

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    auto work = [&](int rt) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.push(rt);
        dist[rt] = 0;
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
        return dist;
    };

    vector<int> d1 = work(1);
    int mx = 0;
    int s = 0;
    for(int i = n; i > 0; i --) {
        if(d1[i] > mx) {
            mx = d1[i];
            s = i;
        }
    }
    vector<int> d2 = work(s);
    int t = 0;
    mx = 0;
    for(int i = n; i > 0; i --) {
        if(d2[i] > mx) {
            mx = d2[i];
            t = i;
        }
    }

    vector<int> d3 = work(t);
    
    for(int i = 1; i <= n; i ++) {
        int ans;
        if(d2[i] > d3[i]) {
            ans = s;
        } else if(d2[i] < d3[i]) {
            ans = t;
        } else {
            ans = max(s, t);
        }
        cout << ans << '\n';
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
