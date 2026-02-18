#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<array<int, 2>> g;
    int v = s[0] - '0', num = 1;
    for(int i = 1; i < n; i ++) {
        if(s[i] == s[i - 1]) {
            num ++;
        } else {
            g.push_back({v, num});
            v = s[i] - '0';
            num = 1;
        }
    }
    g.push_back({v, num});

    int ans = 0;
    for(int i = 1; i < g.size(); i ++) {
        if(g[i][0] == g[i - 1][0] + 1) {
            ans += min(g[i][1], g[i - 1][1]);
        }
    }

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