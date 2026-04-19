#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 998244353;


void solve() {
    int n, k;
    cin >> n >> k;
    if(k < n || k > n * n - (n - 1)) {
        cout << "No" << '\n';
    } else {
        vector g(n, vector(n, 0));
        g[0][0] = k;
        int l = 1;
        int r = n * n;
        for(int j = 1; j < n; j ++) {
            g[0][j] = l ++;
        }
        for(int i = 1; i < n; i ++) {
            g[i][i] = r --;
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(!g[i][j]) {
                    if(r == k) {
                        r --;
                    }
                    g[i][j] = r --;
                }
            }
        }

        cout << "Yes" << '\n';
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                cout << g[i][j] << ' ';
            }
            cout << '\n';
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
