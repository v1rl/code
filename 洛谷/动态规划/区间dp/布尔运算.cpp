#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/boolean-evaluation-lcci/description/

/*
*/

const int inf = 1e9;

void solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;

    int n = s.size();

    vector f(n, vector(n, (array<int, 2>){0, 0}));
    for(int len = 1; len <= n; len += 2) {
        for(int l = 0; l + len - 1 < n; l += 2) {
            int r = l + len - 1;
            if(len == 1) {
                f[l][r][s[l] - '0'] = 1;
            } else {
                for(int k = l + 1; k <= r; k += 2) {
                    int l0 = f[l][k - 1][0], l1 = f[l][k - 1][1];
                    int r0 = f[k + 1][r][0], r1 = f[k + 1][r][1];
                    if(s[k] == '&') {
                        f[l][r][0] += l0 * r0 + l0 * r1 + l1 * r0;
                        f[l][r][1] += l1 * r1;
                    } else if(s[k] == '^') {
                        f[l][r][0] += l1 * r1 + l0 * r0;
                        f[l][r][1] += l0 * r1 + l1 * r0;
                    } else if(s[k] == '|') {
                        f[l][r][0] += l0 * r0;
                        f[l][r][1] += l0 * r1 + l1 * r0 + l1 * r1;
                    }
                }
            }
        }
    }

    cout << f[0][n - 1][m] << '\n';
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
