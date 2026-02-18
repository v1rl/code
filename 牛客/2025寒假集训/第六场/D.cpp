#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 2e9;

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    vector<array<int, 2>> a(p);
    for(int i = 0; i < p; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> heap;
    vector dist(n + 1, vector(m + 1, inf));
    vector g(n + 1, vector(m + 1, 0));
    vector vis(n + 1, vector(m + 1, 0));

    for(int i = 0; i < q; i ++) {
        int x, y, t;
        cin >> x >> y >> t;

        g[x][y] = t;
    }


    for(auto [x, y] : a) {
        dist[x][y] = 0;
        heap.push({0, x, y});
    }


    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

    int ans = 0;
    while(heap.size()) {
        auto [d, x, y] = heap.top();
        heap.pop();

        if(vis[x][y]) {
            continue;
        }
        // cerr << d << ' ' << x << ' ' << y << '\n';
        vis[x][y] = true;
        ans = max(d, ans);

        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            if(vis[nx][ny]) {
                continue;
            }

            // cerr << nx << ' ' << ny << ' ' << dist[x][y] + 1 << '\n';
            if(max(g[nx][ny], dist[x][y] + 1) < dist[nx][ny]) {
                dist[nx][ny] = max(g[nx][ny], dist[x][y] + 1);
                heap.push({max(g[nx][ny], dist[x][y] + 1), nx, ny});
            }
        }
    }


    // cout << dist[1][4] << '\n';
    cout << ans << '\n';

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