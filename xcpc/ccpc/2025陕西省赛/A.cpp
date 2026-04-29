#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<int> w(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> w[i];
    }

    vector<vector<array<int, 2>>> vec(n + 1);
    for(int i = 0; i < n; i ++) {
        if(i == 0 || a[i] != a[i - 1]) {
            vec[a[i]].push_back({i, 0});
        }
        if(i != 0 && a[i] != a[i - 1]) {
            vec[a[i - 1]].back()[1] = i - 1;
        }
    }

    vec[a[n - 1]].back()[1] = n - 1;

    vector<vector<array<int, 2>>> res(n + 1);
    for(int i = 1; i <= n; i ++) {
        int lst = 0;
        for(auto [l, r] : vec[i]) {
            if(lst < l) {
                res[i].push_back({lst, l - 1});
            }
            lst = r + 1;    
        }
        if(lst != n) {
            res[i].push_back({lst, n - 1});
        }
    }

    for(int i = 1; i <= n; i ++) {
        if(res[i].size() == 0) {
            cout << w[i] + n << ' ';
            continue;
        }
        auto [l, r] = res[i][0];
        int lst = w[i] + (r - l + 1);
        int lpos = r;

        int ans = 0;
        for(int j = 1; j < res[i].size(); j ++) {
            auto [l, r] = res[i][j];
            if(r - lpos > w[i] + (r - l + 1)) {
                ans += lst;
                lst = w[i] + (r - l + 1);
                lpos = r;
            } else {
                lst += (r - lpos);
                lpos = r;
            }
        }
        ans += lst;
        cout << ans << ' ';
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
