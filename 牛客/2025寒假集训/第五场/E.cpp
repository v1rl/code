#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

const int inf = 1e9 + 10;

void solve() {
    int n, mod;
    cin >> n >> mod;

    vector<int> a(n + 1);
    int sum = 0;
    set<PII> S;

    int ans = -1;
    int l = 0, r = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
        sum %= mod;

        if(sum > ans) {
            ans = sum;
            l = 1, r = i;
        }
        auto it = S.upper_bound({sum, inf});
        if(it != S.end()) {
            if(sum - it->first + mod > ans) {
                ans = sum - it->first + mod;
                l = it->second + 1, r = i;
            }
        }

        S.insert({sum, i});
    }

    cout << l - 1 << ' ' << r - 1 << ' ' << ans << '\n';
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
