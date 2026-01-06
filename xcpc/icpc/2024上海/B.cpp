#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

const int inf = 1e9, mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> din(n + 1);
    vector<set<int>> dout(n + 1);
    for(int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        din[x].insert(y);
        din[y].insert(x);
        dout[x].insert(y);
        dout[y].insert(x);
    }
    vector<int> p(n);
    for(int i = 0; i < n; i ++) {
        cin >> p[i];
    }

    int cur = 1;
    vector<array<int, 2>> add;
    vector<int> pa(n + 1);

    int root = p[0];
    auto dfs = [&](auto &&self, int x) -> void {
        if(cur == n) {
            return;
        }
        bool f = false;
        for(auto ori : din[x]) {
            f = true;
            dout[ori].erase(x);
        }
        if(f) {
            din[x].clear();
        }

        if(dout[x].count(p[cur])) {
            pa[p[cur]] = x;
            self(self, p[cur ++]);
        } else {
            if(dout[x].size()) {
                add.push_back({x, p[cur]});
                pa[p[cur]] = x;
                self(self, p[cur ++]);
            } else if(x == root) {
                root = p[cur];
                self(self, p[cur ++]);
            } else {
                self(self, pa[x]);
            }
        }
    };

    dfs(dfs, root);
    cout << add.size() << '\n';
    for(auto [x, y] : add) {
        cout << x << ' ' << y << '\n';
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