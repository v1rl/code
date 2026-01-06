#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    vector g(n, vector(n, 0));
    int x = 0, y = n / 2;
    g[x][y] = 1;
    int cnt = 2;
    while(cnt <= n * n) {
        int nx = x - 1, ny = y + 1;
        if(nx < 0) {
            nx = n - 1;
        }
        if(ny == n) {
            ny = 0;
        }
        if(g[nx][ny] == 0) {
            g[nx][ny] = cnt ++;
        } else {
            nx = x + 1;
            ny = y;
            if(nx == n) {
                nx = 0;
            }
            g[nx][ny] = cnt ++;
        }
        x = nx, y = ny;
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << g[i][j] << " \n"[j == n - 1];
        }
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
