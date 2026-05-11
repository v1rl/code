#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    if(n != m || n < 2) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    vector g(n, vector(n, 0));
    if(n % 2 == 0) {
        cout << 1 << '\n';
        auto work = [&](int sx, int sy, int col) {
            int cnt = n;
            while(cnt --) {
                g[sx][sy] = col;

                sy ++;
                if(sy == n) {
                    sy = 0;
                }
                g[sx][sy] = col;

                sx ++;
                if(sx == n) {
                    sx = 0;
                }
            }
        };

        for(int i = 1; i <= n / 2; i ++) {
            work(0, (i - 1) * 2, i);
        }
    } else {
        cout << 2 << '\n';
        auto work = [&](int sx, int sy, int col) {
            int cnt = n;
            while(cnt --) {
                g[sx][sy] = col;
                sx ++, sy ++;
                if(sx == n) {
                    sx = 0;
                }
                if(sy == n) {
                    sy = 0;
                }
            }
        };

        for(int i = 1; i <= n; i ++) {
            work(0, i - 1, i);
        }
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
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
