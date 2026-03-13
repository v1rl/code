#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;

/*
分层图，0-index更方便写码
拆7个点，6个方向点，1个中继站点
可以缩小到用3个方向点，但6个方向点可以更方便地得到朝向
*/

const i64 inf = 1e18 + 10;
const int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;

    vector vec(6, vector<vector<array<int, 2>>>(n + 1));
    vector<array<int, 2>> cd;

    auto add = [&](int x, int y) {
        int i = cd.size();
        cd.push_back({x, y});
        vec[0][x].push_back({y, i});
        vec[1][x].push_back({-y, i});
        vec[2][y].push_back({x, i});
        vec[3][y].push_back({-x, i});

        // 逆时针旋转到点出现在正方形的上方直线上
        int k = min({x, n - x + 1, y, n - y + 1});
        // 边数为点数-1，所以是+1而不是+2
        int len = n - k * 2 + 1;
        int res = 0;
        while(x != k) {
            res += len;
            swap(x, y);
            x = n - x + 1;
        }
        res += y - k;

        vec[4][k].push_back({res, i});
        vec[5][k].push_back({-res, i});
    };

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    add(sx, sy);
    add(ex, ey);
    int stt = 0, edd = 1;

    for(int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }

    int N = m + 2;
    vector<vector<PII>> adj(N * 7);
    for(int i = 2; i < N; i ++) {
        for(int j = 0; j < 6; j ++) {
            adj[N * 6 + i].push_back({N * j + i, 1});
            adj[N * j + i].push_back({N * 6 + i, 0});
        }
    }

    for(int j = 0; j < 6; j ++) {
        adj[N * 6 + stt].push_back({N * j + stt, 0});
        adj[N * j + edd].push_back({N * 6 + edd, 0});
    }

    for(int t = 0; t < 6; t ++) {
        for(int j = 1; j <= (t < 4 ? n : n / 2); j ++) {
            if(vec[t][j].size() < 1) {
                continue;
            }
            sort(vec[t][j].begin(), vec[t][j].end());

            for(int i = 1; i < vec[t][j].size(); i ++) {
                auto [p, x] = vec[t][j][i - 1];
                auto [q, y] = vec[t][j][i];
                adj[N * t + x].push_back({N * t + y, 2 * (q - p)});
            }

            if(t >= 4) {
                auto [p, x] = vec[t][j].back();
                auto [q, y] = vec[t][j][0];
                int len = 4 * (n - 2 * j + 1);
                adj[N * t + x].push_back({N * t + y, 2 * (q - p + len)});
            }
        }
    }

    vector<int> f(N * 7);

    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> heap;
    vector<i64> dist(N * 7, inf);
    heap.push({0, N * 6 + stt});
    dist[N * 6 + stt] = 0;

    while(heap.size()) {
        auto [d, x] = heap.top();
        heap.pop();
        if(dist[x] != d) {
            continue;
        }

        for(auto [y, w] : adj[x]) {
            if(dist[y] > dist[x] + w) {
                dist[y] = dist[x] + w;
                f[y] = x;
                heap.push({dist[y], y});
            }
        }
    }

    if(dist[N * 6 + 1] == inf) {
        cout << "Impossible!" << '\n';
        return;
    }

    cout << dist[N * 6 + 1] << '\n';
    vector<array<int, 2>> path;

    int x = N * 6 + edd;
    while(x != N * 6 + stt) {
        // 中继站点不参与最终输出，考虑特判，只将入中继站点的边加入路径
        // 也可以将出中继站点的边加入路径，修改方向和点的输出顺序，单独输出终点即可
        if(x / N == 6) {
            path.push_back({f[x] / N, x % N});
        }
        x = f[x];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    cout << sx << ' ' << sy << '\n';
    for(auto [t, i] : path) {
        cout << "EWSNCI"[t] << '\n';
        auto [x, y] = cd[i];
        cout << x << ' ' << y << '\n';
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
