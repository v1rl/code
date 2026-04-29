#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;
#define int long long

const int inf = 1e9;
typedef array<int, 3> PII;

void solve() {
    int n, m, sx, sy, tx, ty;

    while(cin >> n >> m >> sx >> sy >> tx >> ty && n != 0) {
        auto get = [&](int x, int y) {
            return m * (x - 1) + y;
        };
        vector<vector<array<int, 3>>> adj(n * m + 1);
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j < m; j ++) {
                int x = get(i, j);
                int y = get(i, j + 1);
                int w;
                cin >> w;
                adj[x].push_back({y, w, 0});
                adj[y].push_back({x, w, 0});
            }
            if(i != n) {
                for(int j = 1; j <= n; j ++) {
                    int x = get(i, j);
                    int y = get(i + 1, j);
                    int w;
                    cin >> w;
                    adj[x].push_back({y, w, 1});
                    adj[y].push_back({x, w, 1});
                }
            }
        }

        vector dist(n * m + 1, vector(8, inf));
        vector vis(n * m + 1, vector(8, 0));
        int stt = get(sx, sy);
        int edd = get(tx, ty);

        dist[stt][0] = 0;
        dist[stt][3] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        heap.push({0, stt, 0});
        heap.push({0, stt, 3});

        while(heap.size()) {
            auto [d, x, op] = heap.top();
            heap.pop();

            if(vis[x][op]) {
                continue;
            }
            vis[x][op] = true;

            auto work = [&](int w, int A, int y, int yop) {
                int nd = d + w * A;
                if(nd < dist[y][yop]) {
                    dist[y][yop] = nd;
                    heap.push({nd, y, yop});
                }
            };

            if(op == 0) {
                for(auto [y, w, eop] : adj[x]) {
                    if(eop) {
                        continue;
                    }
                    work(w, 2, y, 1);
                    work(w, 2, y, 2);
                }
            } else if(op == 1) {
                for(auto [y, w, eop] : adj[x]) {
                    if(eop) {
                        continue;
                    }
                    work(w, 1, y, 1);
                    work(w, 2, y, 2);
                }
            } else if(op == 2) {
                work(0, 0, x, 3);
            } else if(op == 3) {
                for(auto [y, w, eop] : adj[x]) {
                    if(!eop) {
                        continue;
                    }
                    work(w, 2, y, 4);
                    work(w, 2, y, 5);
                }
            } else if(op == 4) {
                for(auto [y, w, eop] : adj[x]) {
                    if(!eop) {
                        continue;
                    }
                    work(w, 1, y, 4);
                    work(w, 2, y, 5);
                }
            } else {
                work(0, 0, x, 0);
            }
        }
        cout << min(dist[edd][2], dist[edd][5]) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --) {
        solve();
    }

    return 0;
}

