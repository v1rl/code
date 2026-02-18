#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/
const int inf = 1e9 + 10;

void solve() {
    int p;
    cin >> p;

    vector<array<int, 2>> stk;
    int x, y;
    while(cin >> x >> y, x || y) {
        stk.push_back({x, y});
    }


    int n = stk.size();
    vector<vector<array<int, 2>>> adj(n + 1);
    vector<int> nw(n + 1);
    int cnt = 0;
    auto dfs = [&](auto &&self, int &x, int p) -> void {
        auto [w, zw] = stk[x];
        int cur = x;
        adj[p].push_back({x + 1, w});
        if(zw == 0) {
            self(self, ++x, cur + 1);
            self(self, ++x, cur + 1);
        } else {
            cnt ++;
            nw[x + 1] = zw;
        }
    };

    int t = 0;
    dfs(dfs, t, 0);

    int m = cnt * 20;
    vector f(n + 1, vector(m + 1, inf));
    f[0][0] = 0;
    auto work = [&](auto &&self, int x) -> void {
        for(auto [y, w] : adj[x]) {
            if(nw[y]) {
                for(int j = 1; j <= m; j ++) {
                    for(int k = 1; k <= min(j, nw[y]); k ++) {
                        f[y][j] = min(f[y][j], f[x][j - k] + w * 2 + k * 5);
                    }
                }
            } else {
                for(int j = 0; j <= m; j ++) {
                    f[y][j] = f[x][j] + w * 2;
                }
            }
            self(self, y);
            for(int j = 0; j <= m; j ++) {
                f[x][j] = min(f[y][j], f[x][j]);
            }
        }
    };

    work(work, 0);
    for(int j = m; j >= 0; j --) {
        if(f[0][j] < p) {
            cout << j << '\n';
            break;
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