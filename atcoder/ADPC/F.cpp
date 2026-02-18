#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
回溯过程以f[x][y]是否大于0为循环标准
*/

const i64 inf = 1e18 + 10;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = '#' + s;
    t = '#' + t;
    vector f(n + 1, vector(m + 1, 0));

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if(s[i] == t[j]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }

    string ans;
    int x = n, y = m;
    while(f[x][y] > 0) {
        if(x > 0 && f[x - 1][y] == f[x][y]) {
            x --;
        } else if(y > 0 && f[x][y - 1] == f[x][y]) {
            y --;
        } else {
            ans += s[x];
            x --, y --;            
        }
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