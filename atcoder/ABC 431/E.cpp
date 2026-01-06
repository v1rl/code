#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
按什么顺序遍历
什么情况下该换镜子
按照01 bfs遍历
每个点可以根据它来源的不同记四次
维护来源和点本身，再分类讨论去向决定距离进行怎样的更新
*/

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector(m, '0'));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }
    // cerr << 'h';
    deque<array<int, 3>> q;
    vector dist(4, vector(n, vector(m, inf)));

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};


    dist[3][0][0] = 0;
    q.push_back({3, 0, 0});        

    while(q.size()) {
        auto [d, x, y] = q.front();
        q.pop_front();
        if(x == n - 1 && y == m - 1) {
            if((d == 3 && g[x][y] == 'A') || (d == 2 && g[x][y] == 'B')) {
                cout << dist[d][x][y] << '\n';
            } else {
                cout << dist[d][x][y] + 1 << '\n';
            }
            return;
        }

        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(dist[i][nx][ny] < dist[d][x][y]) {
                continue;
            }
            if(g[x][y] == 'A' && i == d) {
                dist[i][nx][ny] = dist[d][x][y];
                q.push_front({i, nx, ny});     
            } else if(g[x][y] == 'B' && ((d == 0 && i == 1) || (d == 1 && i == 0) || (d == 2 && i == 3) || (d == 3 && i == 2))) {
                dist[i][nx][ny] = dist[d][x][y];
                q.push_front({i, nx, ny}); 
            } else if(g[x][y] == 'C' && ((d == 0 && i == 3) || (d == 3 && i == 0) || (d == 2 && i == 1) || (d == 1 && i == 2))) {
                dist[i][nx][ny] = dist[d][x][y];
                q.push_front({i, nx, ny}); 
            } else {
                if(dist[i][nx][ny] < dist[d][x][y] + 1) {
                    continue;
                }
                dist[i][nx][ny] = dist[d][x][y] + 1;
                q.push_back({i, nx, ny});
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