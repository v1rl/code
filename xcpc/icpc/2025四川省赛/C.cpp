#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> s(n + 1);
    for(int i = 1; i <= n; i ++) {
        for(int j = i; j <= n; j += i) {
            s[j].emplace_back(i);
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = i * 2; j <= n; j += i) {
            s[i].emplace_back(j);
        }
    }

    vector<double> dp(n + 1);
    for(int i = 1; i <= n; i ++) {
        dp[i] = i;
    }

    for(int rd = 0; rd < 100; rd ++) {
        vector<double> ndp = dp;
        for(int i = 1; i <= n; i ++) {
            double sum = 0;
            for(auto c : s[i]) {
                sum += dp[c - 1];
            }
            sum /= s[i].size();
            ndp[i] = min(dp[i - 1], sum) + 1;
        }
        dp = move(ndp);
    }

    cout << fixed << setprecision(10);
    while(q --) {
        int x;
        cin >> x;
        cout << dp[x] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}