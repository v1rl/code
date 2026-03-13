#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

// https://leetcode.cn/problems/maximize-value-of-function-in-a-ball-passing-game/description/

const int N = 35;

void solve() {
    int n;
    cin >> n;
    vector<int> to(n);
    for(int i = 0; i < n; i ++) {
        cin >> to[i];
    }

    vector f(N, vector(n, 0));
    vector g(N, vector(n, 0ll));
    for(int i = 0; i < n; i ++) {
        f[0][i] = to[i];
        g[0][i] = to[i];
    }
    for(int i = 1; i < N; i ++) {
        for(int j = 0; j < n; j ++) {
            f[i][j] = f[i - 1][f[i - 1][j]];
            g[i][j] = g[i - 1][j] + g[i - 1][f[i - 1][j]]; 
        }
    }

    i64 k;
    cin >> k;
    i64 mx = 0;
    for(int i = 0; i < n; i ++) {
        i64 t = k;
        int x = i;
        i64 v = i;
        for(int j = N - 1; j >= 0; j --) {
            if(t >= (1ll << j)) {
                v += g[j][x];
                x = f[j][x];
                t -= (1ll << j);
            }
        }
        mx = max(mx, v);
    }
    cout << mx << '\n';
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