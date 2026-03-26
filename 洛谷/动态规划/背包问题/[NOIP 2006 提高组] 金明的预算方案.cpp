#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P1064

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> m >> n;
    vector<vector<int>> v(n), w(n);
    vector<array<int, 3>> vec(n + 1);
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= n; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        vec[i] = {y * x, x , z};
        if(z) {
            g[z].push_back(i);
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        auto [wi, vi, op] = vec[i];
        if(op != 0) {
            continue;
        }
        int t = g[i].size();
        for(int j = 0; j < 1 << t; j ++) {
            int vs = vi, ws = wi;
            for(int k = 0; k < t; k ++) {
                if(j >> k & 1) {
                    auto [wc, vc, _] = vec[g[i][k]];
                    vs += vc;
                    ws += wc;
                }
            }
            v[cnt].emplace_back(vs);
            w[cnt].emplace_back(ws);
        }
        cnt ++;
    }

    vector<int> f(m + 1);
    for(int i = 0; i < cnt; i ++) {
        for(int j = m; j >= 0; j --) {
            for(int k = 0; k < v[i].size(); k ++) {
                if(j >= v[i][k]) {
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
                }
            }
        }
    }

    cout << f[m] << '\n';
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
