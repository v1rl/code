#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 10;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }

    vector<int> dp(2049);
    dp[0] = 1;
    for(int i = 1; i <= n; i ++) {
        vector<int> ndp(2049);
        ndp[0] = 1;

        for(int j = 0; j < 2048; j ++) {
            ndp[j] |= dp[min(2048, j + a[i])];
        }

        for(int j = 0; j < 2048; j ++) {
            ndp[j] |= dp[min(2048, j ^ b[i])];
        }

        dp = ndp;
    }

    for(int i = 2047; i >= 0; i --) {
        if(dp[i]) {
            cout << i << '\n';
            return;
        }
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