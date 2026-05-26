#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 3>>> adj(n + 1);
    for(int i = 1; i <= m; i ++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        adj[x].push_back({y, a, b});
    }

    int sum = 200 * n;
    vector f(n + 1, vector(sum + 1, inf));

    f[1][0] = 0;
    for(int s = 0; s <= sum; s ++) {
        for(int x = 1; x <= n; x ++) {
            if(f[x][s] == inf) {
                continue;
            }
            for(auto [y, a, b] : adj[x]) {
                if(s + a > sum) {
                    continue;
                }
                f[y][s + a] = min(f[y][s + a], f[x][s] + b);
            }
        }
    }

    i64 ans = 1e18;
    int ansA = 0, ansB = 0;
    for(int s = 0; s <= sum; s ++) {
        if(f[n][s] == inf) {
            continue;
        }
        if(1ll * s * f[n][s] < ans) {
            ans = 1ll * s * f[n][s];
            ansA = s;
            ansB = f[n][s];
        }
    }

    cout << ansA << ' ' << ansB << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}