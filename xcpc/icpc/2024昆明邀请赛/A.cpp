#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const i64 inf = 1e18;

struct Node {
    int level;
    i64 sum = 0;
    int cnt, id;
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n, vector(m, 0));
    vector<vector<int>> pos(n);
    vector<Node> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].level;
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
            if(g[i][j] == -1) {
                pos[i].emplace_back(j);
                a[i].cnt ++;
            } else {
                a[i].sum += g[i][j];
            }
        }
        a[i].id = i;
    }

    sort(a.begin(), a.end(), 
        [&](auto &x, auto &y) {
            if(x.level != y.level) {
                return x.level > y.level;
            }
            return x.sum + 1ll * x.cnt * k > y.sum + 1ll * y.cnt * k;
        });

    i64 lst = inf;
    for(int i = 0; i < n; i ++) {
        auto [level, sum, cnt, id] = a[i];
        i64 tar;
        if(i != 0 && level == a[i - 1].level) {
            tar = lst;
        } else {
            tar = lst - 1;
        }

        i64 l = sum, r = sum + 1ll * cnt * k;
        i64 cur = min(tar, r);
        if(cur < l) {
            cout << "No" << '\n';
            return;
        }
        i64 d = cur - sum;
        for(auto c : pos[id]) {
            i64 p = min<i64>(k, d);
            g[id][c] = p;
            d -= p;
        }

        lst = cur;
    }

    cout << "Yes" << '\n';
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
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
