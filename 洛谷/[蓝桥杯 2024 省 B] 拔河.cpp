#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<i64> pre(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    vector<vector<i64>> g(n + 1);
    multiset<i64> S;
    for(int i = 1; i <= n; i ++) {
        for(int j = i; j <= n; j ++) {
            g[i].emplace_back(pre[j] - pre[i - 1]);
            S.insert(pre[j] - pre[i - 1]);
        }
    }

    i64 ans = inf;
    for(int r = 1; r <= n; r ++) {
        for(auto c : g[r]) {
            S.erase(S.find(c));
        }
        for(int l = 1; l <= r; l ++) {
            i64 x = pre[r] - pre[l - 1];
            auto it = S.lower_bound(x);

            if(it != S.end()) {
                ans = min(ans, *it - x);
            }
            if(it != S.begin()) {
                ans = min(ans, x - *prev(it));
            }
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