#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
in[x][i] 子树x内部（不包括x）含有樱桃i的路径条数
out[x][i] 子树x外部（不包括x）含有樱桃i的路径条数
incnt[x] 子树x内部（包括x）的路径条数
outcnt[x] 子树x外部（不包括x）的路径条数
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

    vector kind(n + 1, vector(m + 1, 0));
    for(int i = 1; i <= n; i ++) {
        int t;
        cin >> t;
        for(int j = 1; j <= t; j ++) {
            int x;
            cin >> x;
            kind[i][x] ++;
        }
    }

    vector<int> incnt(n + 1);
    vector<int> fa(n + 1);
    vector<int> isLeaf(n + 1);
    vector in(n + 1, vector(m + 1, 0));
    auto dfs1 = [&](auto &&self, int x) -> void {
        for(auto y : adj[x]) {
            if(y == fa[x]) {
                continue;
            }
            fa[y] = x;

            self(self, y);
            incnt[x] += incnt[y];
            for(int i = 1; i <= m; i ++) {
                if(kind[y][i]) {
                    in[x][i] += incnt[y];
                } else {
                    in[x][i] += in[y][i];
                }
            }
        }
        if(adj[x].size() == 1 && fa[x] != 0) {
            isLeaf[x] = true;
            incnt[x] = 1;        
        } 
    };

    dfs1(dfs1, 1);

    vector out(n + 1, vector(m + 1, 0));
    vector<int> outcnt(n + 1);
    auto dfs2 = [&](auto &&self, int x) -> void {
        for(auto y : adj[x]) {
            if(y == fa[x]) {
                continue;
            }

            if(x == 1 && adj[x].size() == 1) {
                outcnt[y] = 1;
            } else {
                outcnt[y] = incnt[x] - incnt[y] + outcnt[x];
            }

            for(int i = 1; i <= m; i ++) {
                if(kind[x][i]) {
                    out[y][i] = outcnt[y];
                } else {
                    out[y][i] = in[x][i] - (kind[y][i] ? incnt[y] : in[y][i]);
                    out[y][i] += out[x][i];
                }
            }
            self(self, y);
        }
    };

    dfs2(dfs2, 1);

    for(int i = 1; i <= n; i ++) {
        int sum = outcnt[i];
        if(!isLeaf[i]) {
            sum += incnt[i];
        }

        int ans = 0;
        for(int j = 1; j <= m; j ++) {
            if(kind[i][j]) {
                continue;
            }
            int num = in[i][j] + out[i][j];
            ans += min(num, sum - num);
        }
        cout << ans << ' ';
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
