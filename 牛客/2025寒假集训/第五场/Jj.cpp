#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

void solve() {
    int g[3][3];
    bool ok = true;
    bool vis[10] {};
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j ++) {
            cin >> g[i][j];
            if(vis[g[i][j]]) {
                ok = false;
            }
            vis[g[i][j]] = true;
        }
    }

    int s = g[0][0] + g[1][1] + g[2][2];
    if(g[0][2] + g[1][1] + g[2][0] != s) {
        ok = false;
    } 

    for(int i = 0; i < 3; i ++) {
        if(g[i][0] + g[i][1] + g[i][2] != s) {
            ok = false;
        }
        if(g[0][i] + g[1][i] + g[2][i] != s) {
            ok = false;
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';
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
