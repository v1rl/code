#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<int> bst(n + 1), siz(n + 1, 1);
    siz[0] = 0;
    auto dfs = [&](auto &&self, int x, int p) -> void {
        for(auto y : adj[x]) {
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
    vector<int> cnta(n + 1), cntb(n + 1);
    int sum = 0;
    int tsp = 0;

    auto add = [&](int x) {
        if(a[x]) {
            sum -= min(cnta[a[x]], cntb[a[x]]);
            cnta[a[x]] ++;
            sum += min(cnta[a[x]], cntb[a[x]]);
        } else {
            cnta[a[x]] ++;
        }
        if(b[x]) {
            sum -= min(cnta[b[x]], cntb[b[x]]);
            cntb[b[x]] ++;
            sum += min(cnta[b[x]], cntb[b[x]]);
        } else {
            cntb[b[x]] ++;
        }
    };

    vector<int> ans(n + 1);

    auto work = [&](auto &&self, int x, int p) -> void {
        in[x] = ++tsp;
        ord[tsp] = x;

        for(auto y : adj[x]) {
            if(y == p || y == bst[x]) {
                continue;
            }
            self(self, y, x);
            for(int i = in[y]; i <= out[y]; i ++) {
                cnta[a[ord[i]]] --;
                cntb[b[ord[i]]] --;
            }
            sum = 0;
        }

        if(bst[x]) {
            self(self, bst[x], x);
        }
        add(x);

        for(auto y : adj[x]) {
            if(y == p || y == bst[x]) {
                continue;
            }
            for(int i = in[y]; i <= out[y]; i ++) {
                add(ord[i]);
            }
        }

        if(sum + cnta[0] + cntb[0] >= siz[x]) {
            ans[x] = 1;
        } else {
            ans[x] = 0;
        }

        out[x] = tsp;
    };

    work(work, 1, -1);
    for(int i = 1; i <= n; i ++) {
        cout << ans[i];
    }
    cout << '\n';
}  

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}