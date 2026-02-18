#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    const int S = 2000;

    vector g(S + 2, vector(S + 2, 0));
    vector s(S + 2, vector(S + 2, 0));

    vector<array<int, 4>> a;

    for(int i = 0; i < n; i ++) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        a.push_back({x, y, l, r});
        g[x][l] ++;
        g[y + 1][r + 1] ++;
        g[x][r + 1] --;
        g[y + 1][l] --;
    }

    int ans = 0;
    for(int i = 1; i <= S; i ++) {
        for(int j = 1; j <= S; j ++) {
            g[i][j] += g[i][j - 1] + g[i - 1][j] - g[i - 1][j - 1];
            if(!g[i][j]) ans ++;
            if(g[i][j] == 1) {
                s[i][j] ++;
            }
            s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
        }
    }

    for(auto [x, y, l, r] : a) {
        cout << ans + s[y][r] - s[y][l - 1] - s[x - 1][r] + s[x - 1][l - 1] << '\n';
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
