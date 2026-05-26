#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
inpath[x][s] 子树x内部（包括x）集合为s的路径数
outpath[x][s] 子树x内部（不包括x）集合为s的路径数
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<int> mask(n + 1);
    for(int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j ++) {
            int x;
            cin >> x;
            mask[i] |= 1 << (x - 1);
        }
    }

    int base = 0;
    for(int i = 1; i <= n; i ++) {
        if(adj[i].size() >= 2) {
            base |= mask[i];
        }
    }

    vector<array<int, 64>> inpath(n + 1);
    vector<int> isLeaf(n + 1);
    vector<int> fa(n + 1);
    auto dfs1 = [&](auto &&self, int x) -> void {
        for(auto y : adj[x]) {
            if(fa[x] == y) {
                continue;
            }
            fa[y] = x;
            self(self, y);
            for(int s = 0; s < 64; s ++) {
                inpath[x][s | mask[x]] += inpath[y][s];
            }
        }
        if(adj[x].size() == 1 && x != 1) {
            isLeaf[x] = true;
            inpath[x][mask[x]] = 1;
        }
    };

    dfs1(dfs1, 1);

    vector<array<int, 64>> outpath(n + 1);
    auto dfs2 = [&](auto &&self, int x) -> void {
        vector<int> cnt(64);
        for(int s = 0; s < 64; s ++) {
            cnt[s] = outpath[x][s];
            for(auto y : adj[x]) {
                if(y == fa[x]) {
                    continue;
                }
                cnt[s] += inpath[y][s];
            }
        }

        for(auto y : adj[x]) {
            if(y == fa[x]) {
                continue;
            }

            if(x == 1 && adj[x].size() == 1) {
                outpath[y][mask[x]] = 1;
            } else {                
                for(int s = 0; s < 64; s ++) {
                    outpath[y][s | mask[x]] += cnt[s] - inpath[y][s];
                }
            }
            self(self, y);
        }

    };
    dfs2(dfs2, 1);

    for(int x = 1; x <= n; x ++) {
        vector<int> cnt(64);
        int sum = 0;
        for(int s = 0; s < 64; s ++) {
            sum += outpath[x][s];
            cnt[s | mask[x]] += outpath[x][s];
            if(!isLeaf[x]) {
                sum += inpath[x][s];
                cnt[s] += inpath[x][s];
            }
        }

        int mx = 0;
        int req = base | mask[x];
        for(int s = 0; s < 64; s ++) {
            if((req & s) == req) {
                mx = max(mx, cnt[s]);
            }
        }

        cout << sum - mx << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
