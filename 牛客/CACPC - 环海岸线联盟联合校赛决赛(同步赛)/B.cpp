#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
树
先集合再走和各自分别走取最小值

汇合所需的次数+一起向上的次数

*/

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 17;
const i64 inf = 1e18;

void solve() {
    i64 n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> adj(n + 1);
    int R = 0;
    for(int x = 1; x <= n; x ++) {
        int y;
        cin >> y;
        if(y == 0) {
            R = x;
        } else {
            adj[y].emplace_back(x);
        }
    }    

    vector<int> dep(n + 1);
    queue<int> q;
    dep[R] = 1;
    q.push(R);
    vector<array<int, N>> f(n + 1);
    while(q.size()) {
        int x = q.front();
        q.pop();

        for(auto y : adj[x]) {
            dep[y] = dep[x] + 1;
            f[y][0] = x;
            for(int i = 1; i < N; i ++) {
                f[y][i] = f[f[y][i - 1]][i - 1];
            }
            q.push(y);
        }
    }

    auto lca = [&](int x, int y) {
        if(dep[y] > dep[x]) {
            swap(x, y);
        }
        for(int i = N - 1; i >= 0; i --) {
            if(dep[f[x][i]] >= dep[y]) {
                x = f[x][i];
            }
        }
        if(x == y) {
            return x;
        }
        for(int i = N - 1; i >= 0; i --) {
            if(f[x][i] != f[y][i]) {
                x = f[x][i], y = f[y][i];
            }
        }
        return f[x][0];
    };

    vector<int> dis(n + 1);
    for(int i = 1; i <= n; i ++) {
        int d = dep[i] - dep[R];
        for(int j = N - 1; j >= 0; j --) {
            if(d >> j & 1) {
                dis[i] ++;
            }
        }
    }

    while(m --) {
        int x, y;
        cin >> x >> y;
        int p = lca(x, y);

        i64 ans = inf;
        // int cnt = 0;
        while(p != 0) {
            int cnt1 = 0, cnt2 = 0;
            int d1 = dep[x] - dep[p];
            int d2 = dep[y] - dep[p];
            for(int i = N - 1; i >= 0; i --) {
                if(d1 >> i & 1) {
                    cnt1 ++;
                }
            }
            for(int i = N - 1; i >= 0; i --) {
                if(d2 >> i & 1) {
                    cnt2 ++;
                }
            }
            ans = min(ans, (cnt1 + cnt2) * a + dis[p] * b);
            p = f[p][0];
        }

        int cnt1 = 0, cnt2 = 0;
        int d1 = dep[x] - dep[R];
        int d2 = dep[y] - dep[R];
        for(int i = N - 1; i >= 0; i --) {
            if(d1 >> i & 1) {
                cnt1 ++;
            }
        }
        for(int i = N - 1; i >= 0; i --) {
            if(d2 >> i & 1) {
                cnt2 ++;
            }
        }
        ans = min(ans, (cnt1 + cnt2) * a + dis[p] * b);

        cout << ans << '\n';
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
