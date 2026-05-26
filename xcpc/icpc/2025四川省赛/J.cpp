#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '#' + s;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<int> fa(n + 1);
    auto dfs = [&](auto &&self, int x) -> void {
        for(auto y : adj[x]) {
            if(y == fa[x]) {
                continue;
            }
            fa[y] = x;
            self(self, y);
        }
    };

    dfs(dfs, 1);

    string pre = "SCCPC";
    string suf = "CPCCS";

    vector<array<int, 6>> preNum(n + 1);
    vector<array<int, 6>> sufNum(n + 1);

    for(int i = 1; i <= n; i ++) {
        if(s[i] == 'S') {
            int cnt = 0;
            int x = i;
            while(x && cnt < 5 && s[x] == pre[cnt]) {
                cnt ++;
                preNum[x][cnt] ++;
                x = fa[x];
            }
        } else if(s[i] == 'C') {
            int cnt = 0;
            int x = i;
            while(x && cnt < 5 && s[x] == suf[cnt]) {
                cnt ++;
                sufNum[x][cnt] ++;
                x = fa[x];
            }
        }
    }

    i64 ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= 5; j ++) {
            if(j == 4) {
                // SCCP CP
                ans += 1ll * preNum[i][j] * (sufNum[i][6 - j] - 1);
            } else {
                ans += 1ll * preNum[i][j] * sufNum[i][6 - j];
            }
        }
    }
    cout << ans << '\n';
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