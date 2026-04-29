#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    if(n < 2 * m || n > 1ll * m * (m + 1) / 2 + 1) {
        cout << "NO" << '\n';
        return;
    }

    int p = n;
    vector<set<int>> adj(n + 1);
    int lst = 1;
    int idx = 1;
    n = 2 * m;
    while(n > 2) {
        adj[lst].insert(++idx);
        adj[lst].insert(++idx);
        n -= 2;
        lst = idx;
    }
    adj[lst].insert(++idx);

    int d = p - 2 * m;
    for(int i = m - 2; i >= 1; i --) {
        int cur = 2 * (i + 2) - 1;
        int lcur = 2 * (i + 1) - 1;
        if(d >= i) {
            d -= i;
            adj[lcur].erase(cur);
            int lst = 1;
            for(int j = 0; j < i; j ++) {
                adj[lst].insert(++ idx);
                lst = idx;
            }
            adj[idx].insert(cur);
        }
    }

    cout << "YES" << '\n';
    for(int x = 1; x <= p; x ++) {
        for(auto y : adj[x]) {
            cout << x << ' ' << y << '\n';
        }
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
