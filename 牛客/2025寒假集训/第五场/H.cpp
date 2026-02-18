#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<i64, i64> PII;

/*
*/

void solve() {
    int n;
    cin >> n;
    vector g(n, vector(n, 0));
    i64 s[2] {};
    int c[2] {};
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> g[i][j];
            s[(i + j) & 1] += g[i][j];
            c[(i + j) & 1] ++;
        }
    }

    if(n == 1) {
        cout << "Yes" << '\n';
        return;
    }

    if(s[0] % c[0] || s[1] % c[1] || s[0] / c[0] != s[1] / c[1]) {
        cout << "NO" << '\n';
        return;
    }

    s[0] /= c[0];
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            g[i][j] -= s[0];
            g[i][j] &= 1;
            int v = g[i][j];

            g[i][j] ^= v;
            g[i][0] ^= v;
            g[0][j] ^= v;
            g[0][0] ^= v;
        }
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(g[i][j]) {
                cout << "No" << '\n';
                return;
            }
        }
    }

    cout << "Yes" << '\n';
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
