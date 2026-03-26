#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
给定两个字符串s1和s2
返回s1至少删除多少字符可以成为s2的子串

f[s1的前i个字符][s2前j个字符的后缀]匹配上的最小删除次数
*/

const int inf = 1e9 + 7;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    s1 = '#' + s1, s2 = '#' + s2;

    vector f(n + 1, vector(m + 1, 0));
    for(int i = 1; i <= n; i ++) {
        f[i][0] = i;
        for(int j = 1; j <= m; j ++) {
            if(s1[i] == s2[j]) {
                f[i][j] = f[i - 1][j - 1];
            } else {
                f[i][j] = f[i - 1][j] + 1;
            }
        }
    }

    int mn = inf;
    for(int j = 0; j <= m; j ++) {
        mn = min(mn, f[n][j]);
    }
    cout << mn << '\n';
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
