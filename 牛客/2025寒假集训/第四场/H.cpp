#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int inf = 1e9 + 10;
const int mod = 998244353;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector g(n, vector(m, 0));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }

    i64 mx = -1;
    int tx = 0, ty = 0;
    vector s(n, vector(m, 0ll));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {

            for(int x = max(0, i - 2); x <= min(n - 1, i + 2); x ++) {
                int p = 2 - abs(i - x);
                for(int y = max(0, j - p); y <= min(m - 1, j + p); y ++) {
                    s[i][j] += g[x][y];
                }
            }

            if(s[i][j] > mx) {
                mx = s[i][j];
                tx = i;
                ty = j;
            }
        }
    }

    while(q --) {
        int a, b, add;
        cin >> a >> b >> add;
        a --, b --;

        for(int x = max(0, a - 2); x <= min(n - 1, a + 2); x ++) {
            int p = 2 - abs(a - x);
            for(int y = max(0, b - p); y <= min(m - 1, b + p); y ++) {
                s[x][y] += add;
                if(s[x][y] > mx) {
                    mx = s[x][y];
                    tx = x;
                    ty = y;
                }
            }
        }
        cout << tx + 1 << ' ' << ty + 1 << '\n';
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
