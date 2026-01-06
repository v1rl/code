#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// 有乘法时记得开i64
// 一条路径重合则整体重合
// 若要对第一条边单独处理，则相应的在开始时单独初始化st，结束时单独更新mp
// 要判断反向边，所以需要存边，且需要同时存边保证正反边的连续

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> doors(n + 1);
    vector<int> edges;
    int cnt = 0;
    edges.reserve(n * 3);
    set<i64> S;
    for(int i = 1; i <= n; i ++) {
        int t;
        cin >> t;
        for(int j = 1; j <= t; j ++) {
            int y;
            cin >> y;
            int x = i;
            doors[x].emplace_back(y);

            if(x > y) swap(x, y);
            i64 ls = 1ll * x * n + y;
            if(S.count(ls)) continue;

            adj[x].emplace_back(cnt ++);
            edges.emplace_back(y);
            adj[y].emplace_back(cnt ++);
            edges.emplace_back(x);

            S.insert(ls);
        }
    }

    vector<int> mp(cnt);
    for(int i = 1; i <= n; i ++) {
        int fx = i;
        int fy = doors[fx][0];
        int fedge;
        for(auto e : adj[fx]) {
            if(edges[e] == fy) {
                fedge = e;
                break;
            }
        }

        if(mp[fedge]) {
            cout << mp[fedge] << '\n';
            continue;
        }

        set<int> st;
        vector<int> res;
        auto dfs = [&](auto && self, int u, int x, int p) -> int{
            int tar;
            for(int j = 0; j < doors[x].size(); j ++) {
                int y = doors[x][j];
                if(y == p) {
                    tar = (j + 1) % doors[x].size();
                    break;
                }
            }
            int y = doors[x][tar];
            int edge;
            for(auto e : adj[x]) {
                if(edges[e] == y) {
                    edge = e;
                    break;
                }
            }

            if(x == fx && y == fy) {
                return u;
            }
            st.insert(edge);

            res.emplace_back(edge);
            if(st.count(edge ^ 1)) {
                return self(self, u, y, x);
            } else {
                return self(self, u + 1, y, x);
            }
        };
        st.insert(fedge);
        int ans = dfs(dfs, 1, fy, fx);

        mp[fedge] = ans;
        for(auto c : res) {
            mp[c] = ans;
        }

        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
}