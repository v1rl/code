#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

const int inf = 1e9 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> col(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> col[i];
    }

    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<int> siz(n + 1, 1);
    vector<int> bst(n + 1);
    siz[0] = 0;
    auto dfs = [&](auto &&self, int x, int p) -> void {
        for(auto &y : adj[x]) {
            if(y == p) {
                continue;
            }
            self(self, y, x);
            siz[x] += siz[y];
            if(siz[y] > siz[bst[x]]) {
                bst[x] = y;
            }
        }
    };

    dfs(dfs, 1, -1);

    vector<int> in(n + 1), out(n + 1), ord(n + 1);
    vector<int> cnt(n + 1);
    vector<i64> ans(n + 1);
    int tsp = 0;
    i64 mx = 0, res = 0;

    auto add = [&](int x) {
        cnt[x] ++;
        if(cnt[x] > mx) {
            mx = cnt[x];
            res = x;
        } else if(cnt[x] == mx) {
            res += x;
        }
    };

    auto work = [&](auto &&self, int x, int p) -> void {
        in[x] = ++ tsp;
        ord[tsp] = x;

        for(auto y : adj[x]) {
            if(y == bst[x] || y == p) {
                continue;
            }
            self(self, y, x);
            for(int i = in[y]; i <= out[y]; i ++) {
                cnt[col[ord[i]]] --;
            }
            mx = res = 0;
        }

        if(bst[x]) {
            self(self, bst[x], x);
        }
        add(col[x]);

        for(auto y : adj[x]) {
            if(y == bst[x] || y == p) {
                continue;
            }
            for(int i = in[y]; i <= out[y]; i ++) {
                add(col[ord[i]]);
            }
        }
        ans[x] = res;

        out[x] = tsp;
    };

    work(work, 1, -1);
    for(int i = 1; i <= n; i ++) {
        cout << ans[i] << " \n"[i == n];
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