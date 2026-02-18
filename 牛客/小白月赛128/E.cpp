#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;
const int inf = 1e9;

/*

*/

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector g(n, vector(m, '0'));
    int p = 0;

    if(n == 1 && m == 1) {
        if(k == 0) {
            cout << 0 << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    } else if(n == 1) {
        for(int j = 1; j < m; ) {
            g[0][j] = '1';
            p ++;
            if(j + 2 < m && j + 3 >= m) {
                j += 2;
            } else {
                j += 3;
            }
        }
    } else if(m == 1) {
        for(int i = 1; i < n; ) {
            g[i][0] = '1';
            p ++;
            if(i + 2 < n && i + 3 >= n) {
                i += 2;
            } else {
                i += 3;
            }
        }
    } else{
        for(int i = 1; i < n; ) {
            for(int j = 1; j < m; ) {
                g[i][j] = '1';
                p ++;
                if(j + 2 < m && j + 3 >= m) {
                    j += 2;
                } else {
                    j += 3;
                }
            }
            if(i + 2 < n && i + 3 >= n) {
                i += 2;
            } else {
                i += 3;
            }
        }
    }

    if(n * m - k < p) {
        cout << -1 << '\n';
        return;
    }

    int cnt = n * m - k - p;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(cnt && g[i][j] == '0') {
                g[i][j] = '1';
                cnt --;
            }
            cout << g[i][j] << " \n"[j == m - 1];
        }
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