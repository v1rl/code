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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector vis(n + 1, vector(m + 1, 0));
    vector<array<int, 2>> q;
    for(int i = 0; i < a; i ++) {
        int x, y;
        cin >> x >> y;
        vis[x][y] = 1;
        q.push_back({x, y});
    }

    vector<array<int, 3>> vec;
    for(int i = 0; i < b; i ++) {
        int x, y, t;
        cin >> x >> y >> t;
        vis[x][y] = 2;
        vec.push_back({t, x, y});
    }

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}; 

    sort(vec.begin(), vec.end());
    int tsp = 0;
    int cnt = a;
    int i = 0;
    while(cnt < n * m) {
        tsp ++;
        if(q.empty()) {
            tsp = max(tsp, vec[i][0]);
        }

        while(i < b && vec[i][0] == tsp) {
            auto [_, x, y] = vec[i];
            vis[x][y] = 0;
            for(int j = 0; j < 4; j ++) {
                int nx = x + dx[j], ny = y + dy[j];
                if(nx < 1 || nx > n || ny < 1 || ny > m) {
                    continue;
                }
                if(vis[nx][ny] == 1) {
                    q.push_back({nx, ny});
                }
            }
            i ++;
        }

        vector<array<int, 2>> nq;
        for(auto [x, y] : q) {
            for(int j = 0; j < 4; j ++) {
                int nx = x + dx[j], ny = y + dy[j];
                if(nx < 1 || nx > n || ny < 1 || ny > m) {
                    continue;
                }
                if(vis[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    cnt ++;
                    nq.push_back({nx, ny});
                }
            }
        }

        q = move(nq);
    }

    cout << tsp << '\n';
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