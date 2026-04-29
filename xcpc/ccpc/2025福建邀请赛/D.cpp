#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9 + 10;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<array<int, 2>> edges;
    vector<int> d(n + 1);
    for(int i = 1; i <= n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
        d[x] ++, d[y] ++;
        edges.push_back({x, y});
    } 

    vector<int> vec4, vec2;
    for(int i = 1; i <= n; i ++) {
        if(d[i] == 4) {
            vec4.emplace_back(i);
        } else if(d[i] == 2) {
            vec2.emplace_back(i);
        }
    }

    auto getCenter = [&]() {
        auto bfs = [&](int sx) -> pair<int, vector<int>> {
            queue<int> q;
            q.push(sx);
            vector<int> dis(n + 1, -1);
            dis[sx] = 0;

            int tar = 0;
            vector<int> p(n + 1);

            while(q.size()) {
                int x = q.front();
                q.pop();

                for(auto y : adj[x]) {
                    if(dis[y] != -1) {
                        continue;
                    }
                    dis[y] = dis[x] + 1;
                    p[y] = x;
                    if(dis[y] > dis[tar]) {
                        tar = y;
                    }
                    q.push(y);
                }
            }

            return {tar, p};
        };

        int A = bfs(1).first;
        auto [B, p] = bfs(A);

        vector<int> path;
        for(int i = B; i != 0; i = p[i]) {
            path.emplace_back(i);
        }

        vector<int> ct;
        ct.emplace_back(path[path.size() / 2]);
        if(path.size() % 2 == 0) {
            ct.emplace_back(path[path.size() / 2 - 1]);
        }
        return ct;
    };

    auto check = [&](int sx, int forbid) {
        vector<int> p(n + 1);
        p[sx] = forbid;
        queue<int> q;
        q.push(sx);
        int siz = 0;

        d[sx] --;

        int root = -1;
        int cnt2 = 0;

        while(q.size()) {
            int x = q.front();
            q.pop();
            if(d[x] == 2) {
                root = x;
                cnt2 ++;
            }
            siz ++;
            for(auto y : adj[x]) {
                if(y == p[x]) {
                    continue;
                }
                p[y] = x;
                q.push(y);
            }
        }

        if(siz == 1) {
            d[sx] ++;
            return true;
        }

        if(cnt2 == 0 || cnt2 > 1) {
            d[sx] ++;
            return false;
        }

        int h = 0;
        while((1 << h) - 1 < siz) {
            h ++;
        }
        if((1 << h) - 1 != siz) {
            d[sx] ++;
            return false;
        }

        p[root] = -1;
        vector<int> dep(n + 1);
        dep[root] = 1;
        q.push(root);
        while(q.size()) {
            int x = q.front();
            q.pop();

            int cnt = 0;
            for(auto y : adj[x]) {
                if(y == p[x] || y == forbid) {
                    continue;
                }
                cnt ++;
                p[y] = x;
                dep[y] = dep[x] + 1;
                q.push(y);
            }

            if(cnt > 0 && cnt != 2) {
                d[sx] ++;
                return false;
            }
            if(cnt == 0 && dep[x] != h) {
                d[sx] ++;
                return false;
            }
        }
        d[sx] ++;
        return true;
    };

    vector<int> mk(n + 1);
    if(vec4.size() > 0) {
        for(auto c : vec4) {
            mk[c] = true;
        }
    } else if(vec2.size() > 0) {
        for(auto c : vec2) {
            mk[c] = true;
        }
    } else {
        auto ct = getCenter();
        for(auto c : ct) {
            mk[c] = true;
        }
    }

    for(int i = 0; i < n - 1; i ++) {
        auto [x, y] = edges[i];
        if(mk[x] || mk[y]) {
            if(check(x, y) && check(y, x)) {
                cout << i + 1 << '\n';
                return;
            } 
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
