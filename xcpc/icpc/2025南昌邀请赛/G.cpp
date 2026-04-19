#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int N = 31;
const int inf = 1e9 + 10;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<array<int, 3>> edges;
    edges.reserve(m);
    for(int i = 0; i < m; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }

    vector<array<int, N>> f(n + 1);
    for(int i = 1; i <= n; i ++) {
        f[i][0] = 1;
    }

    for(int i = 1; i < N; i ++) {
        for(auto &[x, y, w] : edges) {
            f[x][i] = max<i64>(f[x][i], min<i64>(inf, 1ll * f[y][i - 1] * w));
        }
    }

    while(q --) {
        int x, d;
        cin >> x >> d;
        for(int i = 0; i < N; i ++) {
            if(d < f[x][i]) {
                cout << i << '\n';
                break;
            }
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
