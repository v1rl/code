#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.nowcoder.com/practice/4727c06b9ee9446cab2e859b4bb86bb8

const int mod = 1e9 + 7;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector f(n + 1, vector(m + 1, 0));
    s1 = '#' + s1, s2 = '#' + s2;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(s1[i] == s2[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }

    int i = n, j = m;
    string ans;
    while(f[i][j]) {
        if(f[i][j] == f[i][j - 1]) {
            j --;
        } else if(f[i][j] == f[i - 1][j]) {
            i --;
        } else {
            ans += s1[i];
            i --;
            j --;
        }
    }

    if(ans.empty()) {
        cout << -1 << '\n';
        return;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
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
