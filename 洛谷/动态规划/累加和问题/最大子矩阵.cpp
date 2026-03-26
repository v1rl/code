#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/max-submatrix-lcci/description/

/*
*/

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector(m, 0));

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }

    bool rev = false;
    if(n > m) {
        vector ng(m, vector(n, 0));
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                ng[j][i] = g[i][j];
            }
        }
        g = move(ng);
        swap(n, m);
        rev = true;
    }

    int U, D, L, R;
    int ans = -inf;
    for(int u = 0; u < n; u ++) {
        vector<int> a(m);
        for(int d = u; d < n; d ++) {
            for(int j = 0; j < m; j ++) {
                a[j] += g[d][j];
            }

            int pre = -inf, res = -inf;
            int l, r;
            for(int cl = 0, cr = 0, j = 0; j < m; j ++) {
                if(pre < 0) {
                    cl = cr = j;
                    pre = a[j];
                } else {
                    cr = j;
                    pre += a[j];
                }
                if(pre > res) {
                    res = pre;
                    l = cl;
                    r = cr;
                }
            }

            if(res > ans) {
                U = u, D = d;
                L = l, R = r;
                ans = res;
            }
        }
    }

    if(rev) {
        cout << L << ' ' << U << ' ' << R << ' ' << D << '\n';
    } else {
        cout << U << ' ' << L << ' ' << D << ' ' << R << '\n';
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
