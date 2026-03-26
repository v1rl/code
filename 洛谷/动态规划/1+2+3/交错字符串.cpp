#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/interleaving-string/description/

/*
f[s3前i个][s1前j个和s2前i-j个]的可行性 
f[s1前i个][s2前j个]的可行性
*/

const int mod = 1e9 + 7;

void solve() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    /*
    int n = s3.size(), m = s1.size(), l = s2.size();
    s1 = '#' + s1, s2 = '#' + s2, s3 = '#' + s3;

    vector f(n + 1, vector(m + 1, 0));
    f[0][0] = 1;

    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= min(i, m); j ++) {
            int k = i - j;
            if(k > l) {
                continue;
            }
            if(s3[i] == s1[j]) {
                f[i][j] |= f[i - 1][j - 1];
            }
            if(s3[i] == s2[k]) {
                f[i][j] |= f[i - 1][j];
            }
        }
    }

    cout << (n == m + l && f[n][m]) << '\n';
    */

    int n = s1.size(), m = s2.size();

    if(s3.size() != n + m) {
        cout << 0 << '\n';
        return;
    }

    s1 = '#' + s1, s2 = '#' + s2, s3 = '#' + s3;

    vector f(n + 1, vector(m + 1, 0));
    f[0][0] = 1;

    for(int i = 1; i <= n; i ++) {
        if(s1[i] == s3[i]) {
            f[i][0] = true;
        } else {
            break;
        }
    }
    for(int j = 1; j <= m; j ++) {
        if(s2[j] == s3[j]) {
            f[0][j] = true;
        } else {
            break;
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            int k = i + j;
            if(s3[k] == s1[i]) {
                f[i][j] |= f[i - 1][j];
            }
            if(s3[k] == s2[j]) {
                f[i][j] |= f[i][j - 1];
            }
        }
    }

    cout << f[n][m] << '\n';
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
