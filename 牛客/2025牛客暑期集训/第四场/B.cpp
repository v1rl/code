#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector g(n + 1, vector(m + 1, '0'));
    vector reach(n + 1, vector(m + 1, 0));
    // vector<vector<int>> ones(n + 1);

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            // if(g[i][j] == '1') {
                // cerr << i << ' ' << j << '\n';
            //     ones[i].emplace_back(j);
            // }
        }
    }


    queue<array<int, 2>> q;
    q.push({1, m});
    reach[1][m] = true;
    while(q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i ++) {
            if(i == 3) continue;
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(g[nx][ny] == '1') continue;
            if(reach[nx][ny]) continue;
            reach[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    vector st(n + 1, vector(m + 1, 0));
    q.push({1, 1});
    st[1][1] = true;
    while(q.size()) {
        auto [x, y] = q.front();
        q.pop();
        // int r = min(y + k, m);
        // auto t = upper_bound(ones[x].begin(), ones[x].end(), y);
        // if(t != ones[x].end()) {
        //     int pos = *t;
            // if(x == 1 && y == 1) {
            //     cout << pos << ' ' << r << '\n';
            // }
        //     if(pos > r && !reach[x][pos - 1]) {
        //         cout << "YES" << '\n';
        //         return;
        //     }
        // }
        for(int i = 0; i < 4; i ++) {
            if(i == 1) continue;
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(g[nx][ny] == '1') continue;
            if(st[nx][ny]) continue;
            st[nx][ny] = true;
            q.push({nx, ny});
        }    
    }


    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j < m; j ++) {
            if(!reach[i][j] && st[i][j]) {
                int x = i, y = j;
                while(x >= 1 && g[x][y] == '0') {
                    if(g[x][y + 1] == '0') {
                        cout << "Yes" << '\n';
                        return;
                    }
                    x --;
                }
                x = i + 1;
                while(x <= n && g[x][y] == '0') {
                    if(g[x][y + 1] == '0') {
                        cout << "Yes" << '\n';
                        return;
                    }
                    x ++;                    
                }
                // cout << "Yes" << '\n';
                // return;
            }
        }
    }

    cout << "No" << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
}