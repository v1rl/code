#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://www.luogu.com.cn/problem/P6419
/*
incost[x] 子树x内部所有点到x的来回花销
outcost[x] 子树x外部所有点到x的来回花销
inmx1[x] 子树x内部点到x的最长距离
inmx2[x] 子树x内部点到x的次长距离
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> adj(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    vector<int> people(n + 1);
    for(int i = 1; i <= m; i ++) {
        int x;
        cin >> x;
        people[x] ++;
    }

    vector<i64> inmx1(n + 1), inmx2(n + 1);
    vector<i64> incost(n + 1);
    vector<int> chose(n + 1);
    vector<int> fa(n + 1);
    auto dfs1 = [&](auto &&self, int x) -> void {
        for(auto [y, w] : adj[x]) {
            if(y == fa[x]) {
                continue;
            }
            fa[y] = x;

            self(self, y);
            if(people[y]) {
                people[x] += people[y];
                incost[x] += incost[y] + w * 2;

                i64 val = inmx1[y] + w;
                if(val > inmx1[x]) {
                    inmx2[x] = inmx1[x];
                    inmx1[x] = val;
                    chose[x] = y;
                } else if(val > inmx2[x]) {
                    inmx2[x] = val;
                }
            }
        }
    };

    dfs1(dfs1, 1);

    vector<i64> outcost(n + 1);
    vector<i64> outmx(n + 1);
    auto dfs2 = [&](auto &&self, int x) -> void {
        for(auto [y, w] : adj[x]) {
            if(y == fa[x]) {
                continue;
            }

            if(m - people[y]) {
                if(people[y]) {
                    outcost[y] = incost[x] - incost[y] - 2 * w;
                } else {
                    outcost[y] = incost[x];
                }
                outcost[y] += outcost[x] + 2 * w;

                if(chose[x] == y) {
                    outmx[y] = max(outmx[x], inmx2[x]) + w;
                } else {
                    outmx[y] = max(outmx[x], inmx1[x]) + w;
                }
            }
            self(self, y);
        }
    };

    dfs2(dfs2, 1);

    for(int i = 1; i <= n; i ++) {
        cout << incost[i] + outcost[i] - max(inmx1[i], outmx[i]) << '\n';
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