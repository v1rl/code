#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// http://poj.org/problem?id=2947

const int mod = 7;

pair<int, vector<int>> gauss(int n, int m, auto &g) {
    for(int x = 1; x <= m; x ++) {
        for(int i = 1; i <= n; i ++) {
            if(i < x && g[i][i] != 0) {
                continue;
            }
            if(g[i][x] > 0) {
                swap(g[i], g[x]);
                break;
            }
        }

        if(g[x][x] == 0) {
            continue;
        }

        for(int i = 1; i <= n; i ++) {
            if(i != x && g[i][x] != 0) {
                int d = gcd(g[i][x], g[x][x]);
                int a = g[x][x] / d;
                int b = g[i][x] / d;
                for(int j = min(i, x); j <= m + 1; j ++) {
                    g[i][j] = ((g[i][j] * a - g[x][j] * b) % mod + mod) % mod;
                }
            }
        }
    }

    vector<int> inv(mod + 1);
    inv[1] = 1;
    for(int i = 2; i <= mod; i ++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }

    int f = 1;
    vector<int> ans(m + 1);
    for(int x = 1; x <= m; x ++) {
        if(g[x][x] == 0) {
            if(g[x][m + 1] == 0) {
                f = 0;
            } else {
                f = -1;
                break;
            }
        } else {
            ans[x] = g[x][m + 1] * inv[g[x][x]] % mod;
        }
    }

    return {f, ans};
}

void solve() {
    int n, m;
    map<string, int> mp {
        {"MON", 1},
        {"TUE", 2},
        {"WED", 3},
        {"THU", 4},
        {"FRI", 5},
        {"SAT", 6},
        {"SUN", 7}
    };
    while(cin >> n >> m, n && m) {
        vector g(max(n, m) + 1, vector(n + 2, 0));
        for(int i = 1; i <= m; i ++) {
            int t;
            cin >> t;
            string s, e;
            cin >> s >> e;
            g[i][n + 1] = (mp[e] - mp[s] + 1 + mod) % mod;
            for(int j = 1; j <= t; j ++) {
                int x;
                cin >> x;
                g[i][x] ++;
                if(g[i][x] >= mod) {
                    g[i][x] -= mod;
                }
            }
        }

        auto [f, ans] = gauss(m, n, g);
        if(f == 0) {
            cout << "Multiple solutions." << '\n';
        } else if(f == -1) {
            cout << "Inconsistent data" << '\n';
        } else {
            for(int i = 1; i <= n; i ++) {
                if(ans[i] < 3) {
                    ans[i] += 7;
                }
                cout << ans[i] << ' ';
            }
            cout << '\n';
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