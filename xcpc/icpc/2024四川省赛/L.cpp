#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<vector<array<int, 2>>> ans(2);
    for(int i = 1; i <= n; i ++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if(b == 0 || (a == 1 && b == 1 && x < y)) {
            ans[0].push_back({x, i});
        } else {
            ans[1].push_back({y, i});
        }
    }

    for(int i = 0; i < 2; i ++) {
        sort(ans[i].begin(), ans[i].end());
        for(auto [_, c] : ans[i]) {
            cout << c << ' ';
        }
        cout << '\n';
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
