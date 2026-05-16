#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
typedef pair<int, int> PII;

void solve() {
    int n;
    cin >> n;
    vector<vector<PII>> adj(n + 1);
    for(int i = 1; i <= n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back({y, 0});
        adj[y].push_back({x, 1});
    }

    vector<i64> sum(n + 1);
    auto dfs1 = [&](auto &&self, int x, int p) -> void {
        for(auto [y, op] : adj[x]) {
            if(y == p) {
                continue;
            }
            self(self, y, x);
            sum[x] += sum[y];
            if(op == 1) {
                sum[x] ++;
            }
        }
    };
    dfs1(dfs1, 1, -1);

    auto dfs2 = [&](auto &&self, int x, int p) -> void {
        for(auto [y, op] : adj[x]) {
            if(y == p) {
                continue;
            }
            if(op) {
                sum[y] = sum[x] - 1;
            } else {
                sum[y] = sum[x] + 1;
            }
            self(self, y, x);
        }
    };
    dfs2(dfs2, 1, -1);

    int mn = *min_element(sum.begin() + 1, sum.end());
    cout << mn << '\n';
    for(int i = 1; i <= n; i ++) {
        if(sum[i] == mn) {
            cout << i << ' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}